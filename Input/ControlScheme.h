#ifndef GAME_INPUT_CONTROLSCHEME_H_
#define GAME_INPUT_CONTROLSCHEME_H_

#include <map>
#include <array>

enum class KeyType;
struct KeyInfo;

class ControlScheme {
public:
    ControlScheme();

    void addKey(char key, KeyType type);
    void deleteKey(char key);

    std::map<char, KeyInfo>& keys();
    KeyInfo key(char key);

private:
    std::map<char, KeyInfo> _key_map;
};

#endif //GAME_INPUT_CONTROLSCHEME_H_