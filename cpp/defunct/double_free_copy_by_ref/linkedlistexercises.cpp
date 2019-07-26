#include "linkedlistexercises.hpp"
#include <iostream>
#include <string>

void test_find()
{
    SimpleLinkedList<std::string> llist = SimpleLinkedList<std::string>("3");
    llist.InsertAtBeginning("3");
    llist.InsertAtBeginning("3");
    llist.InsertAtBeginning("8");
    llist.InsertAtBeginning("3");
    llist.PrintList();
    std::string s {"9"};
    if (find<std::string>(llist,s))
        std::cout <<"Found it \n";
    else
    {
        std::cout <<"Go fish \n";
    }
    
    //std::cin>> s;
}






int main()
{
    test_find();


    return 0;
}