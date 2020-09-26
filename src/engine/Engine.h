#include "../shapes/Shape.h"
#include "messages/MessageBus.h"
#include "framework/Framework.h"

class Engine {
 public:
  Engine();
  void Run();

 private:
  Framework* framework;
  MessageBus* msgBus;
  std::vector<System*> systems;
};
