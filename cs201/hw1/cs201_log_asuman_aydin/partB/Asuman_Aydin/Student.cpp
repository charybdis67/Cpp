
#include <string>
#include <iostream>
using namespace std;
#include "Course.h"
#include "Student.h"
#include "SRS.h"
        Student::Student(const int sid, const string sname )
        {
            studentId = sid;
            studentName = sname;
            courses = new Course[courseNo];

        }
        Student::~Student()
        {
            delete courses;
        }
        Student::Student(const Student &studentToCopy)
        {
            studentId = studentToCopy.studentId;
            studentName = studentToCopy.studentName;
            if(courseNo > 0){
                courses = new Course[courseNo];
                for(int i = 0; i < courseNo; i++)
                {
                    courses[i] = studentToCopy.courses[i];
                }
            }
            else{
                courses = NULL;
            }
        }
       void  Student:: operator=(const Student &right)
        {
            studentId = right.studentId;
            studentName = right.studentName;
            if(courseNo > 0){
                courses = new Course[courseNo];
                for(int i = 0; i < courseNo; i++)
                {
                    courses[i] = right.courses[i];
                }
            }
            else{
                courses = NULL;
            }

        }
        int Student:: getStudentId()
        {
            return studentId;
        }
        string Student:: getStudentName()
        {
            return studentName;
        }
        int Student:: getCourseNo()
        {
            return courseNo;
        }
        void Student:: setId(int studentId)
        {
            studentId = studentId;
        }
        void Student:: setName(string studentName)
        {
            studentName = studentName;
        }
        Course* Student:: getCourse()
        {
            return courses;
        }
        double  Student::calculateStudentCurrentGPA()
        {
            string grades[12] = {"A+", "A", "A-", "B+", "B", "B-", "C+", "C", "C-", "D+", "D", "F"};
            double a = 0.0;
            double y = 0.0;
            double sumGrade = 0;
            double sumCredit = 0;
            string courseGrade = "";
            for(int i = 0; i < courseNo; i++)
            {
                for(int k = 0; k < 12; k++){
                    courseGrade = courses[i].getCourseGrade();
                    y   = courses[i].getCourseCredit();
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

                    sumGrade = sumGrade + a*y;
                    sumCredit = sumCredit + y;
                    }
                }

        double z = sumGrade/sumCredit;
        return z;
        }





