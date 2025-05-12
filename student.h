#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED

#include <string>
using namespace std;

class Student
{
    private:
        string firstName;
        string lastName;
        string birthday;
        double jumpDistance1;
        double jumpDistance2;
        int note;
    
    public:
        Student(string firstName, string lastName, string birthday, double jumpDistance1, double jumpDistance2);
        void setJumpDistance1(double jumpDistance1);
        void setJumpDistance2(double jumpDistance2);
        string getFirstName() const;
        string getLastName() const;
        string getBirthday() const;
        double getJumpDistance1() const;
        double getJumpDistance2() const;
        int& getNote();
        void countTheNote(int& note1, int& note2);
        //void print() const;
};

std::ostream& operator << (std::ostream& out, const Student& obj);
#endif