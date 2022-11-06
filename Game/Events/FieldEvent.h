#ifndef GAME_GAME_EVENTS_FIELDEVENT_H_
#define GAME_GAME_EVENTS_FIELDEVENT_H_

#include <memory>

#include "../Field/FieldChanger.h"
#include "Event.h"

class FieldEvent : public Event {
 public:
  explicit FieldEvent(std::shared_ptr<FieldChanger> field_changer = nullptr);

  void setFieldChanger(std::shared_ptr<FieldChanger> field_changer);

 protected:
  std::shared_ptr<FieldChanger> field_changer;
};

#endif  // GAME_GAME_EVENTS_FIELDEVENT_H_
