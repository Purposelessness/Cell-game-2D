#ifndef GAME_ENGINE_INPUT_KEYBOARDINPUTREADER_CONTROLSCHEME_H_
#define GAME_ENGINE_INPUT_KEYBOARDINPUTREADER_CONTROLSCHEME_H_

#include <unordered_map>

#include "../InputMessage.h"

class ControlScheme {
 public:
  ControlScheme();
  explicit ControlScheme(std::unordered_map<char, InputType> key_map);

  void addKey(char key, InputType type);
  void deleteKey(char key);

  std::unordered_map<char, InputType>& keys();
  InputType key(char key);

 private:
  std::unordered_map<char, InputType> _key_map;
};

#endif  // GAME_ENGINE_INPUT_KEYBOARDINPUTREADER_CONTROLSCHEME_H_
