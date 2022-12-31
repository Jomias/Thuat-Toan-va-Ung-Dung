class ListNode:
    def __init__(self, key, val):
        self.pair = (key, val)
        self.next = None

def hashFunc(key, size):
    return key % size

class HashTable:
    def __init__(self):
        self.m = 10;
        self.h = [None] * self.m
        
    def insert(self, key, val):
        i = hashFunc(key, self.m)
        if not self.h[i]:
            self.h[i] = ListNode(key, val)
            return;
        cur = self.h[i]
        while cur.next: 
            if cur.pair[0] == key:
                cur.pair = (key, val)
                return
            cur = cur.next
        cur.next = ListNode(key, val)  

    def printTable(self):
        for i in range(self.m):
            print(i, end = " ")
            x = self.h[i]
            while(x):
                print(f" --> {x.pair[0]}", end = " ")
                x = x.next
            print();

if __name__ == "__main__":
    a = [4371, 1323, 6173, 4199, 4344, 9679, 1989]
    m = HashTable();
    for i in range(len(a)):
        m.insert(a[i], True)
    m.printTable()
