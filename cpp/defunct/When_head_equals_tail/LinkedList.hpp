#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include <iostream>
#include <cmath>
#include <limits>

#include "Node.hpp"
//TODO: modernize 
template <typename T>
class SimpleLinkedList {

    public:

        SimpleLinkedList ();
        ~SimpleLinkedList();   
        SimpleLinkedList(T item);
        
        Node<T>*  GetHead();
        
        void   SetHead(Node<T> *);
        
        Node<T>*  GetTail();
        
        void   SetTail(Node<T> *);
        int    GetSize();
        void   InsertAtBeginning(T);
        void   InsertAtEnd(T); 
        bool   IsEmpty(); // can be refactored as lambda
        void   Insert(T,int);
        
        T DeleteAtBeginning();
        T DeleteAtEnd();
        T DeleteNode(int pos);
        Node<T>* Search(T);
        Node<T>* Max();
        Node<T>* Min();

        Node<T>* Successor();
        Node<T>* Predecessor();
        void   PrintList();
        void   SetupTail();

     private:
        Node<T> * _head;
        Node<T> * _tail;
        // Container must know their size
        int _size = 0;

};

template<typename T>
SimpleLinkedList<T>::SimpleLinkedList(T item):
_head{new Node<T>(item,nullptr)}
{
    // explcitly assignemnt of head to tail for a single node
    _tail = _head;
}
template<typename T>
SimpleLinkedList<T>::SimpleLinkedList():
_head{new Node<T>(0,nullptr)},_tail{new Node<T>(0,nullptr)} 
{

}
template<typename T>
SimpleLinkedList<T>::~SimpleLinkedList()
{   
    /** Hacky much ? */
    std::cout<< "Cleaning up linkedlist \n";
    delete _head;
    delete _tail;
}   
template<typename T>
Node<T> * SimpleLinkedList<T>::GetHead ()
{
    return _head;
}
template<typename T>
Node<T> * SimpleLinkedList<T>::GetTail ()
{
    return _tail;
}
template<typename T>
void SimpleLinkedList<T>::SetTail(Node<T> * node)
{
    _tail = node;

}
template<typename T>
void SimpleLinkedList<T>::SetHead(Node<T> * node)
{
    _head = node;
    
}
template<typename T>
int SimpleLinkedList<T>::GetSize()
{
    return _size;
}

template<typename T>
bool SimpleLinkedList<T>::IsEmpty()
{   
    if(_head)
        return false;
    else
    {
        return true;
    }
     

}
template<typename T>
void SimpleLinkedList<T>::InsertAtBeginning(T item)
{  
    if (IsEmpty ())
    {
       Node<T> * new_node = new Node<T>(item,nullptr);
       _head = new_node;
       _tail = _head;
       _size++;
       return;
    }
    Node<T>* new_node = new Node<T>(item,nullptr);
    new_node->SetNext(_head);
    _head = new_node;
    _size++;
    return;
} 
template<typename T>
void SimpleLinkedList<T>::InsertAtEnd(T item)
{
    if (IsEmpty ())
    {
        Node<T> * new_node = new Node<T>(item,nullptr);
        _head = new_node;
        _tail = new_node;
        _size++;
        return;
    }
    Node<T> * new_node = new Node<T>(item,nullptr);
    _tail->SetNext(new_node);
    _tail = new_node;
    _size++;
    return;

}
template<typename T>
void SimpleLinkedList<T>::PrintList()
{
    Node<T> * next_ptr = _head;
    while (next_ptr)
    {
        std::cout << next_ptr->GetItem() << "\n";
        next_ptr = next_ptr->GetNext();
    }
}
template<typename T>
void SimpleLinkedList<T>::SetupTail()
{
    if (IsEmpty())
    {
        std::cout << "List is empty do nothing";
        _size = 0 ;
    }

    if (_head->GetNext() == nullptr)
    {
        std::cout << "List has one node , tail == head " << std::endl;
        _tail = _head;
        _size = 1;
    }

    else 
    {
        Node<T> * next_ptr = _head;
        int counter = 0;
        // while level 0
        while(next_ptr->GetNext())
        {
            next_ptr = next_ptr->GetNext();
            counter++;
        } // end of while level 0 
        _tail = next_ptr; 
        _size = counter+1;
    } // end of else 
    
} // end of function


