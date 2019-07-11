#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP


#include "Node.hpp"

template < class T > class SimpleLinkedList {



    private:
        Node<T> * head;
        Node<T> * tail;

    public:

        SimpleLinkedList(Node<T> *,Node<T> * );
        Node<T> * getHead();
        void  setHead(Node<T> *);
        Node<T> * getTail();
        void setTail(Node<T> *);
        void insertAtBeginning(T); 

};

template <class T> SimpleLinkedList<T>::SimpleLinkedList(Node<T> * head, Node<T> * tail ){

    this->head->setNext(head);
    this->tail->setNext(tail);

}


template < class T> void SimpleLinkedList<T>::insertAtBeginning(T item){
    Node<T> * new_node = new Node<T>(item,this->head);
    this->head= new_node;

    return;
}

template<class T> Node<T> * SimpleLinkedList<T>::getHead(){return this->head;}

#endif

