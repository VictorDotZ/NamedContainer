cmake_minimum_required(VERSION 3.20)
set(CMAKE_CXX_STANDARD 20)

project(named_container)

set(LIB_SOURCES
	libsrc/NamedContainer.cpp
)

add_library(named_container_library SHARED ${LIB_SOURCES})

target_include_directories(named_container_library 
	PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
)

add_subdirectory(example/)
add_subdirectory(tests/unit/)
add_subdirectory(tests/integration/)
