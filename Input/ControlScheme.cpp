#include "ControlScheme.h"
#include "InputMessage.h"

namespace Engine {

    ControlScheme::ControlScheme() : keyMap({}) {}

    void ControlScheme::addKey(char key, InputType type) {
        keyMap[key] = {type, InputState::Released};
    }

    void ControlScheme::deleteKey(char key) {
        keyMap.erase(key);
    }

    InputMessage ControlScheme::key(char key) {
        if (keyMap.count(key) == 0)
            return {};
        return keyMap[key];
    }

    std::map<char, InputMessage> &ControlScheme::keys() {
        return keyMap;
    }

}
