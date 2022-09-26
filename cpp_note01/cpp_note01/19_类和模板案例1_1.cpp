/*****************************************************************************
 *  @brief	类模板案例
 描述: 实现一个通用的数组类，要求如下：

	可以对内置数据类型以及自定义数据类型的数据进行存储
	将数组中的数据存储到堆区
	构造函数中可以传入数组的容量
	提供对应的拷贝构造函数以及operator = 防止浅拷贝问题
	提供尾插法和尾删法对数组中的数据进行增加和删除
	可以通过下标的方式访问数组中的元素
	可以获取数组中当前元素个数和数组的容量
 *
 *****************************************************************************/

#include<iostream>
using namespace std;

#include"19_1MyArray.hpp"

template<typename T>
void printMyArr(MyArray<T> arr)
{
	for (int i = 0; i < arr.getCurrentSize(); i++)
	{
		cout << arr[i] << endl;
	}
}
/* 1、测试内置数据类型 */
void test41()
{
	//MyArray<int> arr1(5); //测试有参构造函数

	//MyArray<int> arr2(arr1); //测试拷贝构造函数

	//MyArray<int> arr3(100);  
	//arr3 = arr1; //测试重载运算符

	MyArray<int> arr1(5);
	for (int i = 0; i < 5; i++)
	{
		//利用尾插法，向数组插入数据
		arr1.Tail_Insert(i);
	}

	printMyArr(arr1); //打印数组 0 1 2 3 4
	cout << "arr1的容量为：" << arr1.getCapacity() << endl; //5
	cout << "arr1当前大小为：" << arr1.getCurrentSize() << endl; //5


	MyArray<int> arr2(arr1);
	printMyArr(arr2);
	arr2[4] = 8;  //做左值修改，0 1 2 3 8
	printMyArr(arr2);

	//尾删
	arr2.Tail_Del();
	printMyArr(arr2); //0 1 2 3 
	cout << "arr2的容量为：" << arr2.getCapacity() << endl;//5
	cout << "arr2当前大小为：" << arr2.getCurrentSize() << endl;//4

}



/* 2、测试自定义类型 */
class Person13
{
public:
	string m_Name;
	int m_Age;
	Person13() { }
	Person13(string name, int age)
	{
		m_Name = name;
		m_Age = age;
	}
};

void printMyArr2(MyArray<Person13>& arr)
{
	for (int i = 0; i < arr.getCurrentSize(); i++)
	{
		cout << "姓名：" << arr[i].m_Name << "  年龄：" << arr[i].m_Age << endl;
	}
}
void test42()
{
	cout << endl << endl;
	MyArray<Person13> arr1(5);

	Person13 p1("孙悟空", 100);
	Person13 p2("沙僧", 90);
	Person13 p3("八戒", 80);

	arr1.Tail_Insert(p1);
	arr1.Tail_Insert(p2);

	printMyArr2(arr1);
	cout << "arr1的容量为：" << arr1.getCapacity() << endl;//5
	cout << "arr1当前大小为：" << arr1.getCurrentSize() << endl;//2

	cout << endl;
	arr1.Tail_Insert(p3); //尾插
	printMyArr2(arr1);


}

/*****************************************************************************
 *  @brief	main
 *
 *****************************************************************************/
int main19()
{
	//通用数组测试内置数据类型
	test41();

	//通用数组测试自定义数据类型
	test42();
	return 0;
}