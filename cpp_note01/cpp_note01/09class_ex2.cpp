#include<iostream>
using namespace std;

#include"09point.h"
#include"09circle.h"

/*
点和圆的关系

设计一个圆形类（Circle），和一个点类（Point），计算点和圆的关系。
*/

/** 可以像下面这样写在一个文件中，也可以利用头文件分包，如 point.h  point.cpp, circle.h  circle.cpp
class Point
{
private:
	int X;
	int Y;  //点坐标 (x,y)
public:
	void setXY(int x, int y)
	{
		X = x;
		Y = y;
	}
	int getX()
	{
		return X;
	}
	int getY()
	{
		return Y;
	}
};

class Circle
{
private:
	int R;
	Point c_center;  //圆心，当前类的成员可以是另一个类的对象，称为 对象成员
public:
	void setR(int r)
	{
		R = r;
	}
	int getR()
	{
		return R;
	}
	void setCenter(Point center)
	{
		c_center = center;
	}
	Point getCenter()  //获取圆心
	{
		return c_center;
	}
};
*/

//全局函数判断点和圆的关系
void isInCircle(Circle& c1, Point& dot)
{
	//计算圆心和点的距离的平方
	int distance;
	distance = pow(c1.getCenter().getX() - dot.getX(), 2) + pow(c1.getCenter().getY() - dot.getY(), 2);

	//计算半径r的平方
	int R2;
	R2 = pow(c1.getR(), 2);

	if (distance > R2)
	{
		cout << "点在圆外" << endl;
	}
	else if (distance == R2)
	{
		cout << "点在圆上" << endl;
	}
	else
	{
		cout << "点在圆内" << endl;
	}
}

int main9()
{
	Point dot1;
	//dot1.setXY(9, 0);
	//dot1.setXY(10, 0);
	dot1.setXY(11, 0);

	Point circle_center;
	circle_center.setXY(0, 0);
	Circle circle1;
	circle1.setR(10);
	circle1.setCenter(circle_center);

	isInCircle(circle1, dot1);

	return 0;
}