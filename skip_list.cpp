#include "skip_list.h"
#include "dslib.h"


//SkipListNode methods
SkipListNode::SkipListNode(int value):
                _value(value),
                _pRight(NULL),
                _pLeft(NULL),
                _pDown(NULL),
                _pUp(NULL)
{

}
SkipListNode::~SkipListNode()
{

}


SkipListNode* SkipListNode:: getLeft()
{
    return this->_pLeft;
}

SkipListNode* SkipListNode:: getRight()
{
    return this->_pRight;
}


SkipListNode* SkipListNode:: getDown()
{
    return this->_pDown;
}


SkipListNode* SkipListNode:: getUp()
{
    return this->_pUp;
}


//SkipList  methods
SkipList::SkipList(float prob):_prob(prob),
                               _height(0),
                               _pHead(NULL)
{
    srand (time(NULL));
}

int SkipList::getNumInsertions()
{
    int num_extra_ins =0;
    int rand_num = 0;

     /* Initialize see for random number gen */

    if (_prob) {
        while(1) {
            rand_num = rand();
            if((rand_num%(int(1/_prob))) == 0) {
                 num_extra_ins++;
            } else {
                break;
            }

        }
    }
    return num_extra_ins;
}

void SkipList::insertInUpperRow(SkipListNode* anchor, int value)
{
    if(!anchor) {
        return;

    }

    SkipListNode* toInsert = new SkipListNode(value);
    SkipListNode* nextNode = anchor->_pRight;

    anchor->_pRight = toInsert;
    toInsert->_pLeft = anchor;
    toInsert->_pDown = _pLastNode;
    _pLastNode->_pUp = toInsert;

    if(nextNode) {
        toInsert->_pRight = nextNode;
        nextNode->_pLeft = toInsert;
    }
    _pLastNode = toInsert;
}


void SkipList::insertRowAboveHead(SkipListNode* newHead, int value)
{
    if(!newHead) {
        return;

    }

    SkipListNode* toInsert = new SkipListNode(value);
    newHead->_pRight = toInsert;
    toInsert->_pLeft = newHead;
    toInsert->_pDown = _pLastNode;
    _pLastNode->_pUp = toInsert;
    _pLastNode = toInsert;
     newHead->_pDown = _pHead;
     _pHead->_pUp = newHead;
    _pHead = newHead;
    _height++;
}

void SkipList::bumpUpHead()
{
    SkipListNode* newHead = new SkipListNode(_pHead->_value);
    _pHead->_pUp = newHead;
    newHead->_pDown = _pHead;
    _pHead = newHead;
    _height++;
}

void SkipList::insert(int value)
{
    SkipListNode* pCurr = NULL;
    SkipListNode* pTravDown = NULL;

    int num_extra_ins = getNumInsertions();

     if (!_pHead) {
         _pHead= new SkipListNode(value);
        _pLastNode = _pHead;
        _height+= num_extra_ins;

        while (num_extra_ins) {
            pCurr = new SkipListNode(value);
            pCurr->_pUp = _pLastNode;
            _pLastNode->_pDown = pCurr;
            _pLastNode = pCurr;
            num_extra_ins--;
        }
    } else {
        if (value <_pHead->_value) {
            pTravDown = _pHead;
            _pHead= new SkipListNode(value);
            _height++;
            _pLastNode = _pHead;
            while(pTravDown) {
                pCurr = new SkipListNode(value);
                pCurr->_pUp = _pLastNode;
                pCurr->_pRight = pTravDown;
                _pLastNode->_pDown = pCurr;
                _pLastNode = pCurr;
                pTravDown = pTravDown->_pDown;
            }
        } else {

            SkipListNode* anchor = NULL;
            anchor = getFloorEntry(value);

            if (anchor) {
                SkipListNode* pNew = new SkipListNode(value);
                SkipListNode* nextNode = anchor->_pRight;

                pNew->_pLeft = anchor;
                anchor->_pRight = pNew;
                if (nextNode) {
                    pNew->_pRight = nextNode;
                    nextNode->_pLeft = pNew;
                }
                _pLastNode = pNew;

                for (int i =0; i<num_extra_ins; i++) {
                    while(anchor->_pUp == NULL && (anchor->_pLeft)) {
                        anchor = anchor->_pLeft;
                    }

                    if (anchor!=_pHead) {
                        anchor = anchor->_pUp;
                        insertInUpperRow(anchor, value);
                    } else {
                        SkipListNode* newHead = new SkipListNode(_pHead->_value);
                        insertRowAboveHead(newHead, value);
                        anchor = _pHead;
                    }

                }
            }
        }
    }
     if ( (_pHead) && (_pHead->_pRight != NULL)) {
         bumpUpHead();
     }
}

