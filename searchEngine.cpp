#include "searchEngine.h"
#include <fstream>
#include <iostream>
#include <string>
#include <unordered_set>
#include <map>

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

unordered_set<string> SearchEngine::getPaths(string &query){
    string currentWord="";
    unordered_set<string> allPaths;
    unordered_set<string> tmpPaths;
    
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

map<string,double> SearchEngine::similarity(string &query, unordered_set<string> &allPaths) {
    map<string,double> scores;

    unordered_set<string> commonWords = getCommonWords(allPaths);
    map<string, int> queryVector= vectoriseQuery(query, commonWords);

    map<string, int> fileVector;
    double cosim;
    for(auto it = allPaths.begin(); it!= allPaths.end(); it++){
        fileVector= vectoriseFile(*it, commonWords);
        cosim = getCosim(queryVector,fileVector);
        scores[*it]=cosim;
    }

    return scores;
}

void SearchEngine::showFiles(map<string,double> &simScores){

    if(simScores.size() == 0){
        cout << "\nno results found\n\n";
        return;
    }

    for(auto it=simScores.rbegin(); it!= simScores.rend(); it++){
        ifstream docfile(it->first);

        string previewText="";

        if (docfile.is_open()){
            // print file:
            while (previewText.size()<1000 && docfile.good()) {
                previewText += docfile.get();
            }

            if(docfile.good()){
                previewText += "...";
            }
        }

        cout << endl << it->first << " ["<< it->second << "] -  " << previewText << endl;
    }
    cout << endl << simScores.size() << " results found.\n\n"; 
}

