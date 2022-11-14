#ifndef GAME_PROVIDER_CONTROLSCHEMEFILEPROVIDER_H_
#define GAME_PROVIDER_CONTROLSCHEMEFILEPROVIDER_H_

#include <fstream>
#include <string>
#include <vector>

#include "../Engine/Input/KeyboardInputReader/ControlScheme.h"

class ControlSchemeFileProvider {
 public:
  explicit ControlSchemeFileProvider(std::string filename = "keyboard.txt");

  ControlScheme scanScheme();

  void generateFile(const ControlScheme& control_scheme);
  static ControlScheme defaultScheme();

 private:
  bool fixControlMap(std::unordered_map<char, InputType>& control_map);
  static bool containsUndefined(
      std::unordered_map<char, InputType>& control_map);

  std::unordered_map<char, InputType> decode(const std::string& data);

  std::string encodeInputType(InputType type);
  InputType decodeInputType(const std::string& str);

  std::string _filename;

  std::unordered_map<std::string, InputType> _input_string_map = {
      {"MoveUp", InputType::MoveUp},       {"MoveDown", InputType::MoveDown},
      {"MoveRight", InputType::MoveRight}, {"MoveLeft", InputType::MoveLeft},
      {"Exit", InputType::Exit},           {"Reset", InputType::Reset}};
  const char kDelimiter = '\t';
};

#endif  // GAME_PROVIDER_CONTROLSCHEMEFILEPROVIDER_H_
