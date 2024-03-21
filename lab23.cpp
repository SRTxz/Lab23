#include <iostream>
#include <cmath>
using namespace std;

class ComplexNumber
{
public:
	double real;
	double imag;
	ComplexNumber(double, double);
	ComplexNumber operator+(const ComplexNumber &);
	ComplexNumber operator-(const ComplexNumber &);
	ComplexNumber operator*(const ComplexNumber &);
	ComplexNumber operator/(const ComplexNumber &);
	bool operator==(const ComplexNumber &);
	double abs();
	double angle();
};

ComplexNumber::ComplexNumber(double x = 0, double y = 0)
{
	real = x;
	imag = y;
}

ComplexNumber ComplexNumber::operator+(const ComplexNumber &c)
{
	return ComplexNumber(real + c.real, imag + c.imag);
}

ComplexNumber ComplexNumber::operator-(const ComplexNumber &c)
{
	return ComplexNumber(real - c.real, imag - c.imag);
}

// Write your code here
ComplexNumber operator+(double a, const ComplexNumber &c)
{
	return ComplexNumber(a + c.real, c.imag);
}

ComplexNumber operator-(double a, const ComplexNumber &c)
{
	return ComplexNumber(a - c.real, -c.imag);
}

ComplexNumber ComplexNumber::operator*(const ComplexNumber &c)
{
	return ComplexNumber((real * c.real) - (imag * c.imag), (real * c.imag) + (imag * c.real));
}

ComplexNumber operator*(double a, const ComplexNumber &c)
{
	return ComplexNumber(a * c.real, a * c.imag);
}

ComplexNumber ComplexNumber::operator/(const ComplexNumber &c)
{
	return ComplexNumber(((real * c.real) + (imag * c.imag)) / (pow(c.real, 2) + pow(c.imag, 2)), ((imag * c.real) - (real * c.imag)) / (pow(c.real, 2) + pow(c.imag, 2)));
}

ComplexNumber operator/(double a, const ComplexNumber &c)
{
	return ComplexNumber((a * c.real) / (pow(c.real, 2) + pow(c.imag, 2)), (-(a * c.imag)) / (pow(c.real, 2) + pow(c.imag, 2)));
}

double ComplexNumber::abs()
{
	return (sqrt(pow(real, 2) + pow(imag, 2)));
}

double ComplexNumber::angle()
{
	return atan2(imag, real) * 180 / M_PI;
}

bool ComplexNumber::operator==(const ComplexNumber &c)
{
	if (real == c.real && imag == c.imag)
	{
		return true;
	}
	else
	{
		return false;
	}
}
ComplexNumber operator==(double a, const ComplexNumber &c)
{
	if (a == c.real && c.imag == 0)
		return true;
	else
		return false;
}
ostream &operator<<(ostream &os, const ComplexNumber &c)
{
	if (c.real != 0 && c.imag > 0)
		return os << c.real << "+" << c.imag << "i";
	else if (c.real != 0 && c.imag < 0)
		return os << c.real << c.imag << "i";
	else if (c.real == 0 && c.imag != 0)
		return os << c.imag << "i";
	else if (c.real != 0 && c.imag == 0)
		return os << c.real;
	else
		return os << "0";
}
int main()
{
	ComplexNumber a(1.5, 2), b(3.2, -2.5), c(-1, 1.2);
	cout << a << "\n";
	cout << b << "\n";
	cout << c << "\n";
	cout << a + 2.5 << "\n";
	cout << 2.5 + a << "\n";
	cout << a - 1.5 << "\n";
	cout << 1.5 - a << "\n";
	cout << b + ComplexNumber(0, 2.5) << "\n";
	cout << c - c << "\n";
	cout << "-----------------------------------\n";

	ComplexNumber d = (a + b) / c;
	ComplexNumber e = b / (a - c);
	cout << d << "\n";
	cout << e << "\n";
	cout << c * 2 << "\n";
	cout << 0.5 * c << "\n";
	cout << 1 / c << "\n";
	cout << "-----------------------------------\n";

	cout << ComplexNumber(1, 1).abs() << "\n";
	cout << ComplexNumber(-1, 1).abs() << "\n";
	cout << ComplexNumber(1.5, 2.4).abs() << "\n";
	cout << ComplexNumber(3, 4).abs() << "\n";
	cout << ComplexNumber(69, -9).abs() << "\n";
	cout << "-----------------------------------\n";

	cout << ComplexNumber(1, 1).angle() << "\n";
	cout << ComplexNumber(-1, 1).angle() << "\n";
	cout << ComplexNumber(-1, -1).angle() << "\n";
	cout << ComplexNumber(1, -1).angle() << "\n";
	cout << ComplexNumber(5, 2).angle() << "\n";
	cout << "-----------------------------------\n";

	cout << (ComplexNumber(1, 1) == ComplexNumber(1, 2)) << "\n";
	cout << (ComplexNumber(1, 1) == 1) << "\n";
	cout << (0 == ComplexNumber()) << "\n";
}
