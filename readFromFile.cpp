#include<bits/stdc++.h>
#include"studentClass.cpp"
using namespace std;

void readFromFile(){
    int size;
    ifstream inputFile;
    inputFile.open("studentData.txt", ios::in);
    if(!inputFile.fail()){
        cout << "NOTFAILED!!!\n";
    }
    inputFile >> size;
    cout << size << '\n';
    vector<StudentHeap> sHeap;
    for(int i = 0; i < size && !inputFile.eof(); ++i){
        char line[30];
        StudentHeap currStudent;
        inputFile >> currStudent.ID;
        inputFile >> line;
        currStudent.Name = line;
        inputFile >> currStudent.GPA;
        inputFile >> line;
        currStudent.Department = line;
        sHeap.push_back(currStudent);
        cout << currStudent.ID << '\n';
        cout << currStudent.Name << '\n';
        cout << currStudent.GPA << '\n';
        cout << currStudent.Department << '\n';
    }
    inputFile.close();
}