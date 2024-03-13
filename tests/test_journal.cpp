#include "journal.hpp"
#include <string>
#include <cassert>

void test_modify_method_returns_false_when_not_found_error();
void test_modify_method_returns_false_when_journal_is_empty();
void test_modify_method_returns_true_when_modifying_valid_entry();
void test_delete_method_returns_false_when_journal_is_empty();
void test_delete_method_returns_false_when_entry_not_in_journal();
void test_delete_method_returns_true_when_entry_succesfully_deleted();
void test_get_method_returns_not_found_error_when_given_invalid_name();
void test_get_method_returns_empty_error_when_journal_is_empty();
void test_get_method_returns_correct_entry_when_given_valid_name();
void test_insert_method_returns_not_found_error_when_journal_is_empty();
void test_insert_method_returns_empty_error_when_journal_is_empty();
void test_insert_method_returns_correct_entry_when_given_valid_name();

void driver() {
    test_modify_method_returns_false_when_not_found_error();
    test_modify_method_returns_false_when_journal_is_empty();
    test_modify_method_returns_true_when_modifying_valid_entry();
    test_delete_method_returns_false_when_journal_is_empty();
    test_delete_method_returns_false_when_entry_not_in_journal();
    test_delete_method_returns_true_when_entry_succesfully_deleted();
    test_get_method_returns_not_found_error_when_given_invalid_name();
    test_get_method_returns_empty_error_when_journal_is_empty();
    test_get_method_returns_correct_entry_when_given_valid_name();
    test_insert_method_returns_not_found_error_when_journal_is_empty();
    test_insert_method_returns_empty_error_when_journal_is_empty();
    test_insert_method_returns_correct_entry_when_given_valid_name();

    return;
}

void test_insert_method_returns_correct_entry_when_given_valid_name() {
    // arrange
    Journal* testJournal = new Journal();
    std::string expectedEntry = "test";
    std::string testName = "test";

    // act
    testJournal ->insertEntry(testName, expectedEntry);

    // assert
    assert (testJournal ->getEntry(testName) == expectedEntry);
}

void test_insert_method_returns_empty_error_when_journal_is_empty() {
    // arrange
    Journal* testJournal = new Journal();
    std::string testName = "test";
    std::string expectedRes = "JOURNAL IS EMPTY";

    // act
    std::string res = testJournal ->getEntry(testName);

    // assert
    assert (res == expectedRes);
};

void test_insert_method_returns_not_found_error_when_journal_is_empty() {
    // arrange
    Journal* testJournal = new Journal();
    std::string testName = "test";
    std::string expectedRes = "ENTRY NOT IN JOURNAL";

    // act
    testJournal ->insertEntry(testName, "test");
    std::string res = testJournal ->getEntry("foo");

    // assert
    assert (res == expectedRes);
}

void test_get_method_returns_correct_entry_when_given_valid_name() {
    // arrange
    Journal* testJournal = new Journal();
    std::string expectedEntry = "test";
    std::string testName = "test";

    // act
    testJournal ->insertEntry(testName, expectedEntry);

    // assert
    assert (testJournal ->getEntry(testName) == expectedEntry);

}

void test_get_method_returns_empty_error_when_journal_is_empty() {
    // arrange
    Journal* testJournal = new Journal();
    std::string testName = "test";
    std::string expectedRes = "JOURNAL IS EMPTY";

    // act
    std::string res = testJournal ->getEntry(testName);

    // assert
    assert (res == expectedRes);
}

void test_get_method_returns_not_found_error_when_given_invalid_name() {
    // arrange
    Journal* testJournal = new Journal();
    std::string testName = "test";
    std::string expectedRes = "ENTRY NOT IN JOURNAL";

    // act
    testJournal ->insertEntry(testName, "test");
    std::string res = testJournal ->getEntry("foo");

    // assert
    assert (res == expectedRes);
}

void test_delete_method_returns_true_when_entry_succesfully_deleted() {
    // arrange
    Journal* testJournal = new Journal();
    std::string expectedEntry = "test";
    std::string testName = "test";

    // act
    testJournal ->insertEntry(testName, expectedEntry);
    bool res = testJournal ->deleteEntry(testName);

    // assert
    assert (res == true);

}

void test_delete_method_returns_false_when_entry_not_in_journal() {
    // arrange
    Journal* testJournal = new Journal();
    std::string expectedEntry = "test";
    std::string testName = "test";

    // act
    testJournal ->insertEntry(testName, expectedEntry);
    bool res = testJournal ->deleteEntry("foo");

    // assert
    assert (res == false);
}

void test_delete_method_returns_false_when_journal_is_empty() {
    // arrange
    Journal* testJournal = new Journal();
    std::string testName = "test";

    // act
    bool res = testJournal ->deleteEntry(testName);

    // assert
    assert (res == false);
}

void test_modify_method_returns_true_when_modifying_valid_entry() {
    // arrange
    Journal* testJournal = new Journal();
    std::string expectedEntry = "test";
    std::string testName = "test";
    std::string modefiedExpectedEntry = "modified test";

    // act
    testJournal ->insertEntry(testName, expectedEntry);
    bool res = testJournal ->modifyEntry(testName, modefiedExpectedEntry);
    
    // assert
    assert (testJournal ->getEntry(testName) == modefiedExpectedEntry);
    assert (res == true);
}

void test_modify_method_returns_false_when_journal_is_empty() {
    // arrange
    Journal* testJournal = new Journal();
    std::string testName = "test";
    std::string modefiedExpectedEntry = "modified test";

    // act
    bool res = testJournal ->modifyEntry(testName, modefiedExpectedEntry);
    
    // assert
    assert (res == false);
}

void test_modify_method_returns_false_when_not_found_error() {
    // arrange
    Journal* testJournal = new Journal();
    std::string expectedEntry = "test";
    std::string testName = "test";
    std::string modefiedExpectedEntry = "modified test";

    // act
    testJournal ->insertEntry(testName, expectedEntry);
    bool res = testJournal ->modifyEntry("foo", modefiedExpectedEntry);
    
    // assert
    assert (res == false);

}

int main() {
    driver();

    return 0;
}