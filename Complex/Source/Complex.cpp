#include "Complex.h"
#include <stdexcept>
#include <string>

namespace std {
    double abs(const Complex& c) {
        return std::sqrt(c.Real() * c.Real() + c.Imag() * c.Imag());
    }
}

Complex Complex::operator+(const Complex& c) const {
    return Complex(real + c.real, img + c.img);
}

Complex& Complex::operator+=(const Complex& c) {
    real += c.real;
    img += c.img;
    return *this;
}

Complex Complex::operator-(const Complex& c) const {
    return Complex(real - c.real, img - c.img);
}

Complex& Complex::operator-=(const Complex& c) {
    real -= c.real;
    img -= c.img;
    return *this;
}

Complex Complex::operator*(const Complex& c) const {
    return Complex(
            real * c.real - img * c.img,
            real * c.img + img * c.real
    );
}

Complex& Complex::operator*=(const Complex& c) {
    double r = real * c.real - img * c.img;
    double i = real * c.img + img * c.real;
    real = r;
    img = i;
    return *this;
}

Complex Complex::operator/(const Complex& c) const {
    double denominator = c.real * c.real + c.img * c.img;
    if (denominator < EPSILON) {
        throw std::overflow_error("Division by zero");
    }
    return Complex(
            (real * c.real + img * c.img) / denominator,
            (img * c.real - real * c.img) / denominator
    );
}

Complex& Complex::operator/=(const Complex& c) {
    double denominator = c.real * c.real + c.img * c.img;
    if (denominator < EPSILON) {
        throw std::overflow_error("Division by zero");
    }
    double r = (real * c.real + img * c.img) / denominator;
    double i = (img * c.real - real * c.img) / denominator;
    real = r;
    img = i;
    return *this;
}

bool Complex::operator==(const Complex& c) const {
    return std::fabs(real - c.real) < EPSILON &&
           std::fabs(img - c.img) < EPSILON;
}

bool Complex::operator!=(const Complex& other) const {
    return !(*this == other);
}

std::ostream& operator<<(std::ostream& os, const Complex& c) {
    os << c.real;
    if (c.img >= 0) {
        os << '+';
    }
    os << c.img << 'i';
    return os;
}

std::istream& operator>>(std::istream& is, Complex& c) {
    std::string input;
    is >> input;
    size_t plusMinusPos = input.find_first_of("+-", 1); // Ищем + или - после первого символа
    if (plusMinusPos == std::string::npos) {
        is.setstate(std::ios::failbit);
        return is;
    }

    try {
        c.real = std::stod(input.substr(0, plusMinusPos));
        c.img = std::stod(input.substr(plusMinusPos, input.size() - plusMinusPos - 1));
    } catch (const std::exception&) {
        is.setstate(std::ios::failbit);
    }
    return is;
}

Complex::Complex(std::initializer_list<double> lst) {
auto it = lst.begin();
real = (lst.size() > 0) ? *it++ : 0.0;
img = (lst.size() > 1) ? *it : 0.0;
}

double Complex::modulus() const {
    return std::sqrt(real * real + img * img);
}

bool Complex::operator<(const Complex& other) const {
    return this->modulus() < other.modulus();
}

bool Complex::operator<=(const Complex& other) const {
    return this->modulus() <= other.modulus();
}