A game engine made in C++
=========================

The main `Engine` library will provide the `Engine` class. An engine is comprised of three distinct regions:

## MessageBus

The Message Bus will be the main way `System`s will communicate with one another. For example, if I wanted to display the pause menu when I press `<ESC>`, I would make the input system (which the framework will pass input events to) post a `Message` to its `MessageBus` saying that the key was pressed. The Game Logic will see that message and post another couple of messages that say we should pause the game and render the pause menu.

The Message Bus does *NOT* send messages directly to specific systems. The Message Bus will keep track of the list of running systems and call each system's `handleMessage(Message*)` function, passing the message along. If a system does not care about the message, it will simply ignore it. This does probably add some overhead to the Engine, but the simplicity and ease of use are worth it to me for the time being. I may figure something else out later.

### Message List

- LOG
- DRAW_SHAPE

## Systems

Systems will use polymorphism to implement `System.h`. A system will be able to `Run()`, `handleMessage(Message*)`s and be `configure(MessagBus*, Framework*)`'d. A system will have a MessageBus and a Framework. Systems can not call any OpenGL functions directly and must use the Framework or post a message to the Message Bus.

### System list

- Console
- Input
- Render

#### Note
The input system is unique in that it's the only system that the Framework needs to know about. The Framework's input *class* will handle the conversion from raw OpenGL keycode data to a more manageable Event object that can be passed to the Input system. The input *system* will be the one to actually make decisions on what messages to send and what framework methods to call based on that input. 

## Framework

The framework will provide all the necessary functions for systems to interact with the OpenGL backend. This makes it easy to abstract all the low-level OpenGL memory management and C style blocks of code. It also paves the way for the engine to be framework agnostic as we can just implement the functions for the framework using a different API.

The framework will be a collection of classes that contain all the OpenGL specific functionality such as creating a window, drawing shapes, and handling inputs.

While the core functionality of a `System` is to `Run`, the only functionality of the `Framework` that will block is it's `Start()` Method. The `Start()` method will create all the necessary instances of Framework subclasses as well as OpenGL initialization. All other framework functions should be simple abstractions of OpenGL functions organized by subclass.

A Framework will also keep track of the Input system and call its HandleEvent() method.

### List of functions provided by framework

- Start()
- SetWindowDimensions(int width, int height)
- GetDraw()
- GetInput()

## Game Logic

Now that we have covered everything in the Engine, the final part will be the `Game Logic`. It will probably take some more time before I have a working instance of Game Logic, but all the code should be extremely abstracted.

- The engine will provide a class definition for the game logic. 
- No calls to any OpenGL specific functions. Everything will go through the Engine.

## To build
```bash
cmake --build .
```

## To Run
```bash
cd bin/
./app
```

### Notes
You have to be in the bin directory to run the application because of my simple way of opening shader files. I plan to update this in the future to be more user friendly.

