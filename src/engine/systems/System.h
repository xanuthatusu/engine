#include "messages/MessageBus.h"

class System {
 public:
  void handleMessage(Message* message) {
    switch (message->type) {
    }
  }
 private:
  MessageBus* messageBus;
}
