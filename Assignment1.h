#ifndef ASSIGNMENT1_H
#define ASSIGNMENT1_H

#include <vector>
#include <string>

using namespace std;

// Assignment1 class definition
class Assignment1 {
public:
    // Constructor to initialize file name
    Assignment1(const string& fileName);

    // Required Function: Load array elements from a text file
    void loadFromFile();

    // Required Function: Find the index of an element in the array
    int findElement(int element);

    // Required Function: Replace an element at the given index with a new value
    void changeElement(int index, int newValue, int& oldValue, int& changedValue);

    // Required Function: Add a new element at the end of the array
    void addElement(int element);

    // Required Function: Set an element to zero at a given index
    void zeroElement(int index);

    // Display menu options to the user
    void displayMenu();

private:
    // Vector to hold the array elements
    vector<int> numberArray;

    // File name for array data
    string dataFileName;
};

#endif // ASSIGNMENT1_H