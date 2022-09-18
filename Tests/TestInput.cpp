#include "TestInput.h"

#include <unistd.h>
#include <iostream>

#include "../config.h"
#include "../Input/ControlScheme.h"
#include "../Input/KeyboardInputReader.h"

namespace Test {

    bool Application::isRunning = false;

    void Application::quit() {
        isRunning = false;
    }

    int Application::exec() {
        isRunning = true;
        auto controller = std::make_shared<Controller>();
        auto controlScheme = std::make_shared<ControlScheme>();
//        auto inputReader = std::make_shared<KeyboardInputReader>(controlScheme, controller);

        addKeys(*controlScheme);

        while (isRunning) {
//            inputReader->tick();
            usleep(UPDATE_TIME_MCSEC);
        }

        return 0;
    }

    void Application::addKeys(ControlScheme &controlScheme) {
        controlScheme.addKey('P', InputType::Exit);
        controlScheme.addKey('W', InputType::MoveUp);
        controlScheme.addKey('S', InputType::MoveDown);
        controlScheme.addKey('D', InputType::MoveRight);
        controlScheme.addKey('A', InputType::MoveLeft);
    }

    void Controller::process(const InputMessage &inputMessage) {
        switch (inputMessage.type) {
            case InputType::MoveUp:
                std::cout << "Moving up " + std::to_string(static_cast<int>(inputMessage.state)) << std::endl;
                break;
            case InputType::MoveDown:
                std::cout << "Moving Down " + std::to_string(static_cast<int>(inputMessage.state)) << std::endl;
                break;
            case InputType::MoveRight:
                std::cout << "Moving Right " + std::to_string(static_cast<int>(inputMessage.state)) << std::endl;
                break;
            case InputType::MoveLeft:
                std::cout << "Moving left " + std::to_string(static_cast<int>(inputMessage.state)) << std::endl;
                break;
            case InputType::Exit:
                std::cout << "Exiting" << std::endl;
                Application::quit();
                break;
            case InputType::Reset:
                std::cout << "Reset" << std::endl;
                break;
            case InputType::Undefined:
                break;
        }
    }

    void testField() {
        Application::exec();
    }

} // Test