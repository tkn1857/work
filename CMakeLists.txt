cmake_minimum_required(VERSION 3.16)

project(work)

set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_CXX_STANDARD 14)
# Adding source files without main.c with absolute paths for using variable ${SOURCE_FILES} in test/CMakeLists.txt.
# This is needed for testing all files exluding main.c. 
# test/CMakeLists.txt builds his own binary executable file using provided absolute paths to source files from ${SOURCE_FILES} variable.
# Test binary has his own main file and if we add another main file to test binary this will cause multiple definition error, there will be two functions named main in one binary.
# C/C++ allows only one main function in binary executable.

set(GTEST_DOWNLOAD ${CMAKE_BINARY_DIR}/gtest_download)
set(GTEST_SRC ${CMAKE_BINARY_DIR}/gtest_src)
set(GTEST_BUILD ${CMAKE_BINARY_DIR}/gtest_build)

set(SOURCE_FILES
${PROJECT_SOURCE_DIR}/file.c
)

# Adding to project google test files
configure_file(cmake/gtest/gtest.cmake ${GTEST_DOWNLOAD}/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" . WORKING_DIRECTORY ${GTEST_DOWNLOAD})
execute_process(COMMAND ${CMAKE_COMMAND} --build . WORKING_DIRECTORY ${GTEST_DOWNLOAD} )

add_subdirectory(${GTEST_SRC} ${GTEST_BUILD})

enable_testing()
# Adding folder for test
add_subdirectory(test)
        


add_executable(${PROJECT_NAME} 
${PROJECT_SOURCE_DIR}/main.c
${SOURCE_FILES}
)