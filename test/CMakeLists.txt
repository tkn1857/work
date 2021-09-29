file(GLOB TESTS "${PROJECT_SOURCE_DIR}/test/*.cpp")
list(REMOVE_ITEM TESTS "${PROJECT_SOURCE_DIR}/test/main.cpp")

foreach(FILE ${TESTS})
  set(name)
  get_filename_component(name ${FILE} NAME_WE)
  add_executable("${name}_tests"
    ${SOURCE_FILES}
    ${FILE}
    )
  target_link_libraries("${name}_tests" gtest_main)
  add_test(NAME ${name} COMMAND "${name}_tests")
endforeach()