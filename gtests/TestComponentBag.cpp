#include "gtest/gtest.h"

#include "../Components/Component.h"
#include "../Components/ComponentBag.h"

class TransformComponent : public Component {
public:
    TransformComponent() : Component("TestTransform") {}

    int pos = 0;
};

class HealthComponent : public Component {
public:
    HealthComponent() : Component("TestHealth") {}

    int value = 100;
};

class MoveController {
public:
    explicit MoveController(std::shared_ptr<TransformComponent> component) : component(std::move(component)) {}
    void move() {
        if (!component || !component->isEnabled())
            return;

        if (component->isRemoved()) {
            component.reset();
            return;
        }

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

class TestComponentBag : public ::testing::Test {
protected:
    void SetUp() override {
    }

    void TearDown() override {
    }

    ComponentBag componentBag;
};

TEST_F(TestComponentBag, Test) {
    componentBag.addComponent<TransformComponent>();
    componentBag.addComponent<HealthComponent>();
    auto health = componentBag.getComponent<HealthComponent>();
    EXPECT_EQ(health->value, 100);
    HealthManager::applyDamage(*health);
    EXPECT_EQ(health->value, 90);
    auto transform = componentBag.getComponent<TransformComponent>();
    EXPECT_EQ(transform->pos, TransformComponent{}.pos);

    auto moveController = std::make_unique<MoveController>(transform);
    moveController->move();
    EXPECT_EQ(transform->pos, 1);
    transform->disable();
    moveController->move();
    EXPECT_EQ(transform->pos, 1);
    transform->enable();
    moveController->move();
    EXPECT_EQ(transform->pos, 2);
    componentBag.removeComponent<TransformComponent>();
    moveController->move();
    EXPECT_EQ(moveController->isNull(), true);
}
