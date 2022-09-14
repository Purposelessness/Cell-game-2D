#ifndef GAME_TESTINPUT_H
#define GAME_TESTINPUT_H


#include <memory>

#include "../Input/IController.h"
#include "../Input/KeyInfo.h"

class ControlScheme;

namespace Test {

    class Application {
    public:
        static int exec();

        static void quit();

    private:
        static void addKeys(ControlScheme &controlScheme);

        static bool isRunning;
    };

    class Controller : public IController {
    public:
        void process(const KeyInfo &inputMessage) override;
    };

    void testField();

} // Test


#endif //GAME_TESTINPUT_H