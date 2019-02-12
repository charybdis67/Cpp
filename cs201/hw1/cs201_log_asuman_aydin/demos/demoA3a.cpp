#include "SimpleSRS.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
struct StudentT{
	int id;
	string name;
	StudentT() {}
	StudentT(int id_, string name_) : id(id_), name(name_) {}
};
bool compareStudents (StudentT i, StudentT j) { return (i.id < j.id); }
vector<StudentT> getSortedStudents(vector<StudentT> studentList){
	std::sort (studentList.begin(), studentList.end(), compareStudents);
	return studentList;
}
vector<StudentT> getSortedStudents(Student* students, int n){
	vector<StudentT> studentList;
	cout << "[Running] Read students." << endl;
	for(int i = 0; i < n; i++){
		StudentT studentT;
		studentT.id = students[i].getStudentId();
		studentT.name = students[i].getStudentName();
		studentList.push_back(studentT);
		cout << "Student " << i << " : " << studentT.id << ", " << studentT.name << endl;
	}
	cout << "[Done] Read students." << endl;
	std::sort (studentList.begin(), studentList.end(), compareStudents);
	return studentList;
}
int main(){
	cout << "[Running] Demo..." << endl;
	cout << "---------------------"<< endl;
	SRS srs;
	Student* students = nullptr;
	vector<StudentT> studentList1;
	studentList1.push_back(StudentT(100, "Student1"));
	studentList1.push_back(StudentT(200, "Student2"));
	cout << "[Running] Add Students."<< endl;
	for(int i = 0; i < studentList1.size(); i++){
		srs.addStudent(studentList1.at(i).id, studentList1.at(i).name);
	}
	cout << "[Done] Add Students."<< endl;
	studentList1 = getSortedStudents(studentList1);
	cout << "[Running] Get Students."<< endl;
	int n = srs.getStudents(students);
	cout << "[Done] Get Students."<< endl;
	vector<StudentT> studentList2 = getSortedStudents(students, n);
	bool testResult = studentList1.size() == studentList2.size();
	cout << "[Running] Comparing students."<< endl;
	cout << "Student Size (Expected): " << studentList1.size() << endl;
	cout << "Student Size (Found)   : " << studentList2.size() << endl;
	for(int i = 0; i < studentList1.size() && testResult; i++){
		testResult = studentList1.at(i).id == studentList2.at(i).id &&
			studentList1.at(i).name == studentList2.at(i).name;
		cout << "Student " << i << " (Expected): " << studentList1.at(i).id << ", " << studentList1.at(i).name << endl;
		cout << "Student " << i << " (Found)   : " << studentList2.at(i).id << ", " << studentList2.at(i).name << endl;
	}
	cout << "---------------------"<< endl;
	cout << "[Done] Demo." << endl;
	return testResult;
}
