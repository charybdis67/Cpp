#ifndef __SIMPLE_STUDENT_H
#define __SIMPLE_STUDENT_H
#include <string>
#include <iostream>

using namespace std;

class Student {
    public:
        Student(const int sid = 0, const string sname = "")
        {
        	studentId = sid;
        	studentName = sname;
		}
        ~Student()
        {
        	cout<< "object has been deleted!" ;
		}
        Student(const Student &studentToCopy)
        {
        	studentId = studentToCopy.studentId;
        	studentName = studentToCopy.studentName;
			
		}
        void operator=(const Student &right)
        {
        	if(&right != this)
        	{
        		delete this;    
				  		
			}
        	cout<< "assignment operator is called";
		}
        int getStudentId()
        {
        	return studentId;
		}
        string getStudentName()
        {
        	return studentName;
		}
    private:
        int studentId;
        string studentName;
};

#endif
