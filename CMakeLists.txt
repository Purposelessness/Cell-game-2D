cmake_minimum_required(VERSION 3.20)
project(Game)

set(CMAKE_CXX_STANDARD 20)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -fsanitize-recover=address -O1 -fno-omit-frame-pointer -g")

set(Headers
        Objects/Map/Cell.h
        Observer/EventMessage.h
        Objects/Entity.h
        Objects/Map/Field.h
        Datatypes/Point.h
        Observer/EventListener.h
        Observer/EventManager.h
        Input/KeyboardInputReader.h
        config.h
        Utility/IConvertibleToString.h
        Utility/Concepts.h
        Events/IEvent.h
        Input/IController.h
        Input/ControlScheme.h
        Input/KeyInfo.h
        Tests/TestInput.h
        Core/ITickable.h
        Components/Component.h
        Components/ComponentBag.h
        Components/Transform.h
        Systems/ObjectController.h
        Utility/Tuple.h
        Core/World.h
        Core/IApplication.h Input/IInputMediator.h Input/InputReader.h)

set(Sources
        main.cpp
        Objects/Map/Cell.cpp
        Objects/Entity.cpp
        Objects/Map/Field.cpp
        Observer/EventListener.cpp
        Observer/EventManager.cpp
        Input/KeyboardInputReader.cpp
        Input/ControlScheme.cpp
        Tests/TestInput.cpp
        Components/Component.cpp
        Components/Transform.cpp
        Systems/ObjectController.cpp
        Components/ComponentBag.cpp
        Core/World.cpp
        Core/Application.cpp Core/Application.h Input/InputMediator.cpp Input/InputMediator.h Utility/EventHandler.h Utility/Template.h)

add_executable(Game ${Sources} ${Headers})
add_subdirectory(Tests/gtests)