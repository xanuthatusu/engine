#include <engine/Engine.h>
#include <chrono>
#include <future>
#include <iostream>
#include <vector>

#include <assets/shape/Shape.h>
#include <engine/message/MessageBus.h>
#include <engine/framework/Framework.h>

#include <logic/Logic.h>

#include <engine/systems/Console.h>
#include <engine/systems/Render.h>
#include <engine/systems/Input.h>

Engine::Engine() {
  System::Input* inputSystem = new System::Input();
  systems = std::vector<System::System*>({
    new System::Console(),
    new System::Render(),
    inputSystem,
  });

  msgBus = new MessageBus(systems);
  framework = new Framework::Framework(inputSystem);
  logic = new Logic();

  std::cout << "finished initializing engine\n";
}

void Engine::Run() {
  auto frameworkFuture = std::async(&Framework::Framework::Start, framework);

  std::vector<std::future<void>> systemFutures;

  std::cout << systems.size() << " systems\n";
  std::vector<System::System*>::iterator systemIt;
  for (systemIt = systems.begin(); systemIt != systems.end(); systemIt++) {
    System::System* system = *systemIt;
    system->configure(msgBus, framework);

    systemFutures.push_back(std::async(&System::System::Run, system));
  }

  std::this_thread::sleep_for(std::chrono::seconds(1));

  std::vector<Vertex> vertVect;
  Vertex v = { 0.7f, 0.0f };
  vertVect.push_back(v);
  v = { 0.7f, -0.1f };
  vertVect.push_back(v);
  v = { 0.6f, -0.2f };
  vertVect.push_back(v);
  Shape* shape = new Shape(TRIANGLE, vertVect);
  Message* msg = new Message(DRAW_SHAPE, &shape);

  msgBus->postMessage(msg);

  std::vector<std::future<void>>::iterator futureIt;
  for (futureIt = systemFutures.begin(); futureIt != systemFutures.end(); futureIt++) {
    futureIt->wait();
  }

  frameworkFuture.wait();
}

