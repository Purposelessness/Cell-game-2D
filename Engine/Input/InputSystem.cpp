#include "InputSystem.h"

#include "IController.h"
#include "InputMessage.h"
#include "InputReader.h"

void InputSystem::notify(const InputMessage& input_message) {
  for (auto& controller : _controllers) {
    controller->process(input_message);
  }
}

void InputSystem::tick() {
  for (auto& reader : _readers) {
    reader->process();
  }
}

void InputSystem::addReader(const std::shared_ptr<InputReader>& input_reader) {
  _readers.insert(input_reader);
  input_reader->event_handler.add(this, &InputSystem::notify);
}

void InputSystem::removeReader(
    const std::shared_ptr<InputReader>& input_reader) {
  _readers.erase(input_reader);
  input_reader->event_handler.remove(this, &InputSystem::notify);
}

void InputSystem::addController(
    const std::shared_ptr<IController>& controller) {
  _controllers.insert(controller);
}

void InputSystem::removeController(
    const std::shared_ptr<IController>& controller) {
  _controllers.erase(controller);
}

InputSystem::~InputSystem() {
  for (auto& reader : _readers) {
    reader->event_handler.remove(this, &InputSystem::notify);
  }
}
