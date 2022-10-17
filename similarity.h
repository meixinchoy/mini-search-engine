#include <iostream>
#include <string>
#include <unordered_set>
#include <map>

using namespace std;

unordered_set<string> getCommonWords(unordered_set<string> &allPaths);
map<string,int> vectoriseFile(string filePath, unordered_set<string> &commonWords);
map<string,int> vectoriseQuery(string query, unordered_set<string> &commonWords);
double getCosim(map<string, int> vec1, map<string,int> vec2);


