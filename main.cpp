#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <ctime>
#include "searchEngine.h"

using namespace std;

void showHelp();

int main(int argc, char *argv[])
{
    SearchEngine searchEngine;

    // Store command line arguments
    vector<string> args;
    for (int i = 1; i < argc; i++){
        args.insert(args.end(), string(argv[i]));
    }

    bool showHelpFlag = false;

    vector<string>::iterator it;
    for(it=args.begin();it!=args.end();it++){
        if(*it == "--help"){
            showHelpFlag=true;
        }else{
            clock_t start = clock();
            searchEngine.registerFile(*it);
            cout << *it << " indexed in: "<< (float)(clock()-start)/CLOCKS_PER_SEC << "second(s)\n";
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

        searchEngine.showFiles(allPaths);
    }

    return 0;
}

void showHelp()
{
    cout << "\n\nhelp menu\n\n";

}
