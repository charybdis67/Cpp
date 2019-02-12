#include "SRS.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
struct StudentT{
	int id;
	string name;
	double grade;
	int index;
	StudentT() {}
	StudentT(int id_, string name_) : id(id_), name(name_) {}
	StudentT(int id_, string name_, double grade_) : id(id_), name(name_), grade(grade_) {}
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
		studentT.index = i;
		studentList.push_back(studentT);
		cout << "Student " << i << " : " << studentT.id << ", " << studentT.name << endl;
	}
	cout << "[Done] Read students." << endl;
	std::sort (studentList.begin(), studentList.end(), compareStudents);
	return studentList;
}
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
	srs.addCourse(100, 1, "A", 3);
	srs.addCourse(100, 2, "B", 3);
	srs.addCourse(100, 3, "C", 3);
	srs.addCourse(200, 1, "B-", 3);
	srs.addCourse(200, 2, "C-", 3);
	srs.addCourse(400, 4, "D", 3);
	srs.addCourse(400, 2, "A-", 3);
	srs.addCourse(500, 2, "B", 5);
	cout << "[Done] Add Courses."<< endl;
	cout << "[Running] Remove Course."<< endl;
	srs.removeCourse(100, 1);
	srs.removeCourse(500, 2);
	srs.removeCourse(200, 1);
	cout << "[Done] Remove Course."<< endl;
	cout << "[Running] Get Students."<< endl;
	Student* students = nullptr;
	int n = srs.getStudents(students);
	cout << "[Done] Get Students."<< endl;
	vector<StudentT> studentList1;
	studentList1.push_back(StudentT(100, "StudentA", 2.5));
	studentList1.push_back(StudentT(200, "StudentB", 1.7));
	studentList1.push_back(StudentT(300, "StudentC", 0.0));
	studentList1.push_back(StudentT(400, "StudentD", 2.35));
	studentList1.push_back(StudentT(500, "StudentE", 0.0));
	studentList1 = getSortedStudents(studentList1);
	vector<StudentT> studentList2 = getSortedStudents(students, n);
	cout << "[Running] Calculate Student GPA."<< endl;
	bool result = studentList1.size() == studentList2.size();
	for(int i = 0; i < studentList1.size() && result; i++){
		double grade1 = studentList1.at(i).grade;
		cout << "Student " << studentList1.at(i).id << " (Expected): " << grade1 << endl;
		int index = studentList2.at(i).index;
		double grade2 = students[index].calculateStudentCurrentGPA();
		cout << "Student " << studentList2.at(i).id << " (Found)   : " << grade2 << endl;
		result = result && compareGrade(grade1, grade2) && studentList1.at(i).id == studentList2.at(i).id;
	}
	cout << "[Done] Calculate Course GPA."<< endl;
	if(students){
		delete[] students;
	}
	cout << "Demo result is :" << bool2string(result) << endl;
	cout << "---------------------"<< endl;
	cout << "[Done] Demo." << endl;
	return result;
}
