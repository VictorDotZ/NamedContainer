project(test_named_container)

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -lgtest -lpthread" )

set(TEST_SOURCES
	NamedContainerTest.cpp
)

find_package(GTest REQUIRED)

add_executable(${PROJECT_NAME} ${TEST_SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC ${GOOGLETEST_PATH})

target_link_libraries(${PROJECT_NAME} PRIVATE named_container_library PUBLIC GTest::gtest GTest::gtest_main)
set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

