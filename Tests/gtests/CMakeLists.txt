project(Gtests)

add_subdirectory(googletest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# Files with tests
set(Test_src
        TestField.cpp
        ECS/TestComponentBag.cpp
        ECS/TestWorld.cpp
        ECS/ComponentMocks.h)

# Files of main project that need to be tested
set(Project_src
        ../../Objects/Map/Field.cpp
        ../../Objects/Map/Cell.cpp
        ../../Components/Component.cpp
        ../../Components/ComponentBag.cpp
        ../../Core/World.cpp
        ../../Objects/Entity.cpp
        )

add_executable(GoogleTest_run ${Test_src} ${Project_src})
target_link_libraries(GoogleTest_run gtest gtest_main)
