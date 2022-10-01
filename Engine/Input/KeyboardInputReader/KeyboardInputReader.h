#ifndef GAME_ENGINE_INPUT_KEYBOARDINPUTREADER_KEYBOARDINPUTREADER_H_
#define GAME_ENGINE_INPUT_KEYBOARDINPUTREADER_KEYBOARDINPUTREADER_H_

#include <memory>

#include "../InputReader.h"
#include "../InputMessage.h"

class ControlScheme;

class KeyboardInputReader : public InputReader {
public:
    explicit KeyboardInputReader(ControlScheme& control_scheme);

    void process() override;
    void changeControlScheme(ControlScheme& control_scheme);

private:
    static bool keyPressed(int key);

    std::unordered_map<char, InputMessage> _key_map;
};

#endif //GAME_ENGINE_INPUT_KEYBOARDINPUTREADER_KEYBOARDINPUTREADER_H_