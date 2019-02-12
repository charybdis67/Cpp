
#include <string>
#include <iostream>

using namespace std;

#include "SimpleStudent.h"
#include "SimpleSRS.h"

Student:: Student(int studentId, string studentName)
{
  studentId = studentId;
  studentName = studentName;
}
Student::~Student()
{

}
Student:: Student(const Student &studentToCopy)
{
    studentId = studentToCopy.studentId;
    studentName = studentToCopy.studentName;
}
void Student:: operator=(const Student &right)
{
    studentId = right.studentId;
    studentName = right.studentName;
}
int Student:: getStudentId()
{
    return studentId;
}
string Student:: getStudentName()
{
    return studentName;
}
void Student:: setStudentId(int studentId)
{
    studentId = studentId;
}
void Student::setStudentName(string studentName)
{
    studentName = studentName;
}
