/*
常用集合算法
	学习目标：掌握常用的集合算法
	算法简介：
		set_intersection	// 求两个容器的交集
		set_union	// 求两个容器的并集
		set_difference	// 求两个容器的差集


	① set_intersection
		功能描述：
			求两个容器的交集
		函数原型：
			set_intersection(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);
			// 求两个集合的交集，返回值是交集中最后一个元素的迭代器位置
				// beg1 容器1开始迭代器
				// end1 容器1结束迭代器
				// beg2 容器2开始迭代器
				// end2 容器2结束迭代器
				// dest 目标容器开始迭代器
		注意:两个集合必须是有序序列
			 目标容器需要先开辟空间，从两个容器中取小值

	② set_union
		功能描述：
			求两个集合的并集
		函数原型：
			set_union(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);
			// 求两个集合的并集，返回值是并集中的最后一个元素的迭代器位置
				// beg1 容器1开始迭代器
				// end1 容器1结束迭代器
				// beg2 容器2开始迭代器
				// end2 容器2结束迭代器
				// dest 目标容器开始迭代器
		注意:两个集合必须是有序序列
			 目标容器开辟空间需要为两个容器大小相加

*/

#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*****************************************************************************
 *  @brief	set_intersection
		功能描述：
			求两个容器的交集
		函数原型：
			set_intersection(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);
			// 求两个集合的交集，返回值是交集中最后一个元素的迭代器位置
				// beg1 容器1开始迭代器
				// end1 容器1结束迭代器
				// beg2 容器2开始迭代器
				// end2 容器2结束迭代器
				// dest 目标容器开始迭代器
		注意:两个集合必须是有序序列
			 目标容器需要先开辟空间，从两个容器中取小值

 *****************************************************************************/
class MyPrint03
{
public:
	void operator()(int val)
	{
		cout << val;
	}
};
void a1_set_intersection()
{
	cout << "** set_intersection 交集 **" << endl;

	vector<int> vec1;
	vector<int> vec2;
	for (int i = 0; i < 10; i++)
	{
		vec1.push_back(i);
		vec2.push_back(i+5);
	}

	vector<int> vDest;
	//为交集开辟空间取二者大小的最小值即可
	vDest.resize(min(vec1.size(), vec2.size()));

	vector<int>::iterator itEnd = set_intersection(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), vDest.begin());

	//for_each(vDest.begin(), vDest.end(), MyPrint03());//5 6 7 8 9 0 0 0 0 0
	//注意：由于交集大小一定≤二者大小，所以这里建议使用 set_intersection 返回的迭代器作为结束位置
	for_each(vDest.begin(), itEnd, MyPrint03());//5 6 7 8 9
	cout << endl;
}


/*****************************************************************************
 *  @brief	set_union
	功能描述：
		求两个集合的并集
	函数原型：
		set_union(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);
		// 求两个集合的并集，返回值是并集中的最后一个元素的迭代器位置
			// beg1 容器1开始迭代器
			// end1 容器1结束迭代器
			// beg2 容器2开始迭代器
			// end2 容器2结束迭代器
			// dest 目标容器开始迭代器
	注意:两个集合必须是有序序列
		 目标容器开辟空间需要为两个容器大小相加

 *****************************************************************************/
void a2_set_union()
{
	cout << endl << "** set_union 并集 **" << endl;

	vector<int> vec1;
	vector<int> vec2;
	for (int i = 0; i < 10; i++)
	{
		vec1.push_back(i);
		vec2.push_back(i + 5);
	}

	vector<int> vDest;
	//为并集开辟空间，取二者大小的和
	vDest.resize(vec1.size() + vec2.size());

	vector<int>::iterator itEnd = set_union(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), vDest.begin());

	//for_each(vDest.begin(), vDest.end(), MyPrint03());//0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 0 0 0 0 0
	//注意：由于并集大小一定≥二者大小的和，所以这里建议使用 set_union 返回的迭代器作为结束位置
	for_each(vDest.begin(), itEnd, MyPrint03());//0 1 2 3 4 5 6 7 8 9 10 11 12 13 14
	cout << endl;
}


/*****************************************************************************
 *  @brief	set_difference
	功能描述：
		求两个集合的差集
	函数原型：
		set_difference(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);
		// 求两个集合的差集，返回值是差集中最后一个元素的迭代器位置
		// beg1 容器1开始迭代器
		// end1 容器1结束迭代器
		// beg2 容器2开始迭代器
		// end2 容器2结束迭代器
		// dest 目标容器开始迭代器
	注意：
		  求差集的两个集合必须的有序序列
		  目标容器开辟空间需要从两个容器大小中取较大值

 *****************************************************************************/
void a3_set_difference()
{
	cout << endl << "** set_difference 差集 **" << endl;

	vector<int> vec1;
	vector<int> vec2;
	for (int i = 0; i < 10; i++)
	{
		vec1.push_back(i);
		vec2.push_back(i + 5);
	}

	vector<int> vDest;
	//为差集开辟空间，取二者大小的较大值
	vDest.resize(max(vec1.size(), vec2.size()));

	//vec1与vec2的差集(vec1中不和vec2相同的部分)
	cout << "vec1与vec2的差集为： " << endl;
	vector<int>::iterator itEnd = set_difference(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), vDest.begin());
	for_each(vDest.begin(), itEnd, MyPrint03());
	cout << endl; //0 1 2 3 4


	//vec2与vec1的差集(vec2中不和vec1相同的部分)
	cout << "vec2与vec1的差集为： " << endl;
	vector<int>::iterator itEnd2 = set_difference(vec2.begin(), vec2.end(), vec1.begin(), vec1.end(), vDest.begin());
	for_each(vDest.begin(), itEnd2, MyPrint03());
	cout << endl; //10 11 12 13 14

}

/*****************************************************************************
 *  @brief	main

 *****************************************************************************/
int main()
{
	//求交集
	a1_set_intersection();

	//求并集
	a2_set_union();

	//求差集
	a3_set_difference();

	return 0;
}