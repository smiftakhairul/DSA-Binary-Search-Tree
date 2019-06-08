#ifndef QUETYPE_H_INCLUDED
#define QUETYPE_H_INCLUDED

template<class itemType>
struct nodeType
{
    itemType info;
    nodeType* next;
};

class fullQueue {};

class emptyQueue {};

template<class itemType>
class queType
{
    public:
        queType();
        ~queType();
        void makeEmpty();
        void enqueue(itemType);
        void dequeue(itemType&);
        bool isEmpty();
        bool isFull();
        void printQueue();
        int lengthIs();
    private:
        nodeType<itemType>* front;
        nodeType<itemType>* rear;
        int length;
};

#endif // QUETYPE_H_INCLUDED
