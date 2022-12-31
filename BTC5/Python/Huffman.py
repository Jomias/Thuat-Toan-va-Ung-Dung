import heapq
 
class node:
    def __init__(self, freq, symbol, left = None, right = None):
        self.freq = freq
        self.symbol = symbol
        self.left = left
        self.right = right
    def __lt__(self, nxt):
        return self.freq < nxt.freq

def makeTree(ch, freq, nodes):
    for x in range(len(ch)):
        heapq.heappush(nodes, node(freq[x], ch[x]))

    while(len(nodes) > 1):
        left = heapq.heappop(nodes)
        right = heapq.heappop(nodes)
        heapq.heappush(nodes, node(left.freq + right.freq, '', left, right))
   
def printNodes(node, val = ''):
    if(node.left):  printNodes(node.left, val + '0')
    if(node.right): printNodes(node.right, val + '1')
    if(not node.left and not node.right):   print(f"{node.symbol}: {val}")
        
if __name__ == "__main__":
    ch = ['a', 'b', 'c', 'd', 'e', 'f']
    freq = [5, 9, 12, 13, 16, 45]
    nodes = []
    makeTree(ch, freq, nodes)
    printNodes(nodes[0])