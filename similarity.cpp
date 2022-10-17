#include <map>
#include <fstream>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
#include <cmath>

using namespace std;

// split string into array or words
vector<string> splitString(string path){
        ifstream docfile(path);

        vector<string> res;
        string currentWord="";
        char ch;

        if (docfile.is_open()){
            while (docfile.good()) {
                ch = docfile.get();

                if(isspace(ch)||(int)ch<0){
                    if(currentWord.size()>0){
                        res.push_back(currentWord);
                        currentWord = "";
                    }
                }else{
                    currentWord += ch;
                }
            }
            res.push_back(currentWord);
        }
        docfile.close();

        return res;
}

// vectorise files by words
map<string,int> vectoriseFile(string filePath, unordered_set<string> &commonWords) {
    vector<string> words = splitString(filePath);
    map<string,int> fileVector;

    unordered_set<string>::iterator _it;
    for(_it = commonWords.begin(); _it!= commonWords.end(); _it++){
        fileVector[*_it]=0;
    }

    vector<string>::iterator it;
    for(it = words.begin(); it!= words.end(); it++){
        fileVector[*it]+=1;
    }

    return fileVector;
}

// vectorise query by words
map<string,int> vectoriseQuery(string query, unordered_set<string> &commonWords) {
    vector<string> words;
    string currentWord="";

    for (auto ch: query) {
        if(isspace(ch)||(int)ch<0){
            if(currentWord.size()>0){
                words.push_back(currentWord);
                currentWord = "";
            }
        }else{
            currentWord += ch;
        }
    }
    words.push_back(currentWord);

    map<string,int> queryVector;

    unordered_set<string>::iterator _it;
    for(_it = commonWords.begin(); _it!= commonWords.end(); _it++){
        queryVector[*_it]=0;
    }

    vector<string>::iterator it;
    for(it = words.begin(); it!= words.end(); it++){
        queryVector[*it]+=1;
    }

    return queryVector;
}

// get common words from all files
unordered_set<string> getCommonWords(unordered_set<string> &allPaths){
    unordered_set<string> commonWords;

    unordered_set<string>::iterator it;
    for(it=allPaths.begin(); it!= allPaths.end(); it++){
        vector<string> words = splitString(*it);

        commonWords.insert(words.begin(),words.end());
    }

    return commonWords;
}

// dotProduct
double getDotProduct(map<string, int> vec1, map<string,int> vec2){
    map<string,int>::iterator it;
    double dotProduct=0;

    for(it = vec1.begin(); it!=vec1.end();it++){
        dotProduct+= vec1[it->first]*vec2[it->first];
    }
    return dotProduct;
}

// magnitude
double getMagnitude(map<string, int> vec){
    map<string,int>::iterator it;
    double magnitude=0;

    for(it = vec.begin(); it!=vec.end();it++){
        magnitude+= pow(it->second,2);
    }

    return sqrt(magnitude);
}

double getCosim(map<string, int> vec1, map<string,int> vec2){
    return getDotProduct(vec1,vec2)/ (getMagnitude(vec1)*getMagnitude(vec2));
}