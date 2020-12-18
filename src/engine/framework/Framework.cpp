#include <GL/gl3w.h>
#include <GLFW/glfw3.h>

#include <engine/framework/Framework.h>

#include <cstdio>
#include <iostream>

namespace Framework {

void Framework::Start() {
  SetWindowDimensions(950, 1080);

  draw = new Draw();
  input = new Input(window, inputSystem);

  ShaderInfo shaders[] = {
    {GL_VERTEX_SHADER, "media/shaders/triangles.vert"},
    {GL_FRAGMENT_SHADER, "media/shaders/triangles.frag"},
    {GL_NONE, NULL}
  };

  GLuint program = LoadShaders(shaders);
  glUseProgram(program);

  while (!glfwWindowShouldClose(window)) {
    draw->UpdateScreen();
    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  glfwDestroyWindow(window);

  glfwTerminate();
}

const GLchar* Framework::ReadShader(const char* filename) {
  // TODO: make OS agnostic
  FILE* infile = fopen(filename, "rb");

  if (!infile) {
    std::cout << "Unable to open shader file!\n";
    return NULL;
  }

  fseek(infile, 0, SEEK_END);
  int len = ftell(infile);
  fseek(infile, 0, SEEK_SET);

  GLchar* source = new GLchar[len+1];

  fread(source, 1, len, infile);
  fclose(infile);

  source[len] = 0;

  return const_cast<const GLchar*>(source);
}

GLuint Framework::LoadShaders(ShaderInfo* shaders) {
  // printf("OpenGL version is (%s)\n", glGetString(GL_VERSION));
  if (shaders == NULL) { return 0; }

  GLuint program = glCreateProgram();

  ShaderInfo* entry = shaders;
  while (entry->type != GL_NONE) {
    GLuint shader = glCreateShader(entry->type);

    entry->shader = shader;

    const GLchar* source = ReadShader(entry->filename);
    if (source == NULL) {
      for (entry = shaders; entry->type != GL_NONE; ++entry) {
	glDeleteShader(entry->shader);
	entry->shader = 0;
      }

      return 0;
    }

    glShaderSource(shader, 1, &source, NULL);
    delete [] source;

    glCompileShader(shader);

    GLint compiled;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &compiled);
    if (!compiled) {
      GLsizei len;
      glGetShaderiv( shader, GL_INFO_LOG_LENGTH, &len );

      GLchar* log = new GLchar[len+1];
      glGetShaderInfoLog( shader, len, &len, log );
      std::cerr << "Shader compilation failed: " << log << std::endl;
      delete [] log;

      std::cout << "error!\n";
      return 0;
    }

    glAttachShader(program, shader);

    ++entry;
  }

  glLinkProgram(program);

  GLint linked;
  glGetProgramiv(program, GL_LINK_STATUS, &linked);
  if (!linked) {
    for (entry=shaders; entry->type != GL_NONE; ++entry) {
      glDeleteShader(entry->shader);
      entry->shader = 0;
    }

    return 0;
  }

  return program;
}

void Framework::SetWindowDimensions(int width, int height) {
  glfwInit();

  window = glfwCreateWindow(width, height, "Engine", NULL, NULL);

  glfwMakeContextCurrent(window);

  // set this as the window user pointer so that we can access member data
  // in the static member function keyCallback
  glfwSetWindowUserPointer(window, this);

  gl3wInit();
}

}
