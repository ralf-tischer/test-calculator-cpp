#ifndef CALC_CLASSES_H
#define CALC_CLASSES_H

#include <stdexcept>

template <typename T>
class MathOperations {
private:
    T number1;
    T number2;

public:
    MathOperations(T x = 0, T y = 0)
        : number1(x), number2(y) {}

    T add() const {
        return number1 + number2;
    }

    T subtract() const {
        return number1 - number2;
    }

    T multiply() const {
        return number1 * number2;
    }

    T divide() const {
        if (number2 != 0) {
            return number1 / number2;
        } else {
            throw std::runtime_error("Division by zero");
        }
    }
};

#endif // CALC_CLASSES_H