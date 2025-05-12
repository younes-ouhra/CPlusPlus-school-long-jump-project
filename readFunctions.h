#ifndef READFUNCTIONS_H
#define READFUNCTIONS_H

#include <iostream>
#include "purgeString.h"
#include "student.h"

using namespace std;

string fileName = "Schuelerdaten.txt";

int countTheNumberofStudents()
{
    fstream source(fileName);
    string word = "";

    int counter = 0;
    while (source >> word)
    {
        purgeString(word);
        if(word == "Schueler")       {counter++;}
    }
    return counter;
}

void fillTheArray(Student** arr, int size)
{
    for(int i = 0; i < size; i++)
        {arr[i] = nullptr;}
    
    fstream source(fileName);
    string word = "";
    string firstname = "";
    string lastname = "";
    string birthday = "";
    string firstJump = "";
    string secondJump = "";

    int i = 0;
    while (source >> word)
    {
        purgeString(word);
        if(word == "Schueler")
        {
            source >> firstname;
            source >> lastname;
            source >> birthday;
            source >> firstJump;
            source >> secondJump;
            double fj = replaceCommaWithPoint(firstJump);
            double sj = replaceCommaWithPoint(secondJump);
            arr[i] = new Student(firstname, lastname, birthday, fj, sj);
            i++;
        }
    }
}

#endif