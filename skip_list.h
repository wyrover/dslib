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
        SkipListNode* GetFloorEntry(int value);
        void insertInUpperRow(SkipListNode* anchor, int value);
        void insertRowAboveHead(SkipListNode* newHead, int value);
        void bumpUpHead();
        int computeHeight(SkipListNode* pStart);

    public:
        SkipList(float prob=0.5);
        ~SkipList();
        void insertNode(int value);
        void deleteNode(int value);
        SkipListNode* searchNode(int value);
        void printAllRows();
        int  getNumInsertions();
};

#endif//__SKIP_LIST
