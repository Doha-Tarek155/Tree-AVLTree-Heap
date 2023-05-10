#include<bits/stdc++.h>
using namespace std;

class StudentHeap{
public:
    int ID;
    string Name;
    double GPA;
    string Department;
    StudentHeap(int ID, string Name, double GPA, string Department);
    StudentHeap(){}
};
StudentHeap::StudentHeap(int ID, string Name, double GPA, string Department){
    this->ID = ID;
    this->Name = Name;
    this->GPA = GPA;
    this->Department = Department;
}