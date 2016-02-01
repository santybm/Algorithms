//
//  Problem4b.cpp
//  Homework1
//
//  Created by Santiago Beltran
//  Copyright © 2016 Santiago Beltran. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <map>
using namespace std;

string Analyze(string str, int size);

int main(int argc, const char * argv[]) {
    
    //Check for correct number of arguments
    if (argc != 3){
        cout << "Error. Incorret Format : " << argv[0] << " <String> <Int>\n";
        return -1;
    }
    
    //store arguments accordingly. TEST TO BE IMPLEMENTED
    string analysisStr = argv[1];
    int analysisInt = stoi(argv[2]);
    
    if (analysisInt < 0 or analysisInt > 10){
        cout << "Error. Size not valid. Please enter a value between 0 and 10. \n";
        return -1;
    }
    cout << Analyze(analysisStr, analysisInt) << "\n";
    
    return 0;
}

string Analyze(string str, int size){
    //Return most frequently occuring string inside the "str" string of length "size".
    
    //If size is greater than the length of the string, return the full string.
    if (size > str.length()){
        return str;
    }
    
    //using substring go through each substring of size "size"
    int strplace = 0;
    int maxValue=0;
    string maxKey;
    
    //Using map as a frequency analysis hash table, store substrings to find the most common substring sized 'size'
    map<string, int> substringMap;
    
    while ((strplace + size) <= str.length()){
        string substring = str.substr(strplace, size);
        // TEST: cout << "(" << strplace << "," << size << ") : " << substring << "\n";
        //check if in map, if not add new key with substring and make count (value) 1. Else: add one to key's value.
        if (substringMap.find(substring) == substringMap.end())
        {
            substringMap[substring] = 1;
            if (maxValue < 1){
                maxValue = 1;
                maxKey = substring;
            }
            // TEST: cout << "map[" << substring << "]: " << substringMap[substring] << "\n";
        }
        else{
            int tempValue = ++substringMap[substring];
            if (maxValue < tempValue){
                maxValue = tempValue;
                maxKey = substring;
            }
            // TEST: cout << "map[" << substring << "]: " << substringMap[substring] << "\n";
        }
        strplace += 1;
    }
    
    //Cplusplus: Maps are sorted. Last value will be the highest key!.
    //Using the iterator rbegin, get the first value of the reversed map. Return the most frequently occuring substring.
    
    return maxKey;
    
}