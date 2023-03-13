cmake_minimum_required(VERSION 3.9)
project("smol_tests" LANGUAGES CXX)

# Enable CTest integration
enable_testing()
set(CMAKE_CTEST_ARGUMENTS -V)

function(SMOL_TEST_ADD_EXECUTABLE target sourceList)
  list(APPEND sourceList smol_test.cpp smol_test.h)
  add_executable(${target} ${sourceList})
  set_property(TARGET ${target} PROPERTY CXX_STANDARD 11)
  # Include necesary include paths as needed.
  target_include_directories(${target} PRIVATE "${CMAKE_CURRENT_SOURCE_PATH}")
  # Include necessary libs as needed 
  #target_link_libraries(${target} PRIVATE smol ${OPENGL_LIBRARY})
  # Make it a CTest target
  add_test(NAME ${target}_tests COMMAND ${target})
  #Comment the next line to avoid running this test automatically
  add_custom_command(TARGET ${target} POST_BUILD COMMAND ${CMAKE_CTEST_COMMAND} ${target})
endfunction()


# Add tests
SMOL_TEST_ADD_EXECUTABLE(float_tests sample/float_tests.cpp)
SMOL_TEST_ADD_EXECUTABLE(slow_tests sample/slow_tests.cpp)
SMOL_TEST_ADD_EXECUTABLE(general_tests sample/general_tests.cpp)
