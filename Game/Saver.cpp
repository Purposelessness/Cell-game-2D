#include "Saver.h"

#include <cmath>
#include <filesystem>
#include <fstream>
#include <regex>
#include <sstream>

#include "../Utility/Log/Log.h"
#include "../View/Console/FieldViewAdapter.h"

SaverException::SaverException(std::string filename, std::string what) noexcept
    : _filename(std::move(filename)), _what(std::move(what)),
      _out("(" + _filename + ") " + _what) {}

const char* SaverException::what() const noexcept { return _out.data(); }

GameState::operator std::string() const {
  return encodeFieldInfo(field_info) + "-\n" +
         static_cast<std::string>(player_info);
}

std::string GameState::encodeFieldInfo(const FieldInfoMessage& field_info) {
  const int kHeight = field_info.size.y;
  const int kWidth = field_info.size.x;
  std::string line;
  line.reserve(kHeight * kWidth + kHeight);
  for (int j = 0; j < kHeight; ++j) {
    for (int i = 0; i < kWidth; ++i) {
      line += console::FieldViewAdapter::encode(
          field_info.changes[j * kWidth + i].second);
    }
    line += '\n';
  }

  return line;
}

Saver::Saver(std::string filename) : _filename(std::move(filename)) {}

void Saver::save(const GameState& game_state) const {
  std::ofstream save_file(_filename);
  if (!save_file.good()) {
    throw SaverException(_filename, "Cannot open save file");
  }

  auto sys_now = std::chrono::system_clock::now();
  auto file_now = std::chrono::file_clock::from_sys(sys_now);
  auto seconds = std::chrono::duration_cast<std::chrono::seconds>(
                     sys_now.time_since_epoch())
                     .count();
  seconds = getSecret(seconds);
  save_file << std::to_string(seconds) << '\n';

  std::string line = static_cast<std::string>(game_state);
  save_file << line;

  save_file.close();
  std::filesystem::last_write_time(_filename, file_now);
}

GameState Saver::load() const {
  std::ifstream load_file(_filename);
  if (!load_file.good()) {
    throw SaverException(_filename, "Cannot open load file!");
  }

  std::string line;
  char* ptr = nullptr;
  std::getline(load_file, line);
  int64_t secret = strtoll(line.data(), &ptr, 10);
  if (secret == 0 || !checkSecret(secret)) {
    throw SaverException(_filename, "File edited!");
  }

  std::vector<std::string> field_lines;
  while ((std::getline(load_file, line), line.find('-') == std::string::npos)) {
    line.erase(std::remove(line.begin(), line.end(), '\n'), line.end());
    field_lines.emplace_back(line);
  }
  auto field_info_opt = decodeField(field_lines);
  if (!field_info_opt.has_value()) {
    throw SaverException(_filename, "Error while decoding field data");
  }
  FieldInfoMessage field_info = field_info_opt.value();
  std::getline(load_file, line);
  auto player_info_opt = decodePlayer(line);
  if (!player_info_opt.has_value()) {
    throw SaverException(_filename, "Error while decoding player data");
  }
  PlayerInfoMessage player_info = player_info_opt.value();

  load_file.close();

  auto state = GameState{field_info, player_info};
  return state;
}

std::optional<FieldInfoMessage> Saver::decodeField(
    const std::vector<std::string>& vec_str) {
  if (vec_str.empty()) {
    return std::nullopt;
  }
  const int kWidth = static_cast<int>(vec_str[0].size());
  const int kHeight = static_cast<int>(vec_str.size());
  std::vector<std::pair<Point, CellView>> cells;

  cells.reserve(kWidth * kHeight);
  for (int j = 0; j < kHeight; ++j) {
    const auto& str = vec_str[j];
    if (kWidth != static_cast<int>(str.size())) {
      return std::nullopt;
    }
    for (int i = 0; i < kWidth; ++i) {
      auto cell_view = console::FieldViewAdapter::decode(str[i]);
      if (cell_view == CellView::Undefined) {
        return std::nullopt;
      }
      cells.emplace_back(Point{i, j}, cell_view);
    }
  }

  auto opt = std::optional<FieldInfoMessage>(
      FieldInfoMessage{cells, Size{kWidth, kHeight}});
  return opt;
}

std::optional<PlayerInfoMessage> Saver::decodePlayer(const std::string& str) {
  const std::regex kRegular(
      R"((-?\d+) (-?\d+) \((-?\d+), (-?\d+)\) (-?\d+) (-?\d))");
  const std::vector<std::smatch> kMatches{
      std::sregex_iterator{std::cbegin(str), std::cend(str), kRegular},
      std::sregex_iterator{}};
  if (kMatches.empty()) {
    return std::nullopt;
  }
  const auto& match = kMatches[0];
  int health = std::stoi(match.str(1));
  int money = std::stoi(match.str(2));
  Point position = Point{std::stoi(match.str(3)), std::stoi(match.str(4))};
  int weapon = std::stoi(match.str(5));
  int intelligence = std::stoi(match.str(6));

  auto opt = std::optional<PlayerInfoMessage>{
      PlayerInfoMessage{health, money, position, weapon, intelligence}};

  return opt;
}

bool Saver::checkSecret(int64_t secret) const {
  auto modified_time = std::filesystem::last_write_time(_filename);
  auto sys_time = std::chrono::file_clock::to_sys(modified_time);
  auto seconds = std::chrono::duration_cast<std::chrono::seconds>(
                     sys_time.time_since_epoch())
                     .count();
  seconds = getSecret(seconds);

  return secret == seconds;
}

int64_t Saver::getSecret(int64_t seconds_count) {
  static constexpr int kMagicNumber = 69;
  int64_t out = 0;
  int j = 0;
  std::string str = std::to_string(seconds_count);
  for (int64_t i = static_cast<int64_t>(str.size()) - 1; i > -1; --i) {
    int64_t num = str[i] - '0';
    out += num * static_cast<int64_t>(std::pow(kMagicNumber, j++));
  }
  return out;
}
