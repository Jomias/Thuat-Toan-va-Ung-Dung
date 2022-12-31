#include <bits/stdc++.h>

using namespace std;

struct trie {
    vector<trie *> child;
    bool hasWord;

    trie() 
	{
        child.resize(26, 0);
        hasWord = 0;
    }
};

void add(trie *t, string s) 
{
    for (int i = 0; i < s.size(); ++i)	
	{
		if (!t->child[s[i] - 'a'])	t->child[s[i] - 'a'] = new trie();
		t = t->child[s[i] - 'a'];
	}
	t->hasWord = 1;
}

bool findWord(trie *t, string s) 
{
	for (int i = 0; i < s.length(); ++i) 
	{
		if (!t->child[s[i] - 'a'])	return 0;
		t = t->child[s[i] - 'a'];
	}
	return t->hasWord;
}

bool haveNoChild(trie * root) 
{
	for (int i = 0; i < 26; ++i)	if (root -> child[i])	return 0;
	return 1;
}

trie* remove(trie *root, string s, int i) 
{	
	if (!root)	return 0;
	if (i == s.size()) 
	{
		if (haveNoChild(root))	return 0;
		root -> hasWord = 0;
		return root;
	}
    root->child[s[i] - 'a'] = remove(root->child[s[i] - 'a'], s, i + 1);
    if (haveNoChild(root) && !root->hasWord)	root = 0;
    return root;
}

void printAll(trie *t, string s) 
{
	if (t->hasWord)	cout << s << endl;
	
	for (int i = 0; i < t->child.size(); ++i) 
	{
		if (!t->child[i])	continue;
		printAll(t->child[i], s + (char) (i + 'a'));
	}
}
int main() {
    trie *t = new trie();
    vector<string> words = vector<string>{"the", "a", "an", "there", "answer", "any", "by", "bye", "their"};

    for (string temp : words)	add(t, temp);


	if (findWord(t, "a"))	cout << "Co tu a" << endl;
	remove(t, "an", 0);
	if (findWord(t, "a"))	cout << "Co tu a" << endl;
	if (findWord(t, "an"))	cout << "Co tu an" << endl;
	if (findWord(t, "any"))	cout << "Co tu any" << endl;
	if (findWord(t, "bye"))	cout << "Co tu bye" << endl;
	
	printAll(t, "");
    return 0;
}

