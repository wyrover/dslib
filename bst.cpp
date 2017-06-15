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

BstNode* Bst::_findInorderSucc(BstNode* temp) {


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

    /* Only the root node is present in the BST */
    if ((to_remove == _pRoot) &&
        !_pRoot->_pRight &&  !_pRoot->_pLeft ) {
        delete _pRoot;
        _pRoot = NULL;
    }

    ancestor = findAncestor(data);

    /* Two children */
    if (to_remove->_pLeft && to_remove->_pRight) {

//        BstNode* inorder_succ = _findInorderSucc(to_remove);



    } else if ((to_remove->_pLeft != NULL) &&
            (to_remove->_pRight == NULL)) { /* One left child */


            if (ancestor->_pRight == to_remove) {
                 /*to_remove node is a rchild to the ancestor
                  *Point ancestor's pright to lchild of to_remove
                  */
                ancestor->_pRight = to_remove->_pLeft;
            } else if (ancestor->_pLeft == to_remove) {
                ancestor->_pLeft = to_remove->_pLeft;
            }

            delete to_remove;
    } else if ((to_remove->_pRight != NULL ) &&
            (to_remove->_pLeft == NULL)) { /* One right child */

            if (ancestor->_pRight == to_remove) {

                 /*to_remove node is a rchild to the ancestor
                  *Point ancestor's pright to rchild of to_remove
                  */
                ancestor->_pRight = to_remove->_pRight;
            } else if (ancestor->_pLeft == to_remove) {
                ancestor->_pLeft = to_remove->_pRight;
            }

            delete to_remove;
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

