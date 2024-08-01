class Node:
    def __init__(self,data=None,next=None,prev=None) -> None:
        self.data = data
        self.next = None
        self.prev = None
class Dlinkedlist:
    def __init__(self) -> None:
        self.head = None
        self.tail = None
    def insertAtBegin(self,data):
        n = Node(data)
        if self.head is None:
            self.head = n
            self.tail = n
        else:
            ptr = self.head
            # ttr = self.tail
            n.next = ptr
            ptr.prev = n
            self.head = n
            n.prev = None
    def insertAtend(self,data):
        n = Node(data)
        if self.head is None:
            self.head = n
            self.tail = n
        else:
            ptr = self.tail
            ptr.next = n
            n.prev = ptr
            self.tail = n
    def insertAtindex(self,data,index):
        size = 0
        p = self.head
        while p.next is not None:
            p = p.next
            size = size + 1
        if index<0 or index>=size:
            print("The size of liast is : ",size)
            print("List index out of range :(")
            return
        n = Node(data)
        i = 0
        ptr = self.head 
        while i!= index-1:
            ptr=ptr.next
            i = i + 1
        n.next = ptr.next
        ptr.next = n
        n.prev = ptr
    def deleteFirst(self):
        if self.tail is None:
            print("List is already empty.")
            return
        ptr = self.head
        self.head = ptr.next
        del ptr
    def deleteLast(self):
        if self.tail is None:
            print("List is already empty.")
            return

        if self.head == self.tail:
            del self.tail
            self.head = None
            self.tail = None
            return
        
        ptr = self.tail
        self.tail = ptr.prev
        self.tail.next = None
        del ptr
    def deleteAtIndex(self,index):
        size = 0
        p = self.head
        while p.next is not None:
            p = p.next
            size = size + 1
        if index<0 or index>=size:
            print("The size of liast is : ",size)
            print("List index out of range :(")
            return
        ptr = self.head
        i = 0
        while i!=index:
            ptr = ptr.next
            i = i + 1
        q = ptr.prev
        t = ptr.next
        q.next = t
        t.prev = q
        del ptr    
    def display(self):
        ptr = self.head
        while ptr is not None:
            print(ptr.data,end=" ")
            ptr = ptr.next
        print()
def run():
    n = 'y'
    dl1 = Dlinkedlist()
    while(n!='N' and n!='n'):
        t = int(input("Enter 1 to Insert at start\n2 to insert at end\n3 to insert at Index\n4 to delete first node\n5 to delete last node\n6 to delete node at an index\n7 To display the List : "))
        match t:
            case 1:
                o = int(input("Enter how many values you want to enter : "))
                for i in range(o):
                    val = int(input("Enter the value to enter : "))
                    dl1.insertAtBegin(val)
                dl1.display()
                
            case 2:
                o = int(input("Enter how many values you want to enter : "))
                for i in range(o):
                    val = int(input("Enter the value to enter : "))
                    dl1.insertAtend(val)
                dl1.display()
                
            case 3:
                ind = int(input("Enter the index at which you want to insert : "))
                val = int(input("Enter the value to enter : "))
                dl1.insertAtindex(val,ind)
                dl1.display()
                
            case 4:
                dl1.deleteFirst()
                dl1.display()
            case 5:
                dl1.deleteLast()
                dl1.display()
            case 6:
                ind = int(input("Enter the index at which you want to delete : "))
                dl1.deleteAtIndex(ind)
                dl1.display()
            case 7:
                dl1.display()
        n = input("Enter n/N to stop : ")
if __name__ == '__main__':
    run()
        
        