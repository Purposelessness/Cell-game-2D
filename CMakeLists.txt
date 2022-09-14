cmake_minimum_required(VERSION 3.20)
project(Game)

set(CMAKE_CXX_STANDARD 20)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -fsanitize-recover=address -O1 -fno-omit-frame-pointer -g")

set(Headers
        Objects/Map/Cell.h
        Observer/EventMessage.h
        Objects/Object.h
        Objects/Map/Field.h
        Objects/Player.h
        Datatypes/Point.h
        Observer/EventListener.h
        Observer/EventHandler.h
        Input/InputReader.h
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
        )

set(Sources
        main.cpp
        Objects/Map/Cell.cpp
        Objects/Object.cpp
        Objects/Map/Field.cpp
        Objects/Player.cpp
        Datatypes/Point.cpp
        Observer/EventListener.cpp
        Observer/EventHandler.cpp
        Input/InputReader.cpp
        Input/ControlScheme.cpp
        Tests/TestInput.cpp
        Components/Component.cpp
        Components/ComponentBag.cpp
        Components/Transform.cpp
        )

add_executable(Game ${Sources} ${Headers})
add_subdirectory(gtests)