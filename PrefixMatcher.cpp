#include "PrefixMatcher.h"
#include <string>

int PrefixMatcher::selectRouter(std::string networkAddress) {
    TrieNode* node = root;
    int Router = NULL;
    for(char character : networkAddress) {
        int i = character - '0';
        if(node->children[i] == nullptr) {
            Router = node->routerNumber;
            return Router;
        }
        node = node->children[i];
    }
}

void PrefixMatcher::insert(std::string address, int routerNumber) {
    TrieNode* node = root;
    for (char character : address) {
        int i = character - '0';
        if(node->children[i] == nullptr) {
            node->children[i] = new TrieNode();
        }
        node = node->children[i];
    }
    node->routerNumber = routerNumber;
}

PrefixMatcher::PrefixMatcher() {
    root = new TrieNode();
}

struct PrefixMatcher::TrieNode {
    int routerNumber;
    TrieNode* children[2]; // Options for address only binary numbers 0 and 1
    TrieNode() {
        routerNumber = NULL; // No match for router
        for(int i=0; i<2; i++) {
            children[i] = nullptr;
        }
    }
};

int PrefixMatcher::selectRouterTrie(TrieNode* node) {

}