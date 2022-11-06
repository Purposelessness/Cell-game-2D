#include "EventListener.h"

int EventListener::_length = 0;
std::vector<int> EventListener::_unused_indices = std::vector<int>{};

EventListener::EventListener() { assignIndex(); }

int EventListener::getIndex() const { return _index; }

EventListener::~EventListener() { _unused_indices.push_back(_index); }

void EventListener::assignIndex() {
  if (_unused_indices.empty()) {
    _index = _length;
    _length++;
  } else {
    _index = _unused_indices.back();
    _unused_indices.pop_back();
  }
}
