class TrieNode:
    def __init__(self):
        self.hasWord = False
        self.char = {}

def insert(root, s):
    for c in s:
        root = root.char.setdefault(c, TrieNode())
    root.hasWord = True

def findLCP(root):
    lcp = ''
    while root and len(root.char) == 1:
        for key, val in root.char.items():
            lcp += key
            root = val
    return lcp or None

if __name__ == '__main__':
    root = TrieNode()
    words = ["flower", "flow", "floght"]
    for s in words:
        insert(root, s)
    print('Tien to chung dai nhat:', findLCP(root))