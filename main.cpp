#include<bits/stdc++.h>
#include"menues.cpp"
#include"heapFunctions.cpp"
#include "BST.cpp"
#include "AVL.cpp"
using namespace std;

int main(){
    BST bst;
    vector<Student> students = readFromFile();
    for(auto student: students) {
        bst.addStudent(student.getID(), student.getName(), student.getGPA(), student.getDepartment());
    }
    AVL avl;
    vector<Student> students1 = readFromFile();
    for(auto student: students1) {
        avl.addStudent(student.getID(), student.getName(), student.getGPA(), student.getDepartment());
    }

    char DSChoice;
    while(true){
        menu1();
        cout << "Enter your choice: ";
        cin >> DSChoice;
        if(DSChoice == '1'){
            bool returnToMainMenu = 0;
            while(true&& !returnToMainMenu){
                char BSTChoice;
                menu2();
                cout << "Enter your choice :";
                cin >> BSTChoice;
                if(BSTChoice == '1') {
                    bst.add_student();

                } else if(BSTChoice == '2') {
                    int id;
                    cout<<"ID: ";
                    cin>>id;
                    bst.removeStudent(id);

                } else if(BSTChoice == '3') {
                    int id;
                    cout<<"ID: ";
                    cin>>id;
                    bst.searchStudent(id);

                } else if(BSTChoice == '4') {
                    cout<<"Print "<<bst.sizeBST()<<" Students.\n";
                    bst.print();
                    cout<<"Students per Departments:\n";
                    bst.printDepartment();

                } else if(BSTChoice == '5') {
                    returnToMainMenu=1;
                    break;
                }
            }

        } else if (DSChoice == '2') {
            bool returnToMainMenu = 0;

            while(true&& !returnToMainMenu) {
                menu2();
                char AVLChoice;
                cout << "Enter your choice :";
                cin >> AVLChoice;
                if (AVLChoice) {
                    if (AVLChoice == '1') {
                        avl.addstudent();
                    } else if (AVLChoice == '2') {
                        int id;
                        cout<<"ID: ";
                        cin>>id;
                        avl.removeStudent(id);
                    } else if (AVLChoice == '3') {
                        int id;
                        cout<<"ID: ";
                        cin>>id;
                        avl.searchStudent(id);
                    } else if (AVLChoice == '4') {
                        cout<<"Print "<<avl.sizeAVL()<<" Students.\n";
                        avl.print();
                        cout<<"Students per Departments:\n";
                        avl.printDepartment();
                    } else if (AVLChoice == '5') {
                        returnToMainMenu=1;
                        break;
                    }
                }
            }
} else if (DSChoice == '3') {
            bool returnToMainMenu = 0;
            while (true&& !returnToMainMenu) {
                menu3();
                cout << "Enter your choice: ";
                char minChoice;
                cin >> minChoice;
                if (minChoice == '1') {
                    addStudentToMinHeap();
                }
                else if(minChoice == '2'){
                    printSortedDataMin();
                } else if(minChoice == '3'){
                    returnToMainMenu = 1;
                } else {
                    cout << "Invalid choice.\n###Please choose from 1 to 3:)###\n";
                }
            }
        } else if (DSChoice == '4') {
            bool returnToMainMenu = 0;
            while (true&& !returnToMainMenu) {
                char maxChoice;
                menu3();
                cout << "Enter your choice: ";
                cin >> maxChoice;
                if (maxChoice == '1') {
                    addStudentToMaxHeap();
                }
                else if(maxChoice=='2'){
                    printSortedDataMax();
                } else if(maxChoice== '3'){
                    returnToMainMenu = 1;
                } else {
                    cout << "Invalid choice.\n###Please choose from 1 to 3:)###\n";
                }
            }
        }
        else if (DSChoice == '5') {
            cout<<"Good luck:)\n";
            return 0;
        } else {
            cout << "\nInvalid choice.\n###Please choose from 1 to 5:)###\n\n";
        }
    }
    return 0;
}