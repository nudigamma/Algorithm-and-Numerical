'''Unit test for linked list API '''
import random
import unittest
from DoubleLinkedList import DoubleLinkedList 
from DoubleLinkedList import LinkedNumber
from Node import DoubleNode



class TestTraverseList(unittest.TestCase):
    ''' These sets of function test, test the functionality of 
    traverse and reverseTraverseList'''

    def test_empty_dlist(self):
        # First let us test if we can add a node for an empty list
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

    def test_more_than_one_node_dlist(self):
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

def suite():
    suite = unittest.TestSuite()
    suite.addTest(TestTraverseList('test_empty_dlist'))
    suite.addTest(TestTraverseList('test_one_node_dlist'))
    suite.addTest(TestTraverseList('test_more_than_one_node_dlist'))
    return suite
    
if __name__ == "__main__":
    runner = unittest.TextTestRunner()
    runner.run(suite())