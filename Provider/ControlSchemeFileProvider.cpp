#include "ControlSchemeFileProvider.h"

#include <sstream>
#include <utility>

#include "../Utility/Log/Log.h"

ControlSchemeFileProvider::ControlSchemeFileProvider(std::string filename)
    : _filename(std::move(filename)) {}

ControlScheme ControlSchemeFileProvider::scanScheme() {
  _control_scheme_file.open(_filename);
  if (!_control_scheme_file.good()) {
    LOG_ERROR_F("Cannot open control scheme file " + _filename);
    return {};
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
