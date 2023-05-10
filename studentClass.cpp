#include<bits/stdc++.h>
using namespace std;

class Student{
public:
    int ID;
    string Name;
    double GPA;
    string Department;
    Student(int ID, string Name, double GPA, string Department);
    Student& getStudentData(istream& is) {
       is >> obj.ID;
       is.ignore();
       getline(is, obj.Name);
       is >> obj.GPA;
       is>>obj.Department;
      return is;
    }
    void printStudentData(Student stud){
        os<<"student  information ..."<<endl;
        os<<"ID :"<<stud.ID<<endl;
        os<<"Name  :"<<stud.Name<<endl;
        os<<"GPA :"<<stud.GPA<<endl;
        os<<"Department : "<<stud.Department<<endl;
        cout<<"----------------------"<<endl;
    }
};

Student::Student(int ID, string Name, double GPA, string Department){
    this->ID = ID;
    this->Name = Name;
    this->GPA = GPA;
    this->Department = Department;
}