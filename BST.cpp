#include<bits/stdc++.h>
#include "readFromFile.cpp"
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
    BSTNode *root;
    void printBST(BSTNode *root);

public:
    BST();
    void addStudent(int id, string name, double gpa, string department);

    void print();
};

BST::BST() {
    root=NULL;
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

}

void BST::printBST(BSTNode *root) {
    if(root!=NULL){
        printBST(root->left);
        cout<< "ID: "<<root->data.getID()<<endl;
        cout<< "Name: "<<root->data.getName()<<endl;
        cout<< "GPA: "<<root->data.getGPA()<<endl;
        cout<< "Department: "<<root->data.getDepartment()<<endl;
        printBST(root->right);
    }
}

void BST::print() {
    printBST(root);
}

int main(){
    BST bst;
    vector<Student> students = readFromFile();
    for(auto student: students){
        bst.addStudent(student.getID(),student.getName(),student.getGPA(),student.getDepartment());
    }
    bst.addStudent(12,"Asmaa Ahmed", 3.1, "CS");
    bst.print();
    return 0;
}