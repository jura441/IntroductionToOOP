#include "String.h"


//#define COSTRUCTORS_CHECK
#define MOVE_METHODS_CHECK
//#define CALLING_CONSTRUCTORS

void main()
{
	setlocale(LC_ALL, "");
	
#ifdef COSTRUCTORS_CHECK
	String str1;		//Default constructor
	str1.print();

	String str2(5);	//explicit Single Argument constructor
	str2.print();

	String str3 = "Hello";
	str3 = str3;
	str3.print();

	String str4 = str3;		//CopyConstructor
	str4.print();

	String str5;
	str5 = str4;			//CopyAssignment
	str5.print();
#endif // COSTRUCTORS_CHECK

#ifdef MOVE_METHODS_CHECK
	String str1 = "Hello";
	cout << str1 << endl;
	String str2("World");
	cout << str2 << endl;
	//String str3 = str1 + " " + str2;	//MoveConstructor
	String str3 = str1 + str2;	//MoveConstructor
	//String str3;
	str3 = str1 + str2;
	//str3.print();
	cout << str3 << endl;
	String str4 = str3;
	cout << str4 << endl;
#endif // MOVE_METHODS_CHECK

#ifdef CALLING_CONSTRUCTORS
	String str1;			//Default constructor
	String str2(55);		//Single-argument constructor
	String str3 = "Hello";	//Single-argument constructor (const char* || const char)
	String str4 = str3;		//Copy constructor
	String str5;
	str5 = str4;			//Copy assignment
	str5.print();
	String str6();	// здесь НЕ вызывается никаких конструкторов, и следовательно \
						НЕ создается объект
					//Здесь объявляется функция str(6) которая ничего не принимает \
					 и возвращает объект класса String
	String str7{};	// Явный вызов конструкции по умолчанию
	str7.print();
#endif // CALLING_CONSTRUCTORS




}