#include <iostream>
#include "SimpleSRS.h"
#include "SimpleStudent.h"
using namespace std;

void displayAllStudents(SRS S){
	Student *allStudents;
	int studentNo = S.getStudents(allStudents);
	cout <<"No of students: "<< studentNo << endl;
	for (int i = 0; i < studentNo; i++){
	cout << allStudents[i].getStudentName() <<" (";
	cout << allStudents[i].getStudentId() <<")"<< endl;
	}
	if (allStudents != NULL)
	delete [] allStudents;
}
int main(){
		SRS S;
	S.addStudent(1234, "Cigdem Gunduz");
	S.addStudent(5678, "Ercument Cicek");
	if (S.addStudent(7890, "Cigdem Gunduz"))
		cout <<"Successful insertion for Cigdem Gunduz (7890)"<< endl;
	else 
		cout <<"Unsuccessful insertion for Cigdem Gunduz (7890)"<< endl;
	if (S.addStudent(7890, "Serhan Yilmaz"))
		cout <<"Successful insertion for Serhan Yilmaz (7890)"<< endl;
	else 
		cout <<"Unsuccessful insertion for Serhan Yilmaz (7890)"<< endl;
	if (S.removeStudent(5000))
	cout <<"Successful deletion for Student 5000"<< endl;
	else 
		cout <<"Unuccessful deletion for Student 5000"<< endl;
	for (int i = 0; i < 1000; i++)
		S.addStudent(i, "Gozde Gunesli");
	for (int i = 1500; i > 1; i--)
		S.removeStudent(i);
	
	displayAllStudents(S);
	return 0;
	
}
