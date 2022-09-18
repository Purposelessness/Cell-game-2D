#ifndef GAME_SYSTEMS_OBJECTCONTROLLER_H_
#define GAME_SYSTEMS_OBJECTCONTROLLER_H_

#include <memory>
#include <vector>

#include "../Input/IController.h"

class Transform;

class ObjectController : IController {
public:
    void process(const InputMessage& input_message) override;

private:
    std::vector<std::shared_ptr<Transform>> _components;
};

#endif //GAME_SYSTEMS_OBJECTCONTROLLER_H_