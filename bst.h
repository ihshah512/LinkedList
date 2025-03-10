#ifndef BST_H
#define BST_H

#include <iostream>
#include <string>

using namespace std;

class Node{

public:
friend class BST;
Node(string val){
    m_value = val;
    m_left = nullptr;
    m_right = nullptr;
}
private:
string m_value;
Node * m_left;
Node * m_right;

};

class BST{

public:
BST();
~BST();
void clear();
void insert(string value);

private:
Node * m_root;
//private helper funciton
void clear(Node * & aNode);
void printSorted (Node * aNode);
void dump();
void copy(Node * & aNode, Node *rhsNode);
void insert(string value, Node * & aNode);//helpfer funciton

};

#endif