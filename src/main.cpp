#include "EngineConfig.h"
#include "engine/Engine.h"
#include "shapes/Shape.h"
#include <iostream>

int main() {
  std::cout << "Running Version: " << Engine_VERSION_MAJOR << "." << Engine_VERSION_MINOR << "\n";

  GLfloat vertices[][2] = {
    {0.5f, 0.5f}, {-0.5f, 0.5f}, {0.0f, 0.0f}
  };

  Shape* triOne;
  triOne->SetVertices(3, vertices);

  Engine test;
  // test.SetWindowDimensions(800, 600);
  test.DrawShape(triOne);
  test.Run();

  return 0;
}
