#ifndef __FRAMEWORK__
#define __FRAMEWORK__

#include <engine/framework/Draw.h>

typedef struct {
  GLenum type;
  const char* filename;
  GLuint shader;
} ShaderInfo;

class Framework {
 public:
  void Start();
  void SetWindowDimensions(int width, int height);

 private:
  Draw* draw;
  GLFWwindow* window;

  static const GLchar* ReadShader(const char* filename);
  GLuint LoadShaders(ShaderInfo* shaders);

  static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
  void keyHandler(int key, int scancode, int action, int mods);
};

#endif // __FRAMEWORK__
