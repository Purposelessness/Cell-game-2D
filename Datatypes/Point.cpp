#include "Point.h"

std::string Point::toString() {
    return "(" + std::to_string(x) + "; " + std::to_string(y) + ")";
}
