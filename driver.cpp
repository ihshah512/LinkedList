#include "list.h"
using namespace std;
bool testAddFront1();
// bool testAddFront2();
bool testAppend();
bool testRemoveTail();
bool testRemoveFront1();

// this is a sample driver program
// it is not a rigorous test program
// in projects we need to test rigorously
int main()
{
    cout << "Append function passed" << testAppend() << endl;

    /*
    if (testAppend())
     {
         cout << "Apped functon worked, all items in string array added succesfully into list" << endl;
     }
     else
     {
         throw runtime_error("Unable to append items into list");
     }

    */

    /*cout << testAddFront1() << endl;
    cout << testAddFront2() << endl;

    // aPath.printList();
    try
    {
        testAddFront1();
        testAddFront2();
        //  testRemoveFront1();
    }
    catch (std::runtime_error &e)
    {
        cout << "testRemoveFront1() PASSED!" << endl;
        cout << e.what() << endl;
    }

    aPath.printList();

    */
    return 0;
}
/***************************************
 * Test removeFront() on empty list
 * ************************************/
/*void testRemoveFront1()
{
    LinkedList aPath;
    aPath.removeFront();
}
/***************************************
 * Test addFront() on empty list
 * ************************************/
/*bool testAddFront1()
{
    LinkedList aPath;
    aPath.addFront("ATL");
    if ("ATL" == aPath.front())
    {
        cout << "testAddFront1() PASSED!" << endl;
        return true;
    }
    else
    {
        cout << "testAddFront1() FAILED!" << endl;
        return false;
    }
}
/***************************************
 * Test addFront() on non-empty list
 * Test removeFront() on non-empty list
 * Test front() on non-empty list
 * ************************************/
/*bool testAddFront2()
{
    bool returnVal = false;

    string airports[] = {"BOS", "ATL", "MSP", "LAX"};
    for (int i = 0; i < 4; i++)
        aPath.addFront(airports[i]);
    for (int j = 4; j > 0; j--)
    {
        if (aPath.front() == airports[j])
        {
            returnVal = true;
            // aPath.removeFront();
        }
        else
            returnVal = false;
    }
    return returnVal;
}
*/
bool testAppend()
{
    LinkedList aPath;
    bool result = false;
    ;
    string students[] = {"Imran", "Rizwan", "Ahatsham", "Ambreen"};

    int lengthOfStrArr = sizeof(students) / sizeof(students[0]);

    for (int ix = 0; ix < lengthOfStrArr; ix++)
    {
        aPath.append(students[ix]);
    }

    // aPath.printList();

    int index = lengthOfStrArr;
    int counter = 0;
    while (!aPath.empty())
    {
        // Check if the last appened element into the list is
        // not equal to the last element of the string array
        if (!(aPath.getTailEle() == students[index - 1]))
        {
            return result; // return false if not equal
        }
    }

    result = true;
    return true; // return true if equal which verifies that
    // last element appended into the list was appended succesfully
}
bool testRemoveTail()
{

    return true;
}