#ifndef GAME_ECSLIB_COMPONENTS_COMPONENT_H_
#define GAME_ECSLIB_COMPONENTS_COMPONENT_H_

#include <string>
#include <type_traits>

#include "../../Utility/IConvertibleToString.h"
#include "../../Utility/Object.h"
#include "ComponentConcept.h"

class Component : public Object {
 public:
  [[nodiscard]] int getEntityId() const;
  void linkEntity(int entity_id);

  explicit operator std::string() const override;

 protected:
  template <TComponent T>
  explicit Component(T* tc) : Object(tc) {}

 private:
  int _entity_id = -1;
};

#endif  // GAME_ECSLIB_COMPONENTS_COMPONENT_H_
