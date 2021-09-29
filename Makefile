BUILD_FOLDER=$(shell pwd)/build
TARGET_NAME=test_nokia

format:
	find . -regex '.*\.\(cpp\|hpp\|cc\|cxx\|c\)' -exec clang-format -style=file -i {} \;

conf:
	cd ${BUILD_FOLDER};cmake ..

build:
	cd ${BUILD_FOLDER};make -j8

clean:
	cd ${BUILD_FOLDER};rm -rf *

run:
	cd ${BUILD_FOLDER};./${TARGET_NAME}

test:
	cd ${BUILD_FOLDER};ctest

vtest:
	cd ${BUILD_FOLDER};ctest --verbose

all: conf build run test

.PHONY: conf build test clean
