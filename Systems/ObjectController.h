#ifndef GAME_OBJECTCONTROLLER_H
#define GAME_OBJECTCONTROLLER_H


#include <memory>
#include <vector>

#include "../Input/IController.h"

class Transform;

class ObjectController : IController {
public:
    void process(const KeyInfo &inputMessage) override;

private:
    std::vector<std::shared_ptr<Transform>> components;
};


#endif //GAME_OBJECTCONTROLLER_H