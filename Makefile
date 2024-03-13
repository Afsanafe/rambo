CXX=g++
CFLAGS= -Wall -std=c++11

SRCDIR=src
TESTDIR=tests

all: proj unittest

proj: $(SRCDIR)/main.cpp $(SRCDIR)/journal.cpp
	$(CXX) $(CFLAGS) -o proj $(SRCDIR)/main.cpp $(SRCDIR)/journal.cpp

unittest: $(TESTDIR)/test_journal.cpp $(SRCDIR)/journal.cpp
	$(CXX) $(CFLAGS) -o unittest -I$(SRCDIR) $(TESTDIR)/test_journal.cpp $(SRCDIR)/journal.cpp

clean:
	rm -f proj unittest
