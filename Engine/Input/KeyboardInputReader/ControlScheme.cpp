#include "ControlScheme.h"

#include <utility>

ControlScheme::ControlScheme()
    : ControlScheme(std::unordered_map<char, InputType>{}) {}

ControlScheme::ControlScheme(std::unordered_map<char, InputType> key_map)
    : _key_map(std::move(key_map)) {}

void ControlScheme::addKey(char key, InputType type) { _key_map[key] = type; }

void ControlScheme::deleteKey(char key) { _key_map.erase(key); }

InputType ControlScheme::key(char key) {
  if (!_key_map.contains(key)) {
    return {};
  }
  return _key_map[key];
}

std::unordered_map<char, InputType>& ControlScheme::keys() { return _key_map; }
