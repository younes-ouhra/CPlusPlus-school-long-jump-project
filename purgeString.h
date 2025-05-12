#ifndef PURGESTRING_H
#define PURGESTRING_H

#include <iostream>
using namespace std;

void purgeString(string& text)
{
    size_t result=0;
    while((result=text.find_first_not_of("abcdefghijklmnopqrstuvwxyz"
        "äöüß""ABCDEFGHILJKLMNOPQRSTUVWXYZ"
        "ÄÖÜ"))!=string::npos)
        {text.erase(result, 1);}
}

double replaceCommaWithPoint(string word)
{
    int found=word.find(',');
    if (found!=std::string::npos)
    {
        word.erase(found, 1);
        auto it = word.insert(word.begin() + found, '.');
    }
    
    return stod(word);
}

#endif