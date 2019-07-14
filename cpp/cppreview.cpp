#include <iostream>
#include <cstddef>
#include "Node.hpp"
#include "LinkedList.hpp"
#include <vector>
using std::cout;

int test_node_creation(){
    // Adding first node 
    Node  node1 = Node(1,nullptr);
    cout << "Value of node 1 = " << node1.GetItem() << "\n";
    cout << "the node is pointing to " << node1.GetNext() << "\n";
    cout << "the address of our node " << &node1 << "\n";
    // adding next node
    Node  node2 = Node(2,nullptr);
    cout << "Value of node  2 = " << node2.GetItem() << "\n";
    cout << "the node is pointing to " << node2.GetNext() << "\n";
    cout << "the address of our node " << &node2 << "\n";
    // testing whehter node 1 can point to node 2
    node1.SetNext(&node2);
    cout << "Value of node " << node1.GetItem() << "\n";
    cout << "the node is pointing to " << node1.GetNext() << "\n";
    cout << "the address of our node " << &node1 << "\n";

    return 0;
    
}

int testLinkedList()
{
    SimpleLinkedList llist = SimpleLinkedList();
    if(llist.IsEmpty())
        std::cout << "list is empty \n";
    Node firstNode = Node(0,nullptr);
    llist.SetHead(&firstNode);
    Node secondNode = Node(1,nullptr);
    Node * temp = llist.GetHead();
    llist.SetHead(&secondNode);
    secondNode.SetNext(temp);
    std::cout <<"First item in list "<< llist.GetHead()->GetItem() <<"\n";
    std::cout <<"Second item in list "<< llist.GetHead()->GetNext()->GetItem() <<"\n";
}

void  testInsertAtBeginning()
{

    SimpleLinkedList  llist =  SimpleLinkedList(0);
    llist.InsertAtBeginning(1);
    llist.InsertAtBeginning(2);
    llist.InsertAtBeginning(3);
    llist.PrintList();
    std::cout<< llist.GetTail()->GetItem();

}

void testTailSetup()
{
    SimpleLinkedList llist = SimpleLinkedList();
    std::vector<int> range {0,1,2,3,4,5,6,7,8,9};
    for (auto i:range)
    {
        llist.InsertAtBeginning(i);
    }
    llist.SetupTail();
    int count = llist.GetSize();
    std::cout << "The list has" << count  << " Node\n";
    std::cout <<"The tail is points to item " << llist.GetTail()->GetItem() << "\n";
}

void testInsertAtEnd()
{

    SimpleLinkedList llist = SimpleLinkedList(0);
    std::vector<int> range {1,2};
    for (auto i:range)
    {
        llist.InsertAtBeginning(i);
    }
    //llist.PrintList();
    llist.InsertAtEnd(666);
    llist.PrintList();
    //std::cout << llist.GetHead()->GetNext()->GetNext()->GetNext()->GetItem() << "\n";
}

void testInsert()
{
    SimpleLinkedList llist = SimpleLinkedList();
    std::vector<int> range {3,4,5,6};
    for (auto i:range)
    {
        llist.InsertAtBeginning(i);
    }
    //llist.Insert(1,1);
    //llist.PrintList();
    llist.Insert(666,2);
    llist.PrintList();


}
int main()
{
    //test_node_creation();
    //testLinkedList();
    //testTailSetup();
    //testInsertAtBeginning();
    //testInsertAtEnd();
    testInsert();

}