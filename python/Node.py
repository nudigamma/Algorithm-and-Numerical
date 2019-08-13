''' Node.py implements a Node . Node is an element of a linked list'''

class Node:
    ''' Single linked node'''
    ''' REF page 142'''
    def __init__(self,item, next):
        self.item = item
        self.next = next


    def GetItem(self):
        return self.item

    def GetNext(self):
        return self.next

    def SetItem(self,item):
        self.item = item

    def SetNext(self,next):
        self.next = next
    

class DoubleNode(Node):

    ''' DoubleNode inhirits from Node'''
    def __init__(self,item,next,previous):
        super().__init__(item,next)
        self.previous = previous

    def GetPrevious(self):
        return self.previous

    def SetPrevious(self,previous):
        self.previous = previous
        