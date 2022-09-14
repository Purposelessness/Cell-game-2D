#include "gtest/gtest.h"

#include "../../Components/Component.h"
#include "../../Components/ComponentBag.h"

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

    EXPECT_EQ(componentBag.toString(), "2 components:\nTestTransform\n\tpos = 0\nTestHealth\n\tvalue = 90\n");

    auto moveController = std::make_unique<MoveController>(transform);
    moveController->move();
    EXPECT_EQ(transform->pos, 1);
    transform->disable();
    moveController->move();
    EXPECT_EQ(transform->pos, 1);
    transform->enable();
    moveController->move();
    EXPECT_EQ(transform->pos, 2);

    EXPECT_EQ(componentBag.toString(), "2 components:\nTestTransform\n\tpos = 2\nTestHealth\n\tvalue = 90\n");

    componentBag.removeComponent<TransformComponent>();
    moveController->move();
    EXPECT_EQ(moveController->isNull(), true);

    EXPECT_EQ(componentBag.toString(), "1 components:\nTestHealth\n\tvalue = 90\n") << componentBag.toString();
}
