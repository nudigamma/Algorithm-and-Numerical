/** this program is a unit test for node */
#include "Node.hpp"
#include <string>
#include <iostream>

//TODO: Need to add assert
void testNodeCreation()
{
    Node<double> double_node(400.00);
    Node<std::string> string_node("");
    std::cout<<"I am a double node and i am storing " << double_node.GetItem() << "\n";
    std::cout<<"I am a string node and i am storing " << string_node.GetItem() << "\n";
}

void testNodeLinkage()
{
    Node<double> double_node(400.00);
    Node<double> second_double(800.00,&double_node);
    std::cout<<"Point to first node " << second_double.GetItem() << "\n";
    std::cout<<"Point to first node " << second_double.GetNext()->GetItem() << "\n";
}

int main()
{
    testNodeCreation();//passes !
    testNodeLinkage(); // passes !

    return 0;
}