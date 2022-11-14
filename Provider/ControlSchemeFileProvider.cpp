#include "ControlSchemeFileProvider.h"

#include <algorithm>
#include <regex>
#include <sstream>
#include <utility>

#include "../Utility/Log/Log.h"

ControlSchemeFileProvider::ControlSchemeFileProvider(std::string filename)
    : _filename(std::move(filename)) {}

ControlScheme ControlSchemeFileProvider::scanScheme() {
  auto control_scheme_file = std::ifstream(_filename);
  if (!control_scheme_file.good()) {
    LOG_ERROR_F("Cannot open control scheme file " + _filename +
                "! Generating default scheme.");
    auto scheme = defaultScheme();
    generateFile(scheme);
    return scheme;
  }

  std::stringstream ss;
  ss << control_scheme_file.rdbuf();
  control_scheme_file.close();

  std::unordered_map<char, InputType> map = decode(ss.str());

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
  file.close();
}

std::unordered_map<char, InputType> ControlSchemeFileProvider::decode(
    const std::string& data) {
  const std::regex kRegular{R"(\b([A-Z])[\s\=\-]+(\w+))"};
  std::unordered_map<char, InputType> scheme;

  const std::vector<std::smatch> kMatches{
      std::sregex_iterator{std::cbegin(data), std::cend(data), kRegular},
      std::sregex_iterator{}};
  for (const auto& m : kMatches) {
    char key = m.str(1)[0];
    InputType type = decodeInputType(m.str(2));
    scheme[key] = type;
  }

  return scheme;
}

std::string ControlSchemeFileProvider::encodeInputType(InputType type) {
  auto lamda = [&type](const std::pair<std::string, InputType>& pair) {
    return pair.second == type;
  };
  auto res = std::ranges::find_if(_input_string_map.begin(),
                                  _input_string_map.end(), lamda);
  return res == _input_string_map.end() ? std::string{} : res->first;
}

InputType ControlSchemeFileProvider::decodeInputType(const std::string& str) {
  return _input_string_map.contains(str) ? _input_string_map[str]
                                         : InputType::Undefined;
}

ControlScheme ControlSchemeFileProvider::defaultScheme() {
  ControlScheme scheme{};
  scheme.addKey('W', InputType::MoveUp);
  scheme.addKey('D', InputType::MoveRight);
  scheme.addKey('S', InputType::MoveDown);
  scheme.addKey('A', InputType::MoveLeft);
  scheme.addKey('R', InputType::Reset);
  scheme.addKey('T', InputType::Exit);
  scheme.addKey('L', InputType::Load);
  scheme.addKey('O', InputType::Save);
  return scheme;
}
