// CSC252 Programming in C++
// Mark Langston    6/8/2024

#include <iostream>

/* Length function loops through string and increments variable c
   returns the total length of a C string or char array            */

int length(const char* str) {
    const char* c = str;
    while (*c != '\0') {
        ++c;
    }
    return c - str;
}

/* indexOf function returns the index or position in the char array
   or the first lowest index if multiple of the same char exist.     
   if the character does not exist, function returns -1             */
int indexof(const char* str, char ch) {
    const char* c = str;
    int index = 0;
    while (*c != '\0') {
        if (*c == ch) {
            return index;
        }
        ++c;
        ++index;
    }
    return -1;
}

/* Replace function replaces every occurence of a character in
   a string with the new replacement character                     */
char* replace(char* str, char oldChar, char newChar) {
    char* p = str;
    while (*p != '\0') {
        if (*p == oldChar) {
            *p = newChar;
        }
        ++p;
    }
    return str;
}

/* Concat function merges two strings into a single string
   aka concatenation                                                */
char* concat(const char* str1, const char* str2) {
    int len1 = length(str1);
    int len2 = length(str2);
    char* result = new char[len1 + len2 + 1];
    const char* p1 = str1;
    char* pResult = result;
    while (*p1 != '\0') {
        *pResult = *p1;
        ++p1;
        ++pResult;
    }
    const char* p2 = str2;
    while (*p2 != '\0') {
        *pResult = *p2;
        ++p2;
        ++pResult;
    }
    *pResult = '\0';
    return result;
}

int main() {
    // Program intro
    std::cout << "CSC 252 - Pointer Based Functions in C++" << std::endl << std::endl;

    // Tests for each of the functions:

    const char* testString = "This is a test string.";
    std::cout << std::endl;

    std::cout << "The length of the string:" << std::endl << testString << std::endl << 
        "is equal to: " << length(testString) << std::endl;

    char charIndex = 'a';
    std::cout << "The index of the letter " << charIndex << " is: " << indexof(testString, charIndex)
        << std::endl << std::endl;

    char concatString[] = " This is a second test string.";
    char oldChar = 's';
    char newChar = 'z';
    std::cout << "The second string is: " << concatString << std::endl;
    replace(concatString, oldChar, newChar);
    std::cout << "If we replace the letter s with z: " << concatString << std::endl << std::endl;

    const char* str1 = "This is a test string.";
    const char* str2 = " This is a second test string.";
    char* concatenatedStr = concat(str1, str2);
    std::cout << "If we concatenate the two strings we get: " << std::endl << concatenatedStr << std::endl;

    delete[] concatenatedStr;

    return 0;
}