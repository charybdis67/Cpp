#include "SimpleSRS.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
	cout << "[Running] Demo..." << endl;
	cout << "---------------------"<< endl;
	SRS srs;
	Student* students = nullptr;
	cout << "[Running] Add Students."<< endl;
	srs.addStudent(100, "StudentA");
	srs.addStudent(200, "StudentB");
	srs.addStudent(300, "StudentC");
	srs.addStudent(400, "StudentD");
	cout << "[Done] Add Students."<< endl;
	cout << "[Running] Remove Student (200)."<< endl;
	srs.removeStudent(200);
	cout << "[Done] Remove Student (200)."<< endl;
	cout << "[Running] Remove Student (400)."<< endl;
	srs.removeStudent(400);
	cout << "[Done] Remove Student (400)."<< endl;
	cout << "[Running] Get Students."<< endl;
	int n = srs.getStudents(students);
	cout << "[Done] Get Students."<< endl;
	int a = n == 2 && students[0].getStudentId() == 100 && students[0].getStudentName() == "StudentA"
	&& students[1].getStudentId() == 300 && students[1].getStudentName() == "StudentC";
	cout << "Student Size (Expected): " << 2 << endl;
	cout << "Student Size (Found)   : " << n << endl;
	cout << "Student 0 (Expected): " << 100 << ", " << "StudentA" << endl;
	cout << "Student 0 (Found)   : " << students[0].getStudentId() << ", " << students[0].getStudentName() << endl;
	cout << "Student 1 (Expected): " << 300 << ", " << "StudentC" << endl;
	cout << "Student 1 (Found)   : " << students[1].getStudentId() << ", " << students[1].getStudentName() << endl;
	if(students)
		delete[] students;
	cout << "---------------------"<< endl;
	cout << "[Done] Demo." << endl;
	return a;
}
