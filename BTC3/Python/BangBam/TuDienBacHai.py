def hashFunc(key, size):
    res = 0
    for i in key:
        res += ord(i)
    return res % size

class HashTable:
    def __init__(self):
        self.size = 10;
        self.keys = [None] * self.size
        self.vals = [None] * self.size
        
    def insert(self, key, val):
        i = hashFunc(key, self.size)
        count = 1
        while self.keys[i]:
            if self.keys[i] == key:
                self.vals[i] = val
                return
            i = (i + count * count) % self.size 
            count += 1
        self.keys[i] = key
        self.vals[i] = val

    def find(self, key):
        i = hashFunc(key, self.size)
        count = 1
        while self.keys[i]:
            if self.keys[i] == key:
                return self.vals[i]
            i = (i + count * count) % self.size 
            count += 1
        return None

    def printTable(self):
        for i in range(self.size):
            if (self.keys[i]):   print(f"{i} - {self.keys[i]} - {self.vals[i]}")

if __name__ == "__main__":
    m = HashTable();
    m.insert("hello", "xin chao")
    m.insert("good", "tot")
    m.insert("sad", "buon")
    m.insert("dog", "cho")
    m.insert("cat", "meo")
    m.insert("pig", "heo")
    m.insert("car", "o to")
    print(m.find("hello"))
    m.printTable()
