#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP


#include "Node.hpp"
//TODO: Templetize
//TODO:
class SimpleLinkedList {

    public:

        SimpleLinkedList ();
        ~SimpleLinkedList();   
        SimpleLinkedList(double item);
        Node * GetHead();
        void  SetHead(Node *);
        Node * GetTail();
        void SetTail(Node *);
        void InsertAtBeginning( double);
        void InsertAtEnd(double); 
        bool IsEmpty(); // can be refactored as lambda
        void Insert(double,int);
        void PrintList();
        int SetupTail();

     private:
        Node * _head;
        Node * _tail;
        // Container must know their size
        int size = 0;

};


#endif

