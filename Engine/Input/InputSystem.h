#ifndef GAME_ENGINE_INPUT_INPUTSYSTEM_H_
#define GAME_ENGINE_INPUT_INPUTSYSTEM_H_

#include <memory>
#include <unordered_set>

#include "../Core/ITickable.h"

class InputReader;
class IController;
struct InputMessage;

class InputSystem : public ITickable {
 public:
  void tick() override;

  void addReader(const std::shared_ptr<InputReader>& input_reader);
  void removeReader(const std::shared_ptr<InputReader>& input_reader);

  void addController(const std::shared_ptr<IController>& controller);
  void removeController(const std::shared_ptr<IController>& controller);

  ~InputSystem() override;

 private:
  void notify(const InputMessage& input_message);

  std::unordered_set<std::shared_ptr<InputReader>> _readers;
  std::unordered_set<std::shared_ptr<IController>> _controllers;
};

#endif  // GAME_ENGINE_INPUT_INPUTSYSTEM_H_
