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
	cout << "[Running] Add Student."<< endl;
	srs.addStudent(100, "StudentA");
	cout << "[Done] Add Student."<< endl;
	cout << "[Running] Get Students."<< endl;
	int n = srs.getStudents(students);
	cout << "[Done] Get Students."<< endl;
	bool a = n == 1 && students[0].getStudentId() == 100 && students[0].getStudentName() == "StudentA";
	cout << "Student Size (Expected): " << 1 << endl;
	cout << "Student Size (Found)   : " << n << endl;
	cout << "Student 0 (Expected): " << 100 << ", " << "StudentA" << endl;
	cout << "Student 0 (Found)   : " << students[0].getStudentId() << ", " << students[0].getStudentName() << endl;
	cout << "---------------------"<< endl;
	cout << "[Done] Demo." << endl;
	return a;
}
