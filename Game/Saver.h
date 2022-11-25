#ifndef GAME_GAME_SAVER_H_
#define GAME_GAME_SAVER_H_

#include <cstddef>
#include <exception>
#include <optional>
#include <string>

#include "../Message/FieldInfoMessage.h"
#include "../Message/PlayerInfoMessage.h"

class SaverException : public std::exception {
 public:
  explicit SaverException(std::string filename, std::string what) noexcept;
  [[nodiscard]] const char* what() const noexcept override;

 private:
  std::string _filename;
  std::string _what;
  std::string _out;
};

struct GameState {
  FieldInfoMessage field_info;
  PlayerInfoMessage player_info;

  explicit operator std::string() const;

  static std::string encodeFieldInfo(const FieldInfoMessage& field_info);
};

class Saver {
 public:
  explicit Saver(std::string filename = "save.txt");

  void save(const GameState& game_state) const;
  [[nodiscard]] GameState load() const;

 private:
  [[nodiscard]] bool checkSecret(int64_t secret) const;
  static int64_t getSecret(int64_t seconds_count);
  static std::optional<FieldInfoMessage> decodeField(
      const std::vector<std::string>& vec_str);
  static std::optional<PlayerInfoMessage> decodePlayer(const std::string& str);

  std::string _filename;
};

#endif
