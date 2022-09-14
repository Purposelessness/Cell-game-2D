#include "TestInput.h"

#include <unistd.h>
#include <iostream>

#include "../config.h"
#include "../Input/ControlScheme.h"
#include "../Input/InputReader.h"

namespace Test {

    bool Application::isRunning = false;

    void Application::quit() {
        isRunning = false;
    }

    int Application::exec() {
        isRunning = true;
        auto controller = std::make_shared<Controller>();
        auto controlScheme = std::make_shared<ControlScheme>();
        auto inputReader = std::make_shared<InputReader>(controlScheme, controller);

        addKeys(*controlScheme);

        while (isRunning) {
            inputReader->tick();
            usleep(UPDATE_TIME_MCSEC);
        }

        return 0;
    }

    void Application::addKeys(ControlScheme &controlScheme) {
        controlScheme.addKey('P', KeyType::Exit);
        controlScheme.addKey('W', KeyType::MoveUp);
        controlScheme.addKey('S', KeyType::MoveDown);
        controlScheme.addKey('D', KeyType::MoveRight);
        controlScheme.addKey('A', KeyType::MoveLeft);
    }

    void Controller::process(const KeyInfo &inputMessage) {
        switch (inputMessage.type) {
            case KeyType::MoveUp:
                std::cout << "Moving up " + std::to_string(static_cast<int>(inputMessage.state)) << std::endl;
                break;
            case KeyType::MoveDown:
                std::cout << "Moving Down " + std::to_string(static_cast<int>(inputMessage.state)) << std::endl;
                break;
            case KeyType::MoveRight:
                std::cout << "Moving Right " + std::to_string(static_cast<int>(inputMessage.state)) << std::endl;
                break;
            case KeyType::MoveLeft:
                std::cout << "Moving left " + std::to_string(static_cast<int>(inputMessage.state)) << std::endl;
                break;
            case KeyType::Exit:
                std::cout << "Exiting" << std::endl;
                Application::quit();
                break;
            case KeyType::Reset:
                std::cout << "Reset" << std::endl;
                break;
            case KeyType::Undefined:
                break;
        }
    }

    void testField() {
        Application::exec();
    }

} // Test