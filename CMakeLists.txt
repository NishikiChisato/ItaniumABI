cmake_minimum_required(VERSION 3.14)

project(ItaniumAPI LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

option(ENABLE_SANITIZER "Enable Sanitizer" ON)
if (ENABLE_SANITIZER)
  add_compile_options(
  -fsanitize=address
  -fsanitize=undefined
  -fno-omit-frame-pointer
  -g
  )
  add_link_options(
  -fsanitize=address
  -fsanitize=undefined
  )
endif()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

add_subdirectory(src)
