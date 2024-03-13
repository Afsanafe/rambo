CXX=g++
CFLAGS= -Wall -std=c++11

SRCDIR=src
TESTDIR=tests

all: proj unittest

proj: $(SRCDIR)/main.cpp $(SRCDIR)/Journal.cpp
	$(CXX) $(CFLAGS) -o proj $(SRCDIR)/main.cpp $(SRCDIR)/Journal.cpp

unittest: $(TESTDIR)/test_journal.cpp $(SRCDIR)/Journal.cpp
	$(CXX) $(CFLAGS) -o unittest -I$(SRCDIR) $(TESTDIR)/test_journal.cpp $(SRCDIR)/Journal.cpp

clean:
	rm -f proj unittest
