#include <cmath>

using namespace std;

class MyException {
private:
    const char* message;
public:
    MyException(const char* message) : message(message) {}

    const char* GetMessage() const {
        return message;
    }
};

class QuadraticEquation {
private:
    double _variable_a;
    double _variable_b;
    double _variable_c;
public:
    QuadraticEquation(double _variable_a, double _variable_b, double _variable_c) {
        this->_variable_a = _variable_a;
        if (_variable_a == 0) {
            throw MyException("a = 0");
        }
        this->_variable_b = _variable_b;
        this->_variable_c = _variable_c;
    }
    double Solve() {
        double dis = Discriminant();
        if (dis < 0) {
            throw MyException("no real roots");

        }
        double x1 = FindFirstRoot(dis);
        double x2 = FindSecondRoot(dis);
        double x = (x2 + x1) / 2;
        return x;
    }
    double Discriminant() {
        return (_variable_b * _variable_b) - 4 * _variable_a * _variable_c;
    }
    double FindFirstRoot(double dis) {
        return (-1 * _variable_b + sqrt(dis)) / (2 * _variable_a);
    }
    double FindSecondRoot(double dis) {
        return (-1 * _variable_b - sqrt(dis)) / (2 * _variable_a);
    }
};
