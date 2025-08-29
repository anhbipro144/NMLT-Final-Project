cmake_minimum_required(VERSION 3.14)

project(FTXUI_Example LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(FetchContent)

FetchContent_Declare(
  ftxui
  GIT_REPOSITORY https://github.com/ArthurSonzogni/FTXUI.git
  GIT_TAG        v6.1.9
)

FetchContent_Declare(
  magic_enum
  GIT_REPOSITORY https://github.com/Neargye/magic_enum.git
  GIT_TAG        v0.9.7
)


# Make the fetched FTXUI content available to this project
FetchContent_MakeAvailable(ftxui)
FetchContent_MakeAvailable(magic_enum)

# Define the executable target and its source file

add_library(libfiglet INTERFACE)

target_include_directories(libfiglet INTERFACE
  "${CMAKE_SOURCE_DIR}/libfiglet/dist"
  "${CMAKE_SOURCE_DIR}/include"
)

add_executable(final_project
  ./src/main.cpp
  ./src/ascii.cpp
  ./src/utils.cpp
  ./src/filter.cpp
)


# Link the executable against the FTXUI modules: screen, dom, and component
target_link_libraries(final_project PRIVATE
  ftxui::screen
  ftxui::dom
  ftxui::component
  libfiglet
  magic_enum::magic_enum
)


