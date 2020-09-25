#ifndef __FRAMEWORK__
#define __FRAMEWORK__

#include <GL/gl3w.h>
#include <GLFW/glfw3.h>

typedef struct {
  GLenum type;
  const char* filename;
  GLuint shader;
} ShaderInfo;

class Framework {
 public:
  void Start();
  void UpdateScreen();
  void SetWindowDimensions(int width, int height);

 private:
  enum Buffer_IDs { ArrayBuffer, NumBuffers };
  enum Attrib_IDs { vPosition = 0 };
  enum VAO_IDs { Triangles, NumVAOs };

  GLuint Buffers[NumBuffers];
  GLuint VAOs[NumVAOs];
  
  const GLuint NumVertices = 6;

  GLFWwindow* window;

  static const GLchar* ReadShader(const char* filename);
  GLuint LoadShaders(ShaderInfo* shaders);

  static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
};

#endif // __FRAMEWORK__
