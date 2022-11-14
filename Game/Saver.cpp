#include "Saver.h"

#include <exception>
#include <fstream>
#include <regex>
#include <sstream>

#include "../Utility/Log/Log.h"
#include "../View/Console/FieldViewAdapter.h"

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

void Saver::save(const GameState& game_state) const{
  std::ofstream save_file(_filename);
  if (!save_file.good()) {
    throw std::runtime_error("Cannot open save file!");
  }

  std::string line = static_cast<std::string>(game_state);
  save_file << line;

  save_file.close();
}

GameState Saver::load() const {
  std::ifstream load_file(_filename);
  if (!load_file.good()) {
    throw std::runtime_error("Cannot open load file!");
  }

  std::string line;
  std::vector<std::string> field_lines;
  while ((std::getline(load_file, line), line.find('-') == std::string::npos)) {
    line.erase(std::remove(line.begin(), line.end(), '\n'), line.end());
    field_lines.emplace_back(line);
  }
  auto field_info_opt = decodeField(field_lines);
  if (!field_info_opt.has_value()) {
    throw std::runtime_error("Error while decoding field data");
  }
  FieldInfoMessage field_info = field_info_opt.value();
  std::getline(load_file, line);
  auto player_info_opt = decodePlayer(line);
  if (!player_info_opt.has_value()) {
    throw std::runtime_error("Error while decoding player data");
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

  LOG_INFO_F("Player read from file: " + std::to_string(health) + " " +
             std::to_string(money) + " " + std::string(position));

  auto opt = std::optional<PlayerInfoMessage>{
      PlayerInfoMessage{health, money, position, weapon, intelligence}};

  return opt;
}
