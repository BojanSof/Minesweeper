cmake_minimum_required (VERSION 3.18)

list(APPEND CMAKE_MODULE_PATH
  "${CMAKE_CURRENT_LIST_DIR}/cmake"
)

project (
  Minesweeper
	VERSION 0.1 
  DESCRIPTION "Minesweeper game made using SFML"
	LANGUAGES C CXX
)

find_package(SFML 2.5 COMPONENTS graphics window system)

add_executable(minesweeper)
target_compile_features(minesweeper PRIVATE cxx_std_11)

target_include_directories(minesweeper PRIVATE
  include
)

target_sources(minesweeper
  PRIVATE
    "include/Cell.h"
    "include/Grid.h"
    "include/Random.h"
    "include/Game.h"
    "src/Cell.cpp"
    "src/Grid.cpp"
    "src/Random.cpp"
    "src/Game.cpp"
    "src/main.cpp"
)

target_link_libraries(minesweeper
  PRIVATE
    sfml-graphics
)

add_custom_target(copy_assets
  COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_LIST_DIR}/images ${CMAKE_CURRENT_BINARY_DIR}/images
  COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_LIST_DIR}/fonts ${CMAKE_CURRENT_BINARY_DIR}/fonts
)
add_dependencies(minesweeper copy_assets)