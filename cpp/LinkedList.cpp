#include "LinkedList.hpp"
#include "iostream"

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
       size++;
       return;
    }
    Node * new_node = new Node(item,nullptr);
    new_node->SetNext(_head);
    _head = new_node;
    size++;
    return;
} 

void SimpleLinkedList::InsertAtEnd(double item)
{
    if (IsEmpty ())
    {
        Node * new_node = new Node(item,nullptr);
        _head = new_node;
        _tail = new_node;
        size++;
        return;
    }
    Node * new_node = new Node(item,nullptr);
    _tail->SetNext(new_node);
    _tail = new_node;
    size++;
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

void SimpleLinkedList::Insert(double item, int pos)
{
    if(IsEmpty())
    {
        InsertAtBeginning(item);
        return;
    }
    if(pos < 0)
    {
        std::cout << "Negatives are not valid positions" << "\n";
        return;
    }

}
