cmake_minimum_required(VERSION 3.14)

project(final_project LANGUAGES CXX)

if(POLICY CMP0169)
  cmake_policy(SET CMP0169 OLD)
endif()

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
  libfiglet_src
  GIT_REPOSITORY https://github.com/anhbipro144/libfiglet.git
  GIT_TAG        1.0.0

)

FetchContent_GetProperties(libfiglet_src)
if(NOT libfiglet_src_POPULATED)
  FetchContent_Populate(libfiglet_src)
endif()


# Make the fetched FTXUI content available to this project
FetchContent_MakeAvailable(ftxui)

# Define the executable target and its source file

add_executable(final_project
  ./src/main.cpp
  ./src/ascii.cpp
  ./src/utils.cpp
  ./src/filter.cpp
)

add_library(libfiglet INTERFACE)
target_include_directories(libfiglet INTERFACE
  "${libfiglet_src_SOURCE_DIR}/dist" )

target_include_directories(final_project PRIVATE
  # "${CMAKE_SOURCE_DIR}/libfiglet/dist"
  "${CMAKE_SOURCE_DIR}/include"
)



# Link the executable against the FTXUI modules: screen, dom, and component
target_link_libraries(final_project PRIVATE
  ftxui::screen
  ftxui::dom
  ftxui::component
  libfiglet
)


