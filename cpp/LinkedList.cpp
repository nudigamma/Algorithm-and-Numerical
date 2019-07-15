#include "LinkedList.hpp"
#include <iostream>
#include <cmath>


SimpleLinkedList::SimpleLinkedList(double item):
_head{new Node(item,nullptr)}
{
    // explcitly assignemnt of head to tail for a single node
    _tail = _head;
}

SimpleLinkedList::SimpleLinkedList():
_head{nullptr},_tail{nullptr} 
{

}

SimpleLinkedList::~SimpleLinkedList()
{
    delete _head;
    delete _tail;
}

Node * SimpleLinkedList::GetHead ()
{
    return _head;
}

Node * SimpleLinkedList::GetTail ()
{
    return _tail;
}

void SimpleLinkedList::SetTail(Node * node)
{
    _tail = node;

}

void SimpleLinkedList::SetHead(Node * node)
{
    _head = node;
    
}

int SimpleLinkedList::GetSize()
{
    return _size;
}


bool SimpleLinkedList::IsEmpty()
{   
    if(_head)
        return false;
    else
    {
        return true;
    }
     

}

void SimpleLinkedList::InsertAtBeginning(double item)
{  
    if (IsEmpty ())
    {
       Node * new_node = new Node(item,nullptr);
       _head = new_node;
       _tail = _head;
       _size++;
       return;
    }
    Node * new_node = new Node(item,nullptr);
    new_node->SetNext(_head);
    _head = new_node;
    _size++;
    return;
} 

void SimpleLinkedList::InsertAtEnd(double item)
{
    if (IsEmpty ())
    {
        Node * new_node = new Node(item,nullptr);
        _head = new_node;
        _tail = new_node;
        _size++;
        return;
    }
    Node * new_node = new Node(item,nullptr);
    _tail->SetNext(new_node);
    _tail = new_node;
    _size++;
    return;

}
void SimpleLinkedList::PrintList()
{
    Node * p = _head;
    while (p)
    {
        std::cout << p->GetItem() << "\n";
        p = p->GetNext();
    }
}

void SimpleLinkedList::SetupTail()
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
        Node * p = _head;
        int counter = 0;
        // while level 0
        while(p->GetNext())
        {
            p = p->GetNext();
            counter++;
        } // end of while level 0 
        _tail = p; 
        _size = counter+1;
    } // end of else 
    
} // end of function


/** inserts before a node  */
void SimpleLinkedList::Insert(double item, int pos)
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

    Node *temp_ptr = _head;
    while (pos_counter != pos)
    {   
        temp_ptr = temp_ptr->GetNext();
        pos_counter++;
    }
    Node * new_node = new Node(item,temp_ptr->GetNext());
    temp_ptr->SetNext(new_node);
    _size++;


} // end of function Insert

double SimpleLinkedList::DeleteAtBeginning()
{   
    if(!_head)
    {
        std::cout<< "Linked list is empty\n";
        return NAN;
    }
    if(!_head->GetNext())
    {
        double value {_head->GetItem()};
        _size = 0;
        _head = nullptr;
        return value;

    }
    Node * tmpPtr {_head};
    _head = _head->GetNext();
    double value = tmpPtr->GetItem();
    tmpPtr->SetNext(nullptr);
    delete tmpPtr;
    _size--;
    return value;

}// end of function DeleteAtBeginnning