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
    // Step 1: Create the new node
    Node *nodeToInsert = new Node;
    nodeToInsert->m_elem = toInsert;
    nodeToInsert->m_next = nullptr;

    // Step 2: Check if list is empty
    if (m_head == nullptr)
    {
        m_head = nodeToInsert;
        return;
    }

    // Step 3: Traverse to the last node
    Node *temp = m_head;
    while (temp->m_next != nullptr)
    {
        temp = temp->m_next;
    }

    // Step 4: Append the new node
    temp->m_next = nodeToInsert;
}

void LinkedList::removeTail()
{
    // Check if the list is empty
    if (m_head == nullptr)
    {
        throw runtime_error("List is empty cant remove tail");
    }
    // if LL has only one item
    if (m_head->m_next == nullptr)
    {
        delete m_head;
        m_head = nullptr;
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
{
    if (m_head == nullptr)
    {
        throw runtime_error("List is empty");
    }

    Node *temp = m_head;
    while (temp->m_next != nullptr)
    {
        temp = temp->m_next;
    }
    return temp->m_elem;
}

LinkedList &LinkedList::operator=(const LinkedList &orignal)
{

    // First we would need to check self assignment
    if (this == &orignal)
    {

        return *this;
    }

    // Check if the orignal list is empty or not if empty then set the head of copyToList
    // to nullptr and return it.
    if (orignal.m_head == nullptr)
    {
        m_head = nullptr;
        return *this;
    }

    // Now adelete all the nodes of copyToList to avoid any memory leaks
    Node *temp;
    while (m_head)
    {
        temp = m_head;
        m_head = m_head->m_next;
        delete temp;
    }

    // Now copyToList is competly empty now copy over the orignal list nodes into "this"

    m_head = new Node(orignal.m_head->m_elem);
    Node *current = m_head;
    Node *orignalNode = orignal.m_head->m_next;

    // 5. Deep copy the rest of the nodes
    while (orignalNode)
    {
        current->m_next = new Node(orignalNode->m_elem); // Correct deep copy
        current = current->m_next;
        orignalNode = orignalNode->m_next;
    }

    return *this;
}