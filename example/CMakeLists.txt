project(named_container_example)

set(EXE_SOURCES
	example.cpp
)

add_executable(named_container_example ${EXE_SOURCES})

target_link_libraries(named_container_example PRIVATE named_container_library)
set_target_properties(named_container_example PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

