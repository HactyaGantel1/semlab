#include <iostream>
#include <cstring>
#include <cctype>
#include "../include/string_processor.h"

using namespace std;

const int MAX_LENGTH = 1000;

void processCString(char* str) {
    char* current = str;
    
    while (*current) {
        while (*current && isWordDelimiter(*current)) {
            current++;
        }
        
        if (!*current) break;
        char* wordStart = current;
        while (*current && !isWordDelimiter(*current)) {
            current++;
        }
        char* wordEnd = current - 1;
        
        int letterCount = 0;
        bool hasDigit = false;
for (char* p = wordStart; p <= wordEnd; p++) {
            if (isalpha(*p)) {
                letterCount++;
            }
            if (isdigit(*p)) {
                hasDigit = true;
            }
        }
        
        if (letterCount % 2 == 0 && hasDigit) {
            reverseWord(wordStart, wordEnd);
        }
    }
}

int main() {
    char input[MAX_LENGTH];
    cin.getline(input, MAX_LENGTH);
    
    cout << input  << endl;
    
    processCString(input);
    
    cout <<  input  << endl;
    
    return 0;
}
