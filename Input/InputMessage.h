#ifndef GAME_INPUTMESSAGE_H
#define GAME_INPUTMESSAGE_H


namespace Engine {
    enum class InputType;
    enum class InputState;

    struct InputMessage {
        InputType keyType;
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
}


#endif //GAME_INPUTMESSAGE_H
