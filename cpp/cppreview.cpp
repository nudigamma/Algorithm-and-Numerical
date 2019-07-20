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

void testDeleteAtBeginning()
{
    SimpleLinkedList llist = SimpleLinkedList();
    std::vector<int> range {3,4,5,6};
    for (auto i:range)
    {
        llist.InsertAtBeginning(i);
    }
    llist.PrintList();
    std::cout<<"Deleting! \n";
    llist.DeleteAtBeginning();
    llist.PrintList();
    std::cout<<"Deleting! \n";
    llist.DeleteAtBeginning();
    llist.PrintList();
    std::cout<<"Deleting! \n";
    llist.DeleteAtBeginning();
    llist.PrintList();
    std::cout<<"Deleting! \n";
    llist.DeleteAtBeginning();
    llist.PrintList();
    std::cout<<"Deleting! \n";
    llist.DeleteAtBeginning();
    llist.PrintList();

}
void testDeleteAtEnd()
{
    SimpleLinkedList llist = SimpleLinkedList();
    std::vector<int> range {3,4,5,6};
    for (auto i:range)
    {
        llist.InsertAtBeginning(i);
    }
    llist.PrintList();
    std::cout<<"Deleting! \n";
    std::cout << llist.DeleteAtEnd() << "\n";
    ///llist.PrintList();
    std::cout<<"Deleting! \n";
    std::cout << llist.DeleteAtEnd() << "\n";
    //llist.PrintList();
    std::cout<<"Deleting! \n";
    std::cout << llist.DeleteAtEnd() << "\n";
    //llist.PrintList();
    std::cout<<"Deleting! \n";
    std::cout << llist.DeleteAtEnd() << "\n";
    std::cout<<"Deleting! \n";
    std::cout << llist.DeleteAtEnd() << "\n";
    //llist.PrintList();

}
void testDeleteNode()

{
    SimpleLinkedList llist = SimpleLinkedList();
    std::vector<int> range {1,2,3,4,5,6,7,8,9,10};
    for (auto i:range)
    {
        llist.InsertAtBeginning(i);
    }
    llist.PrintList();
    //std::cout<<"Deleting! \n";
    //std::cout << llist.DeleteNode(10) << "\n";
    ///llist.PrintList();
    std::cout<<"Deleting! \n";
    std::cout << llist.DeleteNode(0) << "\n";
    //llist.PrintList();
    //std::cout<<"Deleting! \n";
    //std::cout << llist.DeleteNode(1) << "\n";
    //llist.PrintList();
    //std::cout<<"Deleting! \n";
    //std::cout << llist.DeleteNode(5) << "\n";
   // std::cout<<"Deleting! \n";
    //std::cout << llist.DeleteNode(5) << "\n";
    //llist.PrintList();

}

void testSearch()
{
    SimpleLinkedList llist = SimpleLinkedList();
    std::vector<int> range {1,2,3,4,5,6,7,8,9,10};
    for (auto i:range)
    {
        llist.InsertAtBeginning(i);
    }
    if(Node * n = llist.Search(111))
    {
      std::cout << n->GetItem() << std::endl;   
    }
    SimpleLinkedList llist1 = SimpleLinkedList();
    if(Node * n = llist1.Search(111))
    {
        std::cout << n->GetItem() << std::endl;   
    }
}

void testMinMax()
{
    SimpleLinkedList llist = SimpleLinkedList();
    std::vector<int> range {-0,-2,-999,-5,-6,-7,-8,-9,1000};
    for (auto i:range)
    {
        llist.InsertAtBeginning(i);
    }
    
    std::cout << " Min is " << llist.Min()->GetItem() << std::endl;
    std::cout << " Predecessor is " << llist.Predecessor()->GetItem() << std::endl;
    
  }
int main()
{
    //test_node_creation();
    //testLinkedList();
    //testTailSetup();
    //testInsertAtBeginning();
    //testInsertAtEnd();
    //testInsert();
    //testDeleteAtBeginning();
    //testDeleteAtEnd();
    //testDeleteNode();
    //testSearch();
    testMinMax();


}