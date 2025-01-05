#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include <vector>
#include "calc-classes.hpp"

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
bool parseInput(const string& input, vector<double>& numbers, vector<char>& operations);
string readWelcomeMessageFromFile(const string& filePath);

int main()
{
    string filePath = "Assets/test.txt";
    string input;
    vector<double> numbers;
    vector<char> operations;

    cout << "********************" << endl;
    cout << "* RATSI CALCULATOR *" << endl;
    cout << "********************" << endl;
    cout << readWelcomeMessageFromFile(filePath) << endl << endl;
    
    while (true) {
        numbers.clear();
        operations.clear();

        cout << "Enter your calculation: ";
        getline(cin, input);
        if (input == "x") {
            break;
        }

        if (!parseInput(input, numbers, operations)) {
            cout << "Invalid input. Please enter a valid calculation." << endl;
            continue;
        }

        // First pass: handle * and /
        for (size_t i = 0; i < operations.size(); ++i) {
            if (operations[i] == '*' || operations[i] == '/') {
                numbers[i] = calculate(numbers[i], operations[i], numbers[i + 1]);
                numbers.erase(numbers.begin() + i + 1);
                operations.erase(operations.begin() + i);
                --i; // Adjust index after erasing
            }
        }

        // Second pass: handle + and -
        double result = numbers[0];
        for (size_t i = 0; i < operations.size(); ++i) {
            result = calculate(result, operations[i], numbers[i + 1]);
        }

        cout << "Result: " << result << endl;
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

bool parseInput(const string& input, vector<double>& numbers, vector<char>& operations) {
    size_t pos = 0;
    size_t nextPos = 0;

    while (nextPos != string::npos) {
        nextPos = input.find_first_of("+-*/", pos);
        string numStr = input.substr(pos, nextPos - pos);

        try {
            numbers.push_back(convertInputToNumber(numStr));
        } catch (const invalid_argument&) {
            return false;
        } catch (const out_of_range&) {
            return false;
        }

        if (nextPos != string::npos) {
            operations.push_back(input[nextPos]);
            pos = nextPos + 1;
        }
    }

    return true;
}

double convertInputToNumber(const string& input) {
    try {
        return stod(input);
    } catch (const invalid_argument& e) {
        throw invalid_argument("Invalid number format");
    } catch (const out_of_range& e) {
        throw out_of_range("Number out of range");
    }
}

OpsType getOpsType(char operation) {
    switch (operation) {
        case '+': return ADD;
        case '-': return SUBTRACT;
        case '*': return MULTIPLY;
        case '/': return DIVIDE;
        default: throw invalid_argument("Invalid operation");
    }
}

template <typename T>
double calculate(T number1, char operation, T number2) {
    switch (getOpsType(operation)) {
        case ADD: return number1 + number2;
        case SUBTRACT: return number1 - number2;
        case MULTIPLY: return number1 * number2;
        case DIVIDE: 
            if (number2 == 0) throw invalid_argument("Division by zero");
            return number1 / number2;
        default: throw invalid_argument("Invalid operation");
    }
}