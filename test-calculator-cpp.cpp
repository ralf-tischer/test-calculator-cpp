#include <iostream>
#include <fstream>
#include <string>
#include "calc-classes.h"

using namespace std;

// Operation enum 
enum OpsType {
    ADD = 1,    // 1
    SUBTRACT,   // 2
    MULTIPLY,   // 3
    DIVIDE      // 4 
};

// Declaration
template <typename T>
double calculate(T number1, char operation, T number2);
OpsType getOpsType(char operation);

int main()
{
    string filePath = "Assets/test.txt";

    string input = "x";
    int number1 = 0, number2 = 0;
    char operation = '+';

    cout << "*************************" << endl;
    cout << "* RATSIS TASCHENRECHNER *" << endl;
    cout << "*************************" << endl;

    ifstream inputFile(filePath);
    if (inputFile.is_open()) {
        string line;
        while (getline(inputFile, line)) {
            cout << line << endl;
        }
        inputFile.close();
    }
    else {
        cout << "Error: Unable to open file." << endl;
    }

    while (true) {
        cout << endl << "Number 1 (or 'x' to end): ";
        cin >> input;
        if (input == "x") {
            break;
        }
        number1 = stoi(input); // Convert input to integer

        cout << "Operation (+, -, *, /): ";
        cin >> operation;
        cout << "Number 2: ";
        cin >> number2;

        cout << "Result: " << calculate(number1, operation, number2) << endl;
    }
    return 0;
}

OpsType getOpsType(char operation) {
    OpsType result = ADD;   // default

    if (operation == '-') {
        result = SUBTRACT;
    }
    else if (operation == '*') {
        result = MULTIPLY;
    }
    else if (operation == '/') {
        result = DIVIDE;
    }
    return result;
}

template <typename T>
double calculate(T number1, char operation, T number2) {
    double result = 0.0;
    MathOperations<T> myCalculation(number1, number2); // init

    switch (getOpsType(operation)) {
    case ADD: // Add
        result = myCalculation.add();
        break;
    case SUBTRACT: // Subtract
        result = myCalculation.subtract();
        break;
    case MULTIPLY: // Multiply
        result = myCalculation.multiply();
        break;
    case DIVIDE: // Divide
        result = myCalculation.divide();
        break;
        // Add further cases here  
    default:
        result = 0.0;
    }
    return result;
}