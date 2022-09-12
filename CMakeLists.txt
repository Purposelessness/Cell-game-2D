cmake_minimum_required(VERSION 3.20)
project(Game)

set(CMAKE_CXX_STANDARD 20)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -fsanitize-recover=address -O1 -fno-omit-frame-pointer -g")

add_executable(Game main.cpp Objects/Map/Cell.cpp Objects/Map/Cell.h Observer/EventMessage.h Objects/Object.cpp Objects/Object.h Objects/Map/Field.cpp Objects/Map/Field.h Objects/Player.cpp Objects/Player.h Datatypes/Point.cpp Datatypes/Point.h Observer/EventListener.cpp Observer/EventListener.h Observer/EventHandler.cpp Observer/EventHandler.h Input/InputReader.cpp Input/InputReader.h config.h Utility/IConvertibleToString.h Utility/Concepts.h Events/IEvent.h Input/IController.h Input/ControlScheme.cpp Input/ControlScheme.h Input/InputMessage.h Tests/TestInput.cpp Tests/TestInput.h)
