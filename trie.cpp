
#include "trie.h"

TrieNode::TrieNode()
{
}

TrieNode::TrieNode(char c) : _c(c)
{
}

TrieNode::~TrieNode()
{
}

Trie::Trie()
{
    this->_root = unique_ptr<TrieNode>(new TrieNode());
    _num_words = 0;
}

void Trie::insertIntoTrie(string word)
{
    TrieNode *nav = _root.get();
    int word_len = word.size();
    int char_count = 0;

    for (auto &c : word)
    {
        map<char, unique_ptr<TrieNode>>::const_iterator it =
            nav->_children.find(c);

        if (it == nav->_children.end())
        {
            /* No child exists with this character. Create one */
            unique_ptr<TrieNode> _child(new TrieNode(c));

            if (char_count == word_len - 1)
            {
                _child->_is_word = true;
            }

            _child->_parent = nav;
            TrieNode *tmp = _child.get();
            nav->_children.insert(make_pair(c, move(_child)));
            nav->_num_children++;

            nav = tmp;
            _num_words++;
        }
        else
        {
            nav = it->second.get();
        }

        if (char_count == word_len - 1)
        {
            nav->_is_word = true;
        }

        char_count++;
    }
}

bool Trie::deleteFromTrie(string word)
{

    TrieNode *leaf_node = getPrefNode(word);

    if (!leaf_node)
    {
        return false;
    }
    return true;
}

void Trie::_print(string &prefix, const TrieNode &node)
{
    for (const auto &child : node._children)
    {
        prefix.push_back(child.first);

        if (child.second->_is_word)
        {

            cout << prefix << endl;
        }

        _print(prefix, *(child.second));
        prefix.pop_back();
    }
}

void Trie::printAllWords()
{
    string str = "";
    _print(str, *_root);
}

TrieNode *Trie::getPrefNode(const string &prefix)
{
    TrieNode *nav = _root.get();
    int pref_len = prefix.size();
    int char_count = 0;
    bool pref_found = true;

    for (auto &c : prefix)
    {
        map<char, unique_ptr<TrieNode>>::const_iterator it =
            nav->_children.find(c);

        if (it == nav->_children.end())
        {

            if (char_count != pref_len - 1)
            {
                pref_found = false;
            }
            break;
        }
        else
        {
            nav = it->second.get();
        }
        char_count++;
    }

    if (pref_found)
    {
        return nav;
    }
    else
    {
        return nullptr;
    }
}

void Trie::getWordsWithPref(string pref)
{
    TrieNode *start_node = getPrefNode(pref);

    if (!start_node)
    {
        cout << "Could not find the prefix" << endl;
        return;
    }
    else
    {

        _print(pref, *start_node);
    }
}
