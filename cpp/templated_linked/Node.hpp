#ifndef NODE_HPP
#define NODE_HPP


template < class T> class Node {
private:
    T item;
    Node * next;
                     
public:
    Node(T, Node*);
    T getItem();
    Node<T> * getNext();
    void setItem(T);
    void setNext(Node<T>*);    
   

};


template< class T>
Node<T>::Node(T initial, Node <T>* address){
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
void Node<T>::setNext(Node<T> * nextptr){
    next = nextptr;
}
#endif