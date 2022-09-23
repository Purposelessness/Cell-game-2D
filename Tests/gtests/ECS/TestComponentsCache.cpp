#include "gtest/gtest.h"

#include "../../../../ECSLib/Components/ComponentsCache.h"
#include "ComponentMocks.h"
#include "../../../../ECSLib/Core/World.h"

TEST(ComponentsCacheTest, main) {
    auto world = std::make_shared<World>();
    auto entity = world->addEntity("pupa");
    auto entity_2 = world->addEntity("lupa");
    auto entity_3 = world->addEntity("zupa");

    CommonCache::getCache<HealthComponent>().addComponent(entity);
    CommonCache::getCache<HealthComponent>().addComponent(entity_2);
    CommonCache::getCache<HealthComponent>().addComponent(entity_3);

    auto& components = CommonCache::getCache<HealthComponent>();
    for (auto key : components.keys) {
        HealthManager::applyDamage(components.getComponent(key));
    }

    EXPECT_EQ(CommonCache::getCache<HealthComponent>().getComponent(entity).value, 90);
    EXPECT_EQ(CommonCache::getCache<HealthComponent>().getComponent(entity_2).value, 90);
}
