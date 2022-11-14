#ifndef GAME_GAME_SAVER_H_
#define GAME_GAME_SAVER_H_

#include <optional>
#include <string>

#include "../Message/FieldInfoMessage.h"
#include "../Message/PlayerInfoMessage.h"

struct GameState {
  FieldInfoMessage field_info;
  PlayerInfoMessage player_info;

  explicit operator std::string() const;

  static std::string encodeFieldInfo(const FieldInfoMessage& field_info);
};

class Saver {
 public:
  explicit Saver(std::string filename = "save.txt");

  void save(const GameState& game_state);
  GameState load();

 private:
  static std::optional<FieldInfoMessage> decodeField(
      const std::vector<std::string>& vec_str);
  static std::optional<PlayerInfoMessage> decodePlayer(const std::string& str);

  std::string _filename;
};

#endif
