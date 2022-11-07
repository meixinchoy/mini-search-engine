#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <filesystem>
#include <sstream>  
#include <iterator>
namespace fs = std::filesystem;

using namespace std;

void split_str( std::string const &str, const char delim,  
std::vector <std::string> &out )  
{  
    // create a stream from the string  
    std::stringstream s(str);  
        
    std::string s2;  
    while (std:: getline (s, s2, delim) )  
    {  
        out.push_back(s2); // store the string in s2  
    }  
}  

void parse_dataset_into_webpages(const std::string& filename)
{
    std::vector<std::string> lines;
    std::ifstream input(filename);
    std::string line;
    int num = 0;
    while (std::getline(input, line))
    {
        if(num%50==0){
            ofstream f("webpage_"+to_string(num/50)+".txt");
            std::vector <std::string> out; // store the string in vector  
            split_str (line, ' ', out); // call function to split the string 

            std::ostringstream imploded;
            const char* const delim = " ";
            std::copy(out.begin()+1, out.end(),
            std::ostream_iterator<std::string>(imploded, delim)); // join string

            f << imploded.str();
        }
        num++;
    }
}