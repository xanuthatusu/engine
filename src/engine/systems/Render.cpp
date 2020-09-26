#include <engine/systems/Render.h>

void Render::handleMessage(Message* message) {
  switch (message->getType()) {
  case DRAW_SHAPE:
    message->log();
    drawShape(message);
  }
}

void Render::Run() {}

const char* Render::Name() {
  return "render";
}

void Render::drawShape(Message* message) {
  // TODO: we'll call framework functions from here to draw the shape defined by message
}

