// classes.h
// Define the class MathOperations

#pragma once

/**
 * @class MathOperations
 * @brief A class to perform basic arithmetic operations.
 *
 * The MathOperations class provides methods to perform addition, subtraction,
 * multiplication, and division on two integer numbers.
 */
class MathOperations
{
public:
    int number1 = 0; ///< The first number for the arithmetic operation.
    int number2 = 0; ///< The second number for the arithmetic operation.

    /**
     * @brief Constructor to initialize the numbers.
     * @param x The first number (default is 0).
     * @param y The second number (default is 0).
     */
    MathOperations(int x = 0, int y = 0)
    {
        number1 = x;
        number2 = y;
    }

    /**
     * @brief Adds the two numbers.
     * @return The sum of number1 and number2.
     */
    double add();

    /**
     * @brief Subtracts the second number from the first number.
     * @return The difference between number1 and number2.
     */
    double subtract();

    /**
     * @brief Multiplies the two numbers.
     * @return The product of number1 and number2.
     */
    double multiply();

    /**
     * @brief Divides the first number by the second number.
     * @return The quotient of number1 divided by number2. Returns 0.0 if number2 is 0.
     */
    double divide();
};

// Method implementations

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
    if (MathOperations::number2 == 0)
    {
        return 0.0;
    }
    else
    {
        return (double)MathOperations::number1 / MathOperations::number2;
    }
}