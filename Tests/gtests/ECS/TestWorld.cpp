#include "gtest/gtest.h"

#include "ComponentMocks.h"
#include "../../../ECSLib/Core/World.h"

class WorldTest : public ::testing::Test {
protected:
    void SetUp() override {

    }

    World _world;
};

TEST_F(WorldTest, Test) {
    auto entity_1 = std::make_shared<Entity>("Pupa");
    entity_1->component_bag.addComponent<HealthComponent>();
    entity_1->component_bag.addComponent<TransformComponent>();
    EXPECT_EQ(entity_1->toString(),
              "------------------Entity:Pupa\n2 components:\nTestTransform\n\tpos = 0\nTestHealth\n\tvalue = 100\n------------------");

    auto entity_2 = std::make_shared<Entity>("Lupa");
    entity_2->component_bag.addComponent<HealthComponent>();
    entity_2->component_bag.addComponent<TransformComponent>();
    entity_2->component_bag.addComponent<StrengthComponent>();
    entity_2->component_bag.getComponent<HealthComponent>()->_value = 20;
    EXPECT_EQ(entity_2->toString(),
              "------------------Entity:Lupa\n3 components:\nTestStrength\nTestTransform\n\tpos = 0\nTestHealth\n\tvalue = 20\n------------------");

    _world.addEntity(entity_1);
    _world.addEntity(entity_2);

    auto correct_vector = std::vector<std::shared_ptr<Entity>>{entity_1, entity_2};
    std::sort(correct_vector.begin(), correct_vector.end());
    auto filtered = _world.filter<HealthComponent, TransformComponent>();
    std::sort(filtered.begin(), filtered.end());
    bool are_equal = correct_vector == filtered;
    EXPECT_EQ(are_equal, true);

    correct_vector = std::vector<std::shared_ptr<Entity>>{entity_2};
    std::sort(correct_vector.begin(), correct_vector.end());
    filtered = _world.filter<HealthComponent, TransformComponent, StrengthComponent>();
    std::sort(filtered.begin(), filtered.end());
    are_equal = correct_vector == filtered;
    EXPECT_EQ(are_equal, true);
}
