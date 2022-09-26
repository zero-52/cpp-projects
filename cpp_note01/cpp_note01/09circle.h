#pragma once //防止头文件重复包含
#include<iostream>
using namespace std;
#include"09point.h"

class Circle
{
private:
	int R;
	Point c_center;  //要包含 Point 类的头文件
public:
	void setR(int r);  //设置半径
	int getR();  //获取半径
	void setCenter(Point center);  //设置圆心
	Point getCenter();  //获取圆心
};