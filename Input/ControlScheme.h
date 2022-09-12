#ifndef GAME_CONTROLSCHEME_H
#define GAME_CONTROLSCHEME_H


#include <map>
#include <array>

namespace Engine {

    enum class InputType;
    struct InputMessage;

    class ControlScheme {
    public:
        ControlScheme();

        void addKey(char key, InputType type);
        void deleteKey(char key);

        std::map<char, InputMessage> &keys();
        InputMessage key(char key);

    private:
        std::map<char, InputMessage> keyMap;
    };

}


#endif //GAME_CONTROLSCHEME_H