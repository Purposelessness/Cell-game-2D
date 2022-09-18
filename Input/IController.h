#ifndef GAME_INPUT_ICONTROLLER_H_
#define GAME_INPUT_ICONTROLLER_H_

struct KeyInfo;

class IController {
public:
    virtual void process(const KeyInfo& input_message) = 0;
};

#endif //GAME_INPUT_ICONTROLLER_H_
