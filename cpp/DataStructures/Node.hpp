#ifndef NODE_HPP
#define NODE_HPP
#include <cstddef>
#include <memory>

template <typename T>

class Node 
{
public:
    Node();
    Node(T);
    Node(T,Node *);
    Node(Node*);
    T GetItem();
    Node * GetNext();
    void SetItem(T);
    void SetNext(Node *); 

private:
    T _item;
    unique_ptr<Node <T>>  _next;
};



//  default contructor
template <typename T>
Node<T>::Node(): _item{0}, _next{nullptr}
{

}
template <typename T>
Node<T>::Node(T value ): _item{value}, _next{nullptr}
{

}
template <typename T>
Node<T>::Node(Node * next):_item(0), _next{next}
{

};

template <typename T>
Node<T>::Node(T value , Node * next_node): _item {value}, _next {next_node} 
{
    
};
template <typename T>
T Node<T>::GetItem()
{
    return _item;
}
template <typename T>
void Node<T>::SetItem(T value )
{
    _item = value;
}
template <typename T>
Node<T> * Node<T>::GetNext()
{
    return _next;
}
template <typename T>
void Node<T>::SetNext(Node* new_node)
{
    _next= new_node;
}

#endif