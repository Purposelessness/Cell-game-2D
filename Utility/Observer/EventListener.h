#ifndef GAME_OBSERVER_EVENTLISTENER_H_
#define GAME_OBSERVER_EVENTLISTENER_H_

#include <vector>

#include "EventMessage.h"

class EventListener {
 public:
  EventListener();
  virtual ~EventListener();

  [[nodiscard]] int getIndex() const;

  virtual void update(EventMessage*) = 0;

 private:
  void assignIndex();

  static int _length;
  static std::vector<int> _unused_indices;

  int _index = -1;
};

#endif  // GAME_OBSERVER_EVENTLISTENER_H_
