#include "ControlScheme.h"
#include "KeyInfo.h"

ControlScheme::ControlScheme() : keyMap({}) {}

void ControlScheme::addKey(char key, KeyType type) {
    keyMap[key] = {type, KeyState::Released};
}

void ControlScheme::deleteKey(char key) {
    keyMap.erase(key);
}

KeyInfo ControlScheme::key(char key) {
    if (keyMap.count(key) == 0)
        return {};
    return keyMap[key];
}

std::map<char, KeyInfo> &ControlScheme::keys() {
    return keyMap;
}
