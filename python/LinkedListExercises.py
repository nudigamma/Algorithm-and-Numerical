from LinkedList import SimpleLinkedList
from Node import Node
import numpy as np


def find(linked_list,key):
    '''1.3.21 Write a method find() that takes a linked list and a string key as arguments and return true if some node in the list ha
    has key as its item field , false otherwise'''
    head = linked_list.get_head()
    next_reference = head
    while(next_reference != None):
        if(next_reference.get_item() == key):
            return True
        next_reference = next_reference.get_next()
    return False # reached the end without finding the key

def removeAfter(Node):
    if (Node == None or Node.get_next() == None):
        return
    to_delete_ref = Node.get_next()
    Node.set_next(to_delete_ref.get_next())
    to_delete_ref.set_next(None)

def insertBetween(node1, node2,item):
    if(node1 == None or node2 == None):
        return
    new_node = Node(item,node2)
    node1.set_next(new_node)
    return
#I did not want to use overload
def find2(node,key):
    next_reference = node
    while(next_reference != None):
        if(next_reference.get_item() == key):
            return next_reference
        next_reference = next_reference.get_next()
    return None # reached the end without finding the key

def delete2(linked_list,node):
    if (node is linked_list.get_head()): # first node is on the head need to update head
        linked_list.set_head(node.get_next())
        node.set_next(None)
        return linked_list.get_head()

    next_reference = linked_list.get_head() 
    
    while(not (next_reference.get_next() is node )):
        next_reference = next_reference.get_next()
    if(next_reference != None):
        next_reference.set_next(node.get_next())
        node.set_next(None)
        return next_reference.get_next()
    return None

def remove(linked_list,key):
    save_ptr = linked_list.get_head()
    while(save_ptr):
        save_ptr = find2(save_ptr,key)
        if(save_ptr):
            save_ptr = delete2(linked_list,save_ptr)
    return     

def rMax(Node,max):
    '''recursive max'''
    if(Node == None):
        return max
    else:
        if(Node.get_item() > max):
            max = Node.get_item()
        return rMax(Node.get_next(),max)
def reverseList(list_to_reverse):
    ''' reverse list ex 1.3.30 '''
    next_ref = list_to_reverse.get_head()
    if(next_ref == None):
        return None
    delete_ref = next_ref
    reversed_list = SimpleLinkedList()
    while(next_ref):
        reversed_list.insertAtBeginning(next_ref.get_item())
        next_ref = next_ref.get_next()
        list_to_reverse.SetHead(next_ref)
        delete_ref.set_next(None)
        delete_ref = next_ref
    return reversed_list

def rReverseList(list_to_reverse,reversed_list):
    if not (list_to_reverse.get_head()):
        return list_to_reverse,reversed_list
    
    node = Node(list_to_reverse.get_head().get_item(),reversed_list.get_head())    
    reversed_list.SetHead(node)
   
    list_to_reverse.SetHead(list_to_reverse.get_head().get_next())
    return rReverseList(list_to_reverse,reversed_list)

def recursiveReverseSedgwick(first):
    if(first == None):
        return None
    if(first.get_next() == None):
        return first
    second = first.get_next() # this moves foward untill reaching the last node
    rest = recursiveReverseSedgwick(second) # when end is reached start returning
     
    second.set_next(first)
    first.set_next(None)
    return rest


def main():
    llist = SimpleLinkedList()
    reversed_list = SimpleLinkedList()
    items = [3,2,1]
    for item in items:
        llist.insertAtBeginning(item)
    llist.printList()
    print("\n")
    #rReverseList(llist,reversed_list)
    #list2.printList()
    reversed_list.SetHead(recursiveReverseSedgwick(llist.get_head()))
    reversed_list.printList()
    #print(node_to_remove_after.get_item())





main()