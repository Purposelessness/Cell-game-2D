project(GoogleTests)

add_subdirectory(googletest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# Files with tests
set(Test_src
        TestField.cpp
        ECSTest/TestWorld.cpp
        ECSTest/ComponentMocks.h
        UtilityTest/TestEventHandler.cpp
        ECSTest/TestComponentsCache.cpp
        ECSTest/TestFilter.cpp
        EngineTest/TestViewSystem.cpp
        )

# Files of main project that need to be tested
set(Project_src
        ../Utility/TypeIdentifier.cpp
        ../Utility/Identified.cpp
        ../Utility/Object.cpp
        ../Game/Field/Field.cpp
        ../Game/Field/Cell.cpp
        ../ECSLib/Components/Component.cpp
        ../ECSLib/Components/ComponentsCache.cpp
        ../ECSLib/Core/World.cpp
        ../ECSLib/Core/Entity.cpp
        ../ECSLib/Systems/System.cpp
        ../Datatypes/Point.cpp
        ../Datatypes/Vector.cpp
        ../Engine/View/ViewSystem.cpp
        )

add_executable(GoogleTests_run ${Test_src} ${Project_src})
target_link_libraries(GoogleTests_run gtest gtest_main)
