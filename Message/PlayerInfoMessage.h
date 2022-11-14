#ifndef GAME_MESSAGE_PLAYERINFOMESSAGE_H_
#define GAME_MESSAGE_PLAYERINFOMESSAGE_H_

#include "../Datatypes/Point.h"
#include "../Engine/Utility/InfoMessage.h"

struct PlayerInfoMessage : InfoMessage {
  PlayerInfoMessage(int health, int money, Point position, int weapon,
                    int intelligence)
      : health(health), money(money), position(std::move(position)),
        weapon(weapon), intelligence(intelligence) {}

  int health{};
  int money{};
  Point position{};
  int weapon{};
  int intelligence{};

  explicit inline operator std::string() const override {
    constexpr char kDelim = ' ';
    return std::to_string(health) + kDelim + std::to_string(money) + kDelim +
           static_cast<std::string>(position) + kDelim +
           std::to_string(weapon) + kDelim + std::to_string(intelligence);
  }
};

#endif
