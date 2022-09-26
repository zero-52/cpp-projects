/*
常用拷贝和替换算法
	学习目标：掌握常用的拷贝和替换算法
	算法简介：
		copy	// 容器内指定范围的元素拷贝到另一容器中
		replace	// 将容器内指定范围的旧元素修改为新元素
		replace_if	// 容器内指定范围满足条件的元素替换为新元素
		swap	// 互换两个容器的元素

	① copy
		功能描述：
			容器内指定范围的元素拷贝到另一容器中
		函数原型：
			copy(iterator beg, iterator end, iterator dest);
			// 按值查找元素，找到返回指定位置迭代器，找不到返回结束迭代器位置
				// beg 开始迭代器
				// end 结束迭代器
				// dest 目标起始迭代器
		注意：目标容器需要提前开辟空间
	
	② replace
		功能描述：
			将容器内指定范围的旧元素修改为新元素
		函数原型：
			replace(iterator beg, iterator end, oldvalue, newvalue);
			// 将区间内旧元素 替换成 新元素
				// beg 开始迭代器
				// end 结束迭代器
				// oldvalue 旧元素
				// newvalue 新元素
	
	③ replace_if
		功能描述:
			将区间内满足条件的元素，替换成指定元素
		函数原型：
			replace_if(iterator beg, iterator end, _pred, newvalue);
			// 按条件替换元素，满足条件的替换成指定元素
				// beg 开始迭代器
				// end 结束迭代器
				// _pred 谓词
				// newvalue 替换的新元素
		注：replace_if按条件查找，可以利用仿函数灵活筛选满足的条件
	
	④ swap
		功能描述：
			容器互换，交换两个容器中的元素，两个容器类型要相同
		函数原型：
			swap(container c1, container c2);
			// 互换两个容器的元素
			// c1容器1
			// c2容器2

*/

#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*****************************************************************************
 *  @brief	copy
	功能描述：
		容器内指定范围的元素拷贝到另一容器中
	函数原型：
		copy(iterator beg, iterator end, iterator dest);
		// 按值查找元素，找到返回指定位置迭代器，找不到返回结束迭代器位置
			// beg 开始迭代器
			// end 结束迭代器
			// dest 目标起始迭代器
		注意：目标容器需要提前开辟空间
 *****************************************************************************/
class MyPrint02
{
public:
	void operator()(int val)
	{
		cout << val << " ";
	}
};
void a1_copy()
{
	cout << endl << "** copy 容器内指定范围的元素拷贝到另一容器中 **" << endl;

	vector<int> vec1;
	for (int i = 0; i < 5; i++)
	{
		vec1.push_back(i);
	}

	vector<int> vDest;
	vDest.resize(vec1.size()); //目标容器需要提前开辟空间
	//copy
	copy(vec1.begin(), vec1.end(), vDest.begin()); //全部复制，类似于赋值操作

	for_each(vec1.begin(), vec1.end(), MyPrint02());
	cout << endl;
}

/*****************************************************************************
 *  @brief	replace
	功能描述：
		将容器内指定范围的旧元素修改为新元素
	函数原型：
		replace(iterator beg, iterator end, oldvalue, newvalue);
		// 将区间内旧元素 替换成 新元素
			// beg 开始迭代器
			// end 结束迭代器
			// oldvalue 旧元素
			// newvalue 新元素

 *****************************************************************************/
void a2_replace()
{
	cout << endl << "** replace 将容器内指定范围的旧元素修改为新元素 **" << endl;

	vector<int> vec1;
	vec1.push_back(10);
	vec1.push_back(30);
	vec1.push_back(20);
	vec1.push_back(10);
	vec1.push_back(20);

	//replace 替换前
	cout << "replace 替换前：" << endl;
	for_each(vec1.begin(), vec1.end(), MyPrint02());
	cout << endl;

	//replace 替换后
	cout << "replace 替换后：" << endl;
	//替换
	replace(vec1.begin(), vec1.end(), 20, 11); //将范围内的 20 全换为 11
	for_each(vec1.begin(), vec1.end(), MyPrint02());
	cout << endl;
}

/*****************************************************************************
*  @brief	replace_if
	功能描述:
		将区间内满足条件的元素，替换成指定元素
	函数原型：
		replace_if(iterator beg, iterator end, _pred, newvalue);
		// 按条件替换元素，满足条件的替换成指定元素
			// beg 开始迭代器
			// end 结束迭代器
			// _pred 谓词
			// newvalue 替换的新元素
	注：replace_if按条件查找，可以利用仿函数灵活筛选满足的条件

 *****************************************************************************/
class Greater25
{
public:
	bool operator()(int val)
	{
		return val > 25;
	}
};
void a3_replace_if()
{
	cout << endl << "** replace_if 将容器内指定范围满足条件的旧元素修改为新元素 **" << endl;

	vector<int> vec1;
	vec1.push_back(10);
	vec1.push_back(30);
	vec1.push_back(40);
	vec1.push_back(20);
	vec1.push_back(10);
	vec1.push_back(50);
	vec1.push_back(20);

	//replace_if 替换前
	cout << "replace_if 替换前：" << endl;
	for_each(vec1.begin(), vec1.end(), MyPrint02());
	cout << endl;

	//replace_if 替换后
	cout << "replace_if 替换后：" << endl;
	//条件替换
	replace_if(vec1.begin(), vec1.end(), Greater25(), 100); //将范围内的 20 全换为 100
	
	for_each(vec1.begin(), vec1.end(), MyPrint02());
	cout << endl;
}

/*****************************************************************************
*  @brief	swap
	功能描述：
		容器互换，交换两个容器中的元素，两个容器类型要相同
	函数原型：
		swap(container c1, container c2);
		// 互换两个容器的元素
		// c1容器1
		// c2容器2

 *****************************************************************************/
void a4_swap()
{
	cout << endl << "** swap 互换两个容器的元素 **" << endl;

	vector<int> vec1;
	for (int i = 0; i < 10; i++)
	{
		vec1.push_back(i);
	}

	vector<int> vec2;
	for (int i = 100; i > 95; i--)
	{
		vec2.push_back(i);
	}

	cout << "互换前：" << endl;
	for_each(vec1.begin(), vec1.end(), MyPrint02());
	cout << endl;

	for_each(vec2.begin(), vec2.end(), MyPrint02());
	cout << endl;

	//swap 容器互换
	cout << "互换后：" << endl;
	swap(vec1, vec2);
	for_each(vec1.begin(), vec1.end(), MyPrint02());
	cout << endl;

	for_each(vec2.begin(), vec2.end(), MyPrint02());
	cout << endl;
}

/*****************************************************************************
 *  @brief	main

 *****************************************************************************/
int main26_4()
{
	//copy 容器内指定范围的元素拷贝到另一容器中
	a1_copy();

	//replace 将容器内指定范围的旧元素修改为新元素
	a2_replace();

	//replace_if 将容器内指定范围满足条件的旧元素修改为新元素
	a3_replace_if();

	//swap 容器互换
	a4_swap();


	return 0;
}