#include "student.h"
#include <iostream>
#include <iomanip>

Student::Student(string firstName, string lastName, string birthday, double jumpDistance1, double jumpDistance2)
{
    this->firstName = firstName;
    this->lastName = lastName;
    this->birthday = birthday;
    this->jumpDistance1 = jumpDistance1;
    this->jumpDistance2 = jumpDistance2;
}

void Student::setJumpDistance1(double jumpDistance1)
    {this->jumpDistance1 = jumpDistance1;}

void Student::setJumpDistance2(double jumpDistance2)
    {this->jumpDistance2 = jumpDistance2;}

string Student::getFirstName() const        {return firstName;}

string Student::getLastName() const         {return lastName;}

string Student::getBirthday() const         {return birthday;}

double Student::getJumpDistance1() const
    {return jumpDistance1;}

double Student::getJumpDistance2() const
    {return jumpDistance2;}

int& Student::getNote()
    {return note;}

void Student::countTheNote(int& note1, int& note2)
{
    note1 = 0;

    if(jumpDistance1 >= 5)                                                  {note1 = 1;}
    
    else if(jumpDistance1 >= 4.50 && jumpDistance1 <= 4.99)                 {note1 = 2;}
        
    else if(jumpDistance1 >= 4.00 && jumpDistance1 <= 4.49)                 {note1 = 3;}
        
    else if(jumpDistance1 >= 3.50 && jumpDistance1 <= 3.99)                 {note1 = 4;}
        
    else if(jumpDistance1 >= 3.00 && jumpDistance1 <= 3.49)                 {note1 = 5;}
        
    else if (jumpDistance1 < 3.00)                                          {note1 = 6;}
    
    note2 = 6;
    
    if(jumpDistance2 > jumpDistance1)
    {
        double improvement = (jumpDistance2 - jumpDistance1) * 100;

        if(improvement >  50.00)                                                {note2 = 1;}
    
        else if(improvement > 40.00 && improvement <= 50.00)                    {note2 = 2;}
        
        else if(improvement > 30.00 && improvement <= 40.00)                    {note2 = 3;}
        
        else if(improvement > 20.00 && improvement <= 30.00)                    {note2 = 4;}

        else if(improvement > 10.00 && improvement <= 20.00)                    {note2 = 5;}
        
        else if(improvement >= 10.00)                                           {note2 = 6;}
    
        if(note2 <= note1)              {note = note2;}
        else if(note2 >= note1)         {note = note1;}
    }

    else if(jumpDistance2 <= jumpDistance1)
    {
        note = note1;
    }
}
/*
void Student::print() const
{
    cout << "Student\t";
    cout << left << setw(10) << this->getFirstName();
    cout << left << setw(10) << this->getLastName();
    cout << right << setw(15) << this->getBirthday(); 
}
*/


std::ostream& operator << (std::ostream& out, const Student& obj)
{
    cout << left << setw(15) << obj.getFirstName();
    cout << left << setw(10) << obj.getLastName();
    cout << right << setw(15) << obj.getBirthday(); 
    return out;
}