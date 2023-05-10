#include<bits/stdc++.h>
#include"menues.cpp"
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
            while (true) {
                menu3();
                cout << "Enter your choice: ";
                char minChoice;
                cin >> minChoice;
                if (minChoice == '1') {
                    //Add student
                    cout << '.';
                }
                else if(minChoice == '2'){
                    //print all students sorted by GPA
                } else if(minChoice == '3'){
                    break;
                }
            }
        } else if (DSChoice == '4') {
            while (true) {
                char maxChoice;
                menu3();
                cout << "Enter your choice :";
                cin >> maxChoice;
                if (maxChoice) {
                    if (maxChoice == '1') {
                        //Add student
                    }
                } else if(maxChoice=='2'){
                    //print all students sorted by GPA
                } else if(maxChoice== '3'){
                    break;
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



// while (true) {
//                 Menu2();
//                 cout << "Enter your choice :";
//                 cin >> choice;
//                 if (choice) {
//                     if (choice == 1) {
//                         //Add student
//                         Student obj;
//                         int id;string first,last,department;double gpa;
//                         cout<<"Enter ID,first name ,last name ,GPA,Department"<<endl;
//                         cin>>id>>first>>last>>gpa>>department;
//                         string namee="";namee+=first;namee+=" ";namee+=last;
//                         obj.ID=id;obj.Name=namee;obj.Gpa=gpa;obj.Department=department;
//                         tree.insert_New_student(obj);
//                         cout<<"student is added. "<<endl;
//                     } else if (choice == 2) {
//                         //Remove student
//                     } else if(choice==3){
//                        int Id;
//                        cout<<"Enter id: ";
//                        cin>>Id;
//                        tree.search_by_ID(Id);
//                     } else if(choice==4){
//                         //print all students sorted by ID
//                         tree.print_student_sorted_by_ID();
//                     } else if(choice==5){
//                         break;
//                     }
//                 }
//             }
//         } else if (choice == 2) {
//             while (true) {
//                 Menu2();
//                 cout << "Enter your choice :";
//                 cin >> choice;
//                 if (choice) {
//                     if (choice == 1) {
//                         //Add student

//                     } else if (choice == 2) {
//                         //Remove student
//                     } else if(choice==3){
//                         //Search student
//                     } else if(choice==4){
//                         //print all students sorted by ID
//                     } else if(choice==5){
//                         break;
//                     }
//                 }
//             }
//         }