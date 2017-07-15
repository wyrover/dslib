
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
    this->_root = new TrieNode();
    _num_words = 0;
}

void Trie::insertIntoTrie(string word)
{
    TrieNode *nav = _root;
    int word_len = word.size();
    int char_count = 0;

    for (auto &c : word)
    {
        map<char, TrieNode *>::const_iterator it =
            nav->_children.find(c);

        if (it == nav->_children.end())
        {
            /* No child exists with this character. Create one */
            TrieNode *_child = new TrieNode(c);

            if (char_count == word_len - 1)
            {
                _child->_is_word = true;
            }

            _child->_parent = nav;
            TrieNode *tmp = _child;
            nav->_children.insert(make_pair(c, move(_child)));
            nav->_num_children++;

            nav = tmp;
            _num_words++;
        }
        else
        {
            nav = it->second;
        }

        if (char_count == word_len - 1)
        {
            nav->_is_word = true;
        }

        char_count++;
    }
}

void Trie::_deletehelper(TrieNode *node, char prev_c)
{
    /* If a character node is the last letter in a valid word
      * or if a node is a fork, return
      */
    if ((node->_num_children > 1) || (node->_is_word))
    {
        node->_children.erase(prev_c);
        return;
    }
    else
    {
        /* Delete the node after storing the parent and the current character in "prev_c"
         * We need to propagate the character to the last recursion stack so that
         * the children map entry for this character can be removed 
         *
         *          m
                    a
                 r  t   n
                    c
                    h
                    e
                    r   
        * Ex: To delete "matcher", the recursion will stop at 'h' 
        * since "match" is a word in itself and shouldnt be deleted.
        * The 'h' node would have a child map entry to 'e'
        * But the 'e' node would have been deleted in a previous recursion stack. We should remove
        * this mapping for the 'e' node. This is why we propagate "prev_c".
        */

        TrieNode *tmp = node->_parent;
        char prev_c = node->_c;
        delete node;
        return _deletehelper(tmp, prev_c);
    }
}

bool Trie::deleteFromTrie(string word)
{

    /* Get the last letter character node for this string in the Trie */
    TrieNode *leaf_node = getPrefNode(word);

    /* The word to delete doesnt exist */
    if (!leaf_node)
    {
        return false;
    }

    /* if the last character node has children
     * Just set is_word to false and return
     * The word to delete is a part of a bigger word
     * and should not be deleted in memory
     */
    if (leaf_node->_num_children)
    {
        leaf_node->_is_word = false;
        return true;
    }

    /* Get the parent node to leaf and the last character in the string*/

    TrieNode *parent_to_leaf = leaf_node->_parent;
    char prev_c = leaf_node->_c;

    /* Delete the last character node */
    delete leaf_node;
    /* Recursively delete all node till a word or a fork is encountered
     * A fork is a node that has multiple child nodes
     */
    _deletehelper(parent_to_leaf, prev_c);
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
    TrieNode *nav = _root;
    int pref_len = prefix.size();
    int char_count = 0;
    bool pref_found = true;

    for (auto &c : prefix)
    {
        map<char, TrieNode *>::const_iterator it =
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
            nav = it->second;
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
