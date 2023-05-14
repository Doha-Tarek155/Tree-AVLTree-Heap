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
        return vector<Student>();
    }
    else{
        inputFile >> size;
        vector<Student> student;
        for(int i = 0; i < size && inputFile.good(); ++i){
            Student currStudent;
            inputFile >> currStudent.ID;
            getline(inputFile >> ws, currStudent.Name, '\n');
            inputFile >> currStudent.GPA;
            getline(inputFile >> ws, currStudent.Department, '\n');
            student.push_back(currStudent);
        }
        inputFile.close();
        return student;
    }

}