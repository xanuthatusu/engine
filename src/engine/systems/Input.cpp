#include <engine/systems/Input.h>

namespace System {

void Input::Run() {}

const char* Input::Name() {
  return "input";
}

void Input::handleEvent(Framework::Event* event) {
  std::cout << "input handling for event of type " << event->type << " with details: " << event->details << std::endl;
  switch (event->key) {
    case 87:
      std::cout << "w pressed! Moving shape!" << std::endl;
      break;
  }

  std::vector<Vertex> vertVect;
  Vertex v = { 0.0f, 0.0f };
  vertVect.push_back(v);
  v = { 0.2f, 0.2f };
  vertVect.push_back(v);
  v = { -0.2f, 0.2f };
  vertVect.push_back(v);

  Shape* shape = new Shape(TRIANGLE, vertVect);
  Message* msg = new Message(DRAW_SHAPE, &shape);

  messageBus->postMessage(msg);
}

}
