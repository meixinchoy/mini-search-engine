#ifndef SEARCHENGINE_H
#define SEARCHENGINE_H

#include "node.h"
#include <string>
#include <set>

class SearchEngine
{
    private:
        TrieNode *root;

    public:
        SearchEngine();
        void registerFile(string &docPath);
        set<string> getPaths(string &query);
        void showFiles(set<string> &allPaths);
};

#endif // SEARCHENGINE_H
