#ifndef __STUDENT_H
#define __STUDENT_H
#include <string>
using namespace std;
#include "Course.h"
class Student{
    public:
        Student(const int sid = 0, const string sname = "");
        ~Student();
        Student(const Student &studentToCopy);
        void operator=(const Student &right);
        int getStudentId();
        string getStudentName();
        double calculateStudentCurrentGPA();
        void setId(int studentID);
        void setName(string studentname);
        int getCourseNo();
        Course* getCourse();
    private:
        int studentId;
        string studentName;
        Course *courses;
        int courseNo;
};
#endif
