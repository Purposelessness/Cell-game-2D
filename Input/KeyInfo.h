#ifndef GAME_KEYINFO_H
#define GAME_KEYINFO_H


enum class KeyType;
enum class KeyState;

struct KeyInfo {
    KeyType type;
    KeyState state;
};

enum class KeyType {
    Undefined,
    MoveUp,
    MoveDown,
    MoveRight,
    MoveLeft,
    Exit,
    Reset
};

enum class KeyState {
    Released,
    Pressed
};


#endif //GAME_KEYINFO_H
