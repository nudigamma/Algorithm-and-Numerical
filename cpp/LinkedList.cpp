#include "LinkedList.hpp"
#include "iostream"

SimpleLinkedList::SimpleLinkedList(Node * beginning, Node * end):
_head{new Node}, _tail{new Node}
{
    _head = beginning;
    _tail = end;
}

SimpleLinkedList::SimpleLinkedList():
_head{new Node}, _tail{new Node} 
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

bool SimpleLinkedList::IsEmpty()
{   
    if(_head)
        return false;
    else
    {
        return true;
    }
     

}

void SimpleLinkedList::InsertAtBeginning(double item, Node * beginning)
{  
    if (IsEmpty ())
    {
        Node * new_node = new Node(item,nullptr);
        _head = new_node;
        return;

    }
    Node * new_node = new Node(item,beginning);
    _head = new_node;
} 

void SimpleLinkedList::PrintList()
{
    for (Node* p = _head; p->GetNext() != nullptr; p = p->GetNext() )
    {
        std::cout << p->GetItem() << "\n";
    }
}

int SimpleLinkedList::SetupTail()
{
    if (IsEmpty())
    {
        std::cout << "List is empty do nothing";
        return 0 ;
    }

    if (_head->GetNext() == nullptr)
    {
        std::cout << "List has one node , tail == head " << std::endl;
        _tail = _head;
        return 1;
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
        return counter+1;
    } // end of else 
    
} // end of function