/*
常用排序算法
	学习目标：掌握常用的排序算法
	算法简介：
		sort	//对容器内元素进行排序
		random_shuffle //洗牌 指定范围内的元素随机调整次序
		merge	// 容器元素合并，并存储到另一容器中
		reverse // 反转指定范围的元素
	① sort
		功能描述：
			对容器内元素进行排序
		函数原型：
			sort(iterator beg, iterator end, _Pred);
			// 按值查找元素，找到返回指定位置迭代器，找不到返回结束迭代器位置
				// beg 开始迭代器
				// end 结束迭代器
				// _Pred 谓词
	
	② random_shuffle
		功能描述：
			洗牌 指定范围内的元素随机调整次序
		函数原型：
			random_shuffle(iterator beg, iterator end);
			// 指定范围内的元素随机调整次序
			// beg 开始迭代器
			// end 结束迭代器
	
	③ merge
		功能描述：
			两个容器元素合并，并存储到另一容器中
		函数原型：
			merge(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);
			// 容器元素合并，并存储到另一容器中
				// beg1 容器1开始迭代器
				// end1 容器1结束迭代器
				// beg2 容器2开始迭代器
				// end2 容器2结束迭代器
				// dest 目标容器开始迭代器
		
		注意: 两个容器必须是有序的，且要同升序，或同为降序
			  目标容器要先开辟足够的空间


*/

#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*****************************************************************************
 *  @brief	sort
	功能描述：
		对容器内元素进行排序
	函数原型：
		sort(iterator beg, iterator end, _Pred);
		// 按值查找元素，找到返回指定位置迭代器，找不到返回结束迭代器位置
			// beg 开始迭代器
			// end 结束迭代器
			// _Pred 谓词
 *****************************************************************************/
class MyPrint01
{
public:
	void operator()(int val)
	{
		cout << val << " ";
	}
};

class MyDecline
{
public:
	bool operator()(int a, int b)
	{
		return a > b;
	}
};

static void a_test01()
{
	cout << "** sort 排序 **" << endl;

	vector<int> vec;
	vec.push_back(20);
	vec.push_back(10);
	vec.push_back(40);
	vec.push_back(30);

	//sort 升序
	sort(vec.begin(), vec.end());

	for_each(vec.begin(), vec.end(), MyPrint01());
	cout << endl;

	//改为降序
	sort(vec.begin(), vec.end(), greater<int>()); //使用内建仿函数
	//sort(vec.begin(), vec.end(), MyDecline()); //使用自定义仿函数
	for_each(vec.begin(), vec.end(), MyPrint01());
	cout << endl;
}


/*****************************************************************************
 *  @brief	random_shuffle
	功能描述：
		洗牌 指定范围内的元素随机调整次序
	函数原型：
		random_shuffle(iterator beg, iterator end);
		// 指定范围内的元素随机调整次序
		// beg 开始迭代器
		// end 结束迭代器

 *****************************************************************************/
static void a_test02()
{
	cout << endl << "** random_shuffle 随机打乱次序 **" << endl;
	
	srand((unsigned int)time(NULL));//随机种子

	vector<int> vec;
	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30);
	vec.push_back(40);
	vec.push_back(50);

	cout << "打乱前：" << endl;
	for_each(vec.begin(), vec.end(), MyPrint01());

	random_shuffle(vec.begin(), vec.end()); //加入随机种子才能真随机

	cout << endl << "打乱后：" << endl;
	for_each(vec.begin(), vec.end(), MyPrint01());
	cout << endl;
}

/*****************************************************************************
 *  @brief	merge
	功能描述：
		两个容器元素合并，并存储到另一容器中
	函数原型：
		merge(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);
		// 容器元素合并，并存储到另一容器中
			// beg1 容器1开始迭代器
			// end1 容器1结束迭代器
			// beg2 容器2开始迭代器
			// end2 容器2结束迭代器
			// dest 目标容器开始迭代器
	注意: 两个容器必须是有序的，且要同升序，或同为降序
		  目标容器要先开辟足够的空间
 *****************************************************************************/
static void a_test03()
{
	cout << endl << "** merge 容器合并 **" << endl;

	vector<int> vec1;
	vector<int> vec2;
	vec1.push_back(6);
	vec1.push_back(3);
	vec2.push_back(7);
	vec2.push_back(5);

	vector<int> vDest;
	vDest.resize(vec1.size() + vec2.size());//合并之前要先分配足够的空间
	
	//容器合并
	//merge(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), vDest.begin()); //两个容器同为升序
	merge(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), vDest.begin(), greater<int>()); //同为降序

	for_each(vDest.begin(), vDest.end(), MyPrint01());
	cout << endl;
}


/*****************************************************************************
 *  @brief	reverse
	功能描述：
		将容器内元素进行反转
	函数原型：
		reverse(iterator beg, iterator end);
		// 反转指定范围的元素
		// beg 开始迭代器
		// end 结束迭代器

 *****************************************************************************/
static void a_test04()
{
	cout << endl << "** reverse 容器内元素反转 **" << endl;

	vector<int> vec1;
	vec1.push_back(6);
	vec1.push_back(3);
	vec1.push_back(7);
	vec1.push_back(5);

	cout << "reverse 反转前：" << endl;
	for_each(vec1.begin(), vec1.end(), MyPrint01());
	cout << endl;

	//reverse反转
	cout << "reverse 反转后：" << endl;
	reverse(vec1.begin(), vec1.end());
	for_each(vec1.begin(), vec1.end(), MyPrint01());

}

/*****************************************************************************
 *  @brief	main

 *****************************************************************************/
int main26_3()
{
	//sort 排序
	a_test01();

	//random_shuffle 随机打乱次序
	a_test02();

	//merge 容器合并
	a_test03();

	//reverse 容器内元素反转
	a_test04();

	return 0;
}