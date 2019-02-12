#include "SRS.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;
bool compareGrade(double grade1, double grade2){ return abs(grade1 - grade2) <= 0.001; }
string bool2string(bool b){ return b? "true" : "false"; }
int main(){
	cout << "[Running] Demo..." << endl;
	cout << "---------------------"<< endl;
	SRS srs;
	cout << "[Running] Add Students."<< endl;
	srs.addStudent(100, "StudentA");
	srs.addStudent(200, "StudentB");
	srs.addStudent(300, "StudentC");
	srs.addStudent(400, "StudentD");
	srs.addStudent(500, "StudentE");
	cout << "[Done] Add Students."<< endl;
	cout << "[Running] Add Courses."<< endl;
	srs.addCourse(200, 1, "W", 3);
	srs.addCourse(100, 1, "B-", 3);
	srs.addCourse(400, 1, "FZ", 3);
	srs.addCourse(300, 1, "FX", 3);
	srs.addCourse(500, 1, "B+", 3);
	cout << "[Done] Add Courses."<< endl;
	cout << "[Running] Calculate Course GPA."<< endl;
	double courseGrade = srs.calculateCourseGPA(1);
	cout << "[Done] Calculate Course GPA."<< endl;
	bool a = compareGrade(3.0, courseGrade);
	cout << "Course (Expected): " << 3.0 << endl;
	cout << "Course (Found)   : " << courseGrade << endl;
	cout << "Demo result is :" << bool2string(a) << endl;
	cout << "---------------------"<< endl;
	cout << "[Done] Demo." << endl;
	return a;
}
