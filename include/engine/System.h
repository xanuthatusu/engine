#ifndef __SYSTEM__
#define __SYSTEM__

#include <GL/gl3w.h>
#include <GLFW/glfw3.h>

#include <engine/message/MessageBus.h>
// #include <engine/framework/Framework.h>

#include <iostream>

namespace Framework { class Framework; }

namespace System {

class System {
 public:
  MessageBus* messageBus;
  Framework::Framework* framework;

  void configure(MessageBus* bus, Framework::Framework* frame) {
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

}

#endif // __SYSTEM__
