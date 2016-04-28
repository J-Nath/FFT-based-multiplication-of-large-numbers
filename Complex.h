#pragma once
#ifndef COMPLEX_H
#define COMPLEX_H
#include "iostream"
#include "sstream"
#include "vector"
#define _USE_MATH_DEFINES
#include "math.h"
#include<stdio.h>
#include <cstdlib>
#include "string"
#include <cstring>
class Complex {
public:
	double real_;
	double imag_;

	Complex(void);
	Complex(double const& real);
	Complex(double const& real, double const& imag);
	Complex(Complex const& v);
	Complex operator+(Complex const& a) const;
	Complex operator-(Complex const& a) const;
	Complex operator*(Complex const& a) const;
	Complex operator/(int n) const;
	Complex& operator=(const Complex& a);
	double getReal();
	double getImage();
};
#endif
