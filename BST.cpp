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
public:
    BST() {
        root = NULL;
    }
    void addStudent(int id, string name, double gpa, string department);

    void printBST(BSTNode *root);

    void print();
};

int main(){
    BST bst;
    vector<Student> students = readFromFile();
}