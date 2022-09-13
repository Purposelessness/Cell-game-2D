#ifndef GAME_TESTINPUT_H
#define GAME_TESTINPUT_H


#include <memory>

#include "../Input/IController.h"
#include "../Input/KeyInfo.h"

namespace Engine {
    class ControlScheme;
}

namespace Test {

    class Application {
    public:
        static int exec();

        static void quit();

    private:
        static void addKeys(Engine::ControlScheme &controlScheme);

        static bool isRunning;
    };

    class Controller : public Engine::IController {
    public:
        void process(const Engine::KeyInfo &inputMessage) override;
    };

    void testField();

} // Test


#endif //GAME_TESTINPUT_H