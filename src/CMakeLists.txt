add_library(abi_comm INTERFACE)
target_include_directories(abi_comm INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(layout)
