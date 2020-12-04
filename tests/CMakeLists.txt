set(SOURCE_EXE 
    to_binary_test.cpp
)	

add_executable(test ${SOURCE_EXE})

target_include_directories(test PRIVATE ${CMAKE_SOURCE_DIR}/vendor)

target_link_libraries(test PRIVATE saber)
