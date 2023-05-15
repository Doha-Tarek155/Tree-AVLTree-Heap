#include<bits/stdc++.h>
#include "studentClass.cpp"
using namespace std;
class BSTNode {
public:
    Student data;
    BSTNode* left;
    BSTNode* right;

    BSTNode(Student student) : data(student) {
        this->left = NULL;
        this->right = NULL;
    }
};
class BST{
private:
    int size;
    BSTNode *root;
    void printBST(BSTNode *root);

public:
    BST();
    void addStudent(int id, string name, double gpa, string department);
    void add_student();
    void print();
    void printDepartment();
    void removeStudent(int id);
    void search(int id);
    int sizeBST();
};

BST::BST() {

    root=NULL;
    size=0;
}

int BST::sizeBST() {
    return size;
}
void BST::addStudent(int id, string name, double gpa, string department) {
    Student studentBST(id,name,gpa,department);
    BSTNode* newNode= new BSTNode(studentBST);

    if(root==NULL){
        root = newNode;
    }
    else {
        BSTNode *current = root;
        while (current != NULL) {
            if (current->data.getID() > newNode->data.getID()) {
                if (current->left == NULL) {
                    current->left = newNode;
                    break;
                } else {
                    current = current->left;
                }
            } else if (current->data.getID() < newNode->data.getID()) {
                if (current->right == NULL) {
                    current->right = newNode;
                    break;
                } else {
                    current = current->right;
                }
            }
        }
    }
    size++;
}

void BST :: removeStudent(int id){
    if (root == NULL) {
        cout << "BST tree is empty." << endl;
        return;
    }
    else {
        BSTNode* current = root;
        BSTNode* parent = NULL;
        bool found = false;
        while (current != NULL) {
            if (current->data.getID() == id) {
                found = true;
                break;
            } else if (current->data.getID() > id) {
                parent = current;
                current = current->left;
            } else {
                parent = current;
                current = current->right;
            }
        }
        if (!found) {
            cout << "Student not found." << endl;
            return;
        }
        else {
            cout << "Student is found." << endl;
            cout<<"["<<current->data.getID()<<", "<<current->data.getName()<<", "<<current->data.getGPA()<<", "<<current->data.getDepartment()<<"]"<<endl;

            if (current->left == NULL && current->right == NULL) { // leaf node
                if (parent == NULL) {
                    root = NULL;
                } else if (parent->left == current) {
                    parent->left = NULL;
                } else {
                    parent->right = NULL;
                }
                delete current;
            } else if (current->left != NULL && current->right != NULL) { // node with two children
                BSTNode* successorParent = current;
                BSTNode* successor = current->right;
                while (successor->left != NULL) {
                    successorParent = successor;
                    successor = successor->left;
                }
                current->data = successor->data;
                if (successorParent->left == successor) {
                    successorParent->left = successor->right;
                } else {
                    successorParent->right = successor->right;
                }
                delete successor;
            }
            else {
                BSTNode* child = (current->left != NULL) ? current->left : current->right;
                if (parent == NULL) {
                    root = child;
                } else if (parent->left == current) {
                    parent->left = child;
                } else {
                    parent->right = child;
                }
                delete current;
            }

            cout << "Student is deleted." << endl;
            size--;
        }
    }
}

void BST::search(int id) {
    if (root == NULL) {
        cout << "BST tree is empty." << endl;
        return;
    }
    else {
        BSTNode* current = root;
        while (current != NULL) {
            if (current->data.getID() == id) {
                cout << "Student is found." << endl;
                cout << "[" << current->data.getID() << ", " << current->data.getName() << ", " << current->data.getGPA() << ", " << current->data.getDepartment() << "]" << endl;
                return;
            } else if (current->data.getID() > id) {
                current = current->left;
            } else {
                current = current->right;
            }
        }
        cout << "Student not found." << endl;
        return;
    }
}
void BST::printBST(BSTNode *root) {
    if (root != NULL) {
        printBST(root->left);
        cout << "[" << root->data.getID() << ", " << root->data.getName() << ", " << root->data.getGPA() << ", "
             << root->data.getDepartment() << "]" << endl;
//
//        cout<< "ID: "<<root->data.getID()<<endl;
//        cout<< "Name: "<<root->data.getName()<<endl;
//        cout<< "GPA: "<<root->data.getGPA()<<endl;
//        cout<< "Department: "<<root->data.getDepartment()<<endl;
        printBST(root->right);
    }
}
void BST::printDepartment() {
    map<string, int> depsFreqency = getDepsFreq();
    cout << "IT Department contains: " << depsFreqency["IT"] << '\n';
    cout << "DS Department contains: " << depsFreqency["DS"] << '\n';
    cout << "CS Department contains: " << depsFreqency["CS"] << '\n';
    cout << "IS Department contains: " << depsFreqency["IS"] << '\n';
}


void BST::print() {
    printBST(root);
}

void BST::add_student() {
    int id;
    string name, department;
    double gpa;
    cout << "Enter Student ID: ";
    cin >> id;
    cin.ignore();
    cout << "Enter Student Name: ";
    getline(cin, name);
    cout << "Enter Student GPA: ";
    cin >> gpa;
    cin.ignore();
    cout << "Enter Student Department: ";
    getline(cin, department);
    addStudent(id, name, gpa, department);
//    editDepsFreqData(department);
    cout<<"The student is added.\n";
}

//void bstMenu() {
//    BST bst; // Create an instance of the BST class
//
//    int choice;
//    while (true) {
//        cout << "Choose one of the following options:" << endl;
//        cout << "1. Add student" << endl;
//        cout << "2. Remove student" << endl;
//        cout << "3. Search student" << endl;
//        cout << "4. Print All (sorted by id)" << endl;
//        cout << "5. Return to main menu" << endl;
//        cout << "Enter your choice (1-5): ";
//        cin >> choice;
//
//        switch (choice) {
//            case 1:
//                bst.add_student();
//                break;
//            case 2:
//                // Code for removing a student
//                break;
//            case 3:
//                // Code for searching a student
//                break;
//            case 4:
//                bst.print(); // Print all students sorted by id
//                break;
//            case 5:
//                return; // Return to main menu
//            default:
//                cout << "Invalid choice. Please enter a number between 1 and 5." << endl;
//        }
//    }
//}