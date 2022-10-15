#include "CellViewRecognizer.h"

#include "../Game/Events/InvertControlEvent.h"

std::unordered_map<std::size_t, CellView> CellViewRecognizer::_event_types =
    {{typeid(InvertControlEvent).hash_code(), CellView::ControlInversion},
    };