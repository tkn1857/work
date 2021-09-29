cmake_minimum_required(VERSION 3.1)

project(googletest_download NONE)


include(ExternalProject)
ExternalProject_Add(googletest
  GIT_REPOSITORY    https://github.com/google/googletest.git
  GIT_TAG           release-1.8.1
  SOURCE_DIR        "${GTEST_SRC}"
  BINARY_DIR        "${GTEST_BUILD}"
  CONFIGURE_COMMAND ""
  BUILD_COMMAND     ""
  INSTALL_COMMAND   ""
  TEST_COMMAND      ""
)