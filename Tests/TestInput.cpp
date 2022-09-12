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
        auto controlScheme = std::make_shared<Engine::ControlScheme>();
        auto inputReader = std::make_shared<Engine::InputReader>(controlScheme, controller);

        addKeys(*controlScheme);

        while (isRunning) {
            inputReader->update();
            usleep(UPDATE_TIME_MCSEC);
        }

        return 0;
    }

    void Application::addKeys(Engine::ControlScheme &controlScheme) {
        controlScheme.addKey('P', Engine::InputType::Exit);
        controlScheme.addKey('W', Engine::InputType::MoveUp);
        controlScheme.addKey('S', Engine::InputType::MoveDown);
        controlScheme.addKey('D', Engine::InputType::MoveRight);
        controlScheme.addKey('A', Engine::InputType::MoveLeft);
    }

    void Controller::process(const Engine::InputMessage &inputMessage) {
        switch (inputMessage.keyType) {
            case Engine::InputType::MoveUp:
                std::cout << "Moving up " + std::to_string(static_cast<int>(inputMessage.state)) << std::endl;
                break;
            case Engine::InputType::MoveDown:
                std::cout << "Moving Down " + std::to_string(static_cast<int>(inputMessage.state)) << std::endl;
                break;
            case Engine::InputType::MoveRight:
                std::cout << "Moving Right " + std::to_string(static_cast<int>(inputMessage.state)) << std::endl;
                break;
            case Engine::InputType::MoveLeft:
                std::cout << "Moving left " + std::to_string(static_cast<int>(inputMessage.state)) << std::endl;
                break;
            case Engine::InputType::Exit:
                std::cout << "Exiting" << std::endl;
                Application::quit();
                break;
            case Engine::InputType::Reset:
                std::cout << "Reset" << std::endl;
                break;
            case Engine::InputType::Undefined:
                break;
        }
    }

    void test() {
        Application::exec();
    }

} // Test