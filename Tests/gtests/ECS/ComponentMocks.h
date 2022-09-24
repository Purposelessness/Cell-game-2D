#ifndef GAME_TESTS_GTESTS_ECS_COMPONENTMOCKS_H_
#define GAME_TESTS_GTESTS_ECS_COMPONENTMOCKS_H_

#include "../../../ECSLib/Components/Component.h"
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

class HealthManager {
public:
    static void applyDamage(HealthComponent& health_component) {
        health_component.value -= 10;
    }
};

class TransformSystem : public TickableSystem {
public:
    void process() override {
        auto entities = Filter::with<TransformComponent>(*world.lock());
        for (auto& entity : entities) {
            ++entity.getComponent<TransformComponent>().pos;
        }
    }
};

class HealthSystem : public TickableSystem {
public:
    void process() override {
        auto& components = CommonCache::getCache<HealthComponent>();
        for (auto& component : components.keys) {
            components.getComponent(component).value -= 50;
        }
    }
};

#endif //GAME_TESTS_GTESTS_ECS_COMPONENTMOCKS_H_
