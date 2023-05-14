#include<bits/stdc++.h>
#include "studentClass.cpp"

using namespace std;

vector<Student> readFromFile(){
    int size;
    fstream inputFile;
    char file_name[100]="studentData";
    strcat(file_name,".txt");
    inputFile.open(file_name,ios::in);
    if(!inputFile.is_open()){
        cout << "ERROR: Could not open file\n";
    }
    else{
        inputFile >> size;
        vector<Student> student;
        int id;
        string name, department;
        double gpa;
        for(int i = 0; i < size && inputFile.good(); ++i){
            Student currStudent;
            inputFile >> id;
            currStudent.setID(id);
            getline(inputFile >> ws, name, '\n');
            currStudent.setName(name);
            inputFile >> gpa;
            currStudent.setGPA(gpa);
            getline(inputFile >> ws, department, '\n');
            currStudent.setDepartment(department);
            student.push_back(currStudent);
        }
        inputFile.close();
        return student;
    }

}