#include "Engine.h"
#include <chrono>
#include <future>
#include <iostream>
#include <vector>

#include "../shapes/Shape.h"
#include "messages/MessageBus.h"
#include "framework/Framework.h"

#include "systems/console/Console.h"
#include "systems/render/Render.h"

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
    system->setMessageBus(msgBus);

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

