cmake_minimum_required(VERSION 3.20)
project(Game)

set(CMAKE_CXX_STANDARD 20)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -fsanitize-recover=address -O1 -fno-omit-frame-pointer -g")

set(Headers
        Objects/Field/Cell.h
        Utility/Observer/EventMessage.h
        ECSLib/Core/Entity.h
        Objects/Field/Field.h
        Datatypes/Point.h
        Utility/Observer/EventListener.h
        Utility/Observer/EventManager.h
        Engine/Input/KeyboardInputReader.h
        config.h
        Utility/IConvertibleToString.h
        Utility/Concepts.h
        Events/IEvent.h
        Engine/Input/IController.h
        Engine/Input/ControlScheme.h
        Engine/Input/InputMessage.h
        Engine/Core/ITickable.h
        ECSLib/Components/Component.h
        ECS/Components/Transform.h
        ECS/Systems/ObjectControllerSystem.h
        Utility/Tuple.h
        ECSLib/Core/World.h
        Engine/Core/IApplication.h Engine/Input/InputReader.h Utility/MethodContainer.h)

set(Sources
        main.cpp
        Objects/Field/Cell.cpp
        ECSLib/Core/Entity.cpp
        Objects/Field/Field.cpp
        Utility/Observer/EventListener.cpp
        Utility/Observer/EventManager.cpp
        Engine/Input/KeyboardInputReader.cpp
        Engine/Input/ControlScheme.cpp
        ECSLib/Components/Component.cpp
        ECS/Components/Transform.cpp
        ECS/Systems/ObjectControllerSystem.cpp
        ECSLib/Core/World.cpp
        Engine/Core/Application.cpp Engine/Core/Application.h Engine/Input/InputSystem.cpp Engine/Input/InputSystem.h Utility/EventHandler.h Utility/Template.h Core/MainApplication.cpp Core/MainApplication.h Controllers/TestController.cpp Controllers/TestController.h Utility/TypeIdentifier.h ECSLib/Components/ComponentConcept.h Datatypes/Point.cpp ECS/Systems/MovementSystem.cpp ECS/Systems/MovementSystem.h ECSLib/Components/ComponentsCache.cpp ECSLib/Components/ComponentsCache.h ECSLib/Core/Filter.h ECSLib/Systems/System.h ECSLib/Systems/TickableSystem.h ECSLib/Systems/System.cpp ECS/EntityProviders/PlayerProvider.cpp ECS/EntityProviders/PlayerProvider.h ECS/Markers/ControllableMarker.cpp ECS/Markers/ControllableMarker.h ECS/Components/Health.cpp ECS/Components/Health.h ECS/Components/Weapon.cpp ECS/Components/Weapon.h ECS/Components/Intelligence.cpp ECS/Components/Intelligence.h ECS/Components/Velocity.cpp ECS/Components/Velocity.h Datatypes/Vector.cpp Datatypes/Vector.h Engine/View/ViewSystem.cpp Engine/View/ViewSystem.h Engine/View/ViewRenderer.h Engine/View/ViewMessage.h Utility/TypeIdentifier.cpp Utility/Identified.cpp Utility/Identified.h Utility/Object.cpp Utility/Object.h)

add_executable(Game ${Sources} ${Headers})
add_subdirectory(Tests/gtests)