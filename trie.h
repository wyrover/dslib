#ifndef __TRIE_H
#define __TRIE_H

#include "dslib.h"

class TrieNode
{

    friend class Trie;

  private:
    char _c;
    bool _is_word;
    int _num_children;
    TrieNode *_parent;
    map<char, TrieNode* > _children;

  public:
    TrieNode(char c);
    TrieNode();
    ~TrieNode();
};

class Trie
{

  private:
    int _num_words;
    TrieNode* _root;
    void _print(string &prefix, const TrieNode &node);
    TrieNode *getPrefNode(const string &prefix);
    void _deletehelper(TrieNode* leaf_node, char c);

  public:
    void insertIntoTrie(string word);
    bool deleteFromTrie(string word);
    void printAllWords();
    void getWordsWithPref(string pref);
    Trie();
    ~Trie();
};

#endif
