#include "FieldViewMessage.h"

std::string FieldViewMessage::toString() const  {
    std::string out = "Field View Message:\n";
    for (const auto& k : changes) {
        out += "\t" + k.first.toString() + ": " + cellViewToString(k.second) + '\n';
    }
    return out;
}