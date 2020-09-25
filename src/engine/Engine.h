#include <GL/gl3w.h>
#include <GLFW/glfw3.h>

#include "../shapes/Shape.h"
#include "messages/MessageBus.h"
#include "framework/Framework.h"

class Engine {
 public:
  Engine();
  void DrawShape(Shape*);
  void Run();

 private:
  Framework* framework;
  MessageBus* msgBus;
  std::vector<System*> systems;
};
