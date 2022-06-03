#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

/////////////////////////////////////////////////////////////////////////////////////
/////////////  Class declaration end - конец объявления класса			/////////////////
/////////////////////////////////////////////////////////////////////////////////////

class String
{
	int size;		// размер строки в байтах
	char* str;		// Указатель на строку
public:
	int get_size()const;
	const char* get_str()const;
	char* get_str();

	//		Constructors:

	explicit String(int size = 80);
	String(const char* str);
	String(const String& other);
	String(String&& other);
	~String();

	//			Operators:
	String& operator=(const String& other);
	String& operator=(String&& other);
	const char& operator[](int i)const;
	char& operator[](int i);

	//		Metods:

	void print()const;
	
};

int String:: get_size()const
{
	return size;
}
const char* String:: get_str()const
{
	return str;
}
char* String:: get_str()
{
	return str;
}

//		Constructors:

String::String(int size) :size(size), str(new char[size] {})
{
	cout << "Def1aConstructor:" << this << endl;
}
String::String(const char* str) :String(strlen(str) + 1)
{
	for (int i = 0; i < size; i++)this->str[i] = str[i];
	cout << "Constructor:\t" << this << endl;
}
String::String(const String& other) :String(other.str)
{
	cout << "CopyConstructor:" << this << endl;
}
String::String(String&& other) :size(other.size), str(other.str)
{
	// MoveConstuctor выполняет ShellowCopy (поверхностное копирование)
	other.size = 0;
	other.str = nullptr;	//Зануляем адрес памяти в другом объекте, чтобы эту память не удалил диструктор
	cout << "MoveConstructor:" << this << endl;
}
String::~String()
{
	delete[] this->str;
	cout << "Destructor:\t" << this << endl;
}

//			Operators:
String& String::operator=(const String& other)
{
	if (this == &other)return *this;
	delete[] this->str;
	this->size = other.size;
	this->str = new char[size] {};
	for (int i = 0; i < size; i++)this->str[i] = other.str[i];
	cout << "CopyAssigment:\t" << this << endl;
	return *this;
}
String& String:: operator=(String&& other)
{
	delete[] this->str;
	this->size = other.size;
	this->str = other.str;
	other.size = 0;
	other.str = nullptr;
	cout << "MoveAssignment:\t" << this << endl;
	return*this;
}
const char& String:: operator[](int i)const
{
	return str[i];
}
char& String::operator[](int i)
{
	return str[i];
}

//		Metods:

void String::print()const
{
	cout << "Size:\t" << size << endl;
	cout << "Str:\t" << str << endl;
}


String operator+(const String& left, const String& right)
{
	String cat(left.get_size() + right.get_size() - 1);
	//левую строку копируем соотвественно:
	for (int i = 0; i < left.get_size(); i++)
		cat[i] = left[i];
		//cat.get_str()[i] = left.get_str()[i];
	// Правую строку копируем со смещением в право на размер левой строки
	for (int i = 0; i < right.get_size(); i++)
		cat[i + left.get_size() - 1] = right[i];
		//cat.get_str()[i + left.get_size() - 1] = right.get_str()[i];
	return cat;
	
}

std::ostream& operator<<(std::ostream& os, const String& obj)
{
	return os << obj.get_str();
}

/////////////////////////////////////////////////////////////////////////////////////
/////////////  Class defenition end - определение класса			/////////////////
/////////////////////////////////////////////////////////////////////////////////////


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