#include "LinkedList.hpp"
#include <iostream>
#include <cmath>
#include <limits>


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
    double value {tmpPtr->GetItem()};
    tmpPtr->SetNext(nullptr);
    delete tmpPtr;
    _size--;
    return value;

}// end of function DeleteAtBeginnning

double SimpleLinkedList::DeleteAtEnd()
{   
    if(!_head)
    {
        std::cout<< "Linked list is empty\n";
        return NAN;
    }
    // single node
    if(_head == _tail)
    {
        double value {_head->GetItem()};
        _size = 0;
        _head = nullptr;
        return value;

    }
    Node * tmpPtr {_head};
    while(tmpPtr->GetNext() != _tail)
    {
        tmpPtr = tmpPtr->GetNext();    
    }
    double value {_tail->GetItem() };
    _tail = tmpPtr;
    _tail->SetNext(nullptr);
    tmpPtr = tmpPtr->GetNext();
    delete tmpPtr;
    _size--;
    return value;

}// end of function DeleteAtBeginnning

double SimpleLinkedList::DeleteNode(int pos)
{   
    double value {0};
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

    Node * tmpPtr {_head};
    int counter {1};

    while(counter != pos)
    {
        tmpPtr = tmpPtr->GetNext();    
        counter++;
    }
    value = tmpPtr->GetNext()->GetItem() ;
    Node * deleteNode(tmpPtr->GetNext());
    tmpPtr->SetNext(tmpPtr->GetNext()->GetNext());
    delete deleteNode;
    _size--;
    return value;

}// end of function DeleteAtBeginnning

Node * SimpleLinkedList::Search(double key)
{
    if (_head == nullptr)
    {
        std::cout << "Empty linked list\n";
        return nullptr;
    }
    Node * tmp_ptr = _head;
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

Node* SimpleLinkedList::Max() // overload to return node
{   
    double inf = -std::numeric_limits<double>::infinity();
    if (_head == nullptr)
    {
        std::cout << "Empty linked list\n";
        return nullptr;
    }
    
    Node* tmp_ptr {_head};
    Node* max_ptr {_head};
    double max = inf;
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

Node* SimpleLinkedList::Min() // overload to return node
{   
    double inf = std::numeric_limits<double>::infinity();
    if (_head == nullptr)
    {
        std::cout << "Empty linked list\n";
        return nullptr;
    }
    
    Node* tmp_ptr {_head};
    Node * min_ptr{_head};
    double min = inf;

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

Node* SimpleLinkedList::Successor()

{
    constexpr double inf = -std::numeric_limits<double>::infinity();
    if (_head == nullptr)
    {
        std::cout << "Empty linked list\n";
        return nullptr;
    }
    
    Node* tmp_ptr {_head};
    Node* second_max_ptr = (_head);
    Node* max_ptr = Max();
    double second_max = inf;
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

Node* SimpleLinkedList::Predecessor()

{
    constexpr double inf = std::numeric_limits<double>::infinity();
    if (_head == nullptr)
    {
        std::cout << "Empty linked list\n";
        return nullptr;
    }
    
    Node* next_ptr {_head};
    Node* second_min_ptr = (_head);
    Node* min_ptr = Min();
    double second_min = inf;
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