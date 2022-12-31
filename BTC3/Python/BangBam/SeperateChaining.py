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
        
    def insert(self, key, value):
        index = hashFunc(key, self.m)
        if not self.h[index]:
            self.h[index] = ListNode(key, value)
            return;
        cur = self.h[index]
        while cur.next:
            if cur.pair[0] == key:
                cur.pair = (key, value)
                return
            cur = cur.next
        cur.next = ListNode(key, value)  

    def find(self, key):
        index = hashFunc(key, self.m)
        cur = self.h[index]
        while cur:
            if cur.pair[0] == key:
                return cur.pair[1]
            cur = cur.next
        return -1

    def remove(self, key):
        index = hashFunc(key, self.m)
        cur = self.h[index]
        if not cur: return
        if cur.pair[0] == key:
            self.h[index] = cur.next
            return
        while cur.next:
            if cur.next.pair[0] == key:
                cur.next = cur.next.next
                return

if __name__ == "__main__":
    print("Hello")
