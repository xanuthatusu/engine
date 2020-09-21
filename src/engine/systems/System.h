#ifndef __SYSTEM__
#define __SYSTEM__

#include "../messages/MessageBus.h"

#include <iostream>

class System {
 public:
  MessageBus* messageBus;

  void setMessageBus(MessageBus* bus) {
    messageBus = bus;
  }

  void handleMessage(Message* message) {
    switch (message->getType()) {
    case LOG:
      message->log();
    }
  }

  virtual void Run() { std::cout << "Running system.\n"; };

  virtual const char* Name() { return "generic system"; };
};

#endif // __SYSTEM__
