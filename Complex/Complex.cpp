#include "pch.h"
#include <iostream>
#include <math.h>

using namespace std;

class Complex
{
private:
	double re, im;

public:
	Complex(double r = 0, double i = 0)
	{
		re = r;
		im = i;
	}

	Complex(const Complex & other)
	{
		re = other.re;
		im = other.im;
	}

	~Complex()
	{
	}

	Complex& operator = (Complex & other)
	{
		re = other.re;
		im = other.im;

		return *this;
	}

	friend Complex operator + (Complex & a, Complex & b);
	friend Complex operator + (Complex  a, double b);
	friend Complex operator + (double b, Complex a);

	friend Complex operator - (Complex & a, Complex & b);
	friend Complex operator - (Complex  a, double b);
	friend Complex operator - (double b, Complex a);

	friend Complex operator * (Complex & a, Complex & b);
	friend Complex operator * (Complex  a, double b);
	friend Complex operator * (double b, Complex a);

	friend ostream & operator << (ostream &, const Complex &);
	friend istream & operator >> (istream &, Complex &);

	double GetRe()
	{
		return re;
	};

	double GetIm()
	{
		return im;
	};

	int SetRe(double newVal)
	{
		re = newVal;
		return 1;
	};

	int SetIm(double newVal)
	{
		im = newVal;
		return 1;
	};
};

//-------------------ввод и вывод-----------------------------
ostream & operator << (ostream &out, const Complex & other)
{
	out << other.re;
	if (other.im >= 0)
		out << "+";
	out << other.im << "i";

	return out;
}

istream& operator >> (istream &in, Complex & other)
{
	in >> other.re >> other.im;
	return in;
}
//----------------------------------Сложение-----------------------------------
Complex operator + (Complex & a, Complex & b)
{
	Complex temp;

	temp.SetRe(a.GetRe() + b.GetRe());
	temp.SetIm(a.GetIm() + b.GetIm());

	return temp;
}

Complex operator + (Complex  a, double b)
{
	Complex temp;

	temp.SetRe(a.GetRe() + b);
	temp.SetIm(a.GetIm());

	return temp;
}

Complex operator + (double b, Complex a)
{
	Complex temp;

	temp.SetRe(b + a.GetRe());
	temp.SetIm(a.GetIm());

	return temp;
}
//---------------------------Вычитание-----------------------------
Complex operator - (Complex & a, Complex & b)
{
	Complex temp;

	temp.SetRe(a.GetRe() - b.GetRe());
	temp.SetIm(a.GetIm() - b.GetIm());

	return temp;
}

Complex operator - (Complex  a, double b)
{
	Complex temp;

	temp.SetRe(a.GetRe() - b);
	temp.SetIm(a.GetIm());

	return temp;
}

Complex operator - (double b, Complex a)
{
	Complex temp;

	temp.SetRe(b - a.GetRe());
	temp.SetIm(a.GetIm() * (-1));

	return temp;
}
//----------------Умножение-------------------------------
Complex operator * (Complex & a, Complex & b)
{
	Complex temp;

	temp.SetRe((a.GetRe() * b.GetRe()) - (a.GetIm() * b.GetIm()));
	temp.SetIm((a.GetRe() * b.GetIm()) + (b.GetRe() * a.GetIm()));

	return temp;
}

Complex operator * (Complex  a, double b)
{
	Complex temp;

	temp.SetRe(a.GetRe() * b);
	temp.SetIm(a.GetIm() * b);

	return temp;
}

Complex operator * (double b, Complex a)
{
	Complex temp;

	temp.SetRe(b * a.GetRe());
	temp.SetIm(b * a.GetIm());

	return temp;
}

int main()
{
	setlocale(LC_ALL, "rus");

	Complex a(3, 1);
	Complex b(6, 4);
	Complex c, d, f;

	c = b;

	cout << "Введите d: ";
	cin >> d;

	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;
	cout << "d = " << d << endl;
	cout << "f = " << f << endl;

	cout << "Сложение: " << endl;
	cout << "a + b: " << a + b << endl;
	cout << "c + d: " << c + d << endl;
	cout << "a + 10: " << a + 10 << endl;
	cout << "5 + a: " << 5 + a << endl;

	cout << "Вычитание:" << endl;
	cout << "a - b: " << a - b << endl;
	cout << "c - 4: " << c - 4 << endl;
	cout << "2 - d: " << 2 - d << endl;

	cout << "Умножение: " << endl;
	cout << "a * b: " << a * b << endl;
	cout << "a * 3: " << a * 3 << endl;
	cout << "5 * b: " << 5 * b << endl;

	system("pause");
	return 0;
}