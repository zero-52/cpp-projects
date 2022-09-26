/*
常用算术生成算法
	学习目标：掌握常用的算术生成算法
	注意：
		算术生成算法属于小型算法，使用时包含的头文件为 #include <numeric>
	算法简介：
		accumulate	// 计算容器元素累计总和
		fill	// 向容器中添加元素

	① accumulate
		功能描述：
			计算区间内 容器元素累计总和
		函数原型：
			accumulate(iterator beg, iterator end, value);
			// 计算容器元素累计总和
				// beg 开始迭代器
				// end 结束迭代器
				// value 起始值，与容器元素的累加和相加为最终结果
		头文件为 #include <numeric>

	② fill
		功能描述：
			向容器中填充指定的元素
		函数原型：
			fill(iterator beg, iterator end, value);
			// 向容器中填充元素
				// beg 开始迭代器
				// end 结束迭代器
				// value 填充的值
			注意：fill 将容器大小的所有元素都填充为指定元素

	③ iota 
		iota(iterator beg, iterator end, value);
		//填充，以指定元素递增填充到容器大小
*/

#include<iostream>
#include <vector>
using namespace std;
#include<numeric>
#include <algorithm>

/*****************************************************************************
 *  @brief	accumulate
	功能描述：
		计算区间内 容器元素累计总和
	函数原型：
		accumulate(iterator beg, iterator end, value);
		// 计算容器元素累计总和，返回和值
			// beg 开始迭代器
			// end 结束迭代器
			// value 起始值，与容器元素的累加和相加为最终结果

 *****************************************************************************/
void a1_accumulate()
{
	cout << endl << "** accumulate 计算区间内 容器元素累计总和 **" << endl;

	vector<int> vec1;
	for (int i = 0; i <= 100; i++)
	{
		vec1.push_back(i);
	}
	//accumulate 累加
	int total = accumulate(vec1.begin(), vec1.end(), 0);  //头文件 <numeric>
	cout << "和为：" << total << endl; //0+5050

	int total2 = accumulate(vec1.begin(), vec1.end(), 1000);  //头文件 <numeric>
	cout << "和为：" << total2 << endl; //1000+5050=6050
}
/*****************************************************************************
 *  @brief	fill
	功能描述：
		向容器中填充指定的元素
	函数原型：
		fill(iterator beg, iterator end, value);
		// 向容器中填充元素
			// beg 开始迭代器
			// end 结束迭代器
			// value 填充的值
		注意：fill 将容器大小的所有元素都填充为指定元素

		iota 填充，从指定元素递增填充到容器大小
		iota(vec1.begin(), vec1.end(), 3);
 *****************************************************************************/
class MyPrint03
{
public:
	void operator()(int val)
	{
		cout << val << " ";
	}
};
void a2_fill()
{
	cout << endl << "** fill/iota 向容器中填充指定的元素 **" << endl;

	vector<int> vec1;
	vec1.push_back(10);
	vec1.push_back(10);
	vec1.push_back(10);

	vec1.resize(5);

	//fill 填充，将容器大小的所有元素都填充为指定元素
	cout << "fill 填充，将容器大小的所有元素都填充为指定元素" << endl;
	fill(vec1.begin(), vec1.end(), 100);
	for_each(vec1.begin(), vec1.end(), MyPrint03());

	cout << endl;

	//iota 填充，以指定元素递增填充到容器大小
	cout << endl << "iota 填充，以指定元素递增填充到容器大小" << endl;
	iota(vec1.begin(), vec1.end(), 3);
	for_each(vec1.begin(), vec1.end(), MyPrint03());


	cout << endl << "iota 的用法" << endl;
	int num[10];
	iota(num, num + 10, 100);
	for_each(num, num + 10, MyPrint03());
	cout << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << num[i] << " ";
	}
}
/*****************************************************************************
 *  @brief	main

 *****************************************************************************/
int main26_5()
{
	//accumulate 累加容器指定范围的元素
	a1_accumulate();

	//fill 以指定元素填充容器指定的范围
	a2_fill();

	return 0;
}