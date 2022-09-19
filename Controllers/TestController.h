#ifndef GAME_CONTROLLERS_TESTCONTROLLER_H_
#define GAME_CONTROLLERS_TESTCONTROLLER_H_

#include "../Engine/Input/IController.h"

class TestController : public IController {
public:
    void process(const InputMessage& input_message) override;
};

#endif //GAME_CONTROLLERS_TESTCONTROLLER_H_