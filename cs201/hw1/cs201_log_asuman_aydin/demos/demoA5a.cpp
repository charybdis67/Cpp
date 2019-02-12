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
	cout << "[Done] Add Students."<< endl;
	cout << "[Running] Remove Student (100)."<< endl;
	srs.removeStudent(100);
	cout << "[Done] Remove Student (100)."<< endl;
	cout << "[Running] Get Students."<< endl;
	int n = srs.getStudents(students);
	cout << "[Done] Get Students."<< endl;
	int a = n == 1 && students[0].getStudentId() == 200 && students[0].getStudentName() == "StudentB";
	cout << "Student Size (Expected): " << 1 << endl;
	cout << "Student Size (Found)   : " << n << endl;
	cout << "Student 0 (Expected): " << 200 << ", " << "StudentB" << endl;
	cout << "Student 0 (Found)   : " << students[0].getStudentId() << ", " << students[0].getStudentName() << endl;
	cout << "---------------------"<< endl;
	cout << "[Done] Demo." << endl;
	return a;
}
