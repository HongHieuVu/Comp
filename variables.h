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
    node* lNode;
    node* rNode;
    node* ulNode = NULL;
    node* urNode = NULL;

    node (node* left, node* right);
    node (int charPos);
    ~node(){};
};

vector <node*> huffmanTree(0);

enum class rl:bool {left = true, right = false} pathTrace;

vector <node*> leafs(0);
vector<vector<rl>> huffmanCode(0,vector<rl> (0));
//this code is in reversed order
int charChounter = 0;