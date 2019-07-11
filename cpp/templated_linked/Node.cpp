#include "Node.hpp"



template< class T>
Node<T>::Node(T initial, Node* address){
item = initial;
next = address;

}

template< class T>
T Node<T>::getItem(){
    return item;
}

template< class T>
Node<T>* Node<T>::getNext(){
    return next;
}
template< class T>
void Node<T>::setItem(T value){
    item = value;
}

template< class T>
void Node<T>::setNext(Node * nextptr){
    next = nextptr;
}