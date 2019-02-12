#include "SRS.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
struct CourseGrade{
	int courseId;
	double expectedGrade;
	double foundGrade;
	CourseGrade(int courseId_, double expectedGrade_) : courseId(courseId_), expectedGrade(expectedGrade_) {}
};
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
	cout << "[Done] Add Students."<< endl;
	cout << "[Running] Add Courses."<< endl;
	srs.addCourse(200, 1, "C", 2);
	srs.addCourse(300, 3, "A", 4);
	srs.addCourse(100, 1, "B-", 2);
	srs.addCourse(200, 2, "D", 3);
	cout << "[Done] Add Courses."<< endl;
	cout << "[Running] Remove Course."<< endl;
	srs.removeStudent(200);
	cout << "[Done] Remove Course."<< endl;
	cout << "[Running] Calculate Course GPA."<< endl;
	bool result = true;
	vector<CourseGrade> grades;
	grades.push_back(CourseGrade(1, 2.7));
	grades.push_back(CourseGrade(2, 0.0));
	grades.push_back(CourseGrade(3, 4.0));
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
