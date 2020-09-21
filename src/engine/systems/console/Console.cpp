#include "Console.h"
#include "../../messages/Message.h"

void Console::writeMessage(const char* message) {
  Message msg(LOG, message);
  messageBus->postMessage(&msg);
}

void Console::Run() {
  writeMessage("Starting console!");
}

const char* Console::Name() {
  return "console";
}
