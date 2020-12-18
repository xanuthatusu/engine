#ifndef __FRAMEWORK__
#define __FRAMEWORK__

#include <engine/framework/Draw.h>
#include <engine/framework/Input.h>

namespace Framework {

typedef struct {
  GLenum type;
  const char* filename;
  GLuint shader;
} ShaderInfo;

class Framework {
 public:
  Framework(System::Input* is) : inputSystem{is} {};
  void Start();
  void SetWindowDimensions(int width, int height);

  Draw* GetDraw() { return draw; };
  Input* GetInput() { return input; };

 private:
  Draw* draw;
  Input* input;
  GLFWwindow* window;

  System::Input* inputSystem;

  static const GLchar* ReadShader(const char* filename);
  GLuint LoadShaders(ShaderInfo* shaders);
};

}

#endif // __FRAMEWORK__
