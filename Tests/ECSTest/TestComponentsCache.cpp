#include "gtest/gtest.h"

#include "../../../ECSLib/Components/ComponentsCache.h"
#include "ComponentMocks.h"

TEST(ComponentsCacheTest, main) {
    auto world = std::make_shared<World>();
    auto entity = world->addEntity("pupa");
    auto entity_2 = world->addEntity("lupa");
    auto entity_3 = world->addEntity("zupa");

    CommonCache::getCache<HealthComponent>().addComponent(entity.getId());
    CommonCache::getCache<HealthComponent>().addComponent(entity_2.getId());
    CommonCache::getCache<HealthComponent>().addComponent(entity_3.getId());

    auto& components = CommonCache::getCache<HealthComponent>();
    for (auto key : components.getKeys()) {
        HealthManager::applyDamage(components.getComponent(key));
    }

    EXPECT_EQ(CommonCache::getCache<HealthComponent>().getComponent(entity.getId()).value, 90);
    EXPECT_EQ(CommonCache::getCache<HealthComponent>().getComponent(entity_2.getId()).value, 90);
}
