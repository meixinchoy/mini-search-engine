#include <iostream>
#include <string>
#include <set>
#include <map>

using namespace std;

set<string> getCommonWords(set<string> &allPaths);
map<string,int> vectoriseFile(string filePath, set<string> &commonWords);
map<string,int> vectoriseQuery(string query, set<string> &commonWords);
double getCosim(map<string, int> vec1, map<string,int> vec2);


