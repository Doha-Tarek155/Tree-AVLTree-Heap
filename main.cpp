#include<bits/stdc++.h>
#include"menues.cpp"
#include"heapFunctions.cpp"
#include "BST.cpp"
using namespace std;

int main() {
    char DSChoice;
    BST bst;
    vector<Student> students = readFromFile();
    for(auto student: students) {
        bst.addStudent(student.getID(), student.getName(), student.getGPA(), student.getDepartment());
    }

    while (true) {
        menu1();
        cout << "Enter your choice: ";
        cin >> DSChoice;
        switch (DSChoice) {
            case '1': {
                bool returnToMainMenu = 0;
                while (true&& !returnToMainMenu) {
                    char BSTChoice;
                    menu2();
                    cout << "Enter your choice :";
                    cin >> BSTChoice;
                    switch (BSTChoice) {
                        case '1': {
                            bst.add_student();
                            break;
                        }
                        case '2': {
                            int id;
                            cout<<"ID: ";
                            cin>>id;
                            bst.removeStudent(id);
                            break;
                        }
                        case '3': {
                            int id;
                            cout<<"ID: ";
                            cin>>id;
                            bst.search(id);
                            break;
                        }
                        case '4': {
                            cout<<"Print "<<bst.sizeBST()<<" Students.\n";
                            bst.print();
                            cout<<"Students per Departments:\n";
                            bst.printDepartment();
                            break;
                        }
                        case '5': {
                            returnToMainMenu = 1;
                            break;
                        }
                        default: {
                            cout << "Invalid choice.\n###Please choose from 1 to 5:)###\n";
                            break;
                        }
                    }
                    break;
                }
                }

            case '2': {
                char AVLChoice;
                while (true) {
                    menu2();
                    cout << "Enter your choice :";
                    cin >> AVLChoice;
                    switch (AVLChoice) {
                        case '1': {
//                            addStudentToAVL();
                            break;
                        }
                        case '2': {
//                            removeStudentFromAVL();
                            break;
                        }
                        case '3': {
//                            searchStudentAVL();
                            break;
                        }
                        case '4': {
//                            PrintAVL();
                            break;
                        }
                        case '5': {
                            break;
                        }
                        default: {
                            cout << "Invalid choice.\n###Please choose from 1 to 5:)###\n";
                            break;
                        }
                    }
                    if (AVLChoice == '5') {
                        break;
                    }
                }
                break;
            }
            case '3': {
                bool returnToMainMenu = 0;
                while (true&& !returnToMainMenu) {
                    menu3();
                    cout << "Enter your choice: ";
                    char minChoice;
                    cin >> minChoice;
                    switch (minChoice) {
                        case '1': {
                            addStudentToHeap();
                            break;
                        }
                        case '2': {
                            printSortedDataMin();
                            break;
                        }
                        case '3': {
                            returnToMainMenu = 1;
                            break;
                        }
                        default: {
                            cout << "Invalid choice.\n###Please choose from 1 to 3:)###\n";
                            break;
                        }
                    }
                }
                break;
            }
            case '4': {
                bool returnToMainMenu = 0;
                while (true&& !returnToMainMenu) {
                    char maxChoice;
                    menu3();
                    cout << "Enter your choice :";
                    cin >> maxChoice;
                    switch (maxChoice) {
                        case '1': {
                            addStudentToHeap();
                            break;
                        }
                        case '2': {
                            printSortedDataMax();
                            break;
                        }
                        case '3': {
                            returnToMainMenu = 1;
                            break;
                        }
                        default: {
                            cout << "Invalid choice.\n###Please choose from 1 to 3:)###\n";
                            break;
                        }
                    }
                }
                break;
            }
            case '5': {
                cout << "Good luck :);\n";
                return 0;
            }
            default: {
                cout << "Invalid choice.\n###Please choose from 1 to 5:)###\n";
                break;
            }
        }
    }
}