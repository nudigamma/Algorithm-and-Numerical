import math # has -inf and +inf variables defined
from Node import DoubleNode
__liscence__ = "MIT"
__revision__ = "v.01"
__author__ = "Nadim Farhat nadim.farhat@gmail.com"

class DoubleLinkedList:
    r""" This class defines the API for a double linked list as defined by Sedgwick et all and Cormen et all

    Definition of a double linked list:

    Each node has a previous reference points to the previous node
    Each node has a next reference to the next node
    The previous reference of the "head" of Double Linked List points to None
    The next reference of the "head" of Double Linked List points to next node in the linked list
    The previous reference of the "tail" of Double Linked List points to precedent node
    The next reference of the "tail" of Double Linked List points to None

    Textbook definitions :
    def 1:  linked list is a recursive data structure that is either empty
    or a reference to a node having a generic item and a reference to a linked list Sedgwick et all "Algorithm 4th edition" 
    def 2 : linked list is data structure in which objects are arranged in a linear order, Unlike an array where the order i
    is determined by the indices. The order in a linked list is determeind by a pointer in each object . Linked list a part of dynamic sets and can grow and shrink depending on the need of a program
    The access to a linked list memory is not necessarilly contiguous therefore it might be slower than arrays "Introduction to Algorithms" 3rd Edition"
    """

    def __init__(self,head = None, tail=None, size = 0):
        """ Initializes an empty list """
        self.head = head
        self.tail = tail
        self.size = 0
       

    def get_head(self):
        """ Returns the first node/head in the linked list """
        return self.head
    
    def set_head(self,head_ref):
        """ Sets the head of the linked list to a node. 

        Keyword arguments:
        head_ref : reference to an object of type node
        """
        
        self.head = head_ref
    
    def get_tail(self):
        """ Returns the last node in the linked list """
        return self.tail
    
    def set_tail(self,tail_ref):
        """ Sets the head of the linked list to a node. 

        Keyword arguments:
        head_ref : reference to an object of type node
        """
        self.tail = tail_ref
    
    def get_size(self):
        """ Returns the size of the linked list """
        return self.size

    def __set_size(self,new_size):
        """ set the size of the linked list """
        self.size = new_size

    ####################################### Functionality #################################################
    # computational complexity o(1)

    def insert_at_beginning(self, item):
        """ inserts a node containing item before the head.
            the head will point to the new node.

        Keyword arguments:
        item : can be of any type 
        """
        #  If the list is empty 
        if (self.head == None):
        # Make is a one node list where head and tail are the same
            new_node  = DoubleNode(item,None,None)
            self.head = new_node
            self.tail = new_node
            self.size += 1
            return
        # If the list is not empty 
        new_node = DoubleNode(item,self.head,None)
        # Inserts before the current head
        self.head.previous = new_node
        # Assigns head to the new node
        self.head = new_node
        self.size += 1
        return 

    
    # computational complexity o(n)
    def traverse_list(self):
        """ Iterates from the begining of the double list till end
            sets the tail for the linked list """

        # Empty list   
        if self.head == None:
            print("Linked List is empty")
            return None
        # Starts at the head
        current = self.head
        # Until we reach the tail, only at tail next == None
        while(current.get_next() != None):
            current = current.get_next()
        # Sets the tail
        self.tail = current
    
    def reverse_traverse_list(self):
        """ Iterates from the end of the double list till the begining
            sets the head for the linked list """
        # Empty list
        if self.tail == None:
            print("Linked list is empty")
            return None
        # Starts at the tail
        current = self.tail
        # Untill we reach the head, only at head previous == None
        while(current.get_previous() != None):
            current = current.get_previous()
        # Sets the head
        self.head = current
        
    
    def print_list(self):
        """ prints the content of the list """
        # Empty list
        if self.head == None:
            print("Linked List is empty")
            return None
        # Starts at head
        current = self.head
        print(current.GetItem())
        # Print all elements until the end
        while(current.get_next() != None):
            current = current.get_next()
            print(current.GetItem())

    def reverse_print_list(self):
        """ prints the content of the list """
        # Empty list
        if self.tail == None:
            print("Linked List is empty")
            return None
        # Starts at tail
        current = self.tail
        print(current.GetItem())
        # Print all elements until the end
        while(current.get_previous() != None):
            current = current.get_previous()
            print(current.GetItem())


    # computational complexity o(n)
    def insert_at_end(self,item):
        """ inserts a node containing item after the tail
            the tail will point to the new node.

        Keyword arguments:
        item : can be of any type 
        """
        # Empty list
        if self.head == None:
            new_node  = DoubleNode(item,None,None)
            self.head = new_node
            self.tail = new_node
            self.size += 1
            return

        node = DoubleNode(item,None,self.tail) # since it is an end node
        self.tail.set_next(node)
        self.tail = node
        self.size += 1
        return

    
    def insert(self,pos,item):
        """ inserts a node containing item before a certain position
        this function uses the power of double linked list. since we have two pointers we either
        iterate from the head or tail depending on the size and the position
        so O(n/2)

        Keyword arguments:
        pos : a postive integer of the position
        item : can be of any type 

        """
        # Empty 
        if  self.head == None:
            print("Empty list")
            return -1
        # Invalid poition
        if  pos < 0 or pos > (self.size -1):
            print("Invalid position")
            return -1
        # At head
        if  pos == 0:
            self.insert_at_beginning(item)
            # Update the size
            self.size += 1
            return 0

        # At tail
        if pos == self.size -1:
            self.insert_at_end(item)
            self.size += 1
            # Update the size
            return 0
        # any other position

        new_node = DoubleNode(item,None,None)
        # since we are mantaining a head and a tail and the size, at most insert at pos
        # is n/2
        # if the position belongs to the first half of the list start from the head 

        if pos < self.size // 2:
            current = self.head
            for position in range(pos-1):
                current = current.get_next()
            # Insert the node            
            new_node.set_next(current.get_next())
            current.get_next().set_previous(new_node)
            current.set_next(new_node)
            # Update the size
            self.size += 1
        # else the position belong to the second half of the list, start from the tail
        else:
            current = self.tail
            for position in range((self.size - pos)):
                current = current.get_previous()
            # Insert the node 
            new_node.set_previous(current.get_previous())
            current.get_previous().set_next(new_node)
            current.set_previous(new_node)
            #update the size
            self.size += 1
             

    
    
    def deleteFromBeginning(self):
        if self.head == None: # empty list
            return None
        self.head = self.head.get_next()
    
    def deleteFromEnd(self):
        if (self.head == None or self.head.get_next() == None):
            self.head = None
            return
        current = self.head
        while(current.get_next().get_next() != None):
            current = current.get_next()
        current.set_next(None) 
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
            current = current.get_next()
            if current is self.tail:
                print('''Overflow, please chose a different pos
                      returning linked list unchanged''')
                return -1 
        temp = current.get_next()
        current.set_next(temp.get_next())
        temp.set_next(None)
        
    def search(self,key): 
        '''A query that given a linked list and a key returns
            a reference to the node containing the key or none '''
        current = self.head
        if current.GetItem() == key: # first case 
            return current
        while(current != None):
            if (current.GetItem() == key):
                return current
            current = current.get_next()
            
        # reached end and did not find the key returning None
        return None
    
   

    
