#ifndef __MESSAGE_BUS__
#define __MESSAGE_BUS__

#include "Message.h"

class MessageBus {
 public:
  void postMessage(Message* message);
};

#endif // __MESSAGE_BUS__
