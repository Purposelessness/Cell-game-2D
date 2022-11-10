#ifndef GAME_GAME_FIELD_GENERATOR_RANDOMIZER_H_
#define GAME_GAME_FIELD_GENERATOR_RANDOMIZER_H_

#include <ctime>
#include <random>

#include "../../../Utility/Log/Log.h"

template <typename T>
concept TRandomizer = requires(T t) {
                        { t() } -> std::same_as<bool>;
                      };

struct True {
 public:
  inline bool operator()() const {
    return true;
  }
};

template <int Chance>
struct SimpleRandomizer {
 public:
  SimpleRandomizer() {
    if (Chance < 0 || Chance > 100) {
      LOG_ERROR_F("Invalid random chance. Must be in range [0, 100], but " +
                  std::to_string(Chance) + " provided.");
    }
    std::srand(std::time(nullptr));
  }

  bool operator()() const {
    return std::rand() % 100 < Chance;
  }
};

#endif