class LinkedNumber(DoubleLinkedList):
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
        if self.head.get_next() == None:
            return self.head
        
        minimum = math.inf
        
        current = self.head
        ref_to_minimum = None
        
        while(current  != None):
            if (current.GetItem() < minimum):
                minimum = current.GetItem()
                ref_to_minimum = current     
            current = current.get_next()
            
        self.min = ref_to_minimum
        
    def maximum (self): # to implement after implementing a sort
    
        # depends on the values of the items
        # assuming set of real numbers 
        if self.head == None:
            print("Emtpy list ")
            return None
        if self.head.get_next() == None:
            return self.head
        
        maximum = -math.inf
        
        current = self.head
        ref_to_max = None
        
        while(current != None):
            if (current.GetItem() > maximum):
                maximum = current.GetItem()
                ref_to_max = current
            current = current.get_next()
            
                
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
        if self.head.get_next() == None:
            return None
        
        second_maximum = -math.inf 
        
        current = self.head
        self.maximum()
        max = self.getMax()
        while(current != None):
            if (current is max):
                current = current.get_next() # skip
            elif (current.GetItem() > second_maximum):
                second_maximum = current.GetItem()
                successor_ref = current
               
                current = current.get_next()
            else:
                current = current.get_next()


        return successor_ref 
        
     
    def predecessor(self):
        ''' First method  is easiest to implement, find max first and then compare to max the successor'''
        predecessor_ref = None
        if self.head == None:
            print("Emtpy list ")
            return None
        if self.head.get_next() == None:
            return None
        
        second_minimum = + math.inf 
        
        current = self.head
        self.minimum()
        min = self.getMin()
        while(current != None):
            if (current is min):
                current = current.get_next() # skip
            elif (current.GetItem() < second_minimum):
                
                second_minimum = current.GetItem()
                predecessor_ref= current
               
                current = current.get_next()
            else:
                current = current.get_next()

        return predecessor_ref