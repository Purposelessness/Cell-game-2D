#include "ComponentsCache.h"

std::unordered_map<int, std::shared_ptr<CommonCache>> CommonCache::caches{};
