
#include <string>
#include <iostream>
using namespace std;
#include "SimpleStudent.h"
#include "SimpleSRS.h"

SRS::SRS()
{
    students = new Student();
    studentNo = 0;
}
SRS::	~SRS()
{
    if(students)
        delete students;
}
SRS::SRS(const SRS &srsToCopy)
{
    students = new Student();
    *students = *srsToCopy.students;
}
void  SRS::operator=(const SRS &right)
{
    if(&right !=  this)
    {
        if(studentNo != right.studentNo)
        {
            if(studentNo > 0)
                delete students;
            studentNo = right.studentNo;
            if(studentNo > 0)
            {
                students = new Student();
            }
            else
            {
                students = NULL;
            }
            for(int i = 0; i < studentNo; i++)
            {
                students[i] = right.students[i];
            }
        }
    }
}
bool SRS:: addStudent(const int studentId, const string studentName)
{
    bool state = false;
    Student *students2 = new Student[studentNo];
    for(int i = 0; i < studentNo ; i++)
    {
        students2[i] = students[i];

    }
    if(students)
    {
        delete  []students;
    }
    studentNo++;
    students2[studentNo-1].setStudentId(studentId);
    students2[studentNo -1].setStudentName(studentName);

    students =  new Student[studentNo];
    for(int i = 0; i < studentNo ; i++)
    {
        students[i] = students2[i];
        state = true;
    }
    if(students2)
        delete students2;

    return state;

}
bool SRS:: removeStudent(const int studentId)
{
    int index = 0;
    Student *temp = new Student[studentNo-1];

    for(int i = 0; i < studentNo; i++)
    {
        if(students[i].getStudentId() == studentId)
        {
            index = i;
        }
    }
    for(int i = 0; i < index ; i++)
    {
        temp[i ] = students[i];
    }
    for(int i = index +1; i < studentNo; i++)
    {
        temp[i] = students[i-1];
    }
    studentNo--;
    students = temp;
    if(temp)
    {
        delete []temp;
    }
}
int SRS:: getStudents(Student *&allStudents)
{
    allStudents = new Student[studentNo];
    for(int i = 0; i < studentNo; i++)
    {
        allStudents[i] = students[i];
    }
    int number;
    for(int i = 0; i < studentNo; i++)
    {
        if(allStudents[i].getStudentId() != NULL)
        {
            number++;
        }
    }

    delete []allStudents;
    return number;
}

