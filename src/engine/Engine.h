#include <GL/gl3w.h>
#include <GLFW/glfw3.h>

#include "../shapes/Shape.h"

typedef struct {
  GLenum type;
  const char* filename;
  GLuint shader;
} ShaderInfo;

class Engine {
 public:
  Engine();
  void SetWindowDimensions(int width, int height);
  void DrawShape(Shape*);
  void UpdateScreen();
  void Run();

 private:
  enum Buffer_IDs { ArrayBuffer, NumBuffers };
  enum Attrib_IDs { vPosition = 0 };
  enum VAO_IDs { Triangles, NumVAOs };

  GLuint Buffers[NumBuffers];
  GLuint VAOs[NumVAOs];
  
  const GLuint NumVertices = 6;

  static const GLchar* ReadShader(const char* filename);
  GLuint LoadShaders(ShaderInfo* shaders);

  GLFWwindow* window;
};
