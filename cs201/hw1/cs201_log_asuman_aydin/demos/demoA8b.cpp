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

	cout << "[Running] Add Students."<< endl;
	srs.addStudent(1234, "Cigdem Gunduz");
	srs.addStudent(5678, "Ercument Cicek");
	bool b1 = srs.addStudent(7890, "Cigdem Gunduz");
	if (b1)
		cout <<"Successful insertion for Cigdem Gunduz (7890)"<< endl;
	else 
		cout <<"Unsuccessful insertion for Cigdem Gunduz (7890)"<< endl;
	bool b2 = srs.addStudent(7890, "Serhan Yilmaz");
	if (b2)
		cout <<"Successful insertion for Serhan Yilmaz (7890)"<< endl;
	else 
		cout <<"Unsuccessful insertion for Serhan Yilmaz (7890)"<< endl;
	cout << "[Done] Add Students."<< endl;
	bool b3 = srs.removeStudent(5000);
	if (b3)
		cout <<"Successful deletion for Student 5000"<< endl;
	else 
		cout <<"Unsuccessful deletion for Student 5000"<< endl;
	
	cout << "[Running] Add & Remove Multiple Students ."<< endl;
	 for (int i = 0; i < 100; i++)
		srs.addStudent(i, "Gozde Gunesli");
	 for (int i = 1500; i > 1; i--)
		srs.removeStudent(i);
	cout << "[Done] Add & Remove Multiple Students ."<< endl;
	vector<StudentT> studentList1;
	studentList1.push_back(StudentT(5678, "Ercument Cicek"));
	studentList1.push_back(StudentT(7890, "Cigdem Gunduz"));
	studentList1.push_back(StudentT(0, "Gozde Gunesli"));
	studentList1.push_back(StudentT(1, "Gozde Gunesli"));
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
	testResult = testResult && b1 && !b2 && !b3;
	if(students){
		delete[] students;
	}
	cout << "---------------------"<< endl;
	cout << "[Done] Demo." << endl;
	return testResult;
}
