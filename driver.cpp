#include "list.h"
using namespace std;
bool testAddFront1();
bool testAddFront2();
bool testAppend();
bool testRemoveTail();
bool testRemoveFront1();
bool testGetTailEle();

// this is a sample driver program
// it is not a rigorous test program
// in projects we need to test rigorously

int main()
{

    if (testGetTailEle())
        cout << "Get tail test pass : " << endl;
    else
        cout << "fail" << endl;
    /*
    if (testAppend())
     {

         cout << "+++++++++++++++++++++ " << endl;
     }
     else
     {
         cout << "Append function failed" << endl;
     }

    */

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

bool testGetTailEle()
{
    bool result = false;
    LinkedList aPath;
    string students[] = {"Imran", "Rizwan", "Ahatsham", "Ambreen"};

    int lengthOfStrArr = sizeof(students) / sizeof(students[0]);

    for (int ix = 0; ix < lengthOfStrArr; ix++)
    {
        aPath.append(students[ix]);
    }
    aPath.printList();

    // Math the last element with the tail element

    string tailEle = aPath.getTailEle();
    string arrayLastEle = students[lengthOfStrArr - 1];

    if (tailEle == arrayLastEle)
    {
        result = true;
        return result;
    }
    return result;
}

bool testAppend()
{

    LinkedList aPath;
    try
    {
        cout << "Starting testAppend()..." << endl; // Debugging message
                                                    //   LinkedList aPath;
        string students[] = {"Imran", "Rizwan", "Ahatsham", "Ambreen"};

        int lengthOfStrArr = sizeof(students) / sizeof(students[0]);

        for (int ix = 0; ix < lengthOfStrArr; ix++)
        {
            cout << "Appending: " << students[ix] << endl; // Debugging message
            aPath.append(students[ix]);
        }

        // Append one more element to test
        cout << "Appending: Taskeen" << endl; // Debugging message
        aPath.append("Taskeen");

        // Debugging message
        cout << "Trying to get last element..." << endl;
        string lastElement = aPath.getTailEle();
        cout << "Last element should be Taskeen: " << lastElement << endl;

        // Check if the last appended element is "Taskeen"
        if (lastElement != "Taskeen")
        {
            cout << "Test failed! Last element is: " << lastElement << endl;
            return false;
        }

        cout << "Append test passed!" << endl;
        return true;
    }
    catch (const exception &e)
    {
        cout << "Exception in testAppend(): " << e.what() << endl;
        return false;
    }
}

bool testRemoveTail()
{

    return true;
}

bool testRemoveTail()
{
    try
    {
        // 1. Test Removing from an Empty List (Case 1)
        {
            LinkedList myList;
            try
            {
                myList.removeTail(); // Should throw an exception
                cout << "Test Failed: Expected an exception when removing from an empty list." << endl;
                return false;
            }
            catch (const runtime_error &e)
            {
                cout << "Test Passed: Caught exception - " << e.what() << endl;
            }
        }

        // 2. Test Removing from a List with One Element (Case 2)
        {
            LinkedList myList;
            myList.append("A");
            myList.removeTail();

            if (myList.isEmpty()) // Assuming isEmpty() checks `m_head == nullptr`
            {
                cout << "Test Passed: Single element removed correctly." << endl;
            }
            else
            {
                cout << "Test Failed: List is not empty after removing the only element." << endl;
                return false;
            }
        }

        // 3. Test Removing from a List with Two Elements (Case 3)
        {
            LinkedList myList;
            myList.append("A");
            myList.append("B");  // List: A → B
            myList.removeTail(); // Remove "B"

            if (myList.getTailEle() == "A")
            {
                cout << "Test Passed: Last element removed, first element remains." << endl;
            }
            else
            {
                cout << "Test Failed: Incorrect last element after removal." << endl;
                return false;
            }
        }

        // 4. Test Removing from a List with Multiple Elements (Case 4)
        {
            LinkedList myList;
            myList.append("A");
            myList.append("B");
            myList.append("C");  // List: A → B → C
            myList.removeTail(); // Remove "C"

            if (myList.getTailEle() == "B")
            {
                cout << "Test Passed: Last element removed, previous element is new tail." << endl;
            }
            else
            {
                cout << "Test Failed: Tail is incorrect after removal." << endl;
                return false;
            }
        }

        // 5. Test Removing Until the List is Empty (Case 5)
        {
            LinkedList myList;
            myList.append("X");
            myList.append("Y");
            myList.append("Z"); // List: X → Y → Z

            myList.removeTail(); // Removes "Z"
            myList.removeTail(); // Removes "Y"
            myList.removeTail(); // Removes "X"

            if (myList.isEmpty())
            {
                cout << "Test Passed: List is empty after multiple removals." << endl;
            }
            else
            {
                cout << "Test Failed: List should be empty but is not." << endl;
                return false;
            }
        }

        return true; // All tests passed
    }
    catch (const exception &e)
    {
        cout << "Exception in testRemoveTail(): " << e.what() << endl;
        return false;
    }
}
