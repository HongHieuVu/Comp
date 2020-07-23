#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int countH = 0, stop = 0;

node::node (node* left, node* right) : lNode(left), rNode(right) {
        freq = left->freq + right->freq;
        right->urNode = this;
        // right->ulNode = NULL;
        left->ulNode = this;
        // left->urNode = NULL;
    }
node::node (int charPos) : data(charMap[charPos]), freq(timesSeen[charPos]) {
        lNode = NULL;
        rNode = NULL;
        isLeaf = true;
    }

int lastNodePos;

void generateTree(){
    node* tmpNode = NULL;
    int treeDepth = charMap.size();
    for(int i = 0; i<treeDepth; i++){
        node* pnew = new node(i);
        huffmanTree.push_back(pnew);
        leafs.push_back(pnew);
    }
    // printTreeVtr();
    // logTree(huffmanTree.size());
    for(int i = huffmanTree.size()-1; i>0; i--){
        //branching
        node* pnew = new node(huffmanTree[i], huffmanTree[i-1]);
        //erasing - do not delete pop_back allocated memory
        huffmanTree.pop_back();
        huffmanTree.pop_back();
            // logTree(i);
        //appending
        huffmanTree.push_back(pnew);
            // logTree(i);
        //floating
        lastNodePos = i-1;
        for(int j = lastNodePos; j>0; j--){
            //the newly appended node floats to its position based on frequency
            if(huffmanTree[j-1]->freq >= huffmanTree[j]->freq) break;
            else {
                tmpNode = huffmanTree[j-1];
                huffmanTree[j-1] = huffmanTree[j];
                huffmanTree[j] = tmpNode;
            }
                // logTree(j);
        }
            // logTree(i);
    }
        // printTreeVtr();
        // exploreNodes(huffmanTree[0], "highest node: ");
        // exploreNodes(huffmanTree[0]->lNode, "1st l node: ");
        // exploreNodes(huffmanTree[0]->rNode, "1st r node:");
}

void initHuffmanCodeVtr(){
    vector <rl> newLine(0);

    int size = charMap.size();
    int estimatedTreeDepth = (int) 2*sqrt(size)+1;
    newLine.reserve(estimatedTreeDepth);
    huffmanCode.reserve(size);

    for(int i = 0; i<size; i++){
        huffmanCode.push_back(newLine);
    }

    leafs.reserve(size);
}

void generateHuffmanCode(){
    for(int c = leafs.size()-1; c>=0; c--){
        node* curr = leafs[c];
        // int currDepth = 0;
        while (curr->ulNode != NULL || curr->urNode != NULL){
            if(curr->urNode != NULL){
                // cout << "at: " << c << " depth: " << currDepth << " going right" << endl;
                huffmanCode[c].push_back(rl::left);
                curr = curr->urNode;
            } else if(curr->ulNode != NULL){
                // cout << "at: " << c << " depth: " << currDepth << " going right" << endl;
                huffmanCode[c].push_back(rl::right);
                curr = curr->ulNode;
            }
            // currDepth ++;
        }
    }
    //reverse the order
    rl tmp;
    for(int c = leafs.size()-1; c>=0; c--){
        int charCodeDepth = huffmanCode[c].size();
        for(int i = charCodeDepth-1, j = 0; i>=(int) charCodeDepth/2; i--,j++){
            tmp = huffmanCode[c][i];
            huffmanCode[c][i] = huffmanCode[c][j];
            huffmanCode[c][j] = tmp;
        }
    }
    //arrange the code

}



// void transferTrace(int curDepth,int atCharNo, rl lastTurnWas){
//     int transferStop = huffmanCode[atCharNo].size();
//     huffmanCode[atCharNo+1].reserve(transferStop+1);
//     // huffmanCode[atCharNo+1] = huffmanCode[atCharNo];
//     for(int i = 0; i<transferStop; i++){
//         huffmanCode[atCharNo+1][i] = huffmanCode[atCharNo][i];
//     }
//     //fix the last char
//     if(lastTurnWas == rl::left){
//         huffmanCode[atCharNo+1][transferStop] = rl::right;
//     } else {
//         huffmanCode[atCharNo+1][transferStop] = rl::left;
//     }
// }

//Huffman code is better to encrypt, and huffman tree is better to decrypt, so we would need a function to store the tree, and also the code to our output file.
// int depth = 1;
// bool generateHuffmanCode(node* inputNode){
//         // cout << charChounter << endl;
//     if(inputNode->isLeaf == true){
//         charChounter++;
//         charMap[charChounter] = inputNode->data;
//         return 0;
//     } else {
//             // cout << "went left" << endl;
//             // cout << "freq of left node: " << (inputNode->lNode)->freq << endl;
//         huffmanCode[charChounter].push_back(rl::left);
//         depth++;
//         generateHuffmanCode(inputNode->lNode);
//             // cout << "jumped back and now at char: " << charChounter << endl;
//         transferTrace(depth, charChounter, rl::left);
//             // cout << "reached here after transfering" << endl;

//             // cout << "went right" << endl;
//             // cout << "freq of right node: " << (inputNode->rNode)->freq << endl;
//         huffmanCode[charChounter].push_back(rl::right);
//         depth++;
//         generateHuffmanCode(inputNode->rNode);
//             // cout << "jumped back and now at char: " << charChounter << endl;
//         transferTrace(depth, charChounter, rl::right);
//             // cout << "reached here after transfering" << endl;
//         //how do you know which piece of huffmancode is for which letter?
//         // trying not to use end of code char as I only want to use bool
//         //solution found: use 2D vector
//         //now how do we know when to switch vector? The problem recursed.
//     }
// }
