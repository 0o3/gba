cmake_minimum_required(VERSION 3.0)
project(gba)

set(CMAKE_CXX_STANDARD 17)
if(APPLE)
  include_directories(/usr/local/include)
  link_directories(/usr/local/lib)
endif()

set(SRC main.cpp)
add_executable(${PROJECT_NAME} ${SRC})
target_link_libraries(
  ${PROJECT_NAME}
  sfml-window
  sfml-system
  sfml-network
  sfml-graphics
  sfml-audio)
