#include "searchEngine.h"
#include <fstream>
#include <iostream>
#include <string>
#include <set>
// #include <bits/stdc++.h>

using namespace std;

// CONSTRUCTOR
SearchEngine::SearchEngine(){
    root = getNode();
}

// ADD FILE CONTENT INTO TRIE
void SearchEngine::registerFile(string &docPath){
    // Open document
    ifstream docfile(docPath);

    string currentWord="";
    char ch;

    if (docfile.is_open()){
        // print file:
        while (docfile.good()) {
            ch = docfile.get();

            if(isspace(ch)||(int)ch<0){
                if(currentWord.size()>0){
                    addWordToTrie(this->root, currentWord, docPath);
                    currentWord = "";
                }
            }else{
                currentWord += ch;
            }
        }
        addWordToTrie(this->root, currentWord, docPath);
    }
    docfile.close();
}

set<string> SearchEngine::getPaths(string &query){
    string currentWord="";
    set<string> allPaths;
    set<string> tmpPaths;
    
    for (auto it= query.begin(); it!=query.end(); it++) {
        if(isspace(*it)||(int)*it<0){
            if(currentWord.size()>0){
                tmpPaths = searchWordInTrie(this->root, currentWord);
                allPaths.insert(tmpPaths.begin(), tmpPaths.end());
                currentWord = "";
            }
        }else{
            currentWord += *it;
        }
    }
    tmpPaths = searchWordInTrie(this->root, currentWord);
    allPaths.insert(tmpPaths.begin(), tmpPaths.end());

    return allPaths; 
}

void SearchEngine::showFiles(set<string> &allPaths){

    if(allPaths.size() == 0){
        cout << "\nno results found\n\n";
        return;
    }

    for(auto it=allPaths.begin(); it!= allPaths.end(); it++){
        ifstream docfile(*it);

        string previewText="";

        if (docfile.is_open()){
            // print file:
            while (previewText.size()<600 && docfile.good()) {
                previewText += docfile.get();
            }

            if(docfile.good()){
                previewText += "...";
            }
        }

        cout << endl << *it << "-  " << previewText << endl;
    }
    cout << endl << allPaths.size() << " results found.\n\n"; 
}

