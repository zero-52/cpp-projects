#pragma once  //防止头文件被重复包含
#include<iostream>
using namespace std;
//头文件中只声明成员即可，函数定义在cpp文件中，定义时指明作用域

class Point
{
private:
	int X;
	int Y;  //点坐标 (x,y)
public:
	/*  //头文件中只声明成员即可，函数定义在cpp文件中
	void setXY(int x, int y)   
	{
		X = x;
		Y = y;
	}*/  
	void setXY(int x, int y); 
	int getX();
	int getY();
};
