#include "CellViewRecognizer.h"

#include "../Game/Events/ControlInversionEvent.h"
#include "../Game/Events/MoneyEvent.h"
#include "../Game/Events/GenerateMoneyEvent.h"
#include "../Game/Events/EnemyEvent.h"

std::unordered_map<std::size_t, CellView> CellViewRecognizer::_event_types =
    {{typeid(ControlInversionEvent).hash_code(), CellView::ControlInversion},
     {typeid(MoneyEvent).hash_code(), CellView::Money},
     {typeid(GenerateMoneyEvent).hash_code(), CellView::GenerateMoney},
     {typeid(EnemyEvent).hash_code(), CellView::Enemy}};