#include<bits/stdc++.h>

using namespace std;
class Student{
public:
    int ID;
    string Name;
    double GPA;
    string Department;
    Student(){}
    Student(int ID, string Name, double GPA, string Department){
        this->ID = ID;
        this->Name = Name;
        this->GPA = GPA;
        this->Department = Department;
    };
    int getID();
    string getName();
    double getGPA();
    string getDepartment();
};

//Student::Student(int ID, string Name, double GPA, string Department){
//    this->ID = ID;
//    this->Name = Name;
//    this->GPA = GPA;
//    this->Department = Department;
//}
int Student::getID() {
    return ID;
}

string Student::getName() {
    return Name;
}

double Student::getGPA() {
    return GPA;
}

string Student::getDepartment() {
    return Department;
}