#ifndef GAME_TESTS_GTESTS_ECS_COMPONENTMOCKS_H_
#define GAME_TESTS_GTESTS_ECS_COMPONENTMOCKS_H_

#include "../../../ECSLib/Components/Component.h"
#include "../../../ECSLib/Components/ComponentBag.h"

class TransformComponent : public Component {
public:
    TransformComponent() : Component("TestTransform") {}

    std::string toString() override {
        std::string out = std::move(Component::toString());
        out += "\tpos = " + std::to_string(_pos) + '\n';
        return out;
    }

    int _pos = 0;
};

class HealthComponent : public Component {
public:
    HealthComponent() : Component("TestHealth") {}

    std::string toString() override {
        std::string out = std::move(Component::toString());
        out += "\tvalue = " + std::to_string(_value) + '\n';
        return out;
    }

    int _value = 100;
};

class StrengthComponent : public Component {
public:
    StrengthComponent() : Component("TestStrength") {}

    int _value = 5;
};

class MoveController {
public:
    explicit MoveController(std::shared_ptr<TransformComponent> component) : _component(std::move(component)) {}

    void move() {
        if (!_component)
            return;

        if (_component->isRemoved()) {
            _component.reset();
            return;
        }

        if (!_component->isEnabled())
            return;

        _component->_pos += 1;
    }

    [[nodiscard]] bool isNull() const {
        return _component == nullptr;
    }

private:
    std::shared_ptr<TransformComponent> _component;
};

class HealthManager {
public:
    static void applyDamage(HealthComponent& health_component) {
        health_component._value -= 10;
    }
};

#endif //GAME_TESTS_GTESTS_ECS_COMPONENTMOCKS_H_
