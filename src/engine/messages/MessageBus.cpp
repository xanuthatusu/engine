#include "MessageBus.h"
#include "Message.h"

#include "../systems/System.h"

MessageBus::MessageBus(std::vector<System*> s) {
  systems = s;
}

void MessageBus::postMessage(Message* message) {
  std::vector<System*>::iterator systemIt;
  for (systemIt = systems.begin(); systemIt != systems.end(); systemIt++) {
    System* system = *systemIt;
    system->handleMessage(message);
  } 
}