/** inserts before a nodetemplate<typename T>  */
template <typename T>
void SimpleLinkedList<T>::Insert(T item, int pos)
{   
    if(pos < 0)
    {
        std::cout << "Negatives are not valid positions\n";
        return;
    }
    if(IsEmpty() || pos == 0)
    {
        InsertAtBeginning(item);
        _size++;
        return;
    }
    

    if (( pos +1 ) >= _size )

    {
        std::cout << "Position exceeds the size of the linked list\n";
        return;
    }
    if (pos == _size -1)
    {
        InsertAtEnd(pos);
        _size++;
        return;
    }
    int pos_counter = 1;

    Node<T> *temp_ptr = _head;
    while (pos_counter != pos)
    {   
        temp_ptr = temp_ptr->GetNext();
        pos_counter++;
    }
    Node<T> * new_node = new Node<T>(item,temp_ptr->GetNext());
    temp_ptr->SetNext(new_node);
    _size++;


} // end of function Insert
template<typename T>
T SimpleLinkedList<T>::DeleteAtBeginning()
{   
    if(!_head)
    {
        std::cout<< "Linked list is empty\n";
        return NAN;
    }
    if(!_head->GetNext())
    {
        T value {_head->GetItem()};
        _size = 0;
        _head = nullptr;
        return value;

    }
    Node<T>* tmpPtr {_head};
    _head = _head->GetNext();
    T value {tmpPtr->GetItem()};
    tmpPtr->SetNext(nullptr);
    delete tmpPtr;
    _size--;
    return value;

}// end of function DeleteAtBeginnning
template<typename T>
T SimpleLinkedList<T>::DeleteAtEnd()
{   
    if(!_head)
    {
        std::cout<< "Linked list is empty\n";
        return NAN;
    }
    // single node
    if(_head == _tail)
    {
        T value {_head->GetItem()};
        _size = 0;
        _head = nullptr;
        return value;

    }
    Node<T> * tmpPtr {_head};
    while(tmpPtr->GetNext() != _tail)
    {
        tmpPtr = tmpPtr->GetNext();    
    }
    T value {_tail->GetItem() };
    _tail = tmpPtr;
    _tail->SetNext(nullptr);
    tmpPtr = tmpPtr->GetNext();
    delete tmpPtr;
    _size--;
    return value;

}// end of function DeleteAtBeginnning
template<typename T>
T SimpleLinkedList<T>::DeleteNode(int pos)
{   
    T value {0};
    if(!_head)
    {
        std::cout<< "Linked list is empty\n";
        return NAN;
    }
    // single node
    if(pos < 0)
    {
        std::cout << "Can't take negative values \n";
        return NAN;
    }
    if (pos == 0)
    {
       value = this->DeleteAtBeginning();
       return value;
    }
    
     if (pos >= _size)
    {
        std::cout << "Linked list overflow \n";
        return NAN;

    }

    Node<T>* tmpPtr {_head};
    int counter {1};

    while(counter != pos)
    {
        tmpPtr = tmpPtr->GetNext();    
        counter++;
    }
    value = tmpPtr->GetNext()->GetItem() ;
    Node<T>* deleteNode(tmpPtr->GetNext());
    tmpPtr->SetNext(tmpPtr->GetNext()->GetNext());
    delete deleteNode;
    _size--;
    return value;

}// end of function DeleteAtBeginnning
template<typename T>
Node<T> * SimpleLinkedList<T>::Search(T key)
{
    if (_head == nullptr)
    {
        std::cout << "Empty linked list\n";
        return nullptr;
    }
    Node<T>* tmp_ptr = _head;
    while(tmp_ptr != nullptr)
    {   
        if(tmp_ptr->GetItem() == key)
        {  
            std::cout <<"Key Found ! \n";
            return tmp_ptr;
        }
        tmp_ptr = tmp_ptr->GetNext();
    }

    std::cout << "Reach the end of the list did not find your key \n";
    return nullptr;
}
template<typename T>
Node<T>* SimpleLinkedList<T>::Max() // overload to return node
{   
    T inf = -std::numeric_limits<T>::infinity();
    if (_head == nullptr)
    {
        std::cout << "Empty linked list\n";
        return nullptr;
    }
    
    Node<T>* tmp_ptr {_head};
    Node<T>* max_ptr {_head};
    T max = inf;
    while(tmp_ptr != nullptr)
    {   
        if( tmp_ptr->GetItem() > max)
        {  
            max = tmp_ptr->GetItem();
            max_ptr = tmp_ptr;
        }
        tmp_ptr = tmp_ptr->GetNext();
    }

    return max_ptr;
}
template<typename T>
Node<T>* SimpleLinkedList<T>::Min() // overload to return node
{   
    T inf = std::numeric_limits<T>::infinity();
    if (_head == nullptr)
    {
        std::cout << "Empty linked list\n";
        return nullptr;
    }
    
    Node<T>* tmp_ptr {_head};
    Node<T>* min_ptr{_head};
    T min = inf;

    while(tmp_ptr != nullptr)
    {   
        if( tmp_ptr->GetItem() < min)
        {  
            min = tmp_ptr->GetItem();
            min_ptr = tmp_ptr;
        }
        tmp_ptr = tmp_ptr->GetNext();
    }

    return min_ptr;
}




template<typename T>
Node<T>* SimpleLinkedList<T>::Successor()

{
    constexpr T inf = -std::numeric_limits<T>::infinity();
    if (_head == nullptr)
    {
        std::cout << "Empty linked list\n";
        return nullptr;
    }
    
    Node<T>* tmp_ptr {_head};
    Node<T>* second_max_ptr = (_head);
    Node<T>* max_ptr = Max();
    T second_max = inf;
    while(tmp_ptr != _tail)
    {   
        if( tmp_ptr == max_ptr)
            tmp_ptr = tmp_ptr->GetNext();
        else
        {
            if(tmp_ptr->GetItem()> second_max)
                {   
                    second_max = tmp_ptr->GetItem();
                    second_max_ptr = tmp_ptr;
                    tmp_ptr = tmp_ptr->GetNext();
                }
            else
                {
                    tmp_ptr = tmp_ptr->GetNext();
                }
            
        }

        
    }

    return second_max_ptr;
}


template<typename T>
Node<T>* SimpleLinkedList<T>::Predecessor()

{
    constexpr T inf = std::numeric_limits<T>::infinity();
    if (_head == nullptr)
    {
        std::cout << "Empty linked list\n";
        return nullptr;
    }
    
    Node<T>* next_ptr {_head};
    Node<T>* second_min_ptr = (_head);
    Node<T>* min_ptr = Min();
    T second_min = inf;
    while(next_ptr != _tail)
    {   
        if( next_ptr == min_ptr)
            next_ptr = next_ptr->GetNext();
        else
        {
            if(next_ptr->GetItem() < second_min)
                {   
                    second_min = next_ptr->GetItem();
                    second_min_ptr = next_ptr;
                    next_ptr = next_ptr->GetNext();
                }
            else
                {
                    next_ptr = next_ptr->GetNext();
                }
            
        }

        
    }

    return second_min_ptr;
}

#endif

