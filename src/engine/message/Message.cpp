#include <engine/message/Message.h>

#include <iostream>

Message::Message(MessageType t, void* m) {
  type = t;
  message = m;
}

int Message::GetShape(Shape* shape) {
  if (type != DRAW_SHAPE) {
    return 0;
  }

  Shape* s = *(Shape**)message;
  *shape = *s;
  return 1;
}

void Message::SetMessage(void* m) {
  message = m;
}

void Message::log() {
  if (type != LOG) { return; }

  const char* s = *(const char**)message;
  std::cout << "message: " << s << std::endl;
  std::cout << "type: " << type << std::endl;
}
