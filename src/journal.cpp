#include "journal.hpp"
#include <string>


std::string Journal::getEntry(std::string entryName) {
    if (Journal::entries ->empty()) {
        return "JOURNAL IS EMPTY";
    }

    if (Journal::entries ->find(entryName) == Journal::entries ->end()) {
        return "ENTRY NOT IN JOURNAL";
    }
    
    return Journal::entries ->at(entryName);
}

bool Journal::insertEntry(std::string entryName, std::string note) {
    if (note.empty()) {
        return false;
    }

    std::pair<std::string, std::string> entryToInsert(entryName, note);

    Journal::entries ->insert(entryToInsert);
    return true;
}

bool Journal::deleteEntry(std::string entryName) {
    if (Journal::entries ->empty()) {
        return false;
    }

    if (Journal::entries ->find(entryName) == Journal::entries ->end()) {
        return false;
    }

    Journal::entries ->erase(entryName);
    return true;
}

bool Journal::modifyEntry(std::string entryName, std::string modifiedNote) {
    if (Journal::entries ->empty()) {
        return false;
    }

    if (Journal::entries ->find(entryName) == Journal::entries ->end()) {
        return false;
    }

    Journal::entries ->at(entryName) = modifiedNote;
    return true;
}