#include "ControlSchemeFileProvider.h"

#include <algorithm>
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
    if (line.empty()) {
      break;
    }
    map.insert(proceedLine(line));
  }
  _control_scheme_file.close();

  bool fix = fixControlMap(map);
  ControlScheme scheme{map};

  if (fix) {
    LOG_ERROR_F("In control scheme files found invalid bindings!");
    generateFile(scheme);
  }
  return scheme;
}

bool ControlSchemeFileProvider::fixControlMap(
    std::unordered_map<char, InputType>& control_map) {
  if (control_map.size() == _input_string_map.size() &&
      !containsUndefined(control_map)) {
    return false;
  }
  bool flag = false;

  auto default_scheme = defaultScheme();
  std::unordered_map<InputType, bool> checked{};
  auto tmp = control_map;
  for (const auto& pair : tmp) {
    if (pair.second == InputType::Undefined) {
      control_map.erase(pair.first);
      flag = true;
      continue;
    }
    checked[pair.second] = true;
  }
  for (const auto& pair : default_scheme.keys()) {
    if (checked[pair.second]) {
      continue;
    }
    flag = true;
    control_map[pair.first] = pair.second;
  }

  return flag;
}

bool ControlSchemeFileProvider::containsUndefined(
    std::unordered_map<char, InputType>& control_map) {
  auto undefined_check = [](const std::pair<char, InputType>& pair) -> bool {
    return pair.second == InputType::Undefined;
  };
  return std::ranges::any_of(control_map, undefined_check);
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
    std::string str = encodeInputType(type);
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
  InputType input_type = decodeInputType(input_type_str);

  return {key, input_type};
}

std::string ControlSchemeFileProvider::encodeInputType(InputType type) {
  for (const auto& pair : _input_string_map) {
    if (pair.second == type) {
      return pair.first;
    }
  }
  return {};
}

InputType ControlSchemeFileProvider::decodeInputType(const std::string& str) {
  if (!_input_string_map.contains(str)) {
    return InputType::Undefined;
  }
  return _input_string_map[str];
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
