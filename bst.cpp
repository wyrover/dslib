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
    BstNode* to_remove = NULL;
 

    to_remove = closestNode(data);

    if(!to_remove) {
        cout <<" Value not present to delete " << endl;
        return;
    } else {
        /* Two children */
        if (to_remove->_pLeft && to_remove->_pRight) {

        } else if ((to_remove->_pLeft != NULL) &&
                    (to_remove->_pLeft != NULL)) {

        } else if () {
            
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

