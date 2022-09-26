#include"09point.h"

//因为这些函数为类的成员函数，所以分包写时应该加上作用域 ::，如 类名::成员函数; //表示某类中的成员
//void setXY(int x, int y)
//{
//	X = x;
//	Y = y;
//}

void Point::setXY(int x, int y)
{
	X = x;
	Y = y;
}
int Point::getX()
{
	return X;
}
int Point::getY()
{
	return Y;
}
