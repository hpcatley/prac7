#ifndef AUTCOMPLETE_H
#define AUTOCOMPLETE_H

#include <iostream>
#include <vector>
#include <string>


class Autocomplete {
// Using Trie logic
public:
    std::vector<std::string> getSuggestions(std::string partialWord);
    void insert(std::string word);
    Autocomplete();
    struct TrieNode;
private:
    TrieNode* root;
    void getSuggestionsTrie(TrieNode* root, std::string partialWord,std::vector<std::string> suggestions, std::string currentWord);
};


#endif 