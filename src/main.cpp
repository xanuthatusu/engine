#include "EngineConfig.h"
#include "engine/Engine.h"
#include <iostream>

int main() {
  std::cout << "Running Version: " << Engine_VERSION_MAJOR << "." << Engine_VERSION_MINOR << "\n";

  Engine test;
  test.Run();

  return 0;
}
