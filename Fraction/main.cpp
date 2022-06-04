#include "Fraction.h"


//#define CONSTRUCTORS_CHEK
//#define ARITHMETICAL_OPERATORS_CHEK
//#define INCREMENT_CHEK
//#define COMPARISON_OPERATORS_CHEK
//#define OSTREAM_OPERATOR_CHEK
//#define TYPE_CONVERSONS_BASE
//#define CONVERSIONS_FROM_OTHER_TO_CLASS
//#define CONVERSIONS_FROM_CLASS_TO_OTHER


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

#ifdef CONVERSIONS_FROM_CLASS_TO_OTHER
		Fraction A(2, 3, 4);
		int a = (int)A;
		cout << a << endl;
		double b = A;
		cout << b << endl;
		cout << b << (Fraction(1, 2) == Fraction(5, 11)) << endl;
#endif // CONVERSIONS_FROM_CLASS_TO_OTHER


		Fraction A = 2.75;
		cout << "Введите простую дробь: "; cin >> A;
		cout << (double)A << endl;
		A(123, 55, 77);

		/*A.set_integer(123);
		A.set_numerator(55);
		A.set_denominator(77);*/

		/*Fraction A = 2.75;
		cout << A << endl;*/
} 
