#include<bits/stdc++.h>
#include"readFromFile.cpp"
using namespace std;

vector<Student> SHeap = readFromFile();   

void addStudentToHeap(){
    Student addedStudentData;
    cout << "Enter Student ID: ";
    cin >> addedStudentData.ID;
    cout << "Enter Student Name: ";
    cin >> addedStudentData.Name;
    cout << "Enter Student GPA: ";
    cin >> addedStudentData.GPA;
    cout << "Enter Student Department: ";
    cin >> addedStudentData.Department;
    SHeap.push_back(addedStudentData);
    cout << "The student is added.\n";
}

void minHeapify(vector<Student>& VS, int n, int i)
{
    int smallest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && VS[l].GPA < VS[smallest].GPA)
        smallest = l;

    if (r < n && VS[r].GPA < VS[smallest].GPA)
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
        cout <<'[' << SHeap[i].ID << ", "  << SHeap[i].Name << ", " << SHeap[i].GPA <<
        ", " << SHeap[i].Department << "]\n";
    }
}

//#############################################################################################################################


void maxHeapify(vector<Student>& VS, int n, int i)
{
    int mx = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && VS[l].GPA > VS[mx].GPA)
        mx = l;

    if (r < n && VS[r].GPA > VS[mx].GPA)
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
        cout <<'[' << SHeap[i].ID << ", "  << SHeap[i].Name << ", " << SHeap[i].GPA <<
        ", " << SHeap[i].Department << "]\n";
    }
}

