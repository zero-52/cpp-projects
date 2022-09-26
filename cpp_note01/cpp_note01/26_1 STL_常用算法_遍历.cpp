/*
STL- 常用算法
概述:
	算法主要是由头文件<algorithm> <functional> <numeric>组成。

	<algorithm>是所有STL头文件中最大的一个，范围涉及到比较、 交换、查找、遍历操作、复制、修改等等

	<numeric>体积很小，只包括几个在序列上面进行简单数学运算的模板函数

	<functional>定义了一些模板类,用以声明函数对象。


常用遍历算法
	学习目标：
		掌握常用的遍历算法
	算法简介：
		for_each	//遍历容器（实际开发中，使用频次非常高）
		transform	//搬运容器到另一个容器中
	① for_each
		功能描述：
			实现遍历容器
		函数原型：
			for_each(iterator beg, iterator end, _func);// 遍历算法 遍历容器元素
				// beg 开始迭代器
				// end 结束迭代器
				// _func 函数或者函数对象
	② transform
		功能描述：
			以 _func 的方式运算后将容器搬运到到另一个容器中
		函数原型：
			transform(iterator beg1, iterator end1, iterator beg2, _func);
				//beg1 源容器开始迭代器
				//end1 源容器结束迭代器
				//beg2 目标容器开始迭代器
				//_func 函数或者函数对象
			注意：搬移时，目标容器必须提前开辟好空间
				  搬运后，原容器数据仍存在，搬运相当于复制

*/

#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

//全局函数
void print01(int val)
{
	cout << val << " ";
}

//仿函数
class Print02
{
public:
	void operator()(int val)
	{
		cout << val << " ";
	}
};

//仿函数
class Trans
{
public:
	int operator()(int val)
	{
		//return val; 从容器中直接将数据搬运到目标容器
		return val + 100; //将容器中的数据加上100再搬运到目标容器
	}
};
static void a_test01()
{
	cout << "** 常用遍历算法 **" << endl;
	vector<int> vec1;
	for (int i = 0; i < 5; i++)
	{
		vec1.push_back(i);
	}

	//普通全局函数的函数名是该函数的地址（可以理解成函数指针），仿函数是一个类加 () 是传入一个匿名对象类
	
	//① for_each 遍历算法
	for_each(vec1.begin(), vec1.end(), print01);  //函数回调
	cout << endl;
	for_each(vec1.begin(), vec1.end(), Print02()); //仿函数类名()
	cout << endl;

	//② transform 遍历算法
	vector<int> vecDest;
	vecDest.resize(vec1.size()); //搬移时，目标容器必须提前开辟好空间
	transform(vec1.begin(), vec1.end(), vecDest.begin(), Trans()); //以 Trans仿函数运算后搬运
	
	for_each(vecDest.begin(), vecDest.end(), Print02());//遍历目标容器
	cout << endl;

	//搬运后，原容器数据仍存在
	for_each(vec1.begin(), vec1.end(), Print02()); 

}



/*****************************************************************************
 *  @brief	main

 *****************************************************************************/
int main26_1()
{
	a_test01();


	return 0;
}