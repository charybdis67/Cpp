#include "SRS.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;
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
bool compareGrade(double grade1, double grade2){ return abs(grade1 - grade2) <= 0.001; }
string bool2string(bool b){ return b? "true" : "false"; }
struct Stats{
	int noUnsatisfactory = 0;
	int noProbation = 0;
	int noSatisfactory = 0;
	int noHonor = 0;
	int noHighHonor = 0;
	Stats() {}
	Stats(int highHonor, int honor, int satisfactory, int probation, int unsatisfactory)
		: noHighHonor(highHonor), noHonor(honor), noSatisfactory(satisfactory)
		, noProbation(probation), noUnsatisfactory(unsatisfactory) {}
	bool operator==(Stats rhs){
		return noUnsatisfactory == rhs.noUnsatisfactory && noProbation == rhs.noProbation
		&& noSatisfactory == rhs.noSatisfactory && noHonor == rhs.noHonor && noHighHonor == rhs.noHighHonor;
	}
};

Stats getStatistics(SRS S){
	Student *allStudents;
	int studentNo = S.getStudents(allStudents);
	int noUnsatisfactory = 0;
	int noProbation = 0;
	int noSatisfactory = 0;
	int noHonor = 0;
	int noHighHonor = 0;
	for (int i = 0; i < studentNo; i++){
		double gpa = allStudents[i].calculateStudentCurrentGPA();
		if (gpa < 1.80)
			noUnsatisfactory++;
		else if (gpa < 2.00)
			noProbation++;
		else {
			noSatisfactory++;
			if (gpa >= 3.00 && gpa < 3.50)
				noHonor++;
			if (gpa >= 3.50)
				noHighHonor++;
			}
	}
	Stats stats;
	stats.noHighHonor = noHighHonor;
	stats.noHonor = noHonor;
	stats.noSatisfactory = noSatisfactory;
	stats.noProbation = noProbation;
	stats.noUnsatisfactory = noUnsatisfactory;
	if (allStudents != NULL)
		delete [] allStudents;
	return stats;
}
int main(){
	cout << "[Running] Demo..." << endl;
	cout << "---------------------"<< endl;
	SRS srs;
	cout << "[Running] Add Students."<< endl;
	srs.addStudent(1234, "Cigdem Gunduz");
	srs.addStudent(5678, "Ercument Cicek");
	srs.addStudent(7890, "Cigdem Gunduz");
	srs.addStudent(7890, "Serhan Yilmaz");
	cout << "[Done] Add Students."<< endl;
	cout << "[Running] Add Multiple Student & Courses."<< endl;
	for (int i = 0; i < 100; i++){
		srs.addStudent(i, "Gozde Gunesli");
		srs.addCourse(i, 201, "B", 4);
		srs.addCourse(i, 101, "C", 3);
		srs.addCourse(i, 102, "A+", 4);
		srs.addCourse(i, 103, "F", 3);
		srs.addCourse(i, 204, "D", 2);
		srs.addCourse(i, 503, "C", 3);
	}
	srs.addCourse(1234, 201, "B", 4);
	srs.addCourse(5678, 202, "B", 1);
	srs.addCourse(5678, 201, "C-", 4);
	srs.addCourse(7890, 410, "D+", 4);
	srs.addCourse(7890, 201, "W", 4);
	srs.addStudent(3782, "Onur Karakaslar");
	srs.addCourse(3782, 201, "A", 2);
	srs.addStudent(3782, "Cigdem Demir");
	srs.addCourse(3782, 201, "F", 1);
	cout << "[Done] Add Multiple Student & Courses."<< endl;
	cout << "[Running] Remove Multiple Student & Courses."<< endl;
	srs.removeCourse(5678, 202);
	srs.removeCourse(5678, 210);
	for (int i = 1500; i > 0; i--){
		srs.removeStudent(i);
	}
	cout << "[Done] Remove Multiple Student & Courses."<< endl;
	cout << "[Running] Get Students."<< endl;
	Student* students = nullptr;
	int n = srs.getStudents(students);
	cout << "[Done] Get Students."<< endl;
	vector<StudentT> studentList1;
	studentList1.push_back(StudentT(5678, "Ercument Cicek"));
	studentList1.push_back(StudentT(7890, "Cigdem Gunduz"));
	studentList1.push_back(StudentT(0, "Gozde Gunesli"));
	studentList1.push_back(StudentT(3782, "Onur Karakaslar"));
	studentList1 = getSortedStudents(studentList1);
	vector<StudentT> studentList2 = getSortedStudents(students, n);
	cout << "[Running] Calculate Student GPA."<< endl;
	bool result = studentList1.size() == studentList2.size();
	for(int i = 0; i < studentList1.size() && result; i++){
		cout << "Student " << studentList1.at(i).id << " (Expected): " << studentList1.at(i).name << endl;
		cout << "Student " << studentList2.at(i).id << " (Found)   : " << studentList2.at(i).name << endl;
		result = result && studentList1.at(i).id == studentList2.at(i).id && studentList1.at(i).name == studentList2.at(i).name;
	}
	cout << "[Done] Calculate Course GPA."<< endl;
	Stats stats = getStatistics(srs);
	Stats stats2(1,0,2,0,2);
	result = result && stats == stats2;
	cout << "Number of high honor (Expected) :" << stats2.noHighHonor << endl;
	cout << "Number of high honor (Found)    :" << stats.noHighHonor << endl;
	cout << "Number of honor (Expected) :" << stats2.noHonor << endl;
	cout << "Number of honor (Found)    :" << stats.noHonor << endl;
	cout << "Number of satisfactory (Expected) :" << stats2.noSatisfactory << endl;
	cout << "Number of satisfactory (Found)    :" << stats.noSatisfactory << endl;
	cout << "Number of probation (Expected) :" << stats2.noProbation << endl;
	cout << "Number of probation (Found)    :" << stats.noProbation << endl;
	cout << "Number of unsatisfactory (Expected) :" << stats2.noUnsatisfactory << endl;
	cout << "Number of unsatisfactory (Found)    :" << stats.noUnsatisfactory << endl;
	if(students){
		delete[] students;
	}
	cout << "Demo result is :" << bool2string(result) << endl;
	cout << "---------------------"<< endl;
	cout << "[Done] Demo." << endl;
	return result;
}
