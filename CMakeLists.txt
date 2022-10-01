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
        Engine/Input/KeyboardInputReader/KeyboardInputReader.h
        config.h
        Utility/IConvertibleToString.h
        Utility/Concepts.h
        Events/IEvent.h
        Engine/Input/IController.h
        Engine/Input/KeyboardInputReader/ControlScheme.h
        Engine/Input/InputMessage.h
        Engine/Core/ITickable.h
        ECSLib/Components/Component.h
        ECS/Components/Transform.h
        ECS/Systems/ObjectControllerSystem.h
        Utility/Tuple.h
        ECSLib/Core/World.h
        Engine/Core/IApplication.h
        Engine/Input/InputReader.h
        Utility/MethodContainer.h
        Engine/Core/Application.h
        Engine/Input/InputSystem.h
        Utility/EventHandler.h
        Utility/Template.h
        Core/MainApplication.h
        Controllers/TestController.h
        Utility/TypeIdentifier.h
        ECSLib/Components/ComponentConcept.h
        ECS/Systems/MovementSystem.h
        ECSLib/Components/ComponentsCache.h
        ECSLib/Core/Filter.h
        ECSLib/Systems/System.h
        ECSLib/Systems/TickableSystem.h
        ECS/EntityProviders/PlayerProvider.h
        ECS/Markers/ControllableMarker.h
        ECS/Components/Health.h
        ECS/Components/Weapon.h
        ECS/Components/Intelligence.h
        ECS/Components/Velocity.h
        Datatypes/Vector.h
        Engine/View/ViewSystem.h
        Engine/View/ViewRenderer.h
        Engine/View/ViewMessage.h
        Utility/Identified.h
        Utility/Object.h
        )

set(Sources
        main.cpp
        Objects/Field/Cell.cpp
        ECSLib/Core/Entity.cpp
        Objects/Field/Field.cpp
        Utility/Observer/EventListener.cpp
        Utility/Observer/EventManager.cpp
        Engine/Input/KeyboardInputReader/KeyboardInputReader.cpp
        Engine/Input/KeyboardInputReader/ControlScheme.cpp
        ECSLib/Components/Component.cpp
        ECS/Components/Transform.cpp
        ECS/Systems/ObjectControllerSystem.cpp
        ECSLib/Core/World.cpp
        Engine/Core/Application.cpp
        Engine/Input/InputSystem.cpp
        Core/MainApplication.cpp
        Controllers/TestController.cpp
        Datatypes/Point.cpp
        ECS/Systems/MovementSystem.cpp
        ECSLib/Components/ComponentsCache.cpp
        ECSLib/Systems/System.cpp
        ECS/EntityProviders/PlayerProvider.cpp
        ECS/Markers/ControllableMarker.cpp
        ECS/Components/Health.cpp
        ECS/Components/Weapon.cpp
        ECS/Components/Intelligence.cpp
        ECS/Components/Velocity.cpp
        Datatypes/Vector.cpp
        Engine/View/ViewSystem.cpp
        Utility/TypeIdentifier.cpp
        Utility/Identified.cpp
        Utility/Object.cpp
        Core/View/ConsoleView/ConsoleViewRenderer.cpp Core/View/ConsoleView/ConsoleViewRenderer.h Core/View/ConsoleView/ConsoleFieldViewAdapter.cpp Core/View/ConsoleView/ConsoleFieldViewAdapter.h Engine/View/ViewMessage.h Core/View/FieldViewMessage.h Core/View/ConsoleView/ConsoleHelper.h Core/View/ConsoleView/ConsoleFieldViewTab.cpp Core/View/ConsoleView/ConsoleFieldViewTab.h Core/View/ConsoleView/ConsoleLogViewTab.cpp Core/View/ConsoleView/ConsoleLogViewTab.h Utility/IDisposable.h Core/ViewSystemDeployer.cpp Core/ViewSystemDeployer.h Core/View/ConsoleView/ConsoleHelper.cpp Core/InputSystemDeployer.cpp Core/InputSystemDeployer.h Core/View/IMainApplication.h)

add_executable(Game ${Sources} ${Headers})
#add_subdirectory(Tests)