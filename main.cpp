#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <filesystem>
#include <ctime>
#include "searchEngine.h"
namespace fs = std::filesystem;

using namespace std;

void showHelp();
void indexFile(SearchEngine &searchEngine, string filePath);

int main(int argc, char *argv[])
{
    SearchEngine searchEngine;

    // Store command line arguments
    vector<string> args;
    for (int i = 1; i < argc; i++){
        args.insert(args.end(), string(argv[i]));
    }

    bool showHelpFlag = false;
    bool isPathDir = false;

    vector<string>::iterator it;
    for(it=args.begin();it!=args.end();it++){
        if(*it == "--help"){
            showHelpFlag=true;
        }else if(*it == "--dir"){
            isPathDir=true;
        }else{
            if(isPathDir == true){
                for(const auto &file: fs::directory_iterator(*it)){
                    indexFile(searchEngine, file.path().string());
                }
            }else{
                indexFile(searchEngine, *it);
            }
        }
    }

    if(showHelpFlag){
        showHelp();
    }

    cout<< "\nstarting mini search engine... Enter '.' to quit\n\n";

    while(1){
        cout << "[mini search engine]: ";
        string q;
        getline(cin, q);
        if (q == ".")
            break;

        set<string> allPaths = searchEngine.getPaths(q);

        map<string,double> similarityScores = searchEngine.similarity(q, allPaths);

        searchEngine.showFiles(similarityScores);
    }

    return 0;
}

void showHelp()
{
    cout << "\n\nMini Search Engine\n"<<
            "to launch:\n\t './search-engine.exe <params> <filepath(s)>'"<<
            "\nparams: \n\t--help: show help menu\n\t --dir: index all files in the directory\n"<<
            "filepath(s):\n\tinput all file/directory paths, separated by space\n\n";

}

void indexFile(SearchEngine &searchEngine, string filePath)
{
    clock_t start = clock();
    searchEngine.registerFile(filePath);
    cout << filePath << " indexed in: "<< (float)(clock()-start)/CLOCKS_PER_SEC << "second(s)\n";
}