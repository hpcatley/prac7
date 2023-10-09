#include "Autocomplete.h"
#include <string> 
#include <vector>
#include <iostream>

// Define struct for the TrieNode
struct Autocomplete::TrieNode {
    TrieNode* children[26]; // Vector defining all possible nodes (characters)
    bool isEndOfTrie; // boolean to determine if the end of the trie has been reached (node has no child)
    // Constructor for TrieNode struct
    TrieNode() {
        for (int i=0; i < 26; i++) {
            children[i] = nullptr;
        }
        isEndOfTrie = false;
    }
};

// Constructor for Autocomplete class
Autocomplete::Autocomplete() {
    root = new TrieNode();
}


// Function to add a word to the known words (traverse tree, adding
// letters as nodes as needed)
void Autocomplete::insert(std::string word) {
    TrieNode* node = root;
    for (char c : word) {
        int i = c - 'a';
        if (node->children[i] == nullptr) {
            node->children[i] = new TrieNode();

        }
        node = node->children[i];
    }
    node->isEndOfTrie = true;
}

// Function to provide suggestions based on what has been typed so far
std::vector<std::string> Autocomplete::getSuggestions(std::string partialWord) {
    TrieNode* node = root;
    std::vector<std::string> knownWords;
    std::string currentSuggestion = "";

    for (char character : partialWord) {
        int i = character - 'a';
        if(node->children[i] == nullptr) {
            return knownWords; 
        }
        node = node->children[i];
        currentSuggestion = currentSuggestion + character;
    }

    getSuggestionsTrie(node, partialWord, knownWords, currentSuggestion);
    return knownWords;
}

// Secondary suggestion function to facilitate the use of 
// a trie
void Autocomplete::getSuggestionsTrie(TrieNode* node, std::string partialWord, std::vector<std::string> knownWords, std::string currentSuggestion) {
    if(node == nullptr) {
        return;
    }
    if (node->isEndOfTrie) {
        knownWords.push_back(currentSuggestion);
    }
    for( char character = 'a'; character <= 'z'; character++) {
        int i = character - 'a';
        if(node->children[i] != nullptr) {
            getSuggestionsTrie(node->children[i], partialWord, knownWords, currentSuggestion + character);
        }
    }
}