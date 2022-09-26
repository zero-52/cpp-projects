//设计立方体类(Cube)
//
//求出立方体的面积和体积
//
//创建两个立方体，分别用全局函数和成员函数判断两个立方体是否完全相同。

#include<iostream>
using namespace std;

class Cube
{
//public:
//	int m_L;
//	int m_W;
//	int m_H;

private:
	int m_L;
	int m_W;
	int m_H;

public:
	void setLWH(int L,int W,int H)
	{
		m_L = L;
		m_W = W;
		m_H = H;
	}
	int getL()
	{
		return m_L;
	}

	int getW()
	{
		return m_W;
	}

	int getH()
	{
		return m_H;
	}
	int area()
	{
		return 2 * (m_L * m_W + m_L * m_H + m_W * m_H);
	}
	int volume()
	{
		return m_L * m_H * m_W;
	}
	//用成员函数比较两个立方体是否相同（注意与全局函数的区别，参数个数不同）
	bool isSameByClass(Cube& c)
	{
		if (m_L == c.getL() && m_W == c.getW() && m_H == c.getH())
		{
			return true;
		}
		return false;
	}

};

//用全局函数比较两个立方体是否相同
//bool isSame(Cube c1, Cube c2) //值传递，还会拷贝出来一份数据
bool isSame(Cube& c1, Cube& c2) //引用传递
{
	if (c1.getL() == c2.getL() && c1.getW() == c2.getW() && c1.getH() == c2.getH())
	{
		return true;
	}
	return false;
}

int main8()
{
	//Cube cube;
	//cube.m_H = 2;
	//cube.m_L = 2;
	//cube.m_W = 2;
	Cube cube1;
	cube1.setLWH(2, 2, 2);
	cout << "面积为：" << cube1.area() << endl;
	cout << "体积为：" << cube1.volume() << endl;

	Cube cube2;
	cube2.setLWH(2, 2, 3);

	//用全局函数比较两个立方体是否相同
	cout << "用全局函数比较两个立方体是否相同" << endl;
	bool ret = isSame(cube1, cube2);
	if (ret)
	{
		cout << "cube1和cube2相同" << endl;
	}
	else
	{
		cout << "cube1和cube2不同" << endl;
	}

	//用成员函数比较两个立方体是否相同
	cout << "用成员函数比较两个立方体是否相同" << endl;
	bool retByClass = cube1.isSameByClass(cube2);
	if (retByClass)
	{
		cout << "cube1和cube2相同" << endl;
	}
	else
	{
		cout << "cube1和cube2不同" << endl;
	}
	return 0;
}