#include<bits/stdc++.h>
#include"menues.cpp"
#include"heapFunctions.cpp"

using namespace std;

int main(){
    char DSChoice;
    while(true){
        menu1();
        cout << "Enter your choice: ";
        cin >> DSChoice;
        if(DSChoice == '1'){
            char BSTChoice;
            menu2();
            cout << "Enter your choice :";
            cin >> BSTChoice;
            if(BSTChoice == '1') {

            } else if(BSTChoice == '2') {
                
            } else if(BSTChoice == '3') {
                
            } else if(BSTChoice == '4') {
                
            } else if(BSTChoice == '5') {
                break;
            }
        } else if (DSChoice == '2') {
            while (true) {
                menu2();
                char AVLChoice;
                cout << "Enter your choice :";
                cin >> AVLChoice;
                if (AVLChoice) {
                    if (AVLChoice == '1') {
                        //Add student

                    } else if (AVLChoice == '2') {
                        //Remove student
                    } else if(AVLChoice == '3'){
                        //Search student
                    } else if(AVLChoice == '4'){
                        //print all students sorted by ID
                    } else if(AVLChoice == '5'){
                        break;
                    }
                }
            }
        } else if (DSChoice == '3') {
            bool returnToMainMenu = 1;
            while (true&&returnToMainMenu) {
                menu3();
                cout << "Enter your choice: ";
                char minChoice;
                cin >> minChoice;
                if (minChoice == '1') {
                    addStudentToHeap();
                }
                else if(minChoice == '2'){
                    //print all students sorted by GPA
                } else if(minChoice == '3'){
                    returnToMainMenu = 0;
                }
            }
        } else if (DSChoice == '4') {
            bool returnToMainMenu = 1;
            while (true&&returnToMainMenu) {
                char maxChoice;
                menu3();
                cout << "Enter your choice :";
                cin >> maxChoice;
                if (maxChoice) {
                    if (maxChoice == '1') {
                        addStudentToHeap();
                    }
                } else if(maxChoice=='2'){
                    //print all students sorted by GPA
                } else if(maxChoice== '3'){
                    returnToMainMenu = 0;
                }
            }
        }
        else if (DSChoice == '5') {
            cout<<"Good luck );\n";
            return 0;
        } else {
            cout << "Invalid choice.\nPlease choose from 1 to 5:)";
            menu1();
            cin >> DSChoice;
            break;
        }
    }
   return 0;
}