#include "gtest/gtest.h"

#include "ComponentMocks.h"

TEST(WorldTest, TestEntities) {
//     world.addEntity("pupa");
//    auto entity_1 = std::make_shared<Entity>("Pupa");
//    entity_1->component_bag.addComponent<HealthComponent>();
//    entity_1->component_bag.addComponent<TransformComponent>();
//    EXPECT_EQ(entity_1->toString(),
//              "------------------Entity:Pupa\n2 components:\nTestTransform\n\tpos = 0\nTestHealth\n\tvalue = 100\n------------------");
//
//    auto entity_2 = std::make_shared<Entity>("Lupa");
//    entity_2->component_bag.addComponent<HealthComponent>();
//    entity_2->component_bag.addComponent<TransformComponent>();
//    entity_2->component_bag.addComponent<StrengthComponent>();
//    entity_2->component_bag.getComponent<HealthComponent>()->value = 20;
//    EXPECT_EQ(entity_2->toString(),
//              "------------------Entity:Lupa\n3 components:\nTestStrength\nTestTransform\n\tpos = 0\nTestHealth\n\tvalue = 20\n------------------");
//
//    world.addEntity(entity_1);
//    world.addEntity(entity_2);
//
//    auto correct_vector = std::vector<std::shared_ptr<Entity>>{entity_1, entity_2};
//    std::sort(correct_vector.begin(), correct_vector.end());
//    auto filtered = world.filter<HealthComponent, TransformComponent>();
//    std::sort(filtered.begin(), filtered.end());
//    bool are_equal = correct_vector == filtered;
//    EXPECT_EQ(are_equal, true);
//
//    correct_vector = std::vector<std::shared_ptr<Entity>>{entity_2};
//    std::sort(correct_vector.begin(), correct_vector.end());
//    filtered = world.filter<HealthComponent, TransformComponent, StrengthComponent>();
//    std::sort(filtered.begin(), filtered.end());
//    are_equal = correct_vector == filtered;
//    EXPECT_EQ(are_equal, true);
}

TEST(WorldTest, Systems) {
    auto world = std::make_shared<World>();
    auto transform_system = std::make_shared<TransformSystem>();
    auto health_system = std::make_shared<HealthSystem>();

    world->addSystem(transform_system);
    world->addSystem(health_system);

    auto pupa = world->addEntity("pupa");
    auto lupa = world->addEntity("lupa");
    auto aboba = world->addEntity("aboba");
    pupa.addComponent<HealthComponent>();
    pupa.addComponent<TransformComponent>();
    pupa.addComponent<StrengthComponent>();

    lupa.addComponent<HealthComponent>();
    lupa.addComponent<TransformComponent>();

    aboba.addComponent<HealthComponent>();
    aboba.addComponent<StrengthComponent>();

    world->tick();

    auto health_comp = lupa.getComponent<HealthComponent>();
    auto transform_comp = pupa.getComponent<TransformComponent>();
    auto strength_comp = aboba.getComponent<StrengthComponent>();
    EXPECT_EQ(health_comp.value, 50);
    EXPECT_EQ(transform_comp.pos, 1);
    EXPECT_EQ(strength_comp.value, 5);
}
