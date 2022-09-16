#include "gtest/gtest.h"

#include "ComponentMocks.h"

#include "../../../Core/World.h"
#include "../../../Objects/Entity.h"

class TestWorld : public ::testing::Test {
protected:
    void SetUp() override {

    }

    World world;
};

TEST_F(TestWorld, Test) {
    auto entity1 = std::make_shared<Entity>("Pupa");
    entity1->componentBag.addComponent<HealthComponent>();
    entity1->componentBag.addComponent<TransformComponent>();
    EXPECT_EQ(entity1->toString(),
              "------------------Entity:Pupa\n2 components:\nTestTransform\n\tpos = 0\nTestHealth\n\tvalue = 100\n------------------");

    auto entity2 = std::make_shared<Entity>("Lupa");
    entity2->componentBag.addComponent<HealthComponent>();
    entity2->componentBag.addComponent<TransformComponent>();
    entity2->componentBag.addComponent<StrengthComponent>();
    entity2->componentBag.getComponent<HealthComponent>()->value = 20;
    EXPECT_EQ(entity2->toString(),
              "------------------Entity:Lupa\n3 components:\nTestStrength\nTestTransform\n\tpos = 0\nTestHealth\n\tvalue = 20\n------------------");

    world.addEntity(entity1);
    world.addEntity(entity2);

    auto correctVector = std::vector<std::shared_ptr<Entity>>{entity1, entity2};
    std::sort(correctVector.begin(), correctVector.end());
    auto filtered = world.filter<HealthComponent, TransformComponent>();
    std::sort(filtered.begin(), filtered.end());
    bool areEqual = correctVector == filtered;
    EXPECT_EQ(areEqual, true);

    correctVector = std::vector<std::shared_ptr<Entity>>{entity2};
    std::sort(correctVector.begin(), correctVector.end());
    filtered = world.filter<HealthComponent, TransformComponent, StrengthComponent>();
    std::sort(filtered.begin(), filtered.end());
    areEqual = correctVector == filtered;
    EXPECT_EQ(areEqual, true);
}
