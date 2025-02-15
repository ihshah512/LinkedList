#include "list.h"
#include <stdexcept>

LinkedList::LinkedList() // constructor
    : m_head(nullptr)
{
}

LinkedList::~LinkedList() // destructor
{
    while (!empty())
        removeFront();
}

bool LinkedList::empty() const // is list empty?
{
    return m_head == nullptr;
}

const string &LinkedList::front() const
{ // get front element
    if (!empty())
        return m_head->m_elem;
    else
        throw runtime_error("Error: Reading front of empty list!");
}

void LinkedList::addFront(const string &toInsert)
{

    Node *newNodeAtFront = new Node;
    newNodeAtFront->m_elem = toInsert;

    newNodeAtFront->m_next = m_head; // connect the
    m_head = newNodeAtFront;         // update the head to new node
}

Node *const LinkedList::getHead() const
{

   return m_head;
}

void LinkedList::removeFront()
{
}
/*
void LinkedList::append(const string &toInsert)
{


        1. Frist check is the list empty
        2. Does list has only one node

    Node *m_nodeToInsert = new Node;

    m_nodeToInsert->m_next = nullptr;
    m_nodeToInsert->m_elem = toInsert;

    if (m_head == nullptr)
    {
        m_head = m_nodeToInsert;
        return;
    }

    Node *temp = m_head;

    while (temp->m_next != nullptr)
    {

        temp = temp->m_next;
    }

    temp->m_next = m_nodeToInsert;
}

void LinkedList::removeTail()
{

    // In case of empty list
    if (m_head == nullptr)
    {
        throw runtime_error("No tail to remove list is empty");
        return;
    }

    // In case of having one item in list head itself
    if (m_head->m_next == nullptr)
    {

        delete m_head;
        m_head = nullptr;
        return;
    }

    //in case of having multiple nodes
    Node *temp = m_head;
    while (temp->m_next->m_next != nullptr)
    {
        temp = temp->m_next;
    }
    delete temp->m_next;
    temp->m_next = nullptr;
}
*/
void LinkedList::addInBetween(const string &e,
                              const string &toInsert)
{
}

void LinkedList::remove(const string &e)
{
}

void LinkedList::printList()
{
    // to test this function:
    // case: the list is empty
    // case: the list is not empty
    Node *temp = m_head;
    cout << "The current list is:" << endl;
    while (temp != nullptr)
    {
        cout << temp->m_elem << " => ";
        temp = temp->m_next;
    }
    cout << "END" << endl;
}
// Apped the elemnet at the end of the linked list
void LinkedList::append(const string &toInsert)
{
    /*
        1. First check the LL is empty of not
        2. Create the node you want to insert
        3. What if there is only one node in the LL
    */

    Node *nodeToInsert = new Node;
    nodeToInsert->m_next = nullptr;
    nodeToInsert->m_elem = toInsert;

    if (m_head == nullptr)
    {
        m_head = nodeToInsert;
        return;
    }
    Node *temp = m_head;

    while (temp->m_next != nullptr)
    {
        temp = temp->m_next;
    }

    temp->m_next = nodeToInsert;
}

void LinkedList::removeTail()
{
    // Check if the list is empty
    if (m_head == nullptr)
    {
        return;
    }
    // if LL has only one item
    if (m_head->m_next == nullptr)
    {
        delete m_head;
        m_head == nullptr;
        return;
    }
    Node *temp = m_head;

    while (temp->m_next->m_next != nullptr)
    {
        temp = temp->m_next;
    }
    Node *toDelete = temp->m_next;
    temp->m_next = nullptr;
    delete toDelete;
}

const string &LinkedList::getTailEle() const
{ // get front element
    if(m_head == nullptr){
        throw runtime_error("Error: Reading front of empty list!");
        return m_head->m_elem;
    }
    if(m_head->m_next == nullptr){
        return m_head->m_elem;
    }
    Node *temp = m_head;
    while (temp->m_next != nullptr){
        temp = temp->m_next;
    }
    return temp->m_elem;
}