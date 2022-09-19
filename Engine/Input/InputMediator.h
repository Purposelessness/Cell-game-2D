#ifndef GAME_ENGINE_INPUT_INPUTMEDIATOR_H_
#define GAME_ENGINE_INPUT_INPUTMEDIATOR_H_

#include <unordered_set>
#include <memory>

class InputReader;
class IController;
struct InputMessage;

class InputMediator {
public:
    void tick();

    void addReader(const std::shared_ptr<InputReader>& input_reader);
    void removeReader(const std::shared_ptr<InputReader>& input_reader);

    void addController(const std::shared_ptr<IController>& controller);
    void removeController(const std::shared_ptr<IController>& controller);

    ~InputMediator();

private:
    void notify(const InputMessage& input_message);

    std::unordered_set<std::shared_ptr<InputReader>> _readers;
    std::unordered_set<std::shared_ptr<IController>> _controllers;
};

#endif //GAME_ENGINE_INPUT_INPUTMEDIATOR_H_