#include "Engine.h"
#include <chrono>
#include <future>
#include <iostream>
#include <vector>

#include <GL/gl3w.h>
#include <GLFW/glfw3.h>

#include "../shapes/Shape.h"
#include "messages/MessageBus.h"

#include "systems/console/Console.h"
#include "systems/render/Render.h"

Engine::Engine() {
  Console console;
  Render render;
  std::vector<System*> systems = {
    &console,
    &render,
  };

  MessageBus msgBus(systems);

  std::vector<std::future<void>> systemFutures;

  std::cout << systems.size() << " systems\n";
  std::vector<System*>::iterator systemIt;
  for (systemIt = systems.begin(); systemIt != systems.end(); systemIt++) {
    System* system = *systemIt;
    system->setMessageBus(&msgBus);

    systemFutures.push_back(std::async(&System::Run, system));
  }

  Message msg(DRAW_SHAPE, "square");
  msgBus.postMessage(&msg);

  std::vector<std::future<void>>::iterator futureIt;
  for (futureIt = systemFutures.begin(); futureIt != systemFutures.end(); futureIt++) {
    futureIt->wait();
  }
}

void Engine::SetWindowDimensions(int width, int height) {
  glfwInit();

  window = glfwCreateWindow(width, height, "Engine", NULL, NULL);

  glfwMakeContextCurrent(window);
}

void Engine::DrawShape(Shape*) {
}

void Engine::UpdateScreen() {
  static const float black[] = { 0.0f, 0.0f, 0.0f, 0.0f };
  static const float red[] = { 1.0f, 0.0f, 0.0f, 0.0f };

  glClearBufferfv(GL_COLOR, 0, black);

  glBindVertexArray(VAOs[Triangles]);
  glDrawArrays(GL_TRIANGLES, 0, NumVertices);

  glFlush();
}

void Engine::keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
  if (key == GLFW_KEY_E && action == GLFW_PRESS) {
    std::cout << "EEEE\n";
  }
}

void Engine::Run() {
  gl3wInit();

  glGenVertexArrays(NumVAOs, VAOs);
  glBindVertexArray(VAOs[Triangles]);

  GLfloat  vertices[NumVertices][2] = {
    { -0.90f, -0.90f }, {  0.85f, -0.90f }, { -0.90f,  0.85f },
    {  0.90f, -0.85f }, {  0.90f,  0.90f }, { -0.85f,  0.90f }
  };

  glGenBuffers(NumBuffers, Buffers);
  glBindBuffer(GL_ARRAY_BUFFER, Buffers[ArrayBuffer]);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

  ShaderInfo shaders[] = {
    {GL_VERTEX_SHADER, "media/shaders/triangles.vert"},
    {GL_FRAGMENT_SHADER, "media/shaders/triangles.frag"},
    {GL_NONE, NULL}
  };

  GLuint program = LoadShaders(shaders);
  glUseProgram(program);

  glVertexAttribPointer(vPosition, 2, GL_FLOAT, GL_FALSE, 0, 0);
  glEnableVertexAttribArray(vPosition);

  glfwSetKeyCallback(window, keyCallback);

  while (!glfwWindowShouldClose(window)) {
    UpdateScreen();
    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  glfwDestroyWindow(window);

  glfwTerminate();
}

const GLchar* Engine::ReadShader(const char* filename) {
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

GLuint Engine::LoadShaders(ShaderInfo* shaders) {
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
