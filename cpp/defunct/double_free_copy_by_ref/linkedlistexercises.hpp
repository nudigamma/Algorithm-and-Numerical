#ifndef SEDGWICK_HPP
#define SEDGWICK_HPP

#include "LinkedList.hpp"

template <typename T>
bool  find (SimpleLinkedList<T> , T);

template <typename T>
bool find(SimpleLinkedList<T> list, T item)
{
    T value;
    Node<T> * next_ptr = list.GetHead();
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


#endif 