#ifndef GAME_GAME_IGAME_H_
#define GAME_GAME_IGAME_H_

class IGame {
 public:
  virtual ~IGame() = default;
  virtual void reset() = 0;
  virtual void stop() = 0;
};

#endif  // GAME_GAME_IGAME_H_
