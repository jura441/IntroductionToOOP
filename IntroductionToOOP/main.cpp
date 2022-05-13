#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

class Point
{
private:
	double x;
	double y;
	public:
		double get_x()const
		{
			return x;
		}
		double get_y()const
		{
			return y;
		}
		void set_x(double x)
		{
			this->x = x;
		}
		void set_y(double y)
		{
			this->y = y;
		}

		//				Constructor
		Point()
		{
			x = y = 0;
			cout << "DefaultConstructor:\t" << this << endl;
		}
		~Point()
		{
			cout << "Destructor:\t\t" << this << endl;
		}
		// Methods

		double distance(Point other)
		{
			double x_distance = this->x - other.x;
			double y_distance = this->y - other.y;
			double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
			return distance;
		}
		void print()const
		{
			cout << "X = " << x << "\tY = " << y << endl;
		}
};


double distance(Point A, Point B)
{
	double x_distance = A.get_x() - B.get_x();
	double y_distance = A.get_y() - B.get_y();
	double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
	return distance;
}

//#define STRUCT_POINT
//#define DISTANCE

	void main()
{
	setlocale(LC_ALL, "");
#ifdef STRUCT_POINT

	int a;	//объявление переменной а типа int
	Point A;// объявление переменной А типа point
			// объявление объект А структуры point
			// создание экземепляра А структуры point
	A.x = 2;
	A.y = 3;
	cout << A.x << "\t" << A.y << endl;

	Point* pA = &A;
	cout << pA->x << "\t" << pA->y << endl;
	//cout << (*pA).x << "\t" << (*pA).y << endl;  
#endif // STRUCT_POINT

#ifdef DISTANCE
	Point A;

	A.set_x(2);
	A.set_y(3);
	cout << A.get_x() << "\t" << A.get_y() << endl;

	Point B;

	B.set_x(7);
	B.set_y(8);
	cout << B.get_x() << "\t" << B.get_y() << endl;

	cout << "Расстояние от точки A до точки B: " << A.distance(B) << endl;
	cout << "Расстояние от точки B до точки A: " << B.distance(A) << endl;
	cout << "Расстояние между точками А и В: " << distance(A, B) << endl;
	cout << "Расстояние между точками B и A: " << distance(B, A) << endl;
#endif // DISTANCE

	int a;
	Point A;
	A.print();
	



}