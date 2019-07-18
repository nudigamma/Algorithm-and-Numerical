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
        Node*  GetHead();
        void   SetHead(Node *);
        Node*  GetTail();
        void   SetTail(Node *);
        int    GetSize();
        void   InsertAtBeginning( double);
        void   InsertAtEnd(double); 
        bool   IsEmpty(); // can be refactored as lambda
        void   Insert(double,int);
        
        double DeleteAtBeginning();
        double DeleteAtEnd();
        double DeleteNode(int pos);
        Node * Search(double);
        double Max();
        double Min();
        double Successor();
        double Predecessor();
        void   PrintList();
        void   SetupTail();

     private:
        Node * _head;
        Node * _tail;
        // Container must know their size
        int _size = 0;

};


#endif

