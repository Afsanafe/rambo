#include "journal.hpp"
#include <string>
#include <iostream>

void startApp() {
    Journal* myJournal = new Journal();

    std::string entryCompleted = "no";

    do {
        std::string usersChoice;
        std::cout << "As-Salam-Alaikum, would you like to enter a journal entry Today? (Yes/No): ";
        std::getline(std::cin, usersChoice);
        if (usersChoice == "no" || usersChoice == "NO" || usersChoice == "No") {
            break;
        }
        
        std::string entry; 
        std::cout << "Cool! What do you want to enter?: ";
        std::getline(std::cin, entry);

        std::string entryName; 
        std::cout << "Last thing, what would you like to name the entry?: ";
        std::getline(std::cin, entryName);

        myJournal ->insertEntry(entryName, entry);


        std::cout << "Do you want to add another entry? (Yes/No):";
        std::cin >> entryCompleted;

    } while(
        entryCompleted != "no" &&
        entryCompleted != "NO" &&
        entryCompleted != "n" &&
        entryCompleted != "N"
    );

    myJournal ->printAllEntries();

    delete myJournal;

    return;
}

int main() {
    startApp();

    return 0;
}