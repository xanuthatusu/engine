#include "Message.h"

#include <iostream>
#include <string>

Message::Message(MessageType t, std::string m) {
  type = t;
  message = m;
}

void Message::log() {
  std::cout << "message: " << message << std::endl;
  std::cout << "type: " << type << std::endl;
}
