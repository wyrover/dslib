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
        BstNode* ancestor = findAncestor(data);
        BstNode* newNode = new BstNode(data);
        if (data > ancestor->_data) {
            ancestor->_pRight = newNode;
        } else {
            ancestor->_pLeft = newNode;
        }
    }
}

BstNode* Bst::_findInorderPred(BstNode* temp) {

   return NULL;
 }

void Bst::remove(int data)
{
    BstNode* to_remove = NULL;
    BstNode* ancestor = NULL;

    to_remove = search(data);
    if (!to_remove) {
        cout <<"Value not present" <<endl;
        return;
    }

    ancestor = findAncestor(data);

    /* Two children */
    if (to_remove->_pLeft && to_remove->_pRight) {

    } else if ((to_remove->_pLeft != NULL) &&
            (to_remove->_pRight == NULL)) { /* One left child */

    } else if ((to_remove->_pRight != NULL ) &&
            (to_remove->_pLeft == NULL)) { /* One right child */

    } else { /* Leaf node - no children*/
        if (ancestor->_pRight->_data == to_remove->_data) {
            ancestor->_pRight = NULL;
            delete to_remove;
        } else {
            ancestor->_pRight = NULL;
            delete to_remove;
        }
    }


}

BstNode* Bst::search(int data)
{
    BstNode* anchor = _pRoot;

     if(!_pRoot) {
        return NULL;
    }
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


BstNode* Bst::findAncestor(int data)
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

bool Bst::_isBst(BstNode* temp, int min, int max)
{
    /*
     *  if root is NULL, its a BST
     *  Or if we managed to traverse till the leaf,
     *  all the precedent nodes fulfilled the BST property.
     */

    if (!temp) {
        return true;
    }

    if ((temp->_data < min) || (temp->_data > max)) {
        return false;
    }

    return (_isBst(temp->_pLeft, min, temp->_data) && _isBst(temp->_pRight, temp->_data, max));
}

bool Bst::isBst()
{

    BstNode* anchor = _pRoot;
    bool res = _isBst(anchor, INT_MIN, INT_MAX);

    return res;
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
    queue<BstNode*> level_queue;

    level_queue.push(_pRoot);

    while(!level_queue.empty()) {
        BstNode* temp = level_queue.front();
        cout << "\t" << temp->_data;
        if(temp->_pLeft) {
            level_queue.push(temp->_pLeft);
        }

        if(temp->_pRight) {
            level_queue.push(temp->_pRight);
        }
        level_queue.pop();
    }
}

