#include <GL/gl3w.h>
#include <GLFW/glfw3.h>

#include <shape/Shape.h>
#include <engine/message/MessageBus.h>
#include <engine/framework/Framework.h>

class Engine {
 public:
  Engine();
  void Run();

 private:
  Framework* framework;
  MessageBus* msgBus;
  std::vector<System*> systems;
};
