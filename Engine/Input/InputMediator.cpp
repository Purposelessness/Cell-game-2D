#include "InputMediator.h"

#include "InputReader.h"
#include "IController.h"
#include "InputMessage.h"

void InputMediator::notify(const InputMessage& input_message) {
    for (auto &kController : _controllers) {
        kController->process(input_message);
    }
}

void InputMediator::tick() {
    for (auto& kReader : _readers) {
        kReader->process();
    }
}

void InputMediator::addReader(const std::shared_ptr<InputReader>& input_reader) {
    _readers.insert(input_reader);
    input_reader->event_handler.add(this, &InputMediator::notify);
}

void InputMediator::removeReader(const std::shared_ptr<InputReader>& input_reader) {
    _readers.erase(input_reader);
    input_reader->event_handler.remove(this, &InputMediator::notify);
}

void InputMediator::addController(const std::shared_ptr<IController>& controller) {
    _controllers.insert(controller);
}

void InputMediator::removeController(const std::shared_ptr<IController>& controller) {
    _controllers.erase(controller);
}

InputMediator::~InputMediator() {
    for (auto& kReader : _readers) {
        kReader->event_handler.remove(this, &InputMediator::notify);
    }
}
