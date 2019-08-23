'''Unit test for linked list API '''
import random
import unittest
from DoubleLinkedList import DoubleLinkedList 
from DoubleLinkedList import LinkedNumber
from Node import DoubleNode



class TestTraverseList(unittest.TestCase):
    """ These sets of function test, test the functionality of 
    traverse and reverseTraverseList """

    def test_empty_dlist(self):
        # First let us tests for an empty list
        dList = DoubleLinkedList()
        self.assertEqual(dList.get_head(),None)
        self.assertEqual(dList.get_tail(),None)


    def test_one_node_dlist(self):
        #create a one node list, head == tail
        dList = DoubleLinkedList()
        dNode = DoubleNode(3,None,None)
        dList.set_head(dNode)
        dList.set_tail(dNode)
        dList.reverse_traverse_list()
        self.assertEqual(dList.get_tail().get_item(),3)
        dList.traverse_list()
        self.assertEqual(dList.get_head().get_item(),3)

    def test_one_or_more_nodes(self):
        # dlist generalize for traverse and reverse traverse for 2 nodes and more
        dNode1 = DoubleNode(1,None,None)
        dNode2 = DoubleNode(2,None,None)
        dNode1.set_next(dNode2)
        dNode2.set_previous(dNode1)
        dNode3 = DoubleNode(3,None,None)
        dNode3.set_previous(dNode2)
        dNode2.set_next(dNode3)
        dList = DoubleLinkedList(dNode1,dNode3)
        dList.reverse_traverse_list()
        dList.traverse_list()
        self.assertEqual(dList.get_tail().get_item(),3)
        self.assertEqual(dList.get_head().get_item(),1)

class TestInsertAtBeginning(unittest.TestCase):
    """ These sets of function test, test the functionality of 
    traverse and reverseTraverseList """
    def test_empty_dlist(self):
    # First let us test if we can add a node for an empty list
        dList = DoubleLinkedList()
        dList.insert_at_beginning(4)
        self.assertEqual(dList.get_tail().get_item(),4)
        self.assertEqual(dList.get_head().get_item(),4)
    
    def test_one_or_more_nodes(self):
        # test_empty_dlist is the only edge case 
        dList = DoubleLinkedList()
        numbers = [19,20,23,100,-100,0]
        #fills the list 
        for number in numbers:
            dList.insert_at_beginning(number)
        #Tests the list
        #Insert_at_beginning for Dlist acts like a queue, the first element
        #Gets pushed till therefore we start comparing from the tail for the dlist
        #And the beginning for the numbers 
        node = dList.get_tail()
        for number in numbers:
            self.assertEqual(node.get_item(),number)
            node = node.get_previous()

class TestInsertAtEnd(unittest.TestCase):
    """ These sets of function test, test the functionality of 
    traverse and reverseTraverseList """
    def test_empty_dlist(self):
    # First let us test if we can add a node for an empty list
        dList = DoubleLinkedList()
        dList.add_at_end(4)
        self.assertEqual(dList.get_tail().get_item(),4)
        self.assertEqual(dList.get_head().get_item(),4)
    
    def test_one_or_more_nodes(self):
        # test_empty_dlist is the only edge case 
        dList = DoubleLinkedList()
        numbers = [19,20,23,100,-100,0]
        #fills the list 
        for number in numbers:
            dList.add_at_end(number)
        # Tests the list
        # add_at_end for Dlist acts like a stack, the first element of the list 
        # gets pushed is the first element of the dlist, is  till therefore we start comparing from the head for the dlist
        # And the beginning for the numbers 
        node = dList.get_head()
        for number in numbers:
            self.assertEqual(node.get_item(),number)
            node = node.get_next()

