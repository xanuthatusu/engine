#include <engine/System.h>

#include <engine/framework/Input.h>

namespace System {

class Input: public System {
 public:
  void Run();
  const char* Name();
  void handleEvent(Framework::Event* event);
};

}
