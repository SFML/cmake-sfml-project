.PHONY: build run all clean

build:
	cmake -S . -B build
	cmake --build build

run:
	./build/bin/main

all: build run

clean:
	rm -rf build