int SkipList::computeHeight(SkipListNode* pStart)
{
    int height = 0;
    while(pStart) {
        pStart = pStart->_pDown;
        height++;
    }
    return height;
}

SkipListNode* SkipList::findNewHead()
{
    if(!_pHead) {
        return NULL;
    }

    SkipListNode* pTemp = getFloorEntry(_pHead->_value);

    if (pTemp->_pRight) {
        pTemp = pTemp->_pRight;
    } else { /* Only element present currently is the head*/

        return NULL;
    }

    while(pTemp->_pUp) {
        pTemp = pTemp->_pUp;

    }

    return pTemp;
}

void SkipList::deleteNonHead(int value)
{
    SkipListNode* pTravDown = search(value);
    SkipListNode* pPrevNode = NULL;
    SkipListNode* pNextNode = NULL;
    SkipListNode* pBackNode = NULL;

    while(pTravDown) {
        pPrevNode = pTravDown;
        pNextNode = pTravDown->_pRight;
        pBackNode = pTravDown->_pLeft;

        if(pNextNode && pBackNode ) {
            pNextNode->_pLeft = NULL;
            pBackNode->_pRight = pNextNode;
            pNextNode->_pLeft = pBackNode;
        } else if (pBackNode && !pNextNode) {
            pBackNode->_pRight = NULL;
        }

        pTravDown=pTravDown->_pDown;
        delete pPrevNode;
    }
}

void SkipList::updateHeadValue(int newValue)
{
    SkipListNode* pStart = _pHead;

    while (pStart) {
        pStart->_value = newValue;
        pStart = pStart->_pDown;
    }
}

void SkipList::remove(int value)
{
    SkipListNode* pTravDown = search(value);
    SkipListNode* pPrevNode = NULL;
    SkipListNode* pNextNode = NULL;

    if (!pTravDown) {
        cout <<" Value  " <<value<<" not present ."<<endl;
        return;
    }

    if (!_pHead) {
        cout << " Empty Skip List " <<endl;
        return;
    }
    /* Deleting the head element */
    if(pTravDown == _pHead) {
        SkipListNode* newHead = findNewHead();
        if (!newHead) {
            /*Only Head column present . Just delete and set HEAD = NULL */
            while(pTravDown) {
                pPrevNode = pTravDown;
                pNextNode = pTravDown->_pRight;
                if(pNextNode ) {
                    pNextNode->_pLeft = NULL;
                }

                pTravDown=pTravDown->_pDown;
                delete pPrevNode;
            }
            _pHead = NULL;
            _height = 0;
        } else {
            /*New HEAD found. Replace HEAD column with the next biggest element
             * and delete the column having the next biggest element after
             * the HEAD ( non HEAD element)
             */
            int nextBiggest = newHead->_value;
            deleteNonHead(nextBiggest);
            updateHeadValue(nextBiggest);
        }

    } else {
        /*Delete a non-head element*/
        deleteNonHead(value);
    }
}

SkipListNode* SkipList::getFloorEntry(int value)
{
    SkipListNode* pTemp = _pHead;

    while(true) {
        while((pTemp->_pRight != NULL)&&
                (pTemp->_pRight->_value <= value)){
                    pTemp = pTemp->_pRight;
                }
                if(pTemp->_pDown) {
                    pTemp = pTemp->_pDown;
                } else {
                    break;
                }
    }
    return pTemp;
}

SkipListNode* SkipList::search(int value)
{
    SkipListNode* pTemp = _pHead;

    while(true) {
        while((pTemp->_pRight != NULL)&&
                (pTemp->_pRight->_value <= value)){
            pTemp = pTemp->_pRight;
        }
        if (pTemp) {
            if (pTemp->_value == value) {
                return pTemp;
            }
            if(pTemp->_pDown) {
                pTemp = pTemp->_pDown;
            } else {
                break;
            }

        }
    }
    return NULL;
}


void SkipList::print()
{
    SkipListNode* pLevel = NULL;
    SkipListNode* pRow = NULL;

    if(!_pHead) {
        cout <<"Empty List" <<endl;
    }
    cout<<"Height : "<<_height<<endl;
    for(pLevel=_pHead; pLevel!=NULL; pLevel=pLevel->_pDown) {
        for(pRow=pLevel; pRow!=NULL; pRow=pRow->_pRight) {
            cout <<pRow->_value <<"\t";
        }
        cout <<endl;
    }

}
