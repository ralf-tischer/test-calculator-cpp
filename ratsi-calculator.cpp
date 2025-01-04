#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
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
double convertInputToNumber(const string& input);
OpsType getOpsType(char operation);
bool parseInput(const string& input, double& number1, char& operation, double& number2);
string readWelcomeMessageFromFile(const string& filePath);

int main()
{
    string filePath = "Assets/test.txt";

    string input;
    double number1 = 0, number2 = 0;
    char operation = '+';

    cout << "********************" << endl;
    cout << "* RATSI CALCULATOR *" << endl;
    cout << "********************" << endl;

    cout << readWelcomeMessageFromFile(filePath) << endl;

    while (true) {
        cout << endl << "Enter calculation (example: 12 + 34) or 'x' to end: ";
        getline(cin, input);
        if (input == "x") {
            break;
        }

        if (!parseInput(input, number1, operation, number2)) {
            cout << "Invalid input. Please enter a valid calculation." << endl;
            continue;
        }

        cout << "Result: " << calculate(number1, operation, number2) << endl;
    }
    return 0;
}

string readWelcomeMessageFromFile(const string& filePath) {
    ifstream inputFile(filePath);
    if (inputFile.is_open()) {
        string line = "";
        string content = "";
        while (getline(inputFile, line)) {
            if (content != "") {
                content += "\n";
            }
            content += line;
        }
        inputFile.close();
        return content;
    } else {
        cout << "Error: Unable to open file." << endl;
        return "";
    }
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

double convertInputToNumber(const string& input) {
    try {
        if (input.find('.') != string::npos) {
            return stod(input); // Convert input to double
        } else {
            return stoi(input); // Convert input to integer
        }
    } catch (const invalid_argument& e) {
        cout << "Invalid input. Please enter a valid number." << endl;
        throw;
    } catch (const out_of_range& e) {
        cout << "Input is out of range. Please enter a valid number." << endl;
        throw;
    }
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

bool parseInput(const string& input, double& number1, char& operation, double& number2) {
    size_t pos = input.find_first_of("+-*/");
    if (pos == string::npos) {
        return false;
    }

    string num1Str = input.substr(0, pos);
    string num2Str = input.substr(pos + 1);
    operation = input[pos];

    try {
        number1 = convertInputToNumber(num1Str);
        number2 = convertInputToNumber(num2Str);
    } catch (const invalid_argument&) {
        return false;
    } catch (const out_of_range&) {
        return false;
    }

    return true;
}