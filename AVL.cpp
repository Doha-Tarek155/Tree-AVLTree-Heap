#include <bits/stdc++.h>
#include "studentClass.cpp"
using namespace std;

class AVLNode {
public:
    Student data;
    AVLNode* left;
    AVLNode* right;
    int height;

    AVLNode(Student student) : data(student) {
        this->left = NULL;
        this->right = NULL;
        this->height = 1;
    }
};

class AVL {
private:
    AVLNode *root;
    int size;
    void printAVL(AVLNode *root);
    int ds;
    int cs;
    int it;
    int is;

public:
    AVL();
    bool addStudent(int id, string name, double gpa, string department);
    void addstudent();
    void print();
    void printDepartment();
    void removeStudent(int id);
    void searchStudent(int id);
    int sizeAVL();
    bool search(int id);
    int numIT();
    int numCS();
    int numIS();
    int numDS();

private:
    int getHeight(AVLNode* node);
    int getBalance(AVLNode* node);
    AVLNode* rotateRight(AVLNode* node);
    AVLNode* rotateLeft(AVLNode* node);
    AVLNode* balance(AVLNode* node);
};

AVL::AVL() {
    root = NULL;
    size = 0;
    it=0;
    is=0;
    cs=0;
    ds=0;
}
int AVL::numCS() {
    return cs;
}
int AVL::numIS() {
    return is;
}int AVL::numIT() {
    return it;
}int AVL::numDS() {
    return ds;
}
int AVL::sizeAVL() {
    return size;
}

int AVL::getHeight(AVLNode* node) {
    if (node == NULL) {
        return 0;
    }
    return node->height;
}

int AVL::getBalance(AVLNode* node) {
    if (node == NULL) {
        return 0;
    }
    return getHeight(node->left) - getHeight(node->right);
}

AVLNode* AVL::rotateRight(AVLNode* node) {
    AVLNode* newRoot = node->left;
    AVLNode* temp = newRoot->right;
    newRoot->right = node;
    node->left = temp;
    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
    newRoot->height = max(getHeight(newRoot->left), getHeight(newRoot->right)) + 1;
    return newRoot;
}

AVLNode* AVL::rotateLeft(AVLNode* node) {
    AVLNode* newRoot = node->right;
    AVLNode* temp = newRoot->left;
    newRoot->left = node;
    node->right = temp;
    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
    newRoot->height = max(getHeight(newRoot->left), getHeight(newRoot->right)) + 1;
    return newRoot;
}

AVLNode* AVL::balance(AVLNode* node) {
    if (node == NULL) {
        return NULL;
    }
    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
    int balanceFactor = getBalance(node);

    if (balanceFactor > 1) {
        if (getBalance(node->left) < 0) {
            node->left = rotateLeft(node->left);
        }
        return rotateRight(node);
    } else if (balanceFactor < -1) {
        if (getBalance(node->right) > 0) {
            node->right = rotateRight(node->right);
        }
        return rotateLeft(node);
    }
    return node;
}

bool AVL::addStudent(int id, string name, double gpa, string department) {
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

        Student student(id, name, gpa, department);
        AVLNode *newNode = new AVLNode(student);

        if (root == NULL) {
            root = newNode;
        } else {
            AVLNode *current = root;
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
            root = balance(root);
        }
        size++;
        return true;
    }
    else
        return false;
}

void AVL::removeStudent(int id) {
    if (root == NULL) {
        cout << "AVL tree is empty." << endl;
        return;
    } else {
        AVLNode* current = root;
        AVLNode* parent = NULL;
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
        } else {
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
                AVLNode* successorParent = current;
                AVLNode* successor = current->right;
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
            } else { // node with one child
                AVLNode* child = (current->left != NULL) ? current->left : current->right;
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
            root = balance(root);
        }
    }
}

void AVL::searchStudent(int id) {
    if (root == NULL) {
        cout << "AVL tree is empty." << endl;
        return;
    }
    else {
        AVLNode* current = root;
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

bool AVL::search(int id) {
    if (root == NULL) {
        return false;
    } else {
        AVLNode* current = root;
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

void AVL::printDepartment() {
    cout << "IT Department contains: " << numIT() << '\n';
    cout << "DS Department contains: " << numDS() << '\n';
    cout << "CS Department contains: " << numCS() << '\n';
    cout << "IS Department contains: " << numIS() << '\n';
}


void AVL::printAVL(AVLNode *root) {

    if (root != NULL) {
        printAVL(root->left);
        cout << "[" << root->data.getID() << ", " << root->data.getName() << ", " << root->data.getGPA() << ", "
             << root->data.getDepartment() << "]" << endl;
        printAVL(root->right);
    }
}

void AVL::print() {
    printAVL(root);
}

void AVL::addstudent() {
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
