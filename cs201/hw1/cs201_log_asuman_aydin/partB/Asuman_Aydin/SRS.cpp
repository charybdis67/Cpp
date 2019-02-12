
#include <string>
#include <iostream>
using namespace std;
#include "Student.h"
#include "Course.h"
#include "SRS.h"


    SRS::SRS()
	{
		students = new Student[studentNo];
	}
	 SRS::~SRS()
	{
		delete students;
	}
	 SRS::SRS(const SRS &srsToCopy)
	{
	    if(studentNo > 0){

		students = new Student[studentNo];
		students = srsToCopy.students;
	    }
	    else
        {
            students = NULL;
        }
	}
	void  SRS::operator=(const SRS &right)
	{
		if(studentNo > 0){

		students = new Student[studentNo];
		students = right.students;
	    }
	    else
        {
            students = NULL;
        }
	}
    int  SRS:: getStudents(Student *&allStudents)
 	{
 		int number = 0;
 		allStudents = new Student[studentNo];
 		for(int i = 0; i < studentNo; i++)
 		{
 			allStudents[i] = students[i];
 			number++;
		 }
		 return number;
	 }
       bool  SRS:: addStudent(const int studentId, const string studentName)
	{
	    Student *students2 = new Student[studentNo + 1];
		for(int i = 0; i < studentNo ; i++)
		{
			students2[i] = students[i];

		}
		(students2[studentNo]).setId( studentId);
		(students2[studentNo]).setName(studentName);

		students = students2;

        studentNo++;

		if(students2)
			delete []students2;
        //cout<< " successful";
        return true;
	}
       bool  SRS:: removeStudent(const int studentId)
	{
		int index = -1;
		if(studentNo <= 0)
        {
            return false;
        }
        else if(studentNo == 1)
        {
            if(students[0].getStudentId() == studentId)
            {
                students = NULL;
                studentNo--;
                return true;
            }
            return false;
        }
        else
        {
		Student *temp = new Student[studentNo-1];

		for(int i = 0; i < studentNo; i++)
		{
		    cout<< "ajsndl"<< endl;
		    cout << students[i].getStudentId() << endl;
		    cout << students[i].getStudentName() << endl;
			if(students[i].getStudentId() == studentId)
            {
                index = i;
                cout << "alksmd" << students[i].getStudentId();
            }
		}
		cout<< "index" << index << studentNo ;
		if(index < 0)
        {
            return false;
        }
		else if(index == 0)
        {
            for(int i = 1; i < studentNo; i++)
            {
                temp[i-1] = students[i];
                cout<< "warning";
            }
        }
		else
        {
            for(int i = 0; i < index ;i++)
            {
			temp[i] = students[i];
            }
            for(int i = index +1; i < studentNo; i++)
            {
                temp[i-1] = students[i];
            }
        }
		students = temp;
		studentNo--;

		if(temp)
		{
			delete []temp;
		}

		return true;
		}
	}

        bool SRS::addCourse(const int studentId, const int courseId, const string courseGrade, const int courseCredit)
        {

            string grades[14] = {"A+", "A", "A-", "B+", "B", "B-", "C+", "C", "C-", "D+", "D", "F", "FX", "FZ"};

            for(int i = 0; i < 14 ; i++)
            {
                if(grades[i] != courseGrade)
                {
                    return false;
                }
            }
            for(int i = 0; i < studentNo; i++)
            {
                Student temp = students[i];
                if(temp.getStudentId() == studentId)
                {
                    Course* temp2 = temp.getCourse();
                    for(int j = 0 ; j < temp.getCourseNo(); j++)
                    {
                        if(temp2[j].getCourseId() == courseId)
                        {
                            return false;
                        }

                    }
                    int courseNumber = temp.getCourseNo();
                    Course* temp3 = new Course[courseNumber +1];
                    for(int k = 0; k < courseNumber ; k++){
                        temp3[k] = temp2[k];
                    }
                    temp3[courseNumber].setCourseGrade(courseGrade);
                    temp3[courseNumber].setCourseCredit(courseCredit);
                    temp2 = temp3;
                    delete []temp3;

                    return true;
                }
            }
            return false;
        }
        bool  SRS:: removeCourse(const int studentId, const int courseId)
        {
            for(int i = 0; i < studentNo; i++)
            {
                Student *temp = students[i];
                if(temp.getStudentId() == studentId)
                {
                    Course* temp2 = temp.getCourse();
                    for(int j = 0 ; j < temp.getCourseNo(); j++)
                    {
                        if(temp2[j].getCourseId() == courseId)
                        {
                            return false;
                        }

                    }
                    int courseNumber = temp.getCourseNo();
                    Course* temp3 = new Course[courseNumber -1];
                    for(int k = 0; k < courseNumber -1 ; k++){
                        temp3[k] = temp2[k];
                    }
                    temp2 = temp3;
                    delete []temp3;

                    return true;
                }
            }
            return false;
        }
        double  SRS:: calculateCourseGPA(const int courseId)
        {
            string grades[12] = {"A+", "A", "A-", "B+", "B", "B-", "C+", "C", "C-", "D+", "D", "F"};
            double a = 0.0;
            double y = 0.0;
            double sumGrade = 0;
            double sumCredit = 0;
            string courseGrade = "";
            for(int i = 0; i < studentNo; i++)
            {
                Student temp = students[i];
                Course* temp2 = temp.getCourse();
                for(int j = 0 ; j < temp.getCourseNo(); j++)
                {
                    if(temp2[j].getCourseId() == courseId)
                    {
                        for(int k = 0; k < 12; k++){
                            courseGrade = temp2[j].getCourseGrade();
                            y   = temp2[j].getCourseCredit();
                    if(courseGrade != grades[k]){
                        cout<< "unvalid";
                    }
                    else{
                        switch(k){
                        case 0: a = 4.0; break;
                        case 1: a= 4.0; break;
                        case 2: a = 3.7; break;
                        case 3: a = 3.3; break;
                        case 4: a= 3.0 ;break;
                        case 5: a = 2.7; break;
                        case 6: a = 2.3; break;
                        case 7: a = 2.0; break;
                        case 8: a = 1.7; break;
                        case 9: a = 1.3; break;
                        case 10: a = 1.0; break;
                        case 11: a = 0.0; break;
                        default:  a = 0.0; break;
                    }
                        }
                        }
                    }

                    sumGrade = sumGrade + a*y;
                    sumCredit = sumCredit + y;
                }
                }



        double z = sumGrade/sumCredit;
         return z;
        }

