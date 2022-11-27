#include "node.h"
#include <string>
#include <unordered_set>

#define N 128

using namespace std;

// Returns new trie node (initialized to NULLs)
TrieNode *getNode()
{
	TrieNode *pNode = new TrieNode;

	pNode->isLeaf = false;

	for (int i = 0; i < N; i++)
		pNode->children[i] = NULL;

	return pNode;
}

// Insert word into trie
void addWordToTrie(struct TrieNode *root, string &word, string &docPath)
{
	struct TrieNode *pCrawl = root;

    for(auto it=word.begin();it!=word.end();it++){
		int index = (int) *it;

		if (!pCrawl->children[index])
			pCrawl->children[index] = getNode();

		pCrawl = pCrawl->children[index];
	}

	// mark last node as leaf and save docs path
	pCrawl->isLeaf = true;
    pCrawl->docsPath.insert(docPath);
}

// search word in trie
unordered_set<string> searchWordInTrie(TrieNode *root, string &word)
{
	struct TrieNode *pCrawl = root;

	for(auto it=word.begin();it!=word.end();it++){
		int index = (int)*it;
		if (!pCrawl->children[index])
			return {};

		pCrawl = pCrawl->children[index];
	}

	if(pCrawl->isLeaf){
		return pCrawl->docsPath;
	}else{
		return {};
	}
}

// Driver
// int main()
// {
// 	// Input keys (use only 'a' through 'z'
// 	// and lower case)
// 	string keys[] = {"the", "a", "there",
// 					"answer", "any", "by",
// 					"bye", "their" };
// 	int n = sizeof(keys)/sizeof(keys[0]);

// 	struct TrieNode *root = getNode();

// 	// Construct trie
// 	for (int i = 0; i < n; i++)
// 		insert(root, keys[i]);

// 	// Search for different keys
// 	char output[][32] = {"Not present in trie", "Present in trie"};

// 	// Search for different keys
// 	cout<<"the"<<" --- "<<output[search(root, "the")]<<endl;
// 	cout<<"these"<<" --- "<<output[search(root, "these")]<<endl;
// 	cout<<"their"<<" --- "<<output[search(root, "their")]<<endl;
// 	cout<<"thaw"<<" --- "<<output[search(root, "thaw")]<<endl;
// 	return 0;
// }
