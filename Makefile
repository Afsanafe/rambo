CXX=g++
CFLAGS= -Wall -std=c++11

SRCDIR=src
TESTDIR=tests

all: proj unittest

proj: $(SRCDIR)/main.cpp
	$(CXX) $(CFLAGS) -o proj $(SRCDIR)/main.cpp

unittest: $(TESTDIR)/test_main.cpp
	$(CXX) $(CFLAGS) -o unittest $(TESTDIR)/test_main.cpp 

clean:
	rm -f proj unittest