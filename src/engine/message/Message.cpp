#include <engine/message/Message.h>

#include <iostream>

Message::Message(MessageType t, const char* m) {
  type = t;
  message = m;
}

void Message::setMessage(const char* m) {
  message = m;
}

void Message::log() {
  std::cout << "message: " << message << std::endl;
  std::cout << "type: " << type << std::endl;
}
