#ifndef GAME_INPUTREADER_H
#define GAME_INPUTREADER_H


#include <memory>

#include "../Core/ITickable.h"

class IController;
class ControlScheme;

class InputReader : public ITickable {
public:
    explicit InputReader(std::shared_ptr<ControlScheme> controlScheme,
                         std::shared_ptr<IController> controller = nullptr);

    void tick() override;
    void changeControlScheme(std::shared_ptr<ControlScheme> controlScheme);

private:
    static bool keyPressed(int key);

    std::shared_ptr<IController> controller;
    std::shared_ptr<ControlScheme> controlScheme;
};


#endif //GAME_INPUTREADER_H