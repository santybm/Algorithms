//
//  program4a.cpp
//  Homework1
//
//  Created by Santiago Beltran
//  Copyright © 2016 Santiago Beltran. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

long convertBinaryToLong(string binaryline);

int main(int argc, const char * argv[]) {
    // Recieve the input file. Check for no input file.
    ifstream file1;
    if (argc != 2){
        cout << "Error. Incorret Format : " << argv[0] << " <textfile>\n";
    }
    else{
        //try to open file
        file1.open(argv[1]);
        if (!file1)
        {
            cout << "Error opening file. Try again." << "\n";
            return -1;
        }
        //scan file
        string bline;
        long bsum = 0;
        
        /**
         * Program Logic: Get binary string line, convert binary to decimal,
         * add converted long decimal number to stored base sum value. print sum.
        ***/
        while ( getline(file1, bline)){
            char *end;
            //using strtol convvert string (char array) to decimal (base 2 convertion -- cplusplus ref.)
            long lbinary = strtol(bline.c_str(), &end, 2);
            bsum += lbinary;
            //bsum += convertBinaryToLong(bline);
        }
        file1.close();
        cout << bsum << "\n";
        
    }
    return 0;
}