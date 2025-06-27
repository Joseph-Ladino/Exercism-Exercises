#include "complex_numbers.h"

namespace complex_numbers {
	
	double Complex::real() const { return re; }
	double Complex::imag() const { return im; }
	double Complex::abs() const { return sqrt(re * re + im * im); }

	Complex Complex::conj() const { return Complex(re, -im); }
	Complex Complex::exp() const { return Complex(std::exp(re) * std::cos(im), std::exp(re) * std::sin(im)); }

	bool Complex::operator==(const Complex& b) const { return re == b.re && im == b.im; }
	Complex Complex::operator+(const Complex& b) const { return Complex(re + b.re, im + b.im); }
	Complex Complex::operator-(const Complex& b) const { return Complex(re - b.re, im - b.im); }
	Complex Complex::operator*(const Complex& b) const { return Complex(re * b.re - im * b.im, im * b.re + re * b.im); }
	Complex Complex::operator/(const Complex& b) const { return Complex((re * b.re + im * b.im) / (b.re * b.re + b.im * b.im), (im * b.re - re * b.im) / (b.re * b.re + b.im * b.im)); }

	Complex::Complex(const Complex& b) : re(b.re), im(b.im) {}
	Complex::Complex(double _re, double _im) : re(_re), im(_im) {}

}  // namespace complex_numbers
