#include "gtest/gtest.h"

#include "ComponentMocks.h"

TEST(FilterTest, main) {
    World world;
    Filter filter;
    auto pupa = world.addEntity("pupa");
    auto lupa = world.addEntity("lupa");
    auto aboba = world.addEntity("aboba");
    pupa.addComponent<HealthComponent>();
    pupa.addComponent<TransformComponent>();
    pupa.addComponent<StrengthComponent>();

    lupa.addComponent<HealthComponent>();
    lupa.addComponent<TransformComponent>();

    aboba.addComponent<HealthComponent>();
    aboba.addComponent<StrengthComponent>();

    auto components_1 = filter.with<HealthComponent>(world);
    auto ans_1 = std::vector<Entity>{pupa, lupa, aboba};
    EXPECT_EQ(components_1, ans_1);

    auto components_2 = filter.with<TransformComponent>(world);
    auto ans_2 = std::vector<Entity>{pupa, lupa};
    EXPECT_EQ(components_2, ans_2);
}
