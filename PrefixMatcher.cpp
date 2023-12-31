#include "PrefixMatcher.h"
#include <string>

struct PrefixMatcher::TrieNode {
    int routerNumber;
    TrieNode* children[2]; // Options for address only binary numbers 0 and 1
    TrieNode() {
        routerNumber = -1; // No match for router
        for(int i=0; i<2; i++) {
            children[i] = nullptr;
        }
    }
};

int PrefixMatcher::selectRouter(std::string networkAddress) {
    TrieNode* node = root;
    int Router = -1;
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

int* PrefixMatcher::selectRouterTrie(TrieNode* node) {
    int* Array = new int[2];
    Array[0] = -1;
    Array[1] = 0;
    if(node == nullptr) {
        return Array;
    }

    if(node->children[0] != nullptr) {
        int* leftRouter = selectRouterTrie(node->children[0]);

        if(node->children[1] != nullptr) {
            int* rightRouter = selectRouterTrie(node->children[1]);
            if(leftRouter[1] >= rightRouter[1]) {
                Array[0] = leftRouter[0];
                Array[1] = leftRouter[1] + 1;
                return Array;
            }
            else if (leftRouter[1] < rightRouter[1]) {
                Array[0] = rightRouter[0];
                Array[1] = rightRouter[1]+1;
            }
        }
        else {
            Array[0] = leftRouter[0];
            Array[1] = leftRouter[1] + 1;
        }
    }
    else if(node->children[1] != nullptr) {
        int* rightRouter = selectRouterTrie(node->children[1]);
        Array[0] = rightRouter[0];
        Array[1] = rightRouter[1];
    }
    else {
        Array[0] = node->routerNumber;
        Array[1] = 0;
        return Array;
    }
}