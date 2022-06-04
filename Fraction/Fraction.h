#pragma once
#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

//#define FULL_COMPARISON
#define delimeter "\n-------------------------------------\n"

class Fraction;
Fraction operator*(Fraction left, Fraction right);


class Fraction
{
	int integer;
	int numerator;
	int denominator;
public:
	int get_integer()const
	{
		return integer;
	}
	int get_numerator()const
	{
		return numerator;
	}
	int get_denominator()const
	{
		return denominator;
	}
	void set_integer(int integer)
	{
		this->integer = integer;
	}
	void set_numerator(int numerator)
	{
		this->numerator = numerator;
	}
	void set_denominator(int denominator)
	{
		if (denominator == 0)denominator = 1;
		this->denominator = denominator;
	}

	//		Constructor:

	Fraction()
	{
		this->integer = 0;
		this->numerator = 0;
		this->denominator = 1;
		cout << "DefConstructor:\t" << this << endl;
	}

	Fraction(int integer)
	{
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
		cout << "1argConstructor:\t" << this << endl;
	}

	Fraction(double decimal)
	{
		decimal += 1e-10;
		integer = decimal;
		decimal -= integer;
		denominator = 1e+9;
		numerator = decimal * denominator;
		reduce();
		cout << "ConstructorDBL: \t" << this << endl;
	}

	Fraction(int numerator, int denominator)
	{
		this->integer = 0;
		this->numerator = numerator;
		this->set_denominator(denominator);
		cout << "Constructor:\t" << this << endl;
	}

	Fraction(int integer, int numerator, int denominator)
	{
		this->integer = integer;
		this->numerator = numerator;
		this->set_denominator(denominator);
		cout << "Constuctor:\t" << this << endl;
	}

	Fraction(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "1argConstructor:" << this << endl;
	}

	~Fraction()
	{
		cout << "Destructor:\t" << this << endl;
	}
	//			Operators:

	Fraction& operator=(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyAssignment" << this << endl;
		return *this;
	}
	Fraction& operator*=(const Fraction& other)
	{
		return *this = *this * other;
	}

	//			Increment/Decrement
	Fraction& operator++()
	{
		integer++;
		return *this;
	}
	Fraction& operator++(int)
	{
		Fraction old = *this;
		integer++;
		return old;
	}

	Fraction& operator--()
	{
		integer--;
		return *this;
	}
	Fraction& operator--(int)
	{
		Fraction old = *this;
		integer--;
		return old;
	}

	Fraction& operator()(int integer, int numerator, int denominator)
	{
		set_integer(integer);
		set_numerator(numerator);
		set_denominator(denominator);
		return *this;
	}

	//			Type-cast operators:
	explicit operator int() const
	{
		return integer;
	}
	operator double()const
	{
		return integer + (double)numerator / denominator;
	}

	//explicit Fraction(double decimal)
	//{
	//	decimal += 1e-10;
	//	integer = decimal;	// ��������� ����� ����� ���������� �����
	//	decimal -= integer; // ������� ����������� ����� ����� �� ���������� �����
	//	// ������ ����� ��������� ���������� �������� � ������� �����
	//	numerator = 0;
	//	int i = 0;
	//	int digit = 0;	 // ������� ������� ������
	//	for (; decimal && i<9; i++)
	//	{
	//		numerator *= 10;	//����������� ������� ����� ��� ���������� �������� �������
	//		decimal *= 10;		//�������� ������� �� ���� ������ ������
	//		digit = decimal;
	//		numerator += digit;
	//		decimal -= digit;

	//	}
	//	denominator = pow(10, i);
	//		cout << "1argConstructor:" << this << endl;

	//}

	//			Methods:

	Fraction& to_proper()
	{
		// ��������� ����� � ���������� ( �������� ����� �����)
		integer += numerator / denominator;
		numerator %= denominator;
		return *this;
	}
	Fraction& to_improper()
	{
		// ��������� ����� � ������������ (�������� ����� �����)
		numerator += integer * denominator;
		integer = 0;
		return*this;
	}
	Fraction inverted()const
	{
		Fraction inverted = *this;
		inverted.to_improper();
		int buffer = inverted.numerator;
		inverted.numerator = inverted.denominator;
		inverted.denominator = buffer;
		return inverted;
	}

	Fraction& reduce()
	{
		int more, less, rest;
		if (numerator > denominator)
		{
			more = numerator;
			less = denominator;
		}
		else
		{
			more = numerator;
			less = denominator;
		}
		do
		{
			rest = more % less;
			more = less;
			less = rest;
		} while (rest);
		int GCD = more;	// GCD - Greatest Common Divisor (���������� ����� ��������)
		if (GCD == 0)return*this;
		numerator /= GCD;
		denominator /= GCD;
		return *this;
	}


	void print()const
	{
		if (integer)cout << integer;
		/*if (integer && numerator)cout << "(";*/
		if (numerator)
		{
			if (integer)cout << "(";
			cout << numerator << "/" << denominator;
			if (integer && numerator)cout << ")";
		}
		if (integer == 0 && numerator == 0)cout << 0;
		cout << endl;
	}

	ostream& print(ostream& os)const
	{
		if (integer)os << integer;
		/*if (integer && numerator)cout << "(";*/
		if (numerator)
		{
			if (integer)os << "(";
			os << numerator << "/" << denominator;
			if (integer && numerator)os << ")";
		}
		if (integer == 0 && numerator == 0)os << 0;
		return os;
	}
};

Fraction operator+(const Fraction& left, const Fraction& right);
ostream& operator <<(ostream& os, const Fraction& obj);
istream& operator>>(istream& is, Fraction& obj);