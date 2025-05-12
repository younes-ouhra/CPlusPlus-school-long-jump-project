#ifndef WRITEFUNCTIONS_H
#define WRITEFUNCTIONS_H

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include "student.h"

using namespace std;

string createDataString(Student* student, int note1, int note2)
{
    stringstream a_stream;
    a_stream << setiosflags(ios_base::left) << setw(15) << student->getFirstName();
    a_stream << setiosflags(ios_base::left) << setw(20) << student->getLastName() << "\t";
    a_stream << setiosflags(ios_base::left) << setw(20) << student->getBirthday();
    a_stream << setiosflags(ios_base::left) << setw(15) << (to_string(note1) + " / " + to_string(note2));
    a_stream << setiosflags(ios_base::left) << setw(15) << student->getNote();
    return a_stream.str();
}

void countNotesOfStudents(Student** arr, int size)
{
    ofstream myFile("Schuelernoten.txt");

    myFile << "\t\t\t\t\t\t\tDIE NOTEN:\n\n";
            
    myFile << left << setw(15) << "VORNAME";
    myFile << left << setw(20) << "NACHNAME";
    myFile << left << setw(20) << "GEBURTSDATUM";
    myFile << left << setw(15) << "1. / 2. NOTE";
    myFile << left << setw(15) << "FINALE NOTE";
    myFile << endl << endl;

    for(int i = 0; i < size; i++)
    {
        int firstNote = 0;
        int secondNote = 0;
        arr[i]->countTheNote(firstNote, secondNote);
        myFile << createDataString(arr[i], firstNote, secondNote) << endl;
    }

    myFile.close();
}

#endif