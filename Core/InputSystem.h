#ifndef GAME_CORE_INPUTSYSTEM_H_
#define GAME_CORE_INPUTSYSTEM_H_

#include <memory>

#include "../Engine/Core/ITickable.h"
#include "../Engine/Input/InputMediator.h"

class InputMediator;
class IController;

class InputSystem : public ITickable {
public:
    InputSystem();

    void tick() override;

    void addController(const std::shared_ptr<IController>& controller);
    void removeController(const std::shared_ptr<IController>& controller);

private:
    std::unique_ptr<InputMediator> _mediator;
};

#endif //GAME_CORE_INPUTSYSTEM_H_