#include "EventListener.h"

int EventListener::length = 0;
std::vector<int> EventListener::unusedIndices = std::vector<int>{};

EventListener::EventListener() {
    assignIndex();
}

int EventListener::getIndex() const {
    return index;
}

EventListener::~EventListener() {
    unusedIndices.push_back(index);
}

void EventListener::assignIndex() {
    if (unusedIndices.empty()) {
        index = length;
        length++;
    } else {
        index = unusedIndices.back();
        unusedIndices.pop_back();
    }
}
