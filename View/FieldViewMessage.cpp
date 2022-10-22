#include "FieldViewMessage.h"

FieldViewMessage::operator std::string() const {
    std::string out = "[ Field View Message | ";
    for (const auto& k : changes) {
        out += static_cast<std::string>(k.first) + " - " + cellViewToString(k.second) + "; ";
    }
    out += ']';
    return out;
}
