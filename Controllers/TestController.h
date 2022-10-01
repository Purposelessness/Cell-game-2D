#ifndef GAME_CONTROLLERS_TESTCONTROLLER_H_
#define GAME_CONTROLLERS_TESTCONTROLLER_H_

#include "../Engine/Input/IController.h"
#include "../Core/IApplication.h"

class TestController : public IController {
public:
    explicit TestController(IApplication* application);

    void process(const InputMessage& input_message) override;

private:
    IApplication* _application;
};

#endif //GAME_CONTROLLERS_TESTCONTROLLER_H_