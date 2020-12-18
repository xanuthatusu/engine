#ifndef __FRAMEWORK_INPUT__
#define __FRAMEWORK_INPUT__

#include <GL/gl3w.h>
#include <GLFW/glfw3.h>

/* #include <engine/systems/Input.h> */

namespace System { class Input; }

namespace Framework {

enum EventType {KEY_PRESS};

typedef struct {
  EventType type;
  int key;
  const char* details;
} Event;

class Input {
 public:
  Input(GLFWwindow* w, System::Input* is);
  static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);

  void SetInputSystem(System::Input* is) { inputSystem = is; };

  void handleMessage(int key, int scancode, int action, int mods);

 private:
  GLFWwindow* window;
  System::Input* inputSystem;
};

}

#endif // __FRAMEWORK_INPUT__
