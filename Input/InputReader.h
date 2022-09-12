#ifndef GAME_INPUTREADER_H
#define GAME_INPUTREADER_H


#include <memory>

namespace Engine {

    class IController;
    class ControlScheme;

    class InputReader {
    public:
        explicit InputReader(std::shared_ptr<ControlScheme> controlScheme,
                             std::shared_ptr<IController> controller = nullptr);

        void update();
        void changeControlScheme(std::shared_ptr<ControlScheme> controlScheme);

    private:
        static bool keyPressed(int key);

        std::shared_ptr<IController> controller;
        std::shared_ptr<ControlScheme> controlScheme;
    };

} // Engine


#endif //GAME_INPUTREADER_H