#include <engine/systems/Input.h>

namespace System {

void Input::Run() {}

const char* Input::Name() {
  return "input";
}

void Input::handleEvent(Framework::Event* event) {
  std::cout << "input handling for event of type " << event->type << " with details: " << event->details << std::endl;
  // Message* msg = new Message(LOG, "Input system handling message");
  // messageBus->postMessage(msg);
}

}
