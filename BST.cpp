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
    int ds;
    int cs;
    int it;
    int is;

public:
    BST();

    bool addStudent(int id, string name, double gpa, string department);
    void add_student();
    void print();
    void printDepartment();
    void removeStudent(int id);
    void searchStudent(int id);
    bool search(int id);
    int sizeBST();
    int numIT();
    int numCS();
    int numIS();
    int numDS();
};

BST::BST() {

    root=NULL;
    size=0;
    it=0;
    is=0;
    cs=0;
    ds=0;
}

int BST::sizeBST() {
    return size;
}
int BST::numCS() {
    return cs;
}
int BST::numIS() {
    return is;
}int BST::numIT() {
    return it;
}int BST::numDS() {
    return ds;
}

bool BST::addStudent(int id, string name, double gpa, string department) {
    if (!search(id) && id >= 0 && id <= 100) {
        if (department == "CS") {
            cs++;
        } else if (department == "DS") {
            ds++;
        } else if (department == "IS") {
            is++;
        } else if (department == "IT") {
            it++;
        }
        else if((department!="CS")||(department!="IT")||(department!="DS")||(department!="IS")){
            return false;
        }
        if(gpa<0||gpa>4){
            return false;
        }

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
        return true;
    }
    else
        return false;

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
            if(current->data.getDepartment()=="CS"){
                cs--;
            }else if(current->data.getDepartment()=="DS"){
                ds--;
            }else if(current->data.getDepartment()=="IS"){
                is--;
            }else if(current->data.getDepartment()=="IT"){
                it--;
            }
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

void BST::searchStudent(int id) {
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

bool BST::search(int id) {
    if (root == NULL) {
        return false;
    }
    else {
        BSTNode* current = root;
        while (current != NULL) {
            if (current->data.getID() == id) {
                return true;
            } else if (current->data.getID() > id) {
                current = current->left;
            } else {
                current = current->right;
            }
        }
        return false;
    }
}

void BST::printBST(BSTNode *root) {
    if (root != NULL) {
        printBST(root->left);
        cout << "[" << root->data.getID() << ", " << root->data.getName() << ", " << root->data.getGPA() << ", "
             << root->data.getDepartment() << "]" << endl;
        printBST(root->right);
    }
}
void BST::printDepartment() {
    cout << "IT Department contains: " << numIT() << '\n';
    cout << "DS Department contains: " << numDS() << '\n';
    cout << "CS Department contains: " << numCS() << '\n';
    cout << "IS Department contains: " << numIS() << '\n';
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
    if(addStudent(id, name, gpa, department))
        cout<<"The student is added."<<endl;
    else
        cout<<"Wrong Data try again :)"<<endl;
}