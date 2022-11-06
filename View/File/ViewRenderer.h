#ifndef GAME_VIEW_FILE_VIEWRENDERER_H_
#define GAME_VIEW_FILE_VIEWRENDERER_H_

#include <fstream>

#include "../../Message/LogInfoMesssage.h"
#include "../../config.h"

namespace file {

class ViewRenderer {
 public:
  ViewRenderer();
  explicit ViewRenderer(const std::string& filename);
  ~ViewRenderer();

  template <TInfoMessage T>
  inline ViewRenderer& operator<<(const T& message);

#ifdef OBJECT_FILE_LOGGING
  void enableObjectLogging(bool value);
#endif

 private:
  std::ofstream _log_file;
#ifdef OBJECT_FILE_LOGGING
  bool _enable_object_logging = false;
  std::ofstream _object_log_file;
#endif
};

template <TInfoMessage T>
ViewRenderer& ViewRenderer::operator<<(const T& message) {
#ifdef OBJECT_FILE_LOGGING
  if (_enable_object_logging)
    _object_log_file << static_cast<std::string>(message) << '\n';
#endif
  return *this;
}

template <>
inline ViewRenderer& ViewRenderer::operator<< <LogInfoMessage>(
    const LogInfoMessage& message) {
  _log_file << static_cast<std::string>(message) << '\n';
  _log_file.flush();
  return *this;
}

}  // namespace file

#endif  // GAME_VIEW_FILE_VIEWRENDERER_H_
