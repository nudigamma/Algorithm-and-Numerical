#include <iostream>
#include <cstddef>
#include "Node.hpp"
#include "LinkedList.hpp"



int main()
{
    
    SimpleLinkedList<int> * llist = new SimpleLinkedList<int>(nullptr,nullptr);
    llist->insertAtBeginning(10);
    std::cout << llist->getHead()->getItem();
    llist->insertAtBeginning(12);
    

}