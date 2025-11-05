#include <iostream>
#include <cstring>
#include <cctype>
#include "../include/string_processor.h"

using namespace std;

const int MAX_LENGTH = 1000;

bool isWordDelimiter(char c) {
    return c == ' ' || c == ',' || c == '.' || c == '!' || c == '?';
}

bool containsDigit(const char* start, const char* end) {
    for (const char* p = start; p < end; p++) {
        if (isdigit(*p)) {
            return true;
        }
    }
    return false;
}

void reverseWord(char* start, char* end) {
    while (start < end) {
        char temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

void processCharArray(char str[]) {
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
    
    cout << input << endl;
    
    processCharArray(input);
    
    cout <<  input  << endl;
    
    return 0;
}
