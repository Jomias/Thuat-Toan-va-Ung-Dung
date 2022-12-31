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

bool haveOnlyChild(trie * root) 
{
	int cnt = 0;
	for (int i = 0; i < 26; ++i)	if (root -> child[i])	++cnt;
	return cnt == 1;
}

string findLCP(trie * root) 
{
	string LCP = "";
	while (root && haveOnlyChild(root))
	{
		for (int i = 0; i < 26; ++i) 
		{
			if (root -> child[i]) 
			{
				root = root -> child[i];
				LCP += (char) (i + 'a');
				break;
			}
		}	
	}
	return LCP;
}
int main() {
    trie *t = new trie();
    vector<string> words = vector<string>{"flower", "flow", "floght", "flot"};

    for (string temp : words)	add(t, temp);

	cout << findLCP(t);
    return 0;
}

