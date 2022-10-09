#include <iostream>
#include <string>
#include <set>

#define N 128

using namespace std;

struct TrieNode{
 	TrieNode *children[N];
	bool isLeaf;
    set<string> docsPath;   
};

TrieNode *getNode(void);

void addWordToTrie(TrieNode *root, string &word, string &docPath);

set<string> searchWordInTrie(TrieNode *root, string &word);
