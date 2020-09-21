#ifndef __MESSAGE__
#define __MESSAGE__

#include <string>

enum MessageType {LOG};

class Message {
 public:
  Message(MessageType type, const char* message);
  MessageType getType() const { return type; };
  void setMessage(const char* message);
  void log();
 private:
  MessageType type;
  const char* message;
};

#endif // __MESSAGE__
