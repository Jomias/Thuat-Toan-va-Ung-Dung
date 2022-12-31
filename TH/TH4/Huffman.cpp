#include <bits/stdc++.h>
using namespace std;

class HuffmanTreeNode 
{
	public:
	    char data;
	    int freq;
	    HuffmanTreeNode *left, *right;
	
	    HuffmanTreeNode(char data, int freq, HuffmanTreeNode *left = nullptr, HuffmanTreeNode *right = nullptr) 
		{
	        this -> data = data;
	        this -> left = left;
	        this -> right = right;
	    	this -> freq = freq;
	    }
};

class Compare 
{
	public:
	    bool operator()(HuffmanTreeNode *a, HuffmanTreeNode *b) 
		{
	        return a -> freq > b -> freq;
	    }
};

HuffmanTreeNode *makeTree(priority_queue<HuffmanTreeNode *, vector<HuffmanTreeNode *>, Compare> pq) 
{
    while (pq.size() != 1) 
	{
        HuffmanTreeNode *left = pq.top();	pq.pop();
        HuffmanTreeNode *right = pq.top();	pq.pop();
        pq.push(new HuffmanTreeNode('$', left -> freq + right -> freq, left, right));
    }
    return pq.top();
}

void printTree(HuffmanTreeNode *root, string s) {
    if (root -> left)	printTree(root -> left, s + "0");
    if (root -> right) 	printTree(root -> right, s + "1");

    if (root -> left || root -> right)	return;
    cout << root -> data << " " << s << endl;
}

void HuffmanCodes(vector <char> ch, vector <int> freq) {
    priority_queue<HuffmanTreeNode *, vector<HuffmanTreeNode *>, Compare> pq;
    for (int i = 0; i < freq.size(); ++i)	pq.push(new HuffmanTreeNode(ch[i], freq[i]));
    HuffmanTreeNode *root = makeTree(pq);
    vector<int> v(freq.size());
    printTree(root, "");
}

int main()
{ 
	vector<char> ch = vector<char> {'a', 'b', 'c', 'd', 'e', 'f'};
    vector<int> freq = vector<int> {5, 9, 12, 13, 16, 45};
    HuffmanCodes(ch, freq);
    return 0;
}


