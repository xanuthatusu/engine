#include <engine/Engine.h>
#include <chrono>
#include <future>
#include <iostream>
#include <vector>

#include <shape/Shape.h>
#include <engine/message/MessageBus.h>
#include <engine/framework/Framework.h>

#include <engine/systems/Console.h>
#include <engine/systems/Render.h>

Engine::Engine() {
  systems = std::vector<System*>({
      new Console(),
      new Render(),
    });

  msgBus = new MessageBus(systems);
  framework = new Framework();

  std::cout << "finished initializing engine\n";
}

void Engine::Run() {
  auto frameworkFuture = std::async(&Framework::Start, framework);

  std::vector<std::future<void>> systemFutures;

  std::cout << systems.size() << " systems\n";
  std::vector<System*>::iterator systemIt;
  for (systemIt = systems.begin(); systemIt != systems.end(); systemIt++) {
    System* system = *systemIt;
    system->configure(msgBus, framework);

    systemFutures.push_back(std::async(&System::Run, system));
  }

  Message msg(DRAW_SHAPE, "rect");
  msgBus->postMessage(&msg);

  std::vector<std::future<void>>::iterator futureIt;
  for (futureIt = systemFutures.begin(); futureIt != systemFutures.end(); futureIt++) {
    futureIt->wait();
  }

  frameworkFuture.wait();
}

