#ifndef GAME_COMPONENTMOCKS_H
#define GAME_COMPONENTMOCKS_H


#include "../../../Components/Component.h"
#include "../../../Components/ComponentBag.h"

class TransformComponent : public Component {
public:
    TransformComponent() : Component("TestTransform") {}

    std::string toString() override {
        std::string out = std::move(Component::toString());
        out += "\tpos = " + std::to_string(pos) + '\n';
        return out;
    }

    int pos = 0;
};

class HealthComponent : public Component {
public:
    HealthComponent() : Component("TestHealth") {}

    std::string toString() override {
        std::string out = std::move(Component::toString());
        out += "\tvalue = " + std::to_string(value) + '\n';
        return out;
    }

    int value = 100;
};

class StrengthComponent : public Component {
public:
    StrengthComponent() : Component("TestStrength") {}

    int value = 5;
};

class MoveController {
public:
    explicit MoveController(std::shared_ptr<TransformComponent> component) : component(std::move(component)) {}

    void move() {
        if (!component)
            return;

        if (component->isRemoved()) {
            component.reset();
            return;
        }

        if (!component->isEnabled())
            return;

        component->pos += 1;
    }

    [[nodiscard]] bool isNull() const {
        return component == nullptr;
    }

private:
    std::shared_ptr<TransformComponent> component;
};

class HealthManager {
public:
    static void applyDamage(HealthComponent &healthComponent) {
        healthComponent.value -= 10;
    }
};


#endif //GAME_COMPONENTMOCKS_H
