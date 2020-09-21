#ifndef __MESSAGE_BUS__
#define __MESSAGE_BUS__

#include "Message.h"

class System;
class MessageBus {
 public:
  MessageBus(System** systems);
  void postMessage(Message* message);
 private:
  System** systems;
};

#endif // __MESSAGE_BUS__
