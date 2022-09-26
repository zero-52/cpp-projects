/*
STL- 函数对象（仿函数）
	概念：
		重载函数调用操作符的类，其对象常称为函数对象
		函数对象使用重载的()时，行为类似函数调用，也叫仿函数
	本质：
		函数对象(仿函数)是一个类，不是一个函数

	函数对象特点：
		1、函数对象在使用时，可以像普通函数那样调用, 可以有参数，可以有返回值
		2、函数对象超出普通函数的概念，函数对象可以有自己的状态，因为它是一个类，可以有成员属性
		3、函数对象可以作为参数传递


谓词
	概念：
		返回 bool类型 的仿函数称为谓词
	一元谓词、二元谓词：
		返回bool类型，且operator()接受一个参数，那么叫做一元谓词
		返回bool类型，且operator()接受两个参数，那么叫做二元谓词


内建函数对象（内建仿函数）
	概念：
		STL内建了一些函数对象
	分类:
		算术仿函数

		关系仿函数

		逻辑仿函数

	用法：
		这些仿函数所产生的对象，用法和一般函数完全相同
		使用内建函数对象，需要引入头文件 #include<functional>

算术仿函数
	功能描述：
		实现四则运算
		其中negate是一元运算，其他都是二元运算
	仿函数原型：
		template<class T> T plus<T> //加法仿函数
		template<class T> T minus<T> //减法仿函数
		template<class T> T multiplies<T> //乘法仿函数
		template<class T> T divides<T> //除法仿函数
		template<class T> T modulus<T> //取模仿函数
		template<class T> T negate<T> //取相反数仿函数


关系仿函数
	功能描述：
		实现关系对比
	仿函数原型：
		template<class T> bool equal_to<T> //等于
		template<class T> bool not_equal_to<T> //不等于
		template<class T> bool greater<T> //大于
		template<class T> bool greater_equal<T> //大于等于
		template<class T> bool less<T> //小于
		template<class T> bool less_equal<T> //小于等于
	最常用的就是 greater 仿函数
 
 
逻辑仿函数
	功能描述：
			实现逻辑运算
	函数原型：
		template<class T> bool logical_and<T> //逻辑与
		template<class T> bool logical_or<T> //逻辑或
		template<class T> bool logical_not<T> //逻辑非
	逻辑仿函数实际使用较少
		
*/

#include<iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;


/*****************************************************************************
 *  @brief	函数对象（仿函数）
本质：函数对象(仿函数)是一个类，不是一个函数

函数对象特点：
	1、函数对象在使用时，可以像普通函数那样调用, 可以有参数，可以有返回值
	2、函数对象超出普通函数的概念，函数对象可以有自己的状态，因为它是一个类，可以有成员属性
	3、函数对象可以作为参数传递
 *****************************************************************************/

class MyAdd01
{
public:
	//1、函数对象在使用时，可以像普通函数那样调用, 可以有参数，可以有返回值
	int operator()(int a, int b)
	{
		return a + b;
	}

};

void my_test01()
{
	cout << "** 仿函数 可以有参数，有返回值 **" << endl;
	MyAdd01 myAdd;
	cout << myAdd(10, 10) << endl; //20

}

//2、函数对象超出普通函数的概念，函数对象可以有自己的状态，因为它是一个类，可以有成员属性
class MyPrint01
{
public:
	MyPrint01()
	{
		count = 0;
	}
	void operator()(string str)
	{
		cout << str << endl;
		count++;
	}
	int count; //函数对象可以有自己的状态
};

void my_test02()
{
	cout << endl << "** 仿函数 可以有自己的成员 **" << endl;

	MyPrint01 myPrint;
	myPrint("hello world");
	myPrint("hello world");
	myPrint("hello world");

	cout << "myPrint仿函数调用次数：" << myPrint.count << endl; 

}

//3、函数对象可以作为参数传递
void doPrint(MyPrint01& mprint, string str) 
{
	mprint(str);
}

void my_test03()
{
	cout << endl << "** 仿函数 可以作为参数传递 **" << endl;

	MyPrint01 myPrint;
	doPrint(myPrint, "hello world"); //传递仿函数，和要输出的内容

}

/*****************************************************************************
 *  @brief	谓词
	概念：
		返回bool类型的仿函数称为谓词

	一元谓词、二元谓词
		返回bool类型，且operator()接受一个参数，那么叫做一元谓词
		返回bool类型，且operator()接受两个参数，那么叫做二元谓词
 *****************************************************************************/
//1、一元谓词
class GreaterFive  //大于5
{
public:
	bool operator()(int val) //一元谓词
	{
		return val > 5;
	}
};
void my_test04()
{
	cout << endl << "** 一元谓词 **" << endl;
	vector<int> vec;

	for (int i = 0; i < 10; i++)
	{
		vec.push_back(i);
	}

	//查找容器中 有没有大于5的数字
	//GreaterFive() 类名加一个小括号就是默认构造创建的匿名对象，再加一个小括号才是仿函数
	vector<int>::iterator it = find_if(vec.begin(), vec.end(), GreaterFive()); //find_if
	if (it == vec.end())
	{
		cout << "未找到" << endl;
	}
	else
	{
		cout << "找到了大于5的数字：" << *it << endl;
	}
}

/* 2、二元谓词 */
//仿函数实现降序
class MySortClass
{
public:
	bool operator()(int a, int b) //二元谓词
	{
		return a > b;
	}
};

