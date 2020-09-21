#ifndef __MESSAGE__
#define __MESSAGE__

#include <string>

enum MessageType {LOG};

class Message {
 public:
  Message(MessageType type, std::string message);
  void log();
 private:
  MessageType type;
  std::string message;
};

#endif // __MESSAGE__
