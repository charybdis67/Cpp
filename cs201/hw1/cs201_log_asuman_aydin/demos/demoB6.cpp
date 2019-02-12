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
	cout << "[Running] Add Student."<< endl;
	srs.addStudent(100, "StudentA");
	cout << "[Done] Add Student."<< endl;
	cout << "[Running] Add Course."<< endl;
	srs.addCourse(100, 1, "B-", 3);
	cout << "[Done] Add Course."<< endl;
	cout << "[Running] Add Course Again."<< endl;
	srs.addCourse(100, 1, "C", 4);
	cout << "[Done] Add Course Again."<< endl;
	cout << "[Running] Calculate Course GPA."<< endl;
	double courseGrade = srs.calculateCourseGPA(1);
	cout << "[Done] Calculate Course GPA."<< endl;
	bool a = compareGrade(2.7, courseGrade);
	cout << "Course (Expected): " << 2.7 << endl;
	cout << "Course (Found)   : " << courseGrade << endl;
	cout << "Demo result is :" << bool2string(a) << endl;
	cout << "---------------------"<< endl;
	cout << "[Done] Demo." << endl;
	return a;
}
