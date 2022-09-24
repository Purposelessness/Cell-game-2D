#include "TestController.h"

#include <iostream>

void TestController::process(const InputMessage& input_message) {
    std::string command;
    switch (input_message.type) {
        case InputType::Undefined:
            command = "Undefined";
            break;
        case InputType::MoveUp:
            command = "MoveUp";
            break;
        case InputType::MoveDown:
            command = "MoveDown";
            break;
        case InputType::MoveRight:
            command = "MoveRight";
            break;
        case InputType::MoveLeft:
            command = "MoveLeft";
            break;
        case InputType::Exit:
            command = "Exit";
            break;
        case InputType::Reset:
            command = "Reset";
            break;
    }
    std::cout << "Command is: " << command + std::to_string(static_cast<int>(input_message.state)) << "\n";
}
