cmake_minimum_required(VERSION 3.23)
project(Game)

set(CMAKE_CXX_STANDARD 20)

add_executable(Game main.cpp Objects/Map/Cell.cpp Objects/Map/Cell.h Observer/IEventMessage.h Objects/Object.cpp Objects/Object.h Objects/Map/Field.cpp Objects/Map/Field.h Objects/Player.cpp Objects/Player.h Datatypes/Point.cpp Datatypes/Point.h Observer/EventListener.cpp Observer/EventListener.h Observer/EventHandler.cpp Observer/EventHandler.h Tests/TestObserver.cpp Tests/TestObserver.h Input/InputReader.cpp Input/InputReader.h config.h Input/InputReaderEvent.cpp Input/InputReaderEvent.h Utility/IConvertibleToString.h Utility/Concepts.h)
