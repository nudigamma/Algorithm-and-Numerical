from LinkedList import SimpleLinkedList
from Node import Node

def find(linked_list,key):
    '''1.3.21 Write a method find() that takes a linked list and a string key as arguments and return true if some node in the list ha
    has key as its item field , false otherwise'''
    head = linked_list.GetHead()
    next_reference = head
    while(next_reference != None):
        if(next_reference.GetItem() == key):
            return True
        next_reference = next_reference.GetNext()
    return False # reached the end without finding the key

def removeAfter(Node):
    if (Node == None or Node.GetNext() == None):
        return
    to_delete_ref = Node.GetNext()
    Node.SetNext(to_delete_ref.GetNext())
    to_delete_ref.SetNext(None)

def insertBetween(node1, node2,item):
    if(node1 == None or node2 == None):
        return
    new_node = Node(item,node2)
    node1.SetNext(new_node)
    return
#I did not want to use overload
def find2(node,key):
    next_reference = node
    while(next_reference != None):
        if(next_reference.GetItem() == key):
            return next_reference
        next_reference = next_reference.GetNext()
    return None # reached the end without finding the key

def delete2(linked_list,node):
    if (node is linked_list.GetHead()): # first node is on the head need to update head
        linked_list.SetHead(node.GetNext())
        node.SetNext(None)
        return linked_list.GetHead()

    next_reference = linked_list.GetHead() 
    
    while(not (next_reference.GetNext() is node )):
        next_reference = next_reference.GetNext()
    if(next_reference != None):
        next_reference.SetNext(node.GetNext())
        node.SetNext(None)
        return next_reference.GetNext()
    return None

def remove(linked_list,key):
    save_ptr = linked_list.GetHead()
    while(save_ptr):
        save_ptr = find2(save_ptr,key)
        if(save_ptr):
            save_ptr = delete2(linked_list,save_ptr)
    return     

def main():
    llist = SimpleLinkedList()
    items = ["1","2","1","2"]
    for item in items:
        llist.insertAtBeginning(item)
    #llist.printList()
    remove(llist,"2")
    #print(node_to_remove_after.GetItem())
    llist.printList()




main()