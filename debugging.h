#include <iostream> 
#include <string>
#include <vector>
#include <fstream>

using namespace std;
//pre-processing
void print(vector<content_element_type> content, string note){
    cout << "/*" << note << "*/" << endl;
    int length = content.size();
    for(int i = 0; i<length; i++){
        cout << content[i] << endl;
    }
}

void printCharMap(string note, string attribute){
    cout << "/*" << note << "*/" << endl;
    int length = charMap.size();
    for(int i = 0; i<length; i++){
        cout << i <<")  " << charMap[i] << attribute << timesSeen[i] <<  endl;
    }
}

void printCell(int n, int iter){
    if(iter == n) cout << n << ") " << charMap[n] << " seen " << timesSeen[n] << endl;
}

#define resetMapCharLog ofstream logFile("MapCharLog.txt", ios::trunc);logFile.close();

int logCharMap(int iter){
    ofstream logFile ("MapCharLog.txt", ios::app);
    logFile.seekp(0,ios::end);
    if(!logFile) {
        return 0;
    } else {
        logFile << "/*" << iter << "*/" << endl;
        int length = charMap.size();
        for(int i = 0; i<length; i++){
            logFile << i <<")  " << charMap[i] << " seen: " << timesSeen[i] <<  endl;
        }
    }
    logFile.close();
    return 0;
}

//huffman tree
void printTreeVtr(){
    int treeDepth = huffmanTree.size();
    for(int i = 0; i<treeDepth; i++){
        cout << "node: " << i << " : " << huffmanTree[i]->data << " freq: " << huffmanTree[i]->freq << endl;
    }
    cout << endl;
}

#define resetMapTreeLog ofstream logTreeFile("MapTreeLog.txt", ios::trunc);logFile.close();


int logTree(int iter){
    ofstream logTreeFile ("MapTreeLog.txt", ios::app);
    logTreeFile.seekp(0,ios::end);
    if(!logTreeFile) {
        return 0;
    } else {
        logTreeFile << "/*" << iter << "*/" << endl;
        int stop = huffmanTree.size()+1;
        for(int i = 0; i<stop; i++){
            if(i<huffmanTree.size())
                logTreeFile 
                << "node: " << i << " : " << huffmanTree[i]->data << " freq: " << huffmanTree[i]->freq << " is leaf: " << std::boolalpha << huffmanTree[i]->isLeaf << endl;
            else 
                logTreeFile << "trailing node:" << endl
                << "node: " << i << " : " << huffmanTree[i]->data << " freq: " << huffmanTree[i]->freq << " is leaf: " << std::boolalpha << huffmanTree[i]->isLeaf << endl; 
        }
    }
    logTreeFile << endl;
    logTreeFile.close();
    return 0;
}

void exploreNodes(node* input, string note){
    cout << note << endl;
    if(input->isLeaf == true) 
        cout << "node data: " << input->data
        << endl;
    else
        cout 
        << "freq: " << input->freq 
        << " l: " << (input->lNode)->freq 
        << " r: " << (input->rNode)->freq 
        << endl; 
    if((input->lNode)->isLeaf == true)
        cout << " l data: " << (input->lNode)->data 
        << endl;
    if((input->rNode)->isLeaf == true)
        cout << " r data: " << (input->rNode)->data 
        << endl;
}

void printHuffmanCode(string note){
    cout << " " << note << " " << endl;
    int codeDepth = charMap.size();
    for(int i = 0; i<codeDepth; i++){
        cout << i << ") " <<  "char: " << charMap[i] << " freq: " << leafs[i]->freq << " ";
        int charDepth = huffmanCode[i].size();
        for(int j = 0; j<charDepth; j++){
            if((huffmanCode[i])[j] == rl::left) cout << 1;
            else cout << 0;
        }
        cout << endl;
    }
    cout << endl;
}