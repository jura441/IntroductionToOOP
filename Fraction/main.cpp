#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define delimeter "\n-------------------------------------\n"

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
		cout << "1argConstructor:\t" << this << endl;
	}

	~Fraction()
	{
		cout << "Destructor:\t" << this << endl;
	}
	//			Operators:
	Fraction& operator+(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyAssignment" << this << endl;
	}

	//			Methods:

	void to_proper()
	{
		// ��������� ����� � ���������� ( �������� ����� �����)
		integer += numerator / denominator;
		numerator %= denominator;
	}
	void to_improper()
	{
		// ��������� ����� � ������������ (�������� ����� �����)
		numerator += integer * denominator;
		integer = 0;
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
};

Fraction operator*(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	/*Fraction result;
	result.set_numerator(left.get_numerator() * right.get_numerator());
	result.set_denominator(left.get_denominator() * right.get_denominator());*/
	/*Fraction result
	(
		left.get_numerator() * right.get_numerator(),
		left.get_denominator() * right.get_denominator()
		);
	result.to_proper();
	return result;*/
	return Fraction
	(
		left.get_numerator() * right.get_numerator(),
		left.get_denominator() * right.get_denominator()
	);
}

//#define CONSTRUCTORS_CHEK

	void main()
{
		setlocale(LC_ALL, "");

#ifdef CONSTRUCTORS_CHEK
		Fraction A;
		A.print();

		Fraction B = 5;
		B.print();

		Fraction C(1, 2);
		C.print();

		Fraction D(2, 3, 4);
		D.print();

		Fraction E = C;
		E.print();

		A = D;
		A.print();

#endif // CONSTRUCTORS_CHEK

		Fraction A(2, 3, 4);
		Fraction B(19, 5);
		A.print();
		B.print();



		Fraction C = A * B;
		C.print();

} 
