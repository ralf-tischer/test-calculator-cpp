#ifndef CALC_CLASSES_H
#define CALC_CLASSES_H

#include <iostream>
#include <stack>
#include <queue>
#include <unordered_map>
#include <stdexcept>
#include <string>

using namespace std;

/**
 * @brief A class for performing mathematical operations.
 * 
 * @tparam T The type of the numbers to be used in the operations.
 */
template <typename T>
class MathOperations {
private:
    T number1, number2;

public:
    /**
     * @brief Construct a new Math Operations object.
     * 
     * @param x The first number.
     * @param y The second number.
     */
    MathOperations(T x = 0, T y = 0)
        : number1(x), number2(y) {
        }

    /**
     * @brief Converts an infix expression to Reverse Polish Notation (RPN).
     * 
     * @param input The infix expression as a string.
     * @return queue<string> The RPN expression as a queue of strings.
     */
    queue<string> infixToRPN(const string& input) {
        unordered_map<char, int> precedence = {{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}};
        stack<char> operators;
        queue<string> output;
        size_t pos = 0;

        while (pos < input.size()) {
            if (isdigit(input[pos]) || input[pos] == '.') {
                string number;
                while (pos < input.size() && (isdigit(input[pos]) || input[pos] == '.')) {
                    number += input[pos++];
                }
                output.push(number);
            } else if (input[pos] == '(') {
                operators.push(input[pos++]);
            } else if (input[pos] == ')') {
                while (!operators.empty() && operators.top() != '(') {
                    output.push(string(1, operators.top()));
                    operators.pop();
                }
                operators.pop(); // Remove '('
                pos++;
            } else if (precedence.find(input[pos]) != precedence.end()) {
                while (!operators.empty() && precedence[operators.top()] >= precedence[input[pos]]) {
                    output.push(string(1, operators.top()));
                    operators.pop();
                }
                operators.push(input[pos++]);
            } else {
                pos++;
            }
        }

        while (!operators.empty()) {
            output.push(string(1, operators.top()));
            operators.pop();
        }

        return output;
    }

    /**
     * @brief Evaluates a Reverse Polish Notation (RPN) expression.
     * 
     * @param rpn The RPN expression as a queue of strings.
     * @return double The result of the evaluation.
     * @throws invalid_argument If an invalid operation is encountered.
     */
    double evaluateRPN(queue<string>& rpn) {
        stack<double> values;

        while (!rpn.empty()) {
            string token = rpn.front();
            rpn.pop();

            if (isdigit(token[0]) || (token[0] == '-' && token.size() > 1)) {
                values.push(stod(token));
            } else {
                double number2 = values.top(); values.pop();
                double number1 = values.top(); values.pop();
                values.push(calculate(number1, token[0], number2));
            }
        }

        return values.top();
    }

    /**
     * @brief Performs a calculation based on the given operation.
     * 
     * @param number1 The first number.
     * @param operation The operation to perform.
     * @param number2 The second number.
     * @return double The result of the calculation.
     * @throws invalid_argument If an invalid operation is encountered.
     */
    double calculate(T number1, char operation, T number2) {
        switch (operation) {
            case '+': return number1 + number2;
            case '-': return number1 - number2;
            case '*': return number1 * number2;
            case '/': 
                if (number2 == 0) throw invalid_argument("Division by zero");
                return number1 / number2;
            default: throw invalid_argument("Invalid operation");
        }
    }
};

#endif // CALC_CLASSES_H