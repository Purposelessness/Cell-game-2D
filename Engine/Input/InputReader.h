#ifndef GAME_ENGINE_INPUT_INPUTREADER_H_
#define GAME_ENGINE_INPUT_INPUTREADER_H_

#include "../../Utility/EventHandler.h"

struct InputMessage;

class InputReader {
 public:
  virtual ~InputReader() = default;
  virtual void process() = 0;

  EventHandler<InputMessage> event_handler{};
};

#endif  // GAME_ENGINE_INPUT_INPUTREADER_H_
