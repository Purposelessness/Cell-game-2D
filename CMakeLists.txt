cmake_minimum_required(VERSION 3.20)
project(Game)

set(CMAKE_CXX_STANDARD 20)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -fsanitize-recover=address -O1 -fno-omit-frame-pointer -g")

set(Headers
        Objects/Field/Cell.h
        Observer/EventMessage.h
        ECSLib/Core/Entity.h
        Objects/Field/Field.h
        Datatypes/Point.h
        Observer/EventListener.h
        Observer/EventManager.h
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
        ECSLib/Components/ComponentBag.h
        ECS/Components/Transform.h
        Controllers/ObjectController.h
        Utility/Tuple.h
        ECSLib/Core/World.h
        Engine/Core/IApplication.h Engine/Input/InputReader.h Utility/MethodContainer.h)

set(Sources
        main.cpp
        Objects/Field/Cell.cpp
        ECSLib/Core/Entity.cpp
        Objects/Field/Field.cpp
        Observer/EventListener.cpp
        Observer/EventManager.cpp
        Engine/Input/KeyboardInputReader.cpp
        Engine/Input/ControlScheme.cpp
        ECSLib/Components/Component.cpp
        ECS/Components/Transform.cpp
        Controllers/ObjectController.cpp
        ECSLib/Components/ComponentBag.cpp
        ECSLib/Core/World.cpp
        Engine/Core/MainApplication.cpp Engine/Core/MainApplication.h Engine/Input/InputMediator.cpp Engine/Input/InputMediator.h Utility/EventHandler.h Utility/Template.h Core/Application.cpp Core/Application.h Core/InputSystem.cpp Core/InputSystem.h Controllers/TestController.cpp Controllers/TestController.h ECSLib/Components/TypeIdentifier.cpp ECSLib/Components/TypeIdentifier.h ECSLib/Components/Concept.h)

add_executable(Game ${Sources} ${Headers})
add_subdirectory(Tests/gtests)