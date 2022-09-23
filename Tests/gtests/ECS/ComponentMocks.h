#ifndef GAME_TESTS_GTESTS_ECS_COMPONENTMOCKS_H_
#define GAME_TESTS_GTESTS_ECS_COMPONENTMOCKS_H_

#include "../../../ECSLib/Components/Component.h"
#include "../../../ECSLib/Components/ComponentBag.h"
#include "../../../ECSLib/Components/ComponentsCache.h"
#include "../../../ECSLib/Core/World.h"
#include "../../../ECSLib/Core/Filter.h"

class TransformComponent : public Component {
public:
    TransformComponent() : Component(this) {}

    std::string toString() override {
        std::string out = "TestTransform\n\tpos = " + std::to_string(pos) + '\n';
        return out;
    }

    int pos = 0;
};

class HealthComponent : public Component {
public:
    HealthComponent() : Component(this) {}

    std::string toString() override {
        std::string out = "TestHealth\n\tvalue = " + std::to_string(value) + '\n';
        return out;
    }

    int value = 100;
};

class StrengthComponent : public Component {
public:
    StrengthComponent() : Component(this) {}

    std::string toString() override {
        std::string out = "TestStrength\n";
        return out;
    }

    int value = 5;
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

        _component->pos += 1;
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
        health_component.value -= 10;
    }
};

#endif //GAME_TESTS_GTESTS_ECS_COMPONENTMOCKS_H_
