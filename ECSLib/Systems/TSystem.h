#ifndef GAME_ECSLIB_SYSTEMS_TSYSTEM_H_
#define GAME_ECSLIB_SYSTEMS_TSYSTEM_H_

#include <type_traits>

class System;

template<typename T>
concept TSystem = std::is_base_of_v<System, T>;

#endif //GAME_ECSLIB_SYSTEMS_TSYSTEM_H_
