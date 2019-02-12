#ifndef __SIMPLE_SRS_H
#define __SIMPLE_SRS_H
#include <string>
#include <iostream>
using namespace std;
#include "SimpleStudent.h"

class SRS{
public:
	SRS()
	{
		students = new Student();
		studentNo = 0;
	}
	~SRS()
	{
		delete students;
	}
	SRS(const SRS &srsToCopy)
	{
		students = new Student();
		*students = *srsToCopy.students;
	}
	void operator=(const SRS &right)
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
	bool addStudent(const int studentId, const string studentName)
	{
		Student *students2 = new Student[studentNo];
		for(int i = 0; i < studentNo ; i++)
		{
			students2[i] = students[i];
			
		}
		studentNo++;
		students2[studentNo -1].getStudentId() = studentId;
		students2[studentNo -1].getStudentName() = studentName;
		Student *temp = students;
		students = students2;
		if(temp)
			delete []temp;
	}
	bool removeStudent(const int studentId)
	{
		int index = 0;
		Student *temp = new Student[studentNo-1];
		
		for(int i = 0; i < studentNo; i++)
		{
			if(students[i].getStudentId == studentId)
			{
				index = i;							
			}	
		}
		for(int i = 0; i < index ;i++)
		{
			temp[i ] = students[i];
		}
		for(i = index +1; i < studentNo; i++)
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
 	int getStudents(Student *&allStudents)
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
private:
	Student *students;
	int studentNo;
};
#endif
