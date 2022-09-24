#ifndef GAME_CONTROLLERS_OBJECTCONTROLLER_H_
#define GAME_CONTROLLERS_OBJECTCONTROLLER_H_

#include <memory>
#include <vector>

#include "../Engine/Input/IController.h"
#include "../ECSLib/Systems/System.h"

class Transform;

class ObjectController : public IController, public System {
public:
    void process(const InputMessage& input_message) override;
    void process() override;

private:
    InputMessage _message{};
};

#endif //GAME_CONTROLLERS_OBJECTCONTROLLER_H_