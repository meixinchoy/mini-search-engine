#ifndef SEARCHENGINE_H
#define SEARCHENGINE_H

#include "node.h"
#include "similarity.h"
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
        void showFiles(map<string,double> &allPaths);
        map<string,double> similarity(string &query, set<string> &allPaths);

};

#endif // SEARCHENGINE_H
