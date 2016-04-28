#include "Complex.h"

Complex::Complex(void) {
	real_ = 0;
	imag_ = 0;
}

Complex::Complex(double const& real) {
	real_ = real;
	imag_ = 0;
}

Complex::Complex(double const& real, double const& imag) {
	real_ = real;
	imag_ = imag;
}

Complex::Complex(Complex const& v) {
	real_ = v.real_;
	imag_ = v.imag_;
}

Complex Complex::operator+ (Complex const& a) const {
	Complex result(real_ + a.real_, imag_ + a.imag_);
	return result;
}

Complex Complex::operator- (Complex const& a) const {
	Complex result(real_ - a.real_, imag_ - a.imag_);
	return result;
}

Complex Complex::operator* (Complex const& a) const {
	Complex result(real_ * a.real_ - imag_ * a.imag_, imag_ * a.real_ + real_ * a.imag_);
	return result;
}

Complex Complex::operator/ (int n) const {
	Complex result(real_ / n, imag_ / n);
	return result;
}

Complex& Complex::operator= (const Complex& a) {
	if (this == &a) return *this;  //·ÀÖ¹×Ô¿½±´
	real_ = a.real_;
	imag_ = a.imag_;
}
double Complex::getReal() {
	return real_;
}
double Complex::getImage() {
	return imag_;
}