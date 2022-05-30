#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

class String
{
	int size;		// размер строки в байтах
	char* str;		// Указатель на строку
public:
	int get_size()const
	{
		return size;
	}
	const char* get_str()const
	{
		return str;
	}
	char* get_str()
	{
		return str;
	}

	//		Constructors:

	explicit String(int size = 80)
	{
		this->size = size;
		this->str = new char[size] {};
		cout << "Def1aConstructor:\t" << this << endl;
	}
	String(const char* str)
	{
		this->size = strlen(str) + 1;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)this->str[i] = str[i];
		cout << "Constructor:\t" << this << endl;
	}
	String(const String& other)
	{
		// CopyConstructor должен выполнять DeepCopy (побитовое копирование)
		// т.е. выделить новую память, и скопировать в нее содержимое другого объекта.
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)
		{
			this->str[i] = other.str[i];
		}
		//------------------------------------------------------------
		cout << "CopyConstructor:\t" << this << endl;
			
	}
	~String()
	{
		delete[] this->str;
		cout << "Destructor:\t" << this << endl;
	}

	//			Operators:
	String& operator=(const String& other)
	{
	
		if (this == &other)return *this;
		delete[] this->str;
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)this->str[i] = other.str[i];
		cout << "CopyAssigment:\t" << this << endl;
		return *this;
	}
	const char& operator[](int i)const
	{
		return str[i];
	}
	char& operator[](int i)
	{
		return str[i];
	}

	//		Metods:

	void print()const
	{
		cout << "Size:\t" << size << endl;
		cout << "Str:\t" << str << endl;
	}
	
};

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

//#define COSTRUCTORS_CHEK

void main()
{
	setlocale(LC_ALL, "");
	
#ifdef COSTRUCTORS_CHEK
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
#endif // COSTRUCTORS_CHEK

	String str1 = "Hello";
	cout << str1 << endl;
	String str2 ("World");
	cout << str2 << endl;
	String str3 = str1 + " " + str2;
	//str3.print();
	cout << str3 << endl;

}