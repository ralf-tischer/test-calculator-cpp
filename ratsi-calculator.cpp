#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>
#include "calc-classes.hpp"

const std::string WELCOME_FILE_PATH = "Assets/welcome.txt";

/**
 * @brief Converts the input string to a number.
 * 
 * @param input The input string to convert.
 * @return double The converted number.
 * @throws invalid_argument If the input is not a valid number.
 * @throws out_of_range If the number is out of range.
 */
double convertInputToNumber(const std::string& input) {
    try {
        return std::stod(input);
    } catch (const std::invalid_argument& e) {
        throw std::invalid_argument("Invalid number format");
    } catch (const std::out_of_range& e) {
        throw std::out_of_range("Number out of range");
    }
}

/**
 * @brief Reads the welcome message from a file.
 * 
 * @param filePath The path to the file containing the welcome message.
 * @return std::string The welcome message.
 */
std::string readWelcomeMessageFromFile(const std::string& filePath) {
    std::ifstream inputFile(filePath);
    if (inputFile.is_open()) {
        std::string line = "";
        std::string content = "";
        while (std::getline(inputFile, line)) {
            if (!content.empty()) {
                content += "\n";
            }
            content += line;
        }
        inputFile.close();
        return content;
    } else {
        std::cerr << "Error: Unable to open file." << std::endl;
        return "";
    }
}

/**
 * @brief The main function of the RATSI Calculator.
 * 
 * @return int Exit status of the program.
 */
int main()
{
    std::string input;

    std::cout << "********************" << std::endl;
    std::cout << "* RATSI CALCULATOR *" << std::endl;
    std::cout << "********************" << std::endl;
    std::cout << readWelcomeMessageFromFile(WELCOME_FILE_PATH) << std::endl << std::endl;
    
    MathOperations<double> mathOps;

    while (true) {
        std::cout << "Enter your calculation: ";
        std::getline(std::cin, input);
        
        if (input == "x" || input.empty()) {
            break;
        }

        try {
            std::queue<std::string> rpn = mathOps.infixToRPN(input);
            double result = mathOps.evaluateRPN(rpn);
            std::cout << "Result: " << result << std::endl;
        } catch (const std::exception& e) {
            std::cout << "Error: " << e.what() << std::endl;
        }
    }
    return 0;
}