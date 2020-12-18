#ifndef __MESSAGE__
#define __MESSAGE__

#include <string>
#include <assets/shape/Shape.h>

enum MessageType {LOG, DRAW_SHAPE};

class Message {
 public:
  Message(MessageType type, void* message);
  MessageType getType() const { return type; };
  int GetShape(Shape* shape);
  void SetMessage(void* message);
  void log();
 private:
  MessageType type;
  void* message;
};

#endif // __MESSAGE__
