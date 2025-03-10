#include "bst.h"

BST::BST(){
    m_root = nullptr;

}

BST::~BST(){
    clear();
}

void BST::clear(){

clear(m_root);


}

void BST::clear(Node * & aNode){

    if(aNode != nullptr){//heck if the tree is empty or not we are doing postorder travesel

    clear(aNode->m_left);
    clear(aNode->m_right);
    delete aNode;
    aNode = nullptr;

    }//copy constrcuor cant be crated from postorder traversal we have to use preorder traversal

}

BST::BST(const BST &rhs){

    copy(m_root, rhs.m_root);
}

void BST::copy(Node * & aNode, Node *rhsNode){

        //recursion itself is a loop dont need to run a loop sepratly
        //current tree is empty so root is empty
        //pre order 1. visit node parents visit left visit right
        //create a new memmory value is coming from right hand side
// this is preorder traversal we cant do it in any other order
        if(rhsNode != nullptr)
        {                                                                                                  // 180

            aNode = new Node(rhsNode->m_value);
            copy(aNode->m_left, rhsNode->m_left);
            copy(aNode->m_right, rhsNode->m_right);
        }

}

//in order traversal vist left child then visit node parent and visit child
//in order it self is a sorting algorithm if we run it on BST

void BST::dump(){


printSorted(m_root);

}

void BST::printSorted(Node * aNode){

    if(aNode != nullptr){
        //first traverse left child
        printSorted(aNode->m_left);
        cout << aNode->m_value << " ";
        printSorted(aNode->m_right);

    }

}

//insert 95 in bst we have mantian property of BST ROOT IS 100 so 95 will go on left side

void BST::insert(string value){

    insert(value, m_root);

}

void BST::insert(string value, Node * & aNode){

 if (aNode == nullptr){//once we see the null we need to create a node with rovided value
//secondly check if the val is less than send val to left otherwise snd it to right
    aNode = new Node(value);
 }
 else if (value < aNode->m_value){
    insert(value, aNode->m_left);
 }
 else if(value > aNode->m_value){
    insert(value, aNode->m_right);
 }
 

    

}