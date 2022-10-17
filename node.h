#include <iostream>
#include <string>
#include <unordered_set>

#define N 128

using namespace std;

struct TrieNode{
 	TrieNode *children[N];
	bool isLeaf;
    unordered_set<string> docsPath;   
};

TrieNode *getNode(void);

void addWordToTrie(TrieNode *root, string &word, string &docPath);

unordered_set<string> searchWordInTrie(TrieNode *root, string &word);
