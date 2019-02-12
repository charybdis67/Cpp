
#include <string>
#include <iostream>
#include "SimpleStudent.h"


Student::Student(studentId , studentName )
{
}
Student::~Student()
{
}
Student::Student(const Student &studentToCopy)
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



