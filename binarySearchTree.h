#ifndef BINARYSEARCHTREE_H_INCLUDED
#define BINARYSEARCHTREE_H_INCLUDED
#include "queType.h"

template <class itemType>
struct treeNode
{
    itemType info;
    treeNode* left;
    treeNode* right;
};

enum orderType {PRE_ORDER, IN_ORDER, POST_ORDER};

template <class itemType>
class treeType
{
    public:
        treeType();
        ~treeType();
        void makeEmpty();
        bool isEmpty();
        bool isFull();
        int lengthIs();
        void retrieveItem(itemType& item, bool& found);
        void insertItem(itemType item);
        void deleteItem(itemType item);
        void resetTree(orderType order);
        void getNextItem(itemType& item, orderType order, bool& finished);
        void print();
        void preOrderPrint();
        void postOrderPrint();
        int findMin();
        int findMax();
        int numLeaves();
        int rangeLength();
        int numInternalNodes();
    private:
        treeNode<itemType>* root;
        queType<itemType> preQue;
        queType<itemType> inQue;
        queType<itemType> postQue;
};

#endif // BINARYSEARCHTREE_H_INCLUDED
