// test-project-cpp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#pragma once
#include <iostream>
#include <string>

using namespace std;

// Class definition
class MathOperations {
public:
    int number1, number2;
    MathOperations(int x = 0, int y = 0) {
        number1 = x;
        number2 = y;
    }
    double add();
    double subtract();
    double multiply();
    double divide();
};

// Operation enum 
enum OpsType {
    ADD = 1,    // 1
    SUBTRACT,   // 2
    MULTIPLY,   // 3
    DIVIDE      // 4 
};

// Declaration
double calculate(int number1, char operation, int number2);
OpsType getOpsType(char operation);

int main()
{
    string input;
    int number1 = 0, number2 = 0;
    char operation = '+';

    cout << "*************************" << endl;
    cout << "* RATSIS TASCHENRECHNER *" << endl;
    cout << "*************************" << endl;

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

double calculate(int number1, char operation, int number2) {
    double result = 0.0;
    MathOperations myCalculation(number1, number2); // init

    switch (getOpsType(operation)) {
    case 1: // Add
        result = myCalculation.add();
        break;
    case 2: // Subtract
        result = myCalculation.subtract();
        break;
    case 3: // Multiply
        result = myCalculation.multiply();
        break;
    case 4: // Divide
        result = myCalculation.divide();
        break;
        // Add further cases here  
    default:
        result = 0.0;
    }
    return result;
}

double MathOperations::add() {
    return MathOperations::number1 + MathOperations::number2;
}

double MathOperations::subtract() {
    return MathOperations::number1 - MathOperations::number2;
}

double MathOperations::multiply() {
    return MathOperations::number1 * MathOperations::number2;
}

double MathOperations::divide() {
    if (MathOperations::number2 == 0) {
        return 0.0;
    }
    else {
        return (double)MathOperations::number1 / MathOperations::number2;
    }
}