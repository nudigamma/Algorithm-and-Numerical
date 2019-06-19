''' Node.py implements a Node . Node is an element of a linked list'''


class Nodev1:
    ''' Single linked node'''
    ''' REF page 142'''
    def __init__(self,item,next):
        self.item = item
        self.next = next




class Nodev2:
    ''' Single linked node'''
    ''' REF page 142'''
    def __init__(self,item, next):
        self.item = item
        self.next = next
        


    def getItem(self):
        return self.item

    def getNext(self):
        return self.next

    def setItem(self,item):
        self.item = item

    def setNext(self,next):
        self.next = next