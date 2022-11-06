#include "FieldLogger.h"

#include "../Game/Field/Field.h"
#include "../Utility/Log/Log.h"

FieldLogger& FieldLogger::operator<<(const Field& field) {
  LOG_INFO_F("Field | size: " + static_cast<std::string>(field.getSize()));
  return *this;
}
