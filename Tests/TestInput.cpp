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
            inputReader->tick();
            usleep(UPDATE_TIME_MCSEC);
        }

        return 0;
    }

    void Application::addKeys(Engine::ControlScheme &controlScheme) {
        controlScheme.addKey('P', Engine::KeyType::Exit);
        controlScheme.addKey('W', Engine::KeyType::MoveUp);
        controlScheme.addKey('S', Engine::KeyType::MoveDown);
        controlScheme.addKey('D', Engine::KeyType::MoveRight);
        controlScheme.addKey('A', Engine::KeyType::MoveLeft);
    }

    void Controller::process(const Engine::KeyInfo &inputMessage) {
        switch (inputMessage.type) {
            case Engine::KeyType::MoveUp:
                std::cout << "Moving up " + std::to_string(static_cast<int>(inputMessage.state)) << std::endl;
                break;
            case Engine::KeyType::MoveDown:
                std::cout << "Moving Down " + std::to_string(static_cast<int>(inputMessage.state)) << std::endl;
                break;
            case Engine::KeyType::MoveRight:
                std::cout << "Moving Right " + std::to_string(static_cast<int>(inputMessage.state)) << std::endl;
                break;
            case Engine::KeyType::MoveLeft:
                std::cout << "Moving left " + std::to_string(static_cast<int>(inputMessage.state)) << std::endl;
                break;
            case Engine::KeyType::Exit:
                std::cout << "Exiting" << std::endl;
                Application::quit();
                break;
            case Engine::KeyType::Reset:
                std::cout << "Reset" << std::endl;
                break;
            case Engine::KeyType::Undefined:
                break;
        }
    }

    void testField() {
        Application::exec();
    }

} // Test