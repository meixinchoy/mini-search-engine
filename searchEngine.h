#ifndef SEARCHENGINE_H
#define SEARCHENGINE_H

#include "node.h"
#include "similarity.h"
#include <string>
#include <unordered_set>

class SearchEngine
{
    private:
        TrieNode *root;

    public:
        SearchEngine();
        void registerFile(string &docPath);
        unordered_set<string> getPaths(string &query);
        void showFiles(map<double,string> &allPaths);
        map<double,string> similarity(string &query, unordered_set<string> &allPaths);

};

#endif // SEARCHENGINE_H
