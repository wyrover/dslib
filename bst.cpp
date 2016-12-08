#include "bst.h"


int BstNode::getData()
{

    return _data;
}

void Bst::insert(int data)
{
    if(!_pRoot) {
        _pRoot = new BstNode(data);
        return;
    }

    if(search(data)) {
        cout <<"Value already present" <<endl;
        return;
    } else {
        BstNode* anchor = closestNode(data);
        BstNode* newNode = new BstNode(data);
        if (data > anchor->_data) {
            anchor->_pRight = newNode;
        } else {
            anchor->_pLeft = newNode;
        }
    }
}

void Bst::remove(int data)
{
    if(!(search(data))) {
        cout <<" Value not present to delete " << endl;
        return;
    }

}

BstNode* Bst::search(int data)
{
    if(!_pRoot) {
        return NULL;
    }

    BstNode* anchor = _pRoot;
    while (anchor) {
        if (data > anchor->_data) {
            anchor = anchor->_pRight;
        } else if (data < anchor->_data){
            anchor = anchor->_pLeft;
        } else {
            return anchor;
        }
    }
    return NULL;
}

BstNode* Bst::closestNode(int data)
{
    if(!_pRoot) {
        return NULL;
    }

    BstNode* anchor = _pRoot;
    BstNode* prev = anchor;
    while (anchor) {
        if (data > anchor->_data) {
            prev = anchor;
            anchor = anchor->_pRight;
        } else if (data < anchor->_data){
            prev = anchor;
            anchor = anchor->_pLeft;
        } else {
            break;
        }
    }
    return prev;
}

BstNode* Bst::LCA(int value_1, int value_2)
{
    return NULL;
}

slist_t* Bst::toSlist()
{


    return NULL;
}

bool Bst::isBst()
{


    return false;
}

bool Bst::isBalanced()
{


    return false;
}

bool Bst::isMirror(BstNode* root)
{

    return false;
}

void Bst::mirror()
{


}

bool Bst::hasPathSum()
{
    return false;
}

void Bst::inOrder()
{
    _inOrder(_pRoot);

}

void Bst::preOrder()
{
    _preOrder(_pRoot);

}

void Bst::postOrder()
{
    _postOrder(_pRoot);

}

void Bst::levelOrder()
{
    _levelOrder(_pRoot);

}

void Bst::_inOrder(BstNode* _pRoot)
{
    if(!_pRoot) {
        return;
    }

    _inOrder(_pRoot->_pLeft);
    cout<<"\t"<<_pRoot->_data;
    _inOrder(_pRoot->_pRight);

}

void Bst::_preOrder(BstNode* _pRoot)
{
    if(!_pRoot) {
        return;
    }

    cout<<"\t"<<_pRoot->_data;
    _inOrder(_pRoot->_pLeft);
    _inOrder(_pRoot->_pRight);

}

void Bst::_postOrder(BstNode* _pRoot)
{
    if(!_pRoot) {
        return;
    }

    _inOrder(_pRoot->_pLeft);
    _inOrder(_pRoot->_pRight);
    cout<<"\t"<<_pRoot->_data;
}

void Bst::_levelOrder(BstNode* _pRoot)
{

}

