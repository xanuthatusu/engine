#ifndef __SYSTEM__
#define __SYSTEM__

#include "../messages/MessageBus.h"
#include "../framework/Framework.h"

#include <iostream>

class System {
 public:
  MessageBus* messageBus;
  Framework* framework;

  void configure(MessageBus* bus, Framework* frame) {
    messageBus = bus;
    framework = frame;
  }

  virtual void handleMessage(Message* message) {
    switch (message->getType()) {
    case LOG:
      message->log();
    }
  }

  virtual void Run() { std::cout << "Running system.\n"; };
  virtual const char* Name() { return "generic system"; };
};

#endif // __SYSTEM__
