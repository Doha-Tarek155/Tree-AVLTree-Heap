#include<bits/stdc++.h>

using namespace std;
class Student{
private:
    int ID;
    string Name;
    double GPA;
    string Department;

public:
    Student(){}
    Student(int ID, string Name, double GPA, string Department);

    void setID(int id);
    void setName(string name);
    void setGPA(double gpa);
    void setDepartment(string department);

    int getID();
    string getName();
    double getGPA();
    string getDepartment();
};

Student::Student(int ID, string Name, double GPA, string Department){
    this->ID = ID;
    this->Name = Name;
    this->GPA = GPA;
    this->Department = Department;
}
void Student::setID(int id) {
    this->ID=id;
}

void Student::setName(string name) {
    this->Name=name;
}

void Student::setGPA(double gpa) {
    this->GPA=gpa;
}

void Student::setDepartment(string department) {
    this->Department=department;
}


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