#include<bits/stdc++.h>
#include"studentClass.cpp"
using namespace std;

vector<Student> SHeap = readFromFile();

void addStudentToHeap(){
    int id;
    string name, department;
    double gpa;
    Student addedStudentData;
    cout << "Enter Student ID: ";
    cin >> id;
    addedStudentData.setID(id);
    cout << "Enter Student Name: ";
    cin >> ws;
    getline(cin, name);
    addedStudentData.setName(name);
    cout << "Enter Student GPA: ";
    cin >> gpa;
    addedStudentData.setGPA(gpa);
    cout << "Enter Student Department: ";
    cin >> department;
    editDepsFreqData(department);
    addedStudentData.setDepartment(department);
    SHeap.push_back(addedStudentData);
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
    int n = SHeap.size();
    minHeapSort(SHeap, n);
    for(int i = 0; i < n; ++i) {
        cout <<'[' << SHeap[i].getID() << ", "  << SHeap[i].getName() << ", " << SHeap[i].getGPA() <<
        ", " << SHeap[i].getDepartment() << "]\n";
    }
     map<string, int> depsFreqency = getDepsFreq();
     
    cout << "IT Department contains: " << depsFreqency["IT"] << '\n';
    cout << "DS Department contains: " << depsFreqency["DS"] << '\n';
    cout << "CS Department contains: " << depsFreqency["CS"] << '\n';
    cout << "IS Department contains: " << depsFreqency["IS"] << '\n';
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
    int n = SHeap.size();
    maxHeapSort(SHeap, n);
    for(int i = 0; i < n; ++i) {
        cout <<'[' << SHeap[i].getID() << ", "  << SHeap[i].getName() << ", " << SHeap[i].getGPA()<<
        ", " << SHeap[i].getDepartment() << "]\n";
    }
    map<string, int> depsFreqency = getDepsFreq();
    
    cout << "IT Department contains: " << depsFreqency["IT"] << '\n';
    cout << "DS Department contains: " << depsFreqency["DS"] << '\n';
    cout << "CS Department contains: " << depsFreqency["CS"] << '\n';
    cout << "IS Department contains: " << depsFreqency["IS"] << '\n';
}

