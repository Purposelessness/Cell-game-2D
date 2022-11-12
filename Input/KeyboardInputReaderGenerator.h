#ifndef GAME_INPUT_KEYBOARDINPUTREADERGENERATOR_H_
#define GAME_INPUT_KEYBOARDINPUTREADERGENERATOR_H_

#include <memory>

#include "../Engine/Input/KeyboardInputReader/KeyboardInputReader.h"

class KeyboardInputReaderGenerator {
 public:
  std::shared_ptr<KeyboardInputReader> operator()();
};

#endif
