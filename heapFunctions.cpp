#include<bits/stdc++.h>
#include"readFromFile.cpp"
using namespace std;

vector<Student> SHeap = readFromFile();

void addStudentToHeap(){
    int id;
    string name, department;
    double gpa;
    Student addedStudentData;
    cout << "Enter Student ID: ";
    cin >> id;
    addedStudentData.setID(id);
    cout << "Enter Student Name: ";
    cin >> name;
    addedStudentData.setName(name);
    cout << "Enter Student GPA: ";
    cin >> gpa;
    addedStudentData.setGPA(gpa);
    cout << "Enter Student Department: ";
    cin >> department;
    addedStudentData.setDepartment(department);
    SHeap.push_back(addedStudentData);
}

