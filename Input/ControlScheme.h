#ifndef GAME_CONTROLSCHEME_H
#define GAME_CONTROLSCHEME_H


#include <map>
#include <array>

enum class KeyType;
struct KeyInfo;

class ControlScheme {
public:
    ControlScheme();

    void addKey(char key, KeyType type);
    void deleteKey(char key);

    std::map<char, KeyInfo> &keys();
    KeyInfo key(char key);

private:
    std::map<char, KeyInfo> keyMap;
};


#endif //GAME_CONTROLSCHEME_H