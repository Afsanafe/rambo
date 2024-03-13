#include "journal.hpp"
#include <cassert>

void foo_test();

void driver() {
    foo_test();

    return;
}

void foo_test() {
    // arrange
    int a = 0;
    int b = 1;

    // act
    // a = b;

    // assert
    assert (a == b);
}

int main() {
    driver();

    return 0;
}