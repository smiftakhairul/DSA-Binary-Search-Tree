#include "queType.h"
#include <iostream>

using namespace std;

template<class itemType>
queType<itemType>::queType()
{
    rear=front=NULL;
    length=0;
}

template<class itemType>
queType<itemType>::~queType()
{
    makeEmpty();
}

template<class itemType>
void queType<itemType>::makeEmpty()
{
    nodeType<itemType>* tempPtr;

    while(front!=NULL)
    {
        tempPtr=front;
        front=front->next;
        delete tempPtr;
    }
    rear=NULL;
}

template<class itemType>
void queType<itemType>::enqueue(itemType newItem)
{
    if(isFull())
        throw fullQueue();
    else
    {
        nodeType<itemType>* newNode;
        newNode=new nodeType<itemType>;
        newNode->info=newItem;
        newNode->next=NULL;

        if(rear==NULL)
            front=newNode;
        else
            rear->next=newNode;
        rear=newNode;

        length++;
    }
}

template<class itemType>
void queType<itemType>::dequeue(itemType& item)
{
    if(isEmpty())
        throw emptyQueue();
    else
    {
        nodeType<itemType>* tempPtr;
        tempPtr=front;
        item=front->info;
        front=front->next;

        if(front==NULL)
            rear=NULL;
        delete tempPtr;

        length--;
    }
}

template<class itemType>
bool queType<itemType>::isEmpty()
{
    return (front==NULL);
}

template<class itemType>
bool queType<itemType>::isFull()
{
    nodeType<itemType>* location;
    try
    {
        location=new nodeType<itemType>;
        delete location;
        return false;
    }
    catch(bad_alloc& exception)
    {
        return true;
    }
}

template<class itemType>
void queType<itemType>::printQueue()
{
    nodeType<itemType>* tempPtr;
    tempPtr=front;

    while(tempPtr!=NULL)
    {
        cout << tempPtr->info << " ";
        tempPtr=tempPtr->next;
    }
    delete tempPtr;
}

template<class itemType>
int queType<itemType>::lengthIs()
{
    return length;
}
