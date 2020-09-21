#include "MessageBus.h"
#include "Message.h"

void MessageBus::postMessage(Message* message) {
  message->log();
}
