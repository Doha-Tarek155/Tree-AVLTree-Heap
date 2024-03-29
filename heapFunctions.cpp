#include<bits/stdc++.h>
#include"studentClass.cpp"
using namespace std;

vector<Student> SMinHeap = readFromFile();
vector<Student> SMaxHeap = readFromFile();


bool minCheckIfIDExists(int sid){
    for(int i = 0; i < SMinHeap.size(); ++i){
            if(sid == SMinHeap[i].getID()){
                cout << "this ID is already exist...Enter another one:) ";
                return 1;
            }
        }
    return 0;
}
bool maxCheckIfIDExists(int sid){
    for(int i = 0; i < SMaxHeap.size(); ++i){
            if(sid == SMaxHeap[i].getID()){
                cout << "this ID is already exist...Enter another one:) ";
                return 1;
            }
        }
    return 0;
}

void addStudentToMaxHeap(){
    int id;
    string name, department;
    double gpa;
    Student addedStudentData;
    cout << "Enter Student ID: ";
    cin >> id;
    while(id < 0  || id > 101){
        cout << "Invalid ID);\nEnter ID from 1 to 100: ";
        cin >> id;
    }
    while(maxCheckIfIDExists(id)){
        cin >> id;
    }
    addedStudentData.setID(id);
    cout << "Enter Student Name: ";
    cin >> ws;
    getline(cin, name);
    addedStudentData.setName(name);
    cout << "Enter Student GPA: ";
    cin >> gpa;
    while(gpa < 0 || gpa > 4){
        cout << "Invalid GPA);\nEnter GPA from 0 to 4: ";
        cin >> gpa;
    }
    addedStudentData.setGPA(gpa);
    cout << "Enter Student Department: ";
    cin >> department;
    while(department != "CS" &&department != "IS" &&department != "DS" && department != "IT" ){
        cout << "Invalid Department);\n Choose department from those:(CS, IS, DS, IT): ";
        cin >> department;
    }
    editMaxDepsFreqData(department);
    addedStudentData.setDepartment(department);
    SMaxHeap.push_back(addedStudentData);
    cout << "##The student is added.##\n";
}

void addStudentToMinHeap(){
    int id;
    string name, department;
    double gpa;
    Student addedStudentData;
    cout << "Enter Student ID: ";
    cin >> id;
    while(id < 0 || id > 101){
        cout << "Invalid ID);\nEnter ID from 1 to 100: ";
        cin >> id;
    }
        while(minCheckIfIDExists(id)){
        cin >> id;
    }
    addedStudentData.setID(id);
    cout << "Enter Student Name: ";
    cin >> ws;
    getline(cin, name);
    addedStudentData.setName(name);
    cout << "Enter Student GPA: ";
    cin >> gpa;
    while(gpa < 0 || gpa > 4){
        cout << "Invalid GPA);\nEnter GPA from 0 to 4: ";
        cin >> gpa;
    }
    addedStudentData.setGPA(gpa);
    cout << "Enter Student Department: ";
    cin >> department;
    while(department != "CS" &&department != "IS" &&department != "DS" && department != "IT" ){
        cout << "Invalid Department);\n Choose department from those:(CS, IS, DS, IT): ";
        cin >> department;
    }
    editMinDepsFreqData(department);
    addedStudentData.setDepartment(department);
    SMinHeap.push_back(addedStudentData);
    cout << "##The student is added.##\n";
}


void minHeapify(vector<Student>& VS, int n, int i)
{
    int smallest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && VS[l].getGPA() < VS[smallest].getGPA())
        smallest = l;
    if (r < n && VS[r].getGPA() < VS[smallest].getGPA())
        smallest = r;

    if (smallest != i) {
        swap(VS[i], VS[smallest]);
        minHeapify(VS, n, smallest);
    }
}

void minHeapSort(vector<Student>& VS, int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        minHeapify(VS, n, i);

    for (int i = n - 1; i >= 0; i--) {
        swap(VS[0], VS[i]);
        minHeapify(VS, i, 0);
    }
}

void printSortedDataMin(){
    int n = SMinHeap.size();
    minHeapSort(SMinHeap, n);
    for(int i = 0; i < n; ++i) {
        cout <<'[' << SMinHeap[i].getID() << ", "  << SMinHeap[i].getName() << ", " << SMinHeap[i].getGPA() <<
            ", " << SMinHeap[i].getDepartment() << "]\n";
    }
    map<string, float> depsFreqency = getMinDepsFreq();
    cout << "CS Department contains: " << depsFreqency["CS"] << '\n';
    cout << "IS Department contains: " << depsFreqency["IS"] << '\n';
    cout << "IT Department contains: " << depsFreqency["IT"] << '\n';
    cout << "DS Department contains: " << depsFreqency["DS"] << '\n';
}

//#############################################################################################################################


void maxHeapify(vector<Student>& VS, int n, int i)
{
    int mx = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && VS[l].getGPA() > VS[mx].getGPA())
        mx = l;

    if (r < n && VS[r].getGPA() > VS[mx].getGPA())
        mx = r;

    if (mx != i) {
        swap(VS[i], VS[mx]);
        maxHeapify(VS, n, mx);
    }
}

void maxHeapSort(vector<Student>& VS, int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        maxHeapify(VS, n, i);

    for (int i = n - 1; i >= 0; i--) {
        swap(VS[0], VS[i]);
        maxHeapify(VS, i, 0);
    }
}

void printSortedDataMax(){
    int n = SMaxHeap.size();
    maxHeapSort(SMaxHeap, n);
    for(int i = 0; i < n; ++i) {
        cout <<'[' << SMaxHeap[i].getID() << ", "  << SMaxHeap[i].getName() << ", " << SMaxHeap[i].getGPA()<<
            ", " << SMaxHeap[i].getDepartment() << "]\n";
    }
    map<string, float> depsFreqency = getMaxDepsFreq();

    cout << "CS Department contains: " << depsFreqency["CS"] << '\n';
    cout << "IS Department contains: " << depsFreqency["IS"] << '\n';
    cout << "IT Department contains: " << depsFreqency["IT"] << '\n';
    cout << "DS Department contains: " << depsFreqency["DS"] << '\n';
}