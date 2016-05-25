#ifndef __SKIP_LIST
#define __SKIP_LIST

class SkipListNode{
    friend class SkipList;
    private:
        int _value;
        SkipListNode* _pRight;
        SkipListNode* _pLeft;
        SkipListNode* _pDown;
        SkipListNode* _pUp;


    public:
        SkipListNode();
        SkipListNode(int val=0);
        ~SkipListNode();
        SkipListNode* getLeft();
        SkipListNode* getRight();
        SkipListNode* getDown();
        SkipListNode* getUp();
};

class SkipList {
    private:
        float _prob;
        int _height;
        SkipListNode* _pHead;
        SkipListNode* _pLastNode;
        SkipListNode* getFloorEntry(int value);
        void insertInUpperRow(SkipListNode* anchor, int value);
        void insertRowAboveHead(SkipListNode* newHead, int value);
        void bumpUpHead();
        int  computeHeight(SkipListNode* pStart);
        int  getNumInsertions();
        SkipListNode* findNewHead();
        void deleteNonHead(int value);
        void updateHeadValue(int value);

    public:
        SkipList(float prob=0.5);
        ~SkipList();
        void insert(int value);
        void remove(int value);
        SkipListNode* search(int value);
        void print();
};

#endif//__SKIP_LIST