class TestInsert(unittest.TestCase):
    """ These sets of function test, test the functionality of 
    traverse and reverseTraverseList """
    def test_invalid_size(self):
    # First let us test if we can add a node for an empty list
        dList = DoubleLinkedList()
        self.assertEqual(dList.insert(0,4),-1)
        self.assertEqual(dList.insert(-1,4),-1)
        self.assertEqual(dList.insert(1,4),-1)

    def test_size_update(self):
        # Size 0 
        dList = DoubleLinkedList()
        numbers =[]
        self.assertEqual(dList.get_size(),len(numbers))
        # Size 1 for add_at_end
        numbers = [1]
        for number in numbers:
            dList.add_at_end(number)
        self.assertEqual(dList.get_size(),len(numbers))
        # Size 1 for insert_at_beginning
        dList = DoubleLinkedList()
        numbers = [1]
        for number in numbers:
            dList.insert_at_beginning(number)
        self.assertEqual(dList.get_size(),len(numbers))

        # Size 3 for add_at_end
        dList = DoubleLinkedList()
        numbers = [1,2,3]
        for number in numbers:
            dList.add_at_end(number)
        self.assertEqual(dList.get_size(),len(numbers))

        # Size 3 for add_at_end
        dList = DoubleLinkedList()
        numbers = [1,2,3]
        for number in numbers:
            dList.insert_at_beginning(number)
        self.assertEqual(dList.get_size(),len(numbers))

    def test_invalid_pos(self):
        # Test_empty_dlist is the only edge case 
        dList = DoubleLinkedList()
        numbers = [19,20,23,100,-100,0]
        # Fills the list 
        for number in numbers:
            dList.add_at_end(number)
        # Check for negative position
        self.assertEqual(dList.insert(-1,4),-1)
        # Check for a position equal to size 
        self.assertEqual(dList.insert(dList.get_size(),4),-1)
        # Check for a position bigger than size 
        self.assertEqual(dList.insert(dList.get_size()+1,4),-1)
        # Check for a position bigger than size
        self.assertEqual(dList.insert(dList.get_size()-1,4),0)

    def test_valid_pos(self):
        dList = DoubleLinkedList()
        # Position zero Single node list
        numbers = [1]
        dList.insert_at_beginning(numbers[0])
        for number in numbers:
            dList.insert(0,number)
        self.assertEqual(dList.get_head().get_item(),1)
        # Position zero multiple nodes list 
        numbers = [4,5]
        for number in numbers:
            dList.insert(0,number)
        self.assertEqual(dList.get_head().get_item(),5)
        # Position 1 multiple nodes list
         
        dList.set_head(None)
        dList.set_tail(None)
        dList.set_size(0)
        dList.insert_at_beginning(2) 
        dList.insert_at_beginning(3)
        numbers = [4,5,6]
        for number in numbers:
            dList.insert(1,number)
        self.assertEqual([3,6,5,4,2],dList.convert_to_array())
        numbers = [4,5,6,7,8,9]
        # Position size -1 multiple nodes list
        # cleaning list
        dList.set_head(None)
        dList.set_tail(None)
        dList.set_size(0)
        dList.insert_at_beginning(2) 
        dList.insert_at_beginning(3)
        for number in numbers:
            dList.insert(dList.get_size()-1,number)
        self.assertEqual([3,4,5,6,7,8,9,2],dList.convert_to_array())
        # position in the middle
        dList.insert(4,666)
        self.assertEqual([3,4,5,6,666,7,8,9,2],dList.convert_to_array())

def suite():
    suite = unittest.TestSuite()
    suite.addTest(TestTraverseList('test_empty_dlist'))
    suite.addTest(TestTraverseList('test_one_node_dlist'))
    suite.addTest(TestTraverseList('test_one_or_more_nodes'))
    suite.addTest(TestInsertAtBeginning('test_empty_dlist'))
    suite.addTest(TestInsertAtBeginning('test_one_or_more_nodes'))
    suite.addTest(TestInsertAtEnd('test_empty_dlist'))
    suite.addTest(TestInsertAtEnd('test_one_or_more_nodes'))
    suite.addTest(TestInsert('test_invalid_size'))
    suite.addTest(TestInsert('test_size_update'))
    suite.addTest(TestInsert('test_invalid_pos'))
    suite.addTest(TestInsert('test_valid_pos'))
    return suite

if __name__ == "__main__":
    runner = unittest.TextTestRunner()
    runner.run(suite())