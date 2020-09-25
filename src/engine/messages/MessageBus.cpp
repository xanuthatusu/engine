#include "MessageBus.h"
#include "Message.h"

#include "../systems/System.h"

MessageBus::MessageBus(System** s) {
  systems = s;
}

void MessageBus::postMessage(Message* message) {
  systems[0]->handleMessage(message);
}
