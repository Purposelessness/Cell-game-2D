#ifndef GAME_INPUT_KEYINFO_H_
#define GAME_INPUT_KEYINFO_H_

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

#endif //GAME_INPUT_KEYINFO_H_
