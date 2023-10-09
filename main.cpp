#include <iostream>
#include <string>
#include <vector>
#include "Autocomplete.h"
#include "PrefixMatcher.h"

int main() {
    Autocomplete a;
    // Add words to known words using insert function
    a.insert("bin");
    a.insert("ball");
    a.insert("ballet");

    // Take partial word in as input, and is it is entered
    // check against the known word to suggest autocomplete
    std::string word;
    bool typing = true;
    while(typing == true) {
        std::cout << "Enter word: ";
        std::cin >> word;

        std::vector<std::string> suggestions = a.getSuggestions(word);

        if(suggestions.empty()) {
            std::cout << "No suggestions match what you've typed";
            typing = false;
        } else {
            std::cout << "Suggested words: " << std::endl;
            for (std::string knownWord : suggestions) {
                std::cout << knownWord << std::endl;
            }
        }
    }
    


    return 0;
}