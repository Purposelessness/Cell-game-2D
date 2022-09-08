cmake_minimum_required(VERSION 3.23)
project(Game)

set(CMAKE_CXX_STANDARD 20)

add_executable(Game main.cpp Objects/Map/Cell.cpp Objects/Map/Cell.h Observer/Events/IEventMessage.h Objects/Object.cpp Objects/Object.h Objects/Map/Field.cpp Objects/Map/Field.h Core/Delegate.h Core/FunctionContainer.h Core/Arguments.h Objects/Player.cpp Objects/Player.h Datatypes/Point.cpp Datatypes/Point.h Observer/EventListener.cpp Observer/EventListener.h Observer/EventManager.cpp Observer/EventManager.h)
