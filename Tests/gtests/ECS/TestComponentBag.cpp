#include "gtest/gtest.h"

#include "ComponentMocks.h"

class ComponentBagTest : public ::testing::Test {
protected:
    void SetUp() override {
    }

    void TearDown() override {
    }

    ComponentBag _component_bag;
};

TEST_F(ComponentBagTest, Test) {
    _component_bag.addComponent<TransformComponent>();
    _component_bag.addComponent<HealthComponent>();
    auto health = _component_bag.getComponent<HealthComponent>();
    EXPECT_EQ(health->_value, 100);
    HealthManager::applyDamage(*health);
    EXPECT_EQ(health->_value, 90);
    auto transform = _component_bag.getComponent<TransformComponent>();
    EXPECT_EQ(transform->_pos, TransformComponent{}._pos);

    EXPECT_EQ(_component_bag.toString(), "2 components:\nTestHealth\n\tvalue = 90\nTestTransform\n\tpos = 0\n");

    auto moveController = std::make_unique<MoveController>(transform);
    moveController->move();
    EXPECT_EQ(transform->_pos, 1);
    _component_bag.setState<TransformComponent>(false);
    moveController->move();
    EXPECT_EQ(transform->_pos, 1);
    _component_bag.setState<TransformComponent>(true);
    moveController->move();
    EXPECT_EQ(transform->_pos, 2);

    bool has = _component_bag.hasComponents<TransformComponent, StrengthComponent, HealthComponent>();
    EXPECT_EQ(has, false);

    has = _component_bag.hasComponents<TransformComponent, HealthComponent>();
    EXPECT_EQ(has, true);

    EXPECT_EQ(_component_bag.toString(), "2 components:\nTestHealth\n\tvalue = 90\nTestTransform\n\tpos = 2\n");

    _component_bag.removeComponent<TransformComponent>();
    moveController->move();
    EXPECT_EQ(moveController->isNull(), true);

    has = _component_bag.hasComponents<TransformComponent, HealthComponent>();
    EXPECT_EQ(has, false);

    EXPECT_EQ(_component_bag.toString(), "1 components:\nTestHealth\n\tvalue = 90\n") << _component_bag.toString();
}
