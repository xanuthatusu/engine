#include <engine/systems/Console.h>

#include <thread>
#include <chrono>

namespace System {

void Console::handleMessage(Message* message) {
  // this is the same as the base class...for now
  switch (message->getType()) {
  case LOG:
    message->log();
  }
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

void Console::writeMessage(const char* message) {
  std::string m = "console(";
  m += message;
  m += ")";

  Message msg(LOG, m.c_str());
  messageBus->postMessage(&msg);
}

}
