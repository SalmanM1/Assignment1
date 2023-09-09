#include "Assignment1.h"
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <limits>
#include <exception>

using namespace std;

Assignment1::Assignment1(const string& fileName) : dataFileName(fileName) {}

// Load array elements from a text file
void Assignment1::loadFromFile() {
    ifstream inFile(dataFileName);
    if (!inFile.is_open()) {
        throw runtime_error("Unable to open file.");  // Required Try-Catch Block
    }

    int num;
    while (inFile >> num) {
        numberArray.push_back(num);
    }
}

int Assignment1::findElement(int element) {
    for (size_t i = 0; i < numberArray.size(); ++i) {
        if (numberArray[i] == element) return static_cast<int>(i);
    }
    return -1; // Element not found
}

// Replace an element at the given index with a new value
void Assignment1::changeElement(int index, int newValue, int& oldValue, int& changedValue) {
    if (index < 0 || index >= numberArray.size()) {
        throw out_of_range("Index out of bounds.");  // Required Try-Catch Block
    }
    oldValue = numberArray[index];
    numberArray[index] = newValue;
    changedValue = newValue;
}

// Add a new element at the end of the array
void Assignment1::addElement(int element) {
    numberArray.push_back(element);
}

// Set an element to zero at a given index
void Assignment1::zeroElement(int index) {
    if (index < 0 || index >= numberArray.size()) {
        throw out_of_range("Index out of bounds.");  // Required Try-Catch Block
    }
    numberArray[index] = 0;
}

// Show menu options to the user
void Assignment1::displayMenu() {
    cout << "The file has been successfully loaded.\n";
    cout << "Please enter a number to choose an option:\n";

    int choice, element, index, oldValue, changedValue;
    while (true) {
        cout << "1. Locate Element\n2. Change Element\n3. Insert Element\n4. Zero Element\n5. Exit\n";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter an integer from 1 to 5.\n";
            continue;
        }

        switch (choice) {
        case 1:
            cout << "Enter the element to locate: ";
            cin >> element;
            index = findElement(element);
            if (index != -1) {
                cout << "Element found at index " << index << ".\n";
            }
            else {
                cout << "Element not found.\n";
            }
            break;
        case 2:
            cout << "Enter the index and new value: ";
            cin >> index >> element;
            changeElement(index, element, oldValue, changedValue);
            cout << "Old value: " << oldValue << ", New value: " << changedValue << '\n';
            break;
        case 3:
            cout << "Enter the element to insert: ";
            cin >> element;
            addElement(element);
            cout << "Element inserted.\n";
            break;
        case 4:
            cout << "Enter the index to zero: ";
            cin >> index;
            zeroElement(index);
            cout << "Element zeroed at index " << index << ".\n";
            break;
        case 5:
            return;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    }
}

// Main function to load data and show user menu
int main() {
    Assignment1 handler("data.txt");

    try {
        // Required Try-Catch Block: Load array data from file and display user menu
        handler.loadFromFile();
        handler.displayMenu();
    }
    catch (exception& e) {
        // Exception handling: Print the error message
        cerr << "An error occurred: " << e.what() << '\n';
    }
    return 0;
}