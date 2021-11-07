//include all pre-processing procedures
#include <iostream>
#include <vector>

using namespace std;

/**
 * checks for duplication of characters, and sort it at the same time, but never runs on the first character
 * @param input
 * @return
 */
bool checkDuplicateAndSort(char input){
    for(int i = 0; i<charMap.size(); i++){
        if(input != charMap[i])continue;

        //if a duplication is found
        timesSeen[i] ++;
        for(int j = i; j>0; j--){

            //a type of bubble sort, but exploit the fact that we only increment one element by one at a time.
            if(timesSeen[j-1] >= timesSeen[j]) break;
            else {
                //swaps char
                tmpChar = charMap[j-1];
                charMap[j-1] = charMap[j];
                charMap[j] = tmpChar;

                //swaps times seen log
                tmpInt = timesSeen[j-1];
                timesSeen[j-1] = timesSeen[j];
                timesSeen[j] = tmpInt;
            }
        }
        return true;
    }
    return false;
}

void mapCharAndSort(vector<content_element_type> content){
    int content_length = content.size();

    //for first line, so that we dont have to check for first line in every iteration in the duplication function
    charMap.push_back((content[0])[0]);
    timesSeen.push_back(1);
    int firstLineLength = content[0].length();
    for(int c = 1; c<firstLineLength; c++){
        if(!checkDuplicateAndSort((content[0])[c])){
            charMap.push_back((content[0])[c]);
            timesSeen.push_back(1);
        }
        logCharMap(c);
    }

    //for subsequent lines
    for(int line = 1; line<content_length; line++){
        int linesLength = content[line].length();
        for(int c = 0; c < linesLength; c++){
            if(!checkDuplicateAndSort((content[line])[c])){
                charMap.push_back((content[line])[c]);
                timesSeen.push_back(1);
            }
            logCharMap(c);
        }
    }
}

//trivial functions
bool checkDuplicate(char input){
    //this function checks for duplication of characters, and sort it at the same time, but never runs on the first character
    for(int i = 0; i<charMap.size(); i++){
        if(input == charMap[i]) {
            timesSeen[i] ++;
            return true;
        }
    }
    return false;
}

void mapChar(vector<content_element_type> content){
    int content_length = content.size();
    //for first line, so that we dont have to check for firt line in every iteration in the duplication function
    charMap.push_back((content[0])[0]);
    timesSeen.push_back(1);
    int firstLineLength = content[0].length();
    for(int c = 1; c<firstLineLength; c++){
        if(!checkDuplicate((content[0])[c])){
            charMap.push_back((content[0])[c]);
            timesSeen.push_back(1);
        }
    }
    //for subsequent lines
    for(int line = 1; line<content_length; line++){
        int subLinesLength = content[line].length();
        for(int c = 0; c<subLinesLength; c++){
            if(!checkDuplicate((content[line])[c])){
                charMap.push_back((content[line])[c]);
                timesSeen.push_back(1);
            }
        }
    }
}