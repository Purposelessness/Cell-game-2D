#include "ComponentsCache.h"

std::unordered_map<int, std::shared_ptr<CommonCache>> CommonCache::caches{};

bool CommonCache::isEmpty() const {
    return type_id == -1;
}
