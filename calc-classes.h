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
        : number1(x), number2(y) {
            cout << "Received number1: " << number1 << ", number2: " << number2 << endl;
        }

    T add() const {
        cout << "Adding " << number1 << " and " << number2 << endl;
        return number1 + number2;
    }

    T subtract() const {
        cout << "Subtracting " << number2 << " from " << number1 << endl;
        return number1 - number2;
    }

    T multiply() const {
        cout << "Multiplying " << number1 << " by " << number2 << endl;
        return number1 * number2;
    }

    T divide() const {
        cout << "Dividing " << number1 << " by " << number2 << endl;
        if (number2 != 0) {
            return number1 / number2;
        } else {
            throw std::runtime_error("Division by zero");
        }
    }
};

#endif // CALC_CLASSES_H