#include "FieldInfoMessage.h"

FieldInfoMessage::operator std::string() const {
    std::string out = "[ Field info message | ";
    for (const auto& k : changes) {
        out += static_cast<std::string>(k.first) + " - " + cellViewToString(k.second) + "; ";
    }
    out += ']';
    return out;
}
