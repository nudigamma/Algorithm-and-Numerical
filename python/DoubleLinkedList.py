import math # has -inf and +inf variables defined
from Node import DoubleNode
__liscence__ = "MIT"
__revision__ = "v.01"
__author__ = "Nadim Farhat nadim.farhat@gmail.com"

class DoubleLinkedList:
    ''' This class defines the API for a double linked list as defined by Sedgwick et all and Cormen et all'''
    ''' if node.previous == None ==> Head '''
    ''' if node.next == None ==> Tail '''
    ''' def 1:  linked list is a recursive data structure that is either empty
            or a reference to a ndoe having a generic item and a reference to a linked list Sedgwick et all "Algorithm 4th edition" 
        def 2 : linked list is data structure in which objects are arranged in a linear order, Unlike an array where the order i
            is determined by the indices. The order in a linked list is determeind by a pointer in each object . 
    Simply a list can grow and shrink depending on the need of a program
    The access to a linked list memory is not necessirally contiguous therefore it might be slow interms of memory access and might not use
    hardware and compiler optimization ''' 


    def __init__(self,head = None,tail=None):
        self.head = head
        self.tail = tail
       


    def GetHead(self):
        ''' Returns the first Node in the linked list'''
        return self.head
    
    def SetHead(self,head_ref):
        ''' Sets the head of the linked list to an address/ref'''
        self.head = head_ref
    
    def GetTail(self):
        ''' Returns the last node in the linked list'''
        return self.tail
    
    def SetTail(self,tail_ref):
        ''' Sets the last node in the linked list to an address/reference'''
        self.tail = tail_ref
    
   
   

    # computational complexity o(1)
    def insertAtBeginning(self, item):
        if (self.head == None):
            new_node  = DoubleNode(item,None,None)
            self.head = new_node
            self.tail = new_node
            return
        new_node = DoubleNode(item,self.head,None)
        self.head.previous = new_node
        self.head = new_node
        return 

    
    # computational complexity o(n)
    def traverseList(self):
        if self.head == None:
            print("Linked List is empty")
            return None
        current = self.head
        while(current.GetNext() != None):
            current = current.GetNext()
        self.tail = current

    def printList(self):
        if self.head == None:
            print("Linked List is empty")
            return None
        current = self.head
        print(current.GetItem())
        while(current.GetNext() != None):
            current = current.GetNext()
            print(current.GetItem())
    
    # computational complexity o(n)
    def insertAtEnd(self,item):
        # assuming we dont have the tail
        if self.head == None:
            self.insertAtBeginning(item)
            return
        self.traverseList()
        node = Node(item,None) # since it is an end node
        self.tail.SetNext(node)

     #for insertNode at whe n == pos 
    

    def insert(self,pos,item):
        if  self.head == None:
            self.insertAtBeginning(item)
            return None
        if  pos < 0:
            print("Invalid position")
            return None
        if  pos == 0:
            self.insertAtBeginning(item)
            return
        new_node = Node(item,None)
        current = self.head
        for position in range(pos-1):
            if  current.GetNext().GetNext() != None:
                current = current.GetNext()
            else:
                print("linked list overflow, return linked list as is ")
                return -1
        
        new_node.SetNext(current.GetNext())
        current.SetNext(new_node)
        
    
    
    def deleteFromBeginning(self):
        if self.head == None: # empty list
            return None
        self.head = self.head.GetNext()
    
    def deleteFromEnd(self):
        if (self.head == None or self.head.GetNext() == None):
            self.head = None
            return
        current = self.head
        while(current.GetNext().GetNext() != None):
            current = current.GetNext()
        current.SetNext(None) 
        self.tail = current

    #TODO: check the return    
    def delete(self, pos):
        if self.head == None:
            return -1 
        if pos == 0:
            self.deleteFromBeginning()
            return None
        if pos < 0:
            return -1
        current  = self.head
        for position in range(pos-1):# quick reminder range will be from 0 to pos -1 
            current = current.GetNext()
            if current is self.tail:
                print('''Overflow, please chose a different pos
                      returning linked list unchanged''')
                return -1 
        temp = current.GetNext()
        current.SetNext(temp.GetNext())
        temp.SetNext(None)
        
    def search(self,key): 
        '''A query that given a linked list and a key returns
            a reference to the node containing the key or none '''
        current = self.head
        if current.GetItem() == key: # first case 
            return current
        while(current != None):
            if (current.GetItem() == key):
                return current
            current = current.GetNext()
            
        # reached end and did not find the key returning None
        return None
    
   

    
class LinkedNumber(SimpleLinkedList):
    '''Inherits SimpleLinkedList , adds some functionality for number'''
    def __init__(self,head = None,tail=None,max=0,min = 0):
        super().__init__(head,tail)
        self.min = 0 
        self.max = 0

    def getMax(self):
        ''' Returns the node that contains the highest value '''
        return self.max

    def getMin(self):
        ''' Returns the node that contains the highest value '''
        return self.min

    def minimum(self): #
        # depends on the values of the items
        # assuming set of real numbers 
        if self.head == None:
            print("Emtpy list ")
            return -1
        if self.head.GetNext() == None:
            return self.head
        
        minimum = math.inf
        
        current = self.head
        ref_to_minimum = None
        
        while(current  != None):
            if (current.GetItem() < minimum):
                minimum = current.GetItem()
                ref_to_minimum = current     
            current = current.GetNext()
            
        self.min = ref_to_minimum
        
    def maximum (self): # to implement after implementing a sort
    
        # depends on the values of the items
        # assuming set of real numbers 
        if self.head == None:
            print("Emtpy list ")
            return None
        if self.head.GetNext() == None:
            return self.head
        
        maximum = -math.inf
        
        current = self.head
        ref_to_max = None
        
        while(current != None):
            if (current.GetItem() > maximum):
                maximum = current.GetItem()
                ref_to_max = current
            current = current.GetNext()
            
                
        self.max = ref_to_max
    

    # there are plenty of way to implement successor,
    # first method is to find max, and remove it then run max again o(n^2)
    # second method is find max and make sure successor is less than max but bigger than anythong else o(n^2)
    # third method is find max and it successor in one pass by maintaining two variable  max and successor o(n)
    # could be other methods i am not sure, please let me know any 


    def successor(self): # o(2n) worst case ! o(n) is max is in the begining

        ''' First method  is easiest to implement, find max first and then compare to max the successor'''
        successor_ref = None
        if self.head == None:
            print("Emtpy list ")
            return None
        if self.head.GetNext() == None:
            return None
        
        second_maximum = -math.inf 
        
        current = self.head
        self.maximum()
        max = self.getMax()
        while(current != None):
            if (current is max):
                current = current.GetNext() # skip
            elif (current.GetItem() > second_maximum):
                second_maximum = current.GetItem()
                successor_ref = current
               
                current = current.GetNext()
            else:
                current = current.GetNext()


        return successor_ref 
        
     
    def predecessor(self):
        ''' First method  is easiest to implement, find max first and then compare to max the successor'''
        predecessor_ref = None
        if self.head == None:
            print("Emtpy list ")
            return None
        if self.head.GetNext() == None:
            return None
        
        second_minimum = + math.inf 
        
        current = self.head
        self.minimum()
        min = self.getMin()
        while(current != None):
            if (current is min):
                current = current.GetNext() # skip
            elif (current.GetItem() < second_minimum):
                
                second_minimum = current.GetItem()
                predecessor_ref= current
               
                current = current.GetNext()
            else:
                current = current.GetNext()

        return predecessor_ref