#include "binarySearchTree.h"
#include "queType.cpp"
#include <iostream>

using namespace std;

template <class itemType>
treeType<itemType>::treeType()
{
    root=NULL;
}

template <class itemType>
void destroy(treeNode<itemType>*& tree)
{
    if(tree!=NULL)
    {
        destroy(tree->left);
        destroy(tree->right);
        delete tree;
        tree=NULL;
    }
}

template <class itemType>
treeType<itemType>::~treeType()
{
    destroy(root);
}

template <class itemType>
void treeType<itemType>::makeEmpty()
{
    destroy(root);
}

template <class itemType>
bool treeType<itemType>::isEmpty()
{
    return root==NULL;
}

template <class itemType>
bool treeType<itemType>::isFull()
{
    treeNode<itemType>* location;

    try
    {
        location=new treeNode<itemType>;
        delete location;
        return false;
    }
    catch(bad_alloc& exception)
    {
        return true;
    }
}

template <class itemType>
int countNodes(treeNode<itemType>* tree)
{
    if (tree==NULL)
        return 0;
    else
        return countNodes(tree->left) + countNodes(tree->right) + 1;
}

template <class itemType>
int treeType<itemType>::lengthIs()
{
    return countNodes(root);
}

template <class itemType>
void retrieve(treeNode<itemType>* tree, itemType& item, bool& found)
{
    if(tree==NULL)
        found=false;
    else if(item<tree->info)
        retrieve(tree->left, item, found);
    else if (item>tree->info)
        retrieve(tree->right, item, found);
    else
    {
        item=tree->info;
        found=true;
    }
}

template <class itemType>
void treeType<itemType>::retrieveItem(itemType& item, bool& found)
{
    retrieve(root, item, found);
}

template <class itemType>
void Insert(treeNode<itemType>*& tree, itemType item)
{
    if(tree==NULL)
    {
        tree=new treeNode<itemType>;
        tree->right=NULL;
        tree->left=NULL;
        tree->info=item;
    }
    else if(item<tree->info)
        Insert(tree->left, item);
    else
        Insert(tree->right, item);
}

template <class itemType>
void treeType<itemType>::insertItem(itemType item)
{
    Insert(root, item);
}

template <class itemType>
void Delete(treeNode<itemType>*& tree, itemType item)
{
    if(item<tree->info)
        Delete(tree->left, item);
    else if(item>tree->info)
        Delete(tree->right, item);
    else
        deleteNode(tree);
}

template <class itemType>
void deleteNode(treeNode<itemType>*& tree)
{
    itemType data;
    treeNode<itemType>* tempPtr;
    tempPtr=tree;

    if(tree->left==NULL)
    {
        tree=tree->right;
        delete tempPtr;
    }
    else if(tree->right==NULL)
    {
        tree=tree->left;
        delete tempPtr;
    }
    else
    {
        getPredecessor(tree->left, data);
        tree->info=data;
        Delete(tree->left, data);
    }
}

template <class itemType>
void getPredecessor(treeNode<itemType>* tree, itemType& data)
{
    while(tree->right!=NULL)
        tree=tree->right;
    data=tree->info;
}

template <class itemType>
void treeType<itemType>::deleteItem(itemType item)
{
    Delete(root, item);
}

template <class itemType>
void preOrder(treeNode<itemType>* tree, queType<itemType>& que)
{
    if(tree!=NULL)
    {
        que.enqueue(tree->info);
        preOrder(tree->left, que);
        preOrder(tree->right, que);
    }
}

template <class itemType>
void inOrder(treeNode<itemType>* tree, queType<itemType>& que)
{
    if(tree!=NULL)
    {
        inOrder(tree->left, que);
        que.enqueue(tree->info);
        inOrder(tree->right, que);
    }
}

template <class itemType>
void postOrder(treeNode<itemType>* tree, queType<itemType>& que)
{
    if(tree!=NULL)
    {
        postOrder(tree->left, que);
        postOrder(tree->right, que);
        que.enqueue(tree->info);
    }
}

template <class itemType>
void treeType<itemType>::resetTree(orderType order)
{
    switch (order)
    {
        case PRE_ORDER:
            preOrder(root, preQue);
            break;
        case IN_ORDER:
            inOrder(root, inQue);
            break;
        case POST_ORDER:
            postOrder(root, postQue);
            break;
    }
}

template <class itemType>
void treeType<itemType>::getNextItem(itemType& item, orderType order, bool& finished)
{
    finished=false;

    switch(order)
    {
        case PRE_ORDER:
            preQue.dequeue(item);
            if(preQue.isEmpty())
                finished=true;
            break;
        case IN_ORDER:
            inQue.dequeue(item);
            if(inQue.isEmpty())
                finished=true;
            break;
        case POST_ORDER:
            postQue.dequeue(item);
            if(postQue.isEmpty())
                finished=true;
            break;
    }
}

template <class itemType>
void printTree(treeNode<itemType>* tree)
{
    if(tree!=NULL)
    {
        printTree(tree->left);
        cout << tree->info << " ";
        printTree(tree->right);
    }
}

template <class itemType>
void treeType<itemType>::print()
{
    printTree(root);
}

template <class itemType>
void preOrderTree(treeNode<itemType>* tree)
{
    if(tree!=NULL)
    {
        cout << tree->info << " ";
        preOrderTree(tree->left);
        preOrderTree(tree->right);
    }
}

template <class itemType>
void treeType<itemType>::preOrderPrint()
{
    preOrderTree(root);
}

template <class itemType>
void postOrderTree(treeNode<itemType>* tree)
{
    if(tree!=NULL)
    {
        postOrderTree(tree->left);
        postOrderTree(tree->right);
        cout << tree->info << " ";
    }
}

template <class itemType>
void treeType<itemType>::postOrderPrint()
{
    postOrderTree(root);
}

template <class itemType>
int minimumElement(treeNode<itemType>* tree)
{
    if(tree->left==NULL)
        return tree->info;
    return minimumElement(tree->left);
}

template <class itemType>
int treeType<itemType>::findMin()
{
    minimumElement(root);
}

template <class itemType>
int maximumElement(treeNode<itemType>* tree)
{
    if(tree->right==NULL)
        return tree->info;
    return maximumElement(tree->right);
}

template <class itemType>
int treeType<itemType>::findMax()
{
    maximumElement(root);
}

template <class itemType>
int leaves(treeNode<itemType>* tree)
{
    if(tree==NULL)
        return 0;
    else if(tree->left==NULL && tree->right==NULL)
        return 1;
    else
        return leaves(tree->left) + leaves(tree->right);
}

template <class itemType>
int treeType<itemType>::numLeaves()
{
    leaves(root);
}

template <class itemType>
int treeType<itemType>::rangeLength()
{
    return (findMax()-findMin());
}

template <class itemType>
int treeType<itemType>::numInternalNodes()
{
    return (countNodes(root)-numLeaves());
}
