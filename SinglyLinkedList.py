class Node:
    def __init__(self,data=None,next=None) -> None:
        self.data = data
        self.next = next
class LinkedList:
    def __init__(self) -> None:
        self.head = None
    def insertAtBegin(self,data):
        n = Node(data,self.head)
        self.head = n
    def insertAtEnd(self,data):
        n = Node(data,None)
        if self.head is None:
            self.head = n
            return
        ptr = self.head
        while ptr.next is not None:
            ptr = ptr.next
        ptr.next = n
    def insertAtIndex(self,data,index):
        ptr = self.head
        i = 0
        while i!= index-1:
            ptr = ptr.next
            i=+1
        n = Node(data,ptr.next)
        ptr.next = n
    def deleteFirst(self):
        if self.head is None:
            print("List is empty :(")
        ptr = self.head
        self.head = ptr.next
        del ptr
    def deleteLast(self):
        if self.head is None:
            print("List is empty :(")
        ptr = self.head
        qtr = ptr.next
        while qtr.next is not None:
            ptr = ptr.next
            qtr = qtr.next
        ptr.next = None
        del qtr
    def deleteAtindex(self,index):
        if self.head is None:
            print("List is empty :(")
        length = 0
        count = self.head
        while count.next is not None:
            length= length + 1
            count = count.next
        print("Length of the list is : ",length)
        if(index<0 or index>=length):
            print("List Index out of range")
            return
        ptr = self.head
        q = ptr.next
        i = 0
        while i != index-1:
            ptr = ptr.next
            q = q.next
            i=+1
        ptr.next = q.next
        del q
    def display(self):
        ptr = self.head
        if ptr is None:
            print("List is empty :(")
        while ptr is not None:
            print(ptr.data,end=" ")
            ptr = ptr.next
        print()
    
def run():
    n = 'y'
    l1 =LinkedList()
    while(n!='N' and n!='n'):
        t = int(input("Enter 1 to Insert at start\n2 to insert at end\n3 to insert at Index\n4 to delete first node\n5 to delete last node\n6 to delete node at an index\n7 To display the List : "))
        match t:
            case 1:
                o = int(input("Enter how many values you want to enter : "))
                for i in range(o):
                    val = int(input("Enter the value to enter : "))
                    l1.insertAtBegin(val)
                l1.display()
                
            case 2:
                o = int(input("Enter how many values you want to enter : "))
                for i in range(o):
                    val = int(input("Enter the value to enter : "))
                    l1.insertAtEnd(val)
                l1.display()
                
            case 3:
                ind = int(input("Enter the index at which you want to insert : "))
                val = int(input("Enter the value to enter : "))
                l1.insertAtIndex(val,ind)
                l1.display()
                
            case 4:
                l1.deleteFirst()
                l1.display()
            case 5:
                l1.deleteLast()
                l1.display()
            case 6:
                ind = int(input("Enter the index at which you want to delete : "))
                l1.deleteAtindex(ind)
                l1.display()
        n = input("Enter n/N to stop : ")
if __name__ == '__main__':
    run()