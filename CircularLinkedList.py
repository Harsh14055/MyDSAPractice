class Node:
    def __init__(self,data=None):
        self.data = data
        self.next = None
class CLinkedList:
    def __init__(self) -> None:
        self.head = None
    def insertAtEnd(self,data):
        n = Node(data)
        if self.head is None:
            n.next = n
            self.head = n
        else:
            ptr = self.head
            while ptr.next != self.head:
                ptr = ptr.next
            ptr.next = n
            n.next = self.head
    def insertAtBegin(self,data):
        n = Node(data)
        if self.head is None:
            n.next = n
            self.head = n
        n.next = self.head
        ptr = self.head
        while ptr.next != self.head:
            ptr = ptr.next
        ptr.next = n
        self.head = n
    def insertAtIndex(self,data,index):
        counter = self.head
        count = 0
        while counter.next != self.head:
            count = count+  1
            counter = counter.next
        print("Length of list is {}".format(count))
        if (index>=count) or (index<0):
            print("List index out of range")
            return
        i = 0
        ptr = self.head
        qtr = ptr.next
        while i != index-1:
            ptr = ptr.next
            qtr = qtr.next
            i=+1
        n = Node(data)
        ptr.next = n
        n.next = qtr
    def deleteFirst(self):
        if self.head is None:
            print("List is empty :(")
            return
        ptr = self.head
        qtr=self.head
        while ptr.next != self.head:
            ptr = ptr.next
        self.head = qtr.next
        ptr.next = self.head
        del qtr
    def deleteLast(self):
        if self.head is None:
            print("List is empty :(")
            return
        ptr = self.head
        qtr = ptr.next
        while qtr.next != self.head:
            ptr = ptr.next
            qtr = qtr.next
        ptr.next = self.head
        del qtr
    def deleteAtIndex(self,index):
        counter = self.head
        count = 0
        while counter.next != self.head:
            count = count+  1
            counter = counter.next
        print("Length of list is {}".format(count))
        if (index>=count) or (index<0):
            print("List index out of range")
            return
        ptr = self.head
        qtr = ptr.next
        i = 0
        while i != index-1:
            ptr = ptr.next
            qtr = qtr.next
            i=+1
        ptr.next = qtr.next
        del qtr
    def display(self):
        ptr = self.head
        while True:
            print(ptr.data,end=" ")
            ptr = ptr.next
            if ptr == self.head:
                break
        print()
def run():
    n = 'y'
    cl1 = CLinkedList()
    while(n!='N' and n!='n'):
        t = int(input("Enter 1 to Insert at start\n2 to insert at end\n3 to insert at Index\n4 to delete first node\n5 to delete last node\n6 to delete node at an index\n7 To display the List : "))
        match t:
            case 1:
                o = int(input("Enter how many values you want to enter : "))
                for i in range(o):
                    val = int(input("Enter the value to enter : "))
                    cl1.insertAtBegin(val)
                cl1.display()
                
            case 2:
                o = int(input("Enter how many values you want to enter : "))
                for i in range(o):
                    val = int(input("Enter the value to enter : "))
                    cl1.insertAtEnd(val)
                cl1.display()
                
            case 3:
                ind = int(input("Enter the index at which you want to insert : "))
                val = int(input("Enter the value to enter : "))
                cl1.insertAtIndex(val,ind)
                cl1.display()
                
            case 4:
                cl1.deleteFirst()
                cl1.display()
            case 5:
                cl1.deleteLast()
                cl1.display()
            case 6:
                ind = int(input("Enter the index at which you want to delete : "))
                cl1.deleteAtIndex(ind)
                cl1.display()
            case 7:
                cl1.display
        n = input("Enter n/N to stop : ")
if __name__ == '__main__':
    run()
            