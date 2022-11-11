#ifndef GAME_PROVIDER_CONTROLSCHEMEFILEPROVIDER_H_
#define GAME_PROVIDER_CONTROLSCHEMEFILEPROVIDER_H_

#include <fstream>
#include <string>

#include "../Engine/Input/KeyboardInputReader/ControlScheme.h"

class ControlSchemeFileProvider {
 public:
  explicit ControlSchemeFileProvider(std::string filename = "keyboard.txt");

  ControlScheme scanScheme();
  static ControlScheme defaultScheme();
  void generateFile(const ControlScheme& control_scheme);

 private:
  std::pair<char, InputType> proceedLine(const std::string& line);

  std::string _filename;
  std::ifstream _control_scheme_file;

  std::unordered_map<std::string, InputType> _input_string_map = {
      {"MoveUp", InputType::MoveUp},       {"MoveDown", InputType::MoveDown},
      {"MoveRight", InputType::MoveRight}, {"MoveLeft", InputType::MoveLeft},
      {"Exit", InputType::Exit},           {"Reset", InputType::Reset}};
  const char kDelimiter = '\t';
};

#endif  // GAME_PROVIDER_CONTROLSCHEMEFILEPROVIDER_H_
