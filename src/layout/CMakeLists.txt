file(GLOB SRC_FILES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/*.cc")

foreach(source IN LISTS SRC_FILES)
  message(STATUS "FILE: ${source}")
  get_filename_component(target_name ${source} NAME_WE)
  add_executable(${target_name} ${source})
  target_link_libraries(${target_name} PRIVATE abi_comm)
endforeach()
