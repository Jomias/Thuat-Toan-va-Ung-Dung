def hashFunc(key, size):
    return key % size

class HashTable:
    def __init__(self):
        self.size = 10;
        self.keys = [None] * self.size
        self.vals = [None] * self.size
        
    def insert(self, key, val):
        i = hashFunc(key, self.size)
        while self.keys[i]:
            if self.keys == key:
                self.vals[i] = val
                return
            i = (i + 1) % self.size 
        self.keys[i] = key
        self.vals[i] = val

    def printTable(self):
        for i in range(self.size):
            print(i, end = ": ")
            if (self.keys[i]):   print(self.keys[i])
            else: print()

if __name__ == "__main__":
    a = [4371, 1323, 6173, 4199, 4344, 9679, 1989]
    m = HashTable();
    for i in range(len(a)):
        m.insert(a[i], True)
    m.printTable()
