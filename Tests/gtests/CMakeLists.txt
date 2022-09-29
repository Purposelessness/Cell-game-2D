project(Gtests)

add_subdirectory(googletest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# Files with tests
set(Test_src
        TestField.cpp
        ECS/TestWorld.cpp
        ECS/ComponentMocks.h
        TestEventHandler.cpp
        ECS/TestComponentsCache.cpp ECS/TestFilter.cpp)

# Files of main project that need to be tested
set(Project_src
        ../../Utility/TypeIdentifier.cpp
        ../../Utility/Identified.cpp
        ../../Utility/Object.cpp
        ../../Objects/Field/Field.cpp
        ../../Objects/Field/Cell.cpp
        ../../ECSLib/Components/Component.cpp
        ../../ECSLib/Components/ComponentsCache.cpp
        ../../ECSLib/Core/World.cpp
        ../../ECSLib/Core/Entity.cpp
        ../../ECSLib/Systems/System.cpp
        ../../Datatypes/Point.cpp
        ../../Datatypes/Vector.cpp
        )

add_executable(GoogleTest_run ${Test_src} ${Project_src})
target_link_libraries(GoogleTest_run gtest gtest_main)
