#ifndef __SRS_H
#define __SRS_H
#include <string>
using namespace std;
#include "Student.h"
class SRS{
    public:
        SRS();
        ~SRS();
        SRS(const SRS &srsToCopy);
        void operator=(const SRS &right);

        int getStudents(Student *&allStudents);
        bool addStudent(const int studentId, const string studentName);
        bool removeStudent(const int studentId);
        bool addCourse(const int studentId, const int courseId,
        const string courseGrade, const int courseCredit);
        bool removeCourse(const int studentId, const int courseId);
        double calculateCourseGPA(const int courseId);
    private:
        Student *students;
        int studentNo;
};
#endif
