#include <fstream>
#include <iostream> 
#include <string>
#include <vector>

#define content_element_type string
#define freq_data_type int

#include "variables.h"
#include "documentProperties.h"
#include "debugging.h"
#include "pre-processing.h"
#include "HuffmanTree.h"

using namespace std;

inline void initVtrs(int size){
    charMap.reserve(size);
    timesSeen.reserve(size);
}

int main(){
    ifstream infile(R"(C:\Users\APC\CLionProjects\Comp\sample.txt)",ios::in);

    string line;
    vector<content_element_type> content;
    if(!infile){
        cerr << "Error in open file, please restart the program.";
        exit(1);
    } else {
        while(getline(infile, line)){
            content.push_back(line);
        }
    }

    initVtrs(content.size());
    // print(content,"test input");
    resetMapCharLog
    resetMapTreeLog
    mapCharAndSort(content);
    printCharactersCount();
    // printCharMap("char map:"," seen: ");
    generateTree();
    initHuffmanCodeVtr();
    generateHuffmanCode();
    printHuffmanCode("generated code: ");

    ofstream outfile("compressed.bin", ios::in);

    return 0;
}