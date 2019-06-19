''' Node.py implements a Node . Node is an element of a linked list'''


class Node:
    ''' Single linked node'''
    def __init__(self,item,next):
        self.item = item
        self.next = next

class Double_Node(Node):
    ''' double linked node'''
    ''' Page 234 REF 3 '''
    def __init__(self,item, next,prev):
        super.__init__(self,item,next)
        self.prev = prev

