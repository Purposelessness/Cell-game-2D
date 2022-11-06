#include "InvertControlMarker.h"

InvertControlMarker::InvertControlMarker() : Component(this) {}

InvertControlMarker::operator std::string() const {
  return "[ InvertControlMarker ]";
}
