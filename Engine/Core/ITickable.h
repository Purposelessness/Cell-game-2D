#ifndef GAME_ENGINE_CORE_ITICKABLE_H_
#define GAME_ENGINE_CORE_ITICKABLE_H_

class ITickable {
 public:
  virtual ~ITickable() = default;
  virtual void tick() = 0;
};

#endif  // GAME_ENGINE_CORE_ITICKABLE_H_
