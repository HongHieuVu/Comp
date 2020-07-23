#include <iostream>
#include <vector>

using namespace std;

void printCharactersCount(){
    int timesLength = timesSeen.size();
    int charCount = 0;
    for(int i = 0; i< timesLength; i++){
        count += timesSeen[i];
    }
    cout << "characters count: " << count << endl;
}