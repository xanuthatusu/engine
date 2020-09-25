#include "Console.h"
#include "../../messages/Message.h"

#include <thread>
#include <chrono>

void Console::writeMessage(const char* message) {
  Message msg(LOG, message);
  messageBus->postMessage(&msg);
}

void Console::Run() {
  writeMessage("Starting console!");
  for (int i = 0; i < 15; i++) {
    writeMessage("loop!");
    std::this_thread::sleep_for(std::chrono::seconds(1));
  }
}

const char* Console::Name() {
  return "console";
}
