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

	//			Type-cast operators:
	explicit operator int() const
	{
		return integer;
	}
	operator double()const
	{
		return integer + (double)numerator / denominator;
	}
	
	//			Methods:

	Fraction& to_proper()
	{
		// переводит дробь в правильную ( выделяет целую часть)
		integer += numerator / denominator;
		numerator %= denominator;
		return *this;
	}
	Fraction& to_improper()
	{
		// переводит дробь в неправильную (выделяет целую часть)
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

Fraction operator+(const Fraction& left, const Fraction& right)
{
	return Fraction
	(
		left.get_integer() + right.get_integer(),
		left.get_numerator() * right.get_denominator() + right.get_numerator() * left.get_denominator(),
		left.get_denominator() * right.get_denominator()
	).to_proper();
}

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
	).to_proper();
}
Fraction operator/(Fraction left, Fraction right)
{
	/*left.to_improper();
	right.to_improper();
	return Fraction
	(
		left.get_numerator() * right.get_denominator(),
		right.get_numerator() * left.get_denominator()
	);*/
	return left.to_improper() * right.inverted();
}

#ifdef FULL_COMPARISON
bool operator==(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	/*if (left.get_numerator() * right.get_denominator() == right.get_numerator() * left.get_denominator())
		return true;
	else
		return false;*/
	return left.get_numerator() * right.get_denominator() == right.get_numerator() * left.get_denominator();
}

bool operator!=(const Fraction& left, const Fraction& right)
{
	return !(left == right);
}

bool operator>(Fraction left, Fraction right)
{
	return
		left.to_improper().get_numerator() * right.get_denominator() >
		right.to_improper().get_numerator() * left.get_denominator();
}

bool operator<(Fraction left, Fraction right)
{
	return
		left.to_improper().get_numerator() * right.get_denominator() <
		right.to_improper().get_numerator() * left.get_denominator();
}

bool operator<=(const Fraction& left, const Fraction& right)
{
	return left > right || left == right;
}

bool operator>=(const Fraction& left, const Fraction& right)
{
	return left < right || left == right;
}

#endif // FULL_COMPARISON

ostream& operator <<(ostream& os, const Fraction& obj)
{
	/*if (obj.get_integer()) os << obj.get_integer();
	if (obj.get_numerator())
	{
		if (obj.get_integer())os << "(";
		os << obj.get_numerator() << "/" << obj.get_denominator();
		if (obj.get_integer()) os << ")";
	}
	if (obj.get_integer() == 0 && obj.get_numerator() == 0)os << 0;
	return os;*/
	return obj.print(os);
}

istream& operator>>(istream& is, Fraction& obj)
{
	int integer, numerator, denominator;
	is >> integer >> numerator >> denominator;
	obj.set_integer(integer);
	obj.set_numerator(numerator);
	obj.set_denominator(denominator);

	return is;
}

//#define CONSTRUCTORS_CHEK
//#define ARITHMETICAL_OPERATORS_CHEK
//#define INCREMENT_CHEK
//#define COMPARISON_OPERATORS_CHEK
//#define OSTREAM_OPERATOR_CHEK
//#define TYPE_CONVERSONS_BASE
//#define CONVERSIONS_FROM_OTHER_TO_CLASS


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

#ifdef ARITHMETICAL_OPERATORS_CHEK
		Fraction A(2, 3, 4);
		Fraction B(19, 5);
		A.print();
		B.print();

		Fraction C = A * B;
		C.print();

		(A / B).print();
		(A + B).print();

		A *= B;
		A.print();
#endif // ARITHMETICAL_OPERATORS_CHEK

#ifdef INCREMENT_CHEK
		for (Fraction i(1, 2); i.get_integer() < 10; ++i)
		{
			i.print();
		}
#endif // INCREMENT_CHEK

#ifdef COMPARISON_OPERATORS_CHEK
		cout << (Fraction(1, 2) < Fraction(3, 2)) << endl;
#endif // COMPARISON_OPERATORS_CHEK

#ifdef OSTREAM_OPERATOR_CHEK
		Fraction A(1, 2);
		A.print(cout) << endl;
		//cout << A << endl;  
#endif // OSTREAM_OPERATOR_CHEK

#ifdef TYPE_CONVERSONS_BASE
		cout << typeid(7 / .2).name() << endl;
		int a = 2;		// No conversions
		double b = 3;	// Conversion from less to more
		int c = b;		// Conversion from more to less without data loss
		int d = 5.5;	// Conversion from more to less with data loss  
#endif // TYPE_CONVERSONS_BASE

#ifdef CONVERSIONS_FROM_OTHER_TO_CLASS
		Fraction A = 5;
		cout << A << endl;

		Fraction B;
		cout << "\n -------------------------------\n";
		B = (Fraction)(8);
		cout << "\n -------------------------------\n";
		cout << B << endl;
#endif // CONVERSIONS_FROM_OTHER_TO_CLASS

		/*Fraction A(2,3,4);
		int a = (int)A;
		cout << a << endl;
		double b = A;
		cout << b << endl;
		cout << b << (Fraction(1, 2) == Fraction(5, 11)) << endl;*/

		Fraction A;
		cout << "Введите простую дробь: ";
		cin >> A;
		cout << A << endl;
} 
