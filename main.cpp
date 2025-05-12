#include <iostream>
#include <fstream>
#include "purgeString.h"
#include "readFunctions.h"
#include "writeFunctions.h"
#include "student.h"
#include "student.cpp"

int main()
{
    int numberOfStudents = countTheNumberofStudents();
    Student** students = new Student*[numberOfStudents];
    fillTheArray(students, numberOfStudents);
    countNotesOfStudents(students, numberOfStudents);
    delete students;
}