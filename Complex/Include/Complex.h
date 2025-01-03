#pragma once
#include <iostream>
#include <cmath>

class Complex {
private:
    double real;
    double img;
    static constexpr double EPSILON = 1e-9;
public:
    Complex() : real(0.0), img(0.0) {}
    Complex(double r) : real(r), img(0.0) {}
    Complex(double r, double i) : real(r), img(i) {}
    Complex(std::initializer_list<double> lst);

    double Real() const {return real;}
    double Imag() const {return img;}

    Complex operator+(const Complex& other) const;
    Complex& operator+=(const Complex& other);

    Complex operator-(const Complex& other) const;
    Complex& operator-=(const Complex& other);

    Complex operator*(const Complex& other) const;
    Complex& operator*=(const Complex& other);

    Complex operator/(const Complex& other) const;
    Complex& operator/=(const Complex& other);

    bool operator==(const Complex& c) const;
    bool operator!=(const Complex& other) const;

    friend std::ostream& operator<<(std::ostream& os, const Complex& c);
    friend std::istream& operator>>(std::istream& is, Complex& c);
};

