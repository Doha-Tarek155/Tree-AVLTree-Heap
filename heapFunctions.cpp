#include<bits/stdc++.h>
#include"readFromFile.cpp"
using namespace std;

vector<Student> SHeap = readFromFile();   

void addStudentToHeap(){
    Student addedStudentData;
    cout << "Enter Student ID: ";
    cin >> addedStudentData.ID;
    cout << "Enter Student Name: ";
    cin >> addedStudentData.Name;
    cout << "Enter Student GPA: ";
    cin >> addedStudentData.GPA;
    cout << "Enter Student Department: ";
    cin >> addedStudentData.Department;
    SHeap.push_back(addedStudentData);
}

