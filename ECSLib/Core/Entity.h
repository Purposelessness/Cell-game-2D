#ifndef GAME_ECSLIB_CORE_ENTITY_H_
#define GAME_ECSLIB_CORE_ENTITY_H_

#include "../../Utility/IConvertibleToString.h"
#include "../Components/ComponentsCache.h"

class Entity : public IConvertibleToString {
 public:
  Entity();
  explicit Entity(int id, std::string name);
  ~Entity() override = default;

  template <TComponent T>
  T& addComponent() {
    return CommonCache::getCache<T>().addComponent(_id);
  }

  template <TComponent T>
  T& getComponent() {
    return CommonCache::getCache<T>().getComponent(_id);
  }

  template <TComponent T>
  void removeComponent() {
    CommonCache::getCacheFast<T>().removeComponent(_id);
  }

  template <TComponent T>
  bool hasComponent() {
    return CommonCache::getCacheFast<T>().hasComponent(_id);
  }

  [[nodiscard]] int getId() const;
  [[nodiscard]] std::string getName() const;
  explicit operator std::string() const override;

  auto operator<=>(const Entity& other) const = default;

 private:
  int _id;
  std::string _name;
};

#endif  // GAME_ECSLIB_CORE_ENTITY_H_
