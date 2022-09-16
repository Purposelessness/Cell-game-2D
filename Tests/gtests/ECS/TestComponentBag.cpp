#include "gtest/gtest.h"

#include "ComponentMocks.h"

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

    EXPECT_EQ(componentBag.toString(), "2 components:\nTestHealth\n\tvalue = 90\nTestTransform\n\tpos = 0\n");

    auto moveController = std::make_unique<MoveController>(transform);
    moveController->move();
    EXPECT_EQ(transform->pos, 1);
    componentBag.setState<TransformComponent>(false);
    moveController->move();
    EXPECT_EQ(transform->pos, 1);
    componentBag.setState<TransformComponent>(true);
    moveController->move();
    EXPECT_EQ(transform->pos, 2);

    bool has = componentBag.hasComponents<TransformComponent, StrengthComponent, HealthComponent>();
    EXPECT_EQ(has, false);

    has = componentBag.hasComponents<TransformComponent, HealthComponent>();
    EXPECT_EQ(has, true);

    EXPECT_EQ(componentBag.toString(), "2 components:\nTestHealth\n\tvalue = 90\nTestTransform\n\tpos = 2\n");

    componentBag.removeComponent<TransformComponent>();
    moveController->move();
    EXPECT_EQ(moveController->isNull(), true);

    has = componentBag.hasComponents<TransformComponent, HealthComponent>();
    EXPECT_EQ(has, false);

    EXPECT_EQ(componentBag.toString(), "1 components:\nTestHealth\n\tvalue = 90\n") << componentBag.toString();
}
