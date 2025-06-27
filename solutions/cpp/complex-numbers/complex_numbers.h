#if !defined(COMPLEX_NUMBERS_H)
#define COMPLEX_NUMBERS_H
#include <cmath>

namespace complex_numbers {

	struct Complex {
		double re = 0, im = 0;

		double real() const;
		double imag() const;
		double abs() const;

		Complex conj() const;
		Complex exp() const;

		bool operator==(const Complex&) const;
		Complex operator+(const Complex&) const;
		Complex operator-(const Complex&) const;
		Complex operator*(const Complex&) const;
		Complex operator/(const Complex&) const;

		Complex(const Complex&);
		Complex(double, double);
	};

}  // namespace complex_numbers

#endif  // COMPLEX_NUMBERS_H
