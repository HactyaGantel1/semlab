#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>
#include "../include/string_processor.h"

using namespace std;

const int MAX_LENGTH = 1000;

int main() {
    char input[MAX_LENGTH];
    FILE *inputFile, *outputFile;

    fclose(inputFile);
    
    int len = strlen(input);
    if (len > 0 && input[len - 1] == '\n') {
        input[len - 1] = '\0';
    }
    
    cout << input << endl;
    
  
    processCharArray(input);
    
   
    outputFile = fopen("../data/output.txt", "w");
   
    
    fputs(input, outputFile);
    fclose(outputFile);
    
    cout  << input  << endl;
    
    return 0;
}