//全局函数实现降序
bool mySortFunc(int a, int b)
{
	return a > b;
}

void my_test05()
{
	cout << endl << "** 二元谓词 **" << endl;

	vector<int> vec;

	vec.push_back(20);
	vec.push_back(50);
	vec.push_back(10);
	vec.push_back(30);
	vec.push_back(40);

	sort(vec.begin(), vec.end());
	for (vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
	{
		cout << *it << " "; //10 20 30 40 50
	}
	cout << endl;

	//使用函数对象，改变排序规则为降序
	
	//类名加一个小括号就是默认构造创建的匿名对象，再加一个小括号才是仿函数
	//sort(vec.begin(), vec.end(), MySortClass()); //仿函数降序
	//sort(vec.begin(), vec.end(), mySortFunc); //回调函数降序
	//普通全局函数的函数名是该函数的地址（可以理解成函数指针），仿函数是一个类加 () 是传入一个匿名对象类

	sort(vec.begin(), vec.end(), MySortClass()); //仿函数降序，第三个参数指定排序规则
	for (vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
	{
		cout << *it << " "; //50 40 30 20 10
	}
	cout << endl;

}


/*****************************************************************************
 *  @brief	算术仿函数
	功能描述：
		实现四则运算
		其中negate是一元运算，其他都是二元运算
	仿函数原型：
		template<class T> T plus<T> //加法仿函数
		template<class T> T minus<T> //减法仿函数
		template<class T> T multiplies<T> //乘法仿函数
		template<class T> T divides<T> //除法仿函数
		template<class T> T modulus<T> //取模仿函数
		template<class T> T negate<T> //取相反数仿函数
	使用内建函数对象，需要引入头文件 #include<functional>
 *****************************************************************************/
void my_test06()
{
	cout << endl << "** 内建函数对象：算术仿函数 **" << endl;

	//取相反数仿函数 negate
	negate<int> n;
	cout << "取相反数仿函数：5 取反为 " << n(5) << endl;

	//加法仿函数 plus
	plus<int> p;
	cout << "加法仿函数：" << p(10, 10) << endl;

}

/*****************************************************************************
 *  @brief	关系仿函数
	功能描述：
		实现关系对比
	仿函数原型：
		template<class T> bool equal_to<T> //等于
		template<class T> bool not_equal_to<T> //不等于
		template<class T> bool greater<T> //大于
		template<class T> bool greater_equal<T> //大于等于
		template<class T> bool less<T> //小于
		template<class T> bool less_equal<T> //小于等于
	最常用的就是 greater 仿函数
 *****************************************************************************/
class MyCompare
{

};
void my_test07()
{
	cout << endl << "** 内建函数对象：关系仿函数 **" << endl;

	vector<int> vec;
	vec.push_back(20);
	vec.push_back(50);
	vec.push_back(10);
	vec.push_back(30);
	vec.push_back(40);

	sort(vec.begin(), vec.end());
	for (vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
	{
		cout << *it << " "; //10 20 30 40 50
	}
	cout << endl;


	/* 用关系仿函数 greater 实现降序 */
	sort(vec.begin(), vec.end(), greater<int>()); //使用内建函数对象实现降序
	//sort(vec.begin(), vec.end(), MySortClass());//在 my_test05中，使用了自定义的仿函数实现了降序

	for (vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
	{
		cout << *it << " "; //50 40 30 20 10
	}
	cout << endl;

}


/*****************************************************************************
 *  @brief	逻辑仿函数
	功能描述：
			实现逻辑运算
	函数原型：
		template<class T> bool logical_and<T> //逻辑与
		template<class T> bool logical_or<T> //逻辑或
		template<class T> bool logical_not<T> //逻辑非
	逻辑仿函数实际使用较少
 *****************************************************************************/
void my_test08()
{
	vector<bool> vec;
	vec.push_back(true);
	vec.push_back(false);
	vec.push_back(true);

	for (vector<bool>::iterator it = vec.begin(); it != vec.end(); it++)
	{
		cout << *it << " "; //1 0 1
	}
	cout << endl;

	//逻辑非 将 vec容器搬运到vec2中，并执行逻辑非运算
	vector<bool> vec2;
	vec2.resize(vec.size()); //要想搬运，必须先设置大小
	transform(vec.begin(), vec.end(), vec2.begin(), logical_not<bool>()); //vec以逻辑非方式搬运到vec2
	for (vector<bool>::iterator it = vec2.begin(); it != vec2.end(); it++)
	{
		cout << *it << " "; //0 1 0
	}
	cout << endl;
}

/*****************************************************************************
 *  @brief	main

 *****************************************************************************/
int main25()
{
	//1、函数对象在使用时，可以像普通函数那样调用, 可以有参数，可以有返回值
	my_test01();

	//2、函数对象超出普通函数的概念，函数对象可以有自己的状态，因为它是一个类，可以有成员属性
	my_test02();

	//3、函数对象可以作为参数传递
	my_test03();

	//一元谓词：返回bool类型 + 仿函数有一个参数
	my_test04();

	//二元谓词：返回bool类型 + 仿函数有两个参数
	my_test05();

	//算术仿函数
	my_test06();

	//关系仿函数
	my_test07();

	//逻辑仿函数
	my_test08();


	return 0;

}