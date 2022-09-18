#include "ControlScheme.h"
#include "KeyInfo.h"

ControlScheme::ControlScheme() : _key_map({}) {}

void ControlScheme::addKey(char key, KeyType type) {
    _key_map[key] = {type, KeyState::Released};
}

void ControlScheme::deleteKey(char key) {
    _key_map.erase(key);
}

KeyInfo ControlScheme::key(char key) {
    if (_key_map.count(key) == 0)
        return {};
    return _key_map[key];
}

std::map<char, KeyInfo>& ControlScheme::keys() {
    return _key_map;
}
