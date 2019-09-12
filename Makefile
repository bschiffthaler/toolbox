CXX=g++
CXXFLAGS=-std=c++11 -O3 -march=native -mtune=native

CARGO=cargo
CARGOFLAGS=--release

default: all

all: t skip

bindir:
	mkdir -p bin

t: bindir
	$(CXX) $(CXXFLAGS) -o bin/t cpp/t.cpp

skip: bindir
	cd rust/skip && \
	$(CARGO) build $(CARGOFLAGS) && \
	cp target/release/skip ../../bin

clean:
	rm -rf bin