#include "linkedlistexercises.hpp"
#include <iostream>
#include <string>

void test_find()
{
    SimpleLinkedList<std::string> llist = SimpleLinkedList<std::string>("1");
    llist.InsertAtBeginning("2");
    llist.InsertAtBeginning("2");
    llist.InsertAtBeginning("2");
    llist.InsertAtBeginning("2");
    llist.InsertAtBeginning("2");
    //llist.PrintList();
    std::cout << "\n";
    remove<std::string>(&llist,"2");
    //std::cout << node_to_delete_after_ptr->GetItem() << "\n";
    //llist.PrintList();
    //std::cin>> s;
}






int main()
{
    test_find();


    return 0;
}