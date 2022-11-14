#ifndef GAME_GAME_FIELD_FIELDHELPER_H_
#define GAME_GAME_FIELD_FIELDHELPER_H_

#include "../../Message/FieldInfoMessage.h"
#include "../../View/CellViewRecognizer.h"
#include "Field.h"

class FieldHelper {
 public:
  static FieldInfoMessage info(const Field& field);
};

#endif
