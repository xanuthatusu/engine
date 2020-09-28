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
  // TODO: build shape object using data from message

  std::vector<Vertex> vertVect;
  Vertex v = { 0.5f, 0.4f };
  vertVect.push_back(v);
  v = { -0.1f, -0.7f };
  vertVect.push_back(v);
  v = { -0.5f, 0.3f };
  vertVect.push_back(v);
  Shape* t = new Shape(TRIANGLE, vertVect);

  framework->GetDraw()->AddShape(t);
}

}
