#ifndef GAME_ENGINE_INPUT_ICONTROLLER_H_
#define GAME_ENGINE_INPUT_ICONTROLLER_H_

#include "InputMessage.h"

class IController {
 public:
  virtual ~IController() = default;
  virtual void process(const InputMessage& input_message) = 0;
};

#endif  // GAME_ENGINE_INPUT_ICONTROLLER_H_
