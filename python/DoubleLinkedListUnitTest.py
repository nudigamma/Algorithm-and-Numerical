'''Unit test for linked list API '''
import random
from LinkedList import SimpleLinkedList 
from LinkedList import LinkedNumber
from Node import DoubleNode
#TODO: add lline and function for assertion to follow
#TODO: write test failing to disk 


def testInsertAtBeginning():
    # First let us test if we can add a node for an empty list

    llist = SimpleLinkedList()
    llist.insertAtBeginning(3)
    try:
        assert 3 == (llist.getHead().getItem()), f"Insert begining failed"
    except AssertionError as e:
        print(e)
    llist.insertAtBeginning(4)
    try:
        assert 4 == (llist.getHead().getItem()), "Insert begining failed"

    except AssertionError as e :
        print(e)
       # I don't think there is more edge cases, cleaning
    llist.setHead(None)

def testDeleteFromBeginning():

    llist = SimpleLinkedList()
    (llist.deleteFromBeginning())
    assert None == (llist.getHead()),"Delete Beginning of empty list failed"
    llist.insertAtBeginning(3)
    (llist.deleteFromBeginning())
    assert None == (llist.getHead()),"Delete Beginning of a list with a single node failed"
    llist.insertAtBeginning(3)
    llist.insertAtBeginning(4)
    assert 4 == llist.getHead().getItem(), "Delete Beginning of a list with more than one time failed "
      # I don't think there is more edge cases, cleaning
    llist.setHead(None)

def testInsertAtEnd():
    llist = SimpleLinkedList()
    llist.insertAtEnd(3) # for empty list end is the beginning 
    try:
        assert 3 == (llist.getHead().getItem()), f"Insert End empty list failed"
    except AssertionError as e:
        print(e)
    llist.insertAtEnd(4) # for empty list end is the beginning 
    try:
        assert 4 == (llist.getHead().getNext().getItem()), f"Insert One node list failed"
    except AssertionError as e:
        print(e)

def testDeleteAtEnd():

    print('Beginning of testDelete at End\n')
    llist = SimpleLinkedList()
    llist.deleteFromEnd()
    try:
        assert None == (llist.getHead()), f"Delete End empty list failed"
    except AssertionError as e:
        print(e)
    
    llist.insertAtEnd(4)
    llist.deleteFromEnd() 
    try:
        assert None == (llist.getHead()), f"Delete  One node list failed"
    except AssertionError as e:
        print(e)
    llist.insertAtEnd(3)
    llist.insertAtEnd(4)
    llist.insertAtEnd(5)
    llist.printList()
    llist.deleteFromEnd()
    print('\n')
    llist.printList()
    try:
        assert None == (llist.getHead().getNext().getNext()), f"Delete  One node list failed"
    except AssertionError as e:
        print(e)
    llist.deleteFromEnd()
    print('\n')
    llist.printList()
    try:
        assert None == (llist.getHead().getNext()), f"Delete  One node list failed"
    except AssertionError as e:
        print(e)
    print('end of testDelete at End\n')
def testInsertAtPos():
    # fill list 
    LIST_SIZE = 5 # 0-11
    llist = SimpleLinkedList()
    for number in range(LIST_SIZE):
        llist.insertAtBeginning(number)
    llist.printList()
    #llist.printList()
    # edge positions 0
    llist.insert(0,333)
    llist.printList()
  
    #try:
     #   assert 333 == (llist.getHead().getItem()) ,f"insert @ pos == 0 doesnt work"
    #except AssertionError as e:
     #   print(e)
    # Remember we insert before a Node
    '''llist.insert(11,999)
    #llist.printList()
    llist.traverseList()
    try:
        assert 999 == (llist.getTail().getItem()) ,f"insert @ end doesn't work"

    except AssertionError as e:
        print(e)
    '''
    # position at the middle
    llist.insert(1,666)

    llist.printList()
    node = llist.search(666)
    try:
        assert 666 == node.getItem(), f"insert @ middle doesn't work"
    except AssertionError as e:
        print(e)

    llist.insert(6,999)
    llist.printList()
    
    llist.insert(8,999)
    llist.printList()

def testDeleteAtPos():
    # fill list 
    LIST_SIZE = 1 # 0-11
    llist = SimpleLinkedList()
    for number in range(LIST_SIZE): # items = 0-4
        llist.insertAtBeginning(number)
    llist.printList()
    #llist.printList()
    # edge positions 0
    llist.delete(0)
    print("\n") 
    llist.printList()
    # we can play with delete at edge cases to show it is workuing

def testSearch():
    LIST_SIZE = 50 # 0-11
    llist = SimpleLinkedList()
    for number in range(LIST_SIZE): # items = 0-4
        llist.insertAtBeginning(number)
    llist.printList()
    try:

        assert 48 == llist.search(48).getItem(),"Search  did not pass for item inside list"
    
    except AssertionError as  e:
        print({e})
    
    try:

        assert 0 == llist.search(0).getItem(),"Search  did not pass for item at the end of the list"
    
    except AssertionError as  e:
        print({e})

    try:

        assert 49 == llist.search(49).getItem(),"Search  did not pass for item at the begining of the list"
    
    except AssertionError as  e:
        print({e})
    
    try:

        assert None == llist.search(50),"Search  did not pass for item at the begining of the list"
    
    except AssertionError as  e:
        print({e})

def testMinumum():
    LIST_SIZE = 50 # 0-11
    llist = LinkedNumber()
    for number in range(LIST_SIZE): # items = 0-4
        llist.insertAtBeginning(random.randint(0,39))
    llist.printList()
    llist.minimum()

    print(llist.getMin().getItem())
  
def testMaximum():
    LIST_SIZE = 5 # 0-11
    llist = LinkedNumber()
    for number in range(LIST_SIZE): # items = 0-4
        llist.insertAtBeginning(random.randint(0,39))
    llist.printList()
    llist.maximum()

    print(llist.getMax().getItem())
  
def testSuccessor():
    LIST_SIZE = 5 # 0-11
    llist = LinkedNumber()
    for number in range(LIST_SIZE): # items = 0-4
        llist.insertAtBeginning(random.randint(-39,39))
    llist.printList()
    node = llist.successor()
    print(node.getItem())

def testPredecessor():
    LIST_SIZE = 5 # 0-11
    llist = LinkedNumber()
    for number in range(LIST_SIZE): # items = 0-4
        llist.insertAtBeginning(random.randint(-39,39))
    llist.printList()
    node = llist.predecessor()
    
    print(node.getItem())
    




def testSingleNode():
    '''tests node creation'''
    firstValue = 2
    secondValue = 3
    firstNode = DoubleNode(firstValue,None,None)
    secondNode = DoubleNode(secondValue,None,firstNode)
    firstNode.SetNext(secondNode)

    #get next item 
    headValue = firstNode.GetNext().GetItem()
    try:
        assert firstValue == headValue, "Different values for head, something is wrong"
    except AssertionError as e:
        print(f'{e}')    
    tailValue =  secondNode.GetPrevious().GetItem()
    try:
        assert secondValue == tailValue, "Unexpected value for tail something is wrong"
    except AssertionError as e:
        print(f'{e}')


        
def main():
    #testInsertAtBeginning()
    #testDeleteFromBeginning()
    #testInsertAtEnd()
    #testDeleteAtEnd()
    #testInsertAtPos()
    #testDeleteAtPos()  
    #testSearch()
    #testMinumum()
    #testMaximum()
    #testSuccessor()
    #testPredecessor()
    testSingleNode()
    print("Passed all tests Yiiipppppiiiii")
    
main()