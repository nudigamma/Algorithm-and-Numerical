#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP


#include "Node.hpp"

class SimpleLinkedList {

    public:

        SimpleLinkedList ();
        ~SimpleLinkedList();   
        SimpleLinkedList(Node *,Node * );
        Node * GetHead();
        void  SetHead(Node *);
        Node * GetTail();
        void SetTail(Node *);
        void InsertAtBeginning(double, Node*); 
        bool IsEmpty();
        void PrintList();
        int SetupTail();

     private:
        Node * _head;
        Node * _tail;

};


#endif

