#include "dll.h"
DLL::DLL(){
    m_head = nullptr;
    m_tail = nullptr;
}
DLL::~DLL(){
    Node * temp = nullptr;
    while (!empty()){
        temp = m_head;
        m_head = m_head->m_next;
        delete temp;
    }
    m_head = nullptr;
    m_tail = nullptr;
}
void DLL::insertAtHead(string toInsert){
    // list empty
    // not empty
    Node * newNode = new Node;
    newNode->m_data = toInsert;
    if (empty()){
        m_head = newNode;
        m_tail = newNode;
    }
    else{
        newNode->m_next = m_head;
        m_head->m_previous = newNode;
        m_head = newNode;
    }
}
void DLL::addInBetween(string location, string toInsert){
    // list is empty
    // only one node (is it location?)
    // two nodes (is tail the location?)
    // multiple nodes (location is there)
    // multiple nodes (location is not there)
    if (!empty()){
        if (m_head->m_data == location){
            Node * newNode = new Node;
            newNode->m_data = toInsert;
            m_head->m_previous = newNode;
            newNode->m_next = m_head;
            m_head = newNode;
        }
        else{
            Node * temp = m_head;
            while(temp->m_next->m_next != nullptr &&
                    temp->m_next->m_data != location){
                    temp = temp->m_next;
            }
            if (temp->m_next->m_data == location){
                Node * newNode = new Node;
                newNode->m_data = toInsert;
                newNode->m_next = temp->m_next;
                temp->m_next->m_previous = newNode;
                newNode->m_previous = temp;
                temp->m_next = newNode;
            }
        }
    }
}

void DLL::remove(string & toRemove){
    // list is empty
    // list not empy
        // toRemove is the first
        // toRemove is the last
        // toRemove is in the middle
        // there is no toRemove
        if (!empty()){
            // toRemove is first
            if (m_head->m_data == toRemove){
                Node* toDel = m_head;
                m_head = m_head->m_next;
                m_head->m_previous = nullptr;
                delete toDel;
            }
            else if (m_tail->m_data == toRemove){ // toRemove is the last one
                Node * toDel = m_tail;
                m_tail = toDel->m_previous;
                m_tail->m_next = nullptr;
                delete toDel;
            }
            else{ // toRemove is in the middle
                Node* temp = m_head;
                while(temp->m_next->m_next != nullptr &&
                    temp->m_next->m_data != toRemove){
                        temp = temp->m_next;
                    }
                    if (temp->m_next->m_data == toRemove){
                        Node* toDel = temp->m_next;
                        temp->m_next = toDel->m_next;
                        toDel->m_next->m_previous = temp;
                        delete toDel;
                    }
            }
        }
}

bool DLL::empty() const {
    return (m_head == nullptr);
}

void DLL::dump() const {
    if (!empty()){
        Node * temp = m_head;
        while (temp != nullptr){
            cout << temp->m_data << " ";
            temp = temp->m_next;
        }
    }
}