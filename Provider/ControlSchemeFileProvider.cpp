#include "ControlSchemeFileProvider.h"

#include <sstream>
#include <utility>

#include "../Utility/Log/Log.h"

ControlSchemeFileProvider::ControlSchemeFileProvider(std::string filename)
    : _filename(std::move(filename)) {}

ControlScheme ControlSchemeFileProvider::scanScheme() {
  _control_scheme_file.open(_filename);
  if (!_control_scheme_file.good()) {
    LOG_ERROR_F("Cannot open control scheme file " + _filename +
                "! Generating default scheme.");
    auto scheme = defaultScheme();
    generateFile(scheme);
    return scheme;
  }

  std::unordered_map<char, InputType> map;
  map.reserve(_input_string_map.size());
  std::string line;
  while (std::getline(_control_scheme_file, line)) {
    map.insert(proceedLine(line));
  }

  _control_scheme_file.close();

  return ControlScheme{map};
}

ControlScheme ControlSchemeFileProvider::defaultScheme() {
  ControlScheme scheme{};
  scheme.addKey('W', InputType::MoveUp);
  scheme.addKey('D', InputType::MoveRight);
  scheme.addKey('S', InputType::MoveDown);
  scheme.addKey('A', InputType::MoveLeft);
  scheme.addKey('R', InputType::Reset);
  scheme.addKey('T', InputType::Exit);
  return scheme;
}

void ControlSchemeFileProvider::generateFile(
    const ControlScheme& control_scheme) {
  std::ofstream file(_filename);
  if (!file.good()) {
    LOG_ERROR_F("Cannot create file w/ control scheme!");
    return;
  }
  for (const auto& pair : control_scheme.keys()) {
    auto type = pair.second;
    std::string str{};
    for (const auto& data : _input_string_map) {
      if (data.second == type) {
        str = data.first;
        break;
      }
    }
    std::stringstream line{};
    line << pair.first << '\t' << str << '\n';
    file << line.str();
  }
}

std::pair<char, InputType> ControlSchemeFileProvider::proceedLine(
    const std::string& line) {
  std::stringstream ss(line);
  std::string key_str;
  std::string input_type_str;
  std::getline(ss, key_str, kDelimiter);
  std::getline(ss, input_type_str, kDelimiter);

  char key = key_str.at(0);
  InputType input_type = _input_string_map[input_type_str];

  return {key, input_type};
}
