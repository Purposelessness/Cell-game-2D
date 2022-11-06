#include "FieldEvent.h"

#include <utility>

FieldEvent::FieldEvent(std::shared_ptr<FieldChanger> field_changer)
    : field_changer(std::move(field_changer)) {}

void FieldEvent::setFieldChanger(
    std::shared_ptr<FieldChanger> new_field_changer) {
  field_changer = std::move(new_field_changer);
}
