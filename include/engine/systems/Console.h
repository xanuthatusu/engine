#include <engine/System.h>

namespace System {

class Console: public System {
 public:
  void handleMessage(Message* message);
  void Run();
  const char* Name();

  void writeMessage(const char* message);
};

}
