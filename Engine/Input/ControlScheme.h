#ifndef GAME_ENGINE_INPUT_CONTROLSCHEME_H_
#define GAME_ENGINE_INPUT_CONTROLSCHEME_H_

#include <map>
#include <array>

enum class InputType;
struct InputMessage;

class ControlScheme {
public:
    ControlScheme();

    void addKey(char key, InputType type);
    void deleteKey(char key);

    std::map<char, InputMessage>& keys();
    InputMessage key(char key);

private:
    std::map<char, InputMessage> _key_map;
};

#endif //GAME_ENGINE_INPUT_CONTROLSCHEME_H_