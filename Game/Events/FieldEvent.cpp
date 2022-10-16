#include "FieldEvent.h"

#include <utility>

FieldEvent::FieldEvent(std::shared_ptr<FieldGenerator>  field_generator) : field_generator(std::move(field_generator)) {}

void FieldEvent::setFieldGenerator(std::shared_ptr<FieldGenerator>new_field_generator) {
    field_generator = std::move(new_field_generator);
}
