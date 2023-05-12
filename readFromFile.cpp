#include<bits/stdc++.h>
#include"studentClass.cpp"
using namespace std;

void readFromFile(){
    int size;
    fstream inputFile;
    char file_name[100]="studentData";
    strcat(file_name,".txt");
    inputFile.open(file_name,ios::in);
    if(!inputFile.is_open()){
        cout << "ERROR: Could not open file\n";
        return;
    }
    inputFile >> size;
    cout << size << '\n';
    vector<StudentHeap> sHeap;
    for(int i = 0; i < size && inputFile.good(); ++i){
        StudentHeap currStudent;
        inputFile >> currStudent.ID;
        getline(inputFile >> ws, currStudent.Name, '\n');
        inputFile >> currStudent.GPA;
        getline(inputFile >> ws, currStudent.Department, '\n');
        sHeap.push_back(currStudent);
        cout << currStudent.ID << '\n';
        cout << currStudent.Name << '\n';
        cout << currStudent.GPA << '\n';
        cout << currStudent.Department << '\n';
    }
    inputFile.close();
}