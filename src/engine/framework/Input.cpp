#include <engine/framework/Input.h>
#include <engine/framework/Framework.h>

#include <iostream>

#include <engine/systems/Input.h>

namespace Framework {

  Input::Input(GLFWwindow* w, System::Input* is) {
    glfwSetKeyCallback(w, keyCallback);
    inputSystem = is;
  };

  void Input::keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    Input* input = static_cast<Framework*>(glfwGetWindowUserPointer(window))->GetInput();
    
    input->handleMessage(key, scancode, action, mods);
  };

  void Input::handleMessage(int key, int scancode, int action, int mods) {
    if (action == GLFW_PRESS) {
      Event testEvent = { KEY_PRESS, "test event action" };
      inputSystem->handleEvent(&testEvent);
    }
  }

}
