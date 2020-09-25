#ifndef __RENDER__
#define __RENDER__

#include "../System.h"

class Render: public System {
 public:
  void Run();
  const char* Name();
  void handleMessage(Message* message);
 private:
  void drawShape(Message* message);
};

#endif // __RENDER__
