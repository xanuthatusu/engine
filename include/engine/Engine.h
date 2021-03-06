#include <GL/gl3w.h>
#include <GLFW/glfw3.h>

#include <assets/shape/Shape.h>
#include <logic/Logic.h>
#include <engine/message/MessageBus.h>
#include <engine/framework/Framework.h>

class Engine {
 public:
  Engine();
  void Run();

 private:
  Framework::Framework* framework;
  MessageBus* msgBus;
  Logic* logic;
  std::vector<System::System*> systems;
};
