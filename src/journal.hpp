#ifndef JOURNAL_HPP
#define JOURNAL_HPP

#include <unordered_map>
#include <string>

class Journal {
private:
    std::unordered_map<std::string, std::string>* entries;


public:
    std::string& getEntry(std::string& entryName);
    bool insertEntry(std::string& note);
    bool deleteEntry(std::string& entryName);
    bool modifyEntry(std::string& entryName);
};

#endif