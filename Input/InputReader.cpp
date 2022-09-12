#include "InputReader.h"

#ifdef _WIN32
#include <windows.h>
#elif __linux__
#include <conio.h>
#endif

#include "ControlScheme.h"
#include "IController.h"
#include "InputMessage.h"

namespace Engine {

    InputReader::InputReader(std::shared_ptr<ControlScheme> controlScheme,
                             std::shared_ptr<IController> controller)
                : controlScheme(std::move(controlScheme)), controller(std::move(controller)) {}

    void InputReader::update() {
        if (controller == nullptr)
            return;
#ifdef _WIN32
        for (auto &k : controlScheme->keys()) {
            bool pressed = keyPressed(k.first);
            if (pressed && (k.second.state == InputState::Released)) {
                k.second.state = InputState::Pressed;
            } else if (!pressed && k.second.state == InputState::Pressed) {
                k.second.state = InputState::Released;
            } else {
                continue;
            }
            controller->process(InputMessage{.keyType = k.second.keyType, .state = k.second.state});
        }
#elif __linux__
        // some code
#endif
    }

    void InputReader::changeControlScheme(std::shared_ptr<ControlScheme> controlScheme) {
        this->controlScheme = std::move(controlScheme);
    }

    constexpr int KEY_PRESSED = 0x8000;
    bool InputReader::keyPressed(int key) {
        return GetAsyncKeyState(key) & KEY_PRESSED;
    }

} // Engine