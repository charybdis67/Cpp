#ifndef __COURSE_H
#define __COURSE_H
#include <string>
using namespace std;
class Course{
    public:
        Course();
        ~Course();
        Course(const Course &courseToCopy);
        void operator=(const Course &right);
        int getCourseId();
        int getCourseCredit();
        string getCourseGrade();
        int setCourseId(int courseId);
        int setCourseCredit(int courseCredit);
        string setCourseGrade(string courseGrade);

    private:
        int courseId;
        int courseCredit;
        string courseGrade;
};
#endif
