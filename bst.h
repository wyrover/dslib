
#include "dslib.h"
#include "slist.h"

class BstNode {
    friend class Bst;
    private:
        int _data;
        BstNode* _pLeft;
        BstNode* _pRight;
    public:
        BstNode():_data(0), _pLeft(NULL),_pRight(NULL) {};
        BstNode(int data):_data(data), _pLeft(NULL),_pRight(NULL) {};
        int getData();
};


class Bst {
    bool operator == (const Bst& sec);
    friend ostream& operator << (const ostream& os, const Bst& tree);
    private:
        BstNode* _pRoot;
        int _height();
        void _inOrder(BstNode* _pRoot);
        void _preOrder(BstNode* _pRoot);
        void _postOrder(BstNode* _pRoot);
        void _levelOrder(BstNode* _pRoot);

    public:
        Bst():   _pRoot(NULL) {};
        void     insert(int data);
        void     remove (int data);
        BstNode* search (int data);
        BstNode* closestNode(int value);
        BstNode* LCA(int value_1, int value_2);
        slist_t* toSlist();
        bool     isBst();
        bool     isBalanced();
        bool     isMirror(BstNode* root);
        void     mirror();
        bool     hasPathSum();
        void     inOrder();
        void     postOrder();
        void     preOrder();
        void     levelOrder();
};

