#ifndef GAME_INPUT_INPUTMESSAGE_H_
#define GAME_INPUT_INPUTMESSAGE_H_

enum class InputType;
enum class InputState;

struct InputMessage {
    InputType type;
    InputState state;
};

enum class InputType {
    Undefined,
    MoveUp,
    MoveDown,
    MoveRight,
    MoveLeft,
    Exit,
    Reset
};

enum class InputState {
    Released,
    Pressed
};

#endif //GAME_INPUT_INPUTMESSAGE_H_
