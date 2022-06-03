#include "String.h"

//---------------------------------------------------------------------------------//

int String::get_size()const
{
	return size;
}
const char* String::get_str()const
{
	return str;
}
char* String::get_str()
{
	return str;
}

//		Constructors:

String::String(int size) :size(size), str(new char[size] {})
{
	cout << "Def1aConstructor:" << this << endl;
}
String::String(const char* str) : String(strlen(str) + 1)
{
	for (int i = 0; i < size; i++)this->str[i] = str[i];
	cout << "Constructor:\t" << this << endl;
}
String::String(const String& other) : String(other.str)
{
	cout << "CopyConstructor:" << this << endl;
}
String::String(String&& other) : size(other.size), str(other.str)
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
/////////////  CLASS DEFENITION END - КОНЕЦ ОПРЕДЕЛЕНИЯ КЛАССА			/////////////////
/////////////////////////////////////////////////////////////////////////////////////