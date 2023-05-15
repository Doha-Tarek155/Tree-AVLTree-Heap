#include<bits/stdc++.h>
#ifndef STUDENT_CPP
#define STUDENT_CPP

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

map<string, int> depsFreq = {
        {"IT", 0},
        {"CS", 0},
        {"DS", 0},
        {"IS", 0}
};

void editDepsFreqData(string dep){
    depsFreq[dep]++;
}

map<string, int>& getDepsFreq(){
    return depsFreq;
}

vector<Student> readFromFile()
{
    int size;
    fstream inputFile;
    char file_name[100] = "studentData";
    strcat(file_name, ".txt");
    inputFile.open(file_name, ios::in);
    if (!inputFile.is_open())
    {
        cout << "ERROR: Could not open file\n";
        return vector<Student>();
    }
    else
    {
        inputFile >> size;
        vector<Student> student;
        int id;
        string name, department;
        double gpa;
        for (int i = 0; i < size && inputFile.good(); ++i)
        {
            Student currStudent;
            inputFile >> id;
            currStudent.setID(id);
            getline(inputFile >> ws, name, '\n');
            currStudent.setName(name);
            inputFile >> gpa;
            currStudent.setGPA(gpa);
            getline(inputFile >> ws, department, '\n');
            depsFreq[department]++;
            currStudent.setDepartment(department);
            student.push_back(currStudent);
        }
        inputFile.close();
        return student;
    }
}
#endif
