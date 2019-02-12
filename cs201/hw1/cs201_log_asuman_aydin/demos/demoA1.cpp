#include "SimpleStudent.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
	cout << "[Running] Demo..." << endl;
	cout << "---------------------"<< endl;
	cout << "[Running] Create Student."<< endl;
	Student student(100, "StudentA");
	cout << "[Done] Create Student."<< endl;
	cout << "[Running] Create Student via copy ctor."<< endl;
	Student student2(student);
	cout << "[Done] Create Student via copy ctor."<< endl;
	bool a = student2.getStudentId() == 100 && student2.getStudentName() == "StudentA";
	cout << "Student (Expected): " << 100 << ", " << "StudentA" << endl;
	cout << "Student (Found)   : " << student2.getStudentId() << ", " << student2.getStudentName() << endl;
	cout << "---------------------"<< endl;
	cout << "[Done] Demo." << endl;
	return a;
}
