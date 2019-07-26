#ifndef SEDGWICK_HPP
#define SEDGWICK_HPP

#include "LinkedList.hpp"

template <typename T>
bool  find (SimpleLinkedList<T> *, T);
// 
template<typename T>
void removeAfter(Node<T> *);
//
template<typename T>
void insertBetween(Node<T> *,Node<T> *, T);

//Exercises 1.2. 
template <typename T>
Node<T> * find2 (Node<T> *, T);
template <typename T>
Node<T> * delete2(SimpleLinkedList<T> *,T);
template <typename T>
void remove(SimpleLinkedList<T> *,T);


template <typename T>
bool find(SimpleLinkedList<T> *list, T item)
{
    T value;
    Node<T> * next_ptr = list->GetHead();
    while(next_ptr != nullptr)
    {
        value = next_ptr->GetItem();
        if( value == item)
        {
            return true;
        }
        next_ptr = next_ptr->GetNext();
    }

    return false;

}


template<typename T>
void removeAfter(Node<T> * node)
{
    if ((node==nullptr) || (node->GetNext() == nullptr))
        return;

    Node<T> * to_delete_after_ptr = node->GetNext();
    node->SetNext(to_delete_after_ptr->GetNext());
    delete to_delete_after_ptr;
    return;
}
template<typename T>
void insertBetween(Node<T> * n1_ptr,Node<T> * n2_ptr, T item)
{
    if (!n1_ptr or !n2_ptr)
        return;
    Node<T>* n3 = new Node<T>(item,n2_ptr);
    n1_ptr->SetNext(n3);
}

/** Execrise */
template <typename T>
Node<T> * find2(Node<T> *node_ptr, T item)
{
    T value;
    Node<T> * next_ptr = node_ptr;
    while(next_ptr != nullptr)
    {
        value = next_ptr->GetItem();
        if( value == item)
        {
            return next_ptr;
        }
        next_ptr = next_ptr->GetNext();
    }

    return nullptr;

}
template<typename  T>
Node<T> * delete2(SimpleLinkedList<T> * lst_ptr,Node<T> * node_ptr)
{
    if( node_ptr == lst_ptr->GetHead())
        {
            lst_ptr->SetHead(lst_ptr->GetHead()->GetNext());
            //delete node_ptr;
            return lst_ptr->GetHead();
        }
    Node<T>* next_ptr = lst_ptr->GetHead();
    while (next_ptr->GetNext() != node_ptr)
    {
        next_ptr = next_ptr->GetNext();
    }
    
    next_ptr->SetNext(node_ptr->GetNext());
    //delete node_ptr;
    return next_ptr->GetNext();
}

template<typename T>
void remove(SimpleLinkedList<T> * lst_ptr, T key)
{
    Node<T> * save_head_ptr = lst_ptr->GetHead();
    while(save_head_ptr)
    {   
        save_head_ptr = find2(save_head_ptr,key);
        if(save_head_ptr)
        {
            std::cout<< save_head_ptr->GetItem() <<"\n";
            save_head_ptr = delete2(lst_ptr,save_head_ptr);
        }

    }
    return;  
}
#endif 