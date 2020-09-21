#include "../System.h"

class Console: public System {
 public:
  void Run();
  void writeMessage(const char* message);
  const char* Name();
};
