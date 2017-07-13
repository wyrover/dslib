#ifndef __TRIE_H
#define __TRIE_H

#include "dslib.h"

class TrieNode {

    friend class Trie;
    private:
    char _c;
    map<char, unique_ptr<TrieNode> > _children;

    public:
    TrieNode(char c);
    ~TrieNode();

};

class Trie {

    private:
        int _num_words;
        TrieNode* _root;

    public:
        void insertIntoTrie(string word);
        bool deleteFromTrie(string word);
        void printAllwords();
        void listAllwords(string pref, vector<string>& completions);
        Trie();
        ~Trie();
};










#endif
