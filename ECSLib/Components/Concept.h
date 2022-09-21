#ifndef GAME_ECSLIB_COMPONENTS_CONCEPT_H_
#define GAME_ECSLIB_COMPONENTS_CONCEPT_H_

#include <type_traits>

class Component;

template<typename T>
concept TComponent = std::is_base_of_v<Component, T>;

#endif //GAME_ECSLIB_COMPONENTS_CONCEPT_H_
