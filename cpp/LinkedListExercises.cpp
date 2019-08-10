#include "LinkedListExercises.hpp"
#include <iostream>
#include <string>

void test_recursiveMax()
{   
    double max = std::numeric_limits<double>::infinity();
    SimpleLinkedList<double> llist1 = SimpleLinkedList<double>(50);
  
    llist1.InsertAtBeginning(300);
    llist1.InsertAtBeginning(7);
    llist1.InsertAtBeginning(-8);
    llist1.InsertAtBeginning(-1000);
    llist1.PrintList();
    std::cout << "\n";
    //recursiveReverseList<double>(&llist1,&llist2);
    Node<double> *head_node = recursiveReverseSedgwick<double>(llist1.GetHead());
    llist1.SetHead(head_node);
    llist1.PrintList();
    //std::cout << node_to_delete_after_ptr->GetItem() << "\n";
    //llist.PrintList();
    //std::cin>> s;
}






int main()
{
    test_recursiveMax();


    return 0;
}