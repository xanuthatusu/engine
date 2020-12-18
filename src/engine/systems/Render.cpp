#include <engine/systems/Render.h>
#include <shape/Shape.h>

#include <engine/framework/Framework.h>

namespace System {

void Render::handleMessage(Message* message) {
  switch (message->getType()) {
  case DRAW_SHAPE:
    message->log();
    drawShape(message);
  }
}

void Render::Run() {
}

const char* Render::Name() {
  return "render";
}

void Render::drawShape(Message* message) {
  Shape* shape = new Shape();
  int ok = message->GetShape(shape);
  if (!ok) {
    std::cout << "error!\n";
  }

  framework->GetDraw()->AddShape(shape);
}

}
