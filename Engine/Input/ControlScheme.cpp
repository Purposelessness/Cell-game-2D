#include "ControlScheme.h"
#include "InputMessage.h"

ControlScheme::ControlScheme() : _key_map({}) {}

void ControlScheme::addKey(char key, InputType type) {
    _key_map[key] = {type, InputState::Released};
}

void ControlScheme::deleteKey(char key) {
    _key_map.erase(key);
}

InputMessage ControlScheme::key(char key) {
    if (_key_map.count(key) == 0)
        return {};
    return _key_map[key];
}

std::map<char, InputMessage>& ControlScheme::keys() {
    return _key_map;
}
