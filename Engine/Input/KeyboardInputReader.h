#ifndef GAME_ENGINE_INPUT_KEYBOARDINPUTREADER_H_
#define GAME_ENGINE_INPUT_KEYBOARDINPUTREADER_H_

#include <memory>

#include "InputReader.h"

class ControlScheme;

class KeyboardInputReader : public InputReader {
public:
    explicit KeyboardInputReader(std::shared_ptr<ControlScheme> control_scheme);

    void process() override;
    void changeControlScheme(std::shared_ptr<ControlScheme> control_scheme);

private:
    static bool keyPressed(int key);

    std::shared_ptr<ControlScheme> _control_scheme;
};

#endif //GAME_ENGINE_INPUT_KEYBOARDINPUTREADER_H_