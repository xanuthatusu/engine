#ifndef __MESSAGE_BUS__
#define __MESSAGE_BUS__

#include <engine/message/Message.h>
#include <vector>

class System;
class MessageBus {
 public:
  MessageBus(std::vector<System*> systems);
  void postMessage(Message* message);
 private:
  std::vector<System*> systems;
};

#endif // __MESSAGE_BUS__
