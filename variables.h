// all global variables that are required to be accessible across all functions will be declared here

#include <vector>

using namespace std;

//pre-processing
vector <char> charMap;
vector <freq_data_type> timesSeen;
int count = 0;
char tmpChar; int tmpInt;

//huffman tree
class node{
public:
    freq_data_type freq = 0;
    char data = 0;
    bool isLeaf = false;
    node* lNode;    //left node
    node* rNode;    //right node
    node* ulNode = nullptr;     // upper left node
    node* urNode = nullptr;     // upper right node

    node (node* left, node* right);
    explicit node (int charPos);
    ~node()= default;;
};

vector <node*> huffmanTree;

enum class rl:bool {left = true, right = false} pathTrace;

/**
 * a vector to trace all leaf of this huffman tree
 */
vector <node*> leaf;

/**
 * stores Huffman code for each character
 */
vector<vector<rl>> huffmanCode(0,vector<rl> (0));

//this code is in reversed order
int charChounter = 0;