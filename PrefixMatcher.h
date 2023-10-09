#ifndef PREFIXMATCHER_H
#define PREFIXMATCHER_H
#include <string>

class PrefixMatcher {
public:
    int selectRouter(std::string networkAddress);
    void insert(std::string address, int routerNumber);
    PrefixMatcher();
    struct TrieNode;
private:
    TrieNode* root;
    int* selectRouterTrie(TrieNode* node);
};

#endif