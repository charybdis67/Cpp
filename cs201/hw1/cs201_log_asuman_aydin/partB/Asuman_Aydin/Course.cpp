
#include <string>
#include <iostream>
#include "Course.h"

using namespace std;

        Course::Course()
        {

            courseId = 0;
            courseCredit = 0;
            courseGrade = " ";
        }
        Course::~Course()
        {

        }
        Course::Course(const Course &courseToCopy)
        {
            courseId = courseToCopy.courseId;
            courseCredit = courseToCopy.courseCredit;
            courseGrade = courseToCopy.courseGrade;
        }
        void Course:: operator=(const Course &right)
        {
            courseId = right.courseId;
            courseCredit = right.courseCredit;
            courseGrade = right.courseGrade;
        }
        int Course::getCourseId()
        {
            return courseId;
        }
        int Course::getCourseCredit()
        {
            return courseCredit;
        }
        string Course::getCourseGrade()
        {
            return courseGrade;
        }
        int Course::setCourseId(int courseId)
        {
            courseId = courseId;
        }
        int Course::setCourseCredit(int courseCredit)
        {
            courseCredit = courseCredit;
        }
        string Course:: setCourseGrade(string courseGrade)
        {
            courseGrade = courseGrade;
        }

