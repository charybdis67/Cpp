#include "SRS.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;
struct CourseGrade{
	int courseId;
	double expectedGrade;
	double foundGrade;
	CourseGrade(int courseId_, double expectedGrade_) : courseId(courseId_), expectedGrade(expectedGrade_) {}
};
bool compareGrade(double grade1, double grade2){ return abs(grade1 - grade2) <= 0.001; }
string bool2string(bool b){ return b? "true" : "false"; }
int main(){
	cout << "[Running] Demo..." << endl;
	cout << "---------------------"<< endl;
	SRS srs;
	cout << "[Running] Add Students."<< endl;
	srs.addStudent(300, "StudentA");
	srs.addStudent(100, "StudentB");
	srs.addStudent(400, "StudentC");
	srs.addStudent(200, "StudentD");
	cout << "[Done] Add Students."<< endl;
	cout << "[Running] Add Courses."<< endl;
	srs.addCourse(400, 3, "C", 4);
	srs.addCourse(100, 1, "B-", 3);
	srs.addCourse(100, 3, "C", 4);
	srs.addCourse(200, 2, "A", 2);
	srs.addCourse(200, 1, "B", 3);
	srs.addCourse(300, 1, "B+", 3);
	srs.addCourse(400, 2, "B", 2);
	cout << "[Done] Add Courses."<< endl;
	cout << "[Running] Calculate Course GPA."<< endl;
	bool result = true;
	vector<CourseGrade> grades;
	grades.push_back(CourseGrade(1, 3.0));
	grades.push_back(CourseGrade(2, 3.5));
	grades.push_back(CourseGrade(3, 2.0));
	grades.push_back(CourseGrade(4, 0.0));
	for(int i = 0; i < grades.size(); i++){
		grades.at(i).foundGrade = srs.calculateCourseGPA(grades.at(i).courseId);
	}
	cout << "[Done] Calculate Course GPA."<< endl;
	for(int i = 0; i < grades.size(); i++){
		cout << "Course " << grades.at(i).courseId << " (Expected): " << grades.at(i).expectedGrade << endl;
		cout << "Course " << grades.at(i).courseId << " (Found)   : " << grades.at(i).foundGrade << endl;
		result = result && compareGrade(grades.at(i).expectedGrade, grades.at(i).foundGrade);
	}
	cout << "Demo result is :" << bool2string(result) << endl;
	cout << "---------------------"<< endl;
	cout << "[Done] Demo." << endl;
	return result;
}
