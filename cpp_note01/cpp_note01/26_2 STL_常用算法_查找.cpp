/*
STL- 常用算法
概述:
	算法主要是由头文件<algorithm> <functional> <numeric>组成。

	<algorithm>是所有STL头文件中最大的一个，范围涉及到比较、 交换、查找、遍历操作、复制、修改等等

	<numeric>体积很小，只包括几个在序列上面进行简单数学运算的模板函数

	<functional>定义了一些模板类,用以声明函数对象。


常用查找算法
	学习目标：
		掌握常用的查找算法
	算法简介：
		find		//查找元素
		find_if		//按条件查找元素
		adjacent_find	//查找相邻重复元素
		binary_search	//二分查找法
		count		//统计元素个数
		count_if	//按条件统计元素个数
	① find
		功能描述：
			查找指定元素，找到返回指定元素的迭代器，找不到返回结束迭代器end()
		函数原型：
			find(iterator beg, iterator end, value);
			// 按值查找元素，找到返回指定位置迭代器，找不到返回结束迭代器位置
				// beg 开始迭代器
				// end 结束迭代器
				// value 查找的元素
	注意：find 的底层源码中用到==判断是否找到value，对于查找自定义数据类型，需要重载==运算符

	② find_if
		功能描述：
			按条件查找元素
		函数原型：
			find_if(iterator beg, iterator end, _Pred);
			// 按值查找元素，找到返回指定位置迭代器，找不到返回结束迭代器位置
				// beg 开始迭代器
				// end 结束迭代器
				// _Pred 函数或者谓词（返回bool类型的仿函数）
	
	③ adjacent_find
		功能描述：
			查找相邻重复元素
		函数原型：
			adjacent_find(iterator beg, iterator end);
			// 查找相邻重复元素,返回相邻元素的第一个位置的迭代器，找不到返回结束迭代器位置
				// beg 开始迭代器
				// end 结束迭代器
	
	④ binary_search
		功能描述：
			二分法查找指定元素是否存在，只适用于有序升序序列
		函数原型：
			bool binary_search(iterator beg, iterator end, value);
			// 查找指定的元素，查到 返回true 否则false
				// beg 开始迭代器
				// end 结束迭代器
				// value 查找的元素

			注意: 二分查找法效率很高，但容器中元素必须为有序的

	⑤ count
		功能描述：
			统计容器中某元素个数
		函数原型：
			int count(iterator beg, iterator end, value);
			// 统计元素出现次数，返回个数
				// beg 开始迭代器
				// end 结束迭代器
				// value 统计的元素

		注意：统计自定义数据类型时候，需要配合重载 operator==
		底层源码用到了 == ，对于自定义类型，需要在Person类中重载==，类似于 find 查找自定义数据类型

	⑥ count_if
		功能描述：
			按条件统计元素个数
		函数原型：
			int count_if(iterator beg, iterator end, _Pred);
			// 按条件统计元素出现次数，返回个数 int型
				// beg 开始迭代器
				// end 结束迭代器
				// _Pred 谓词

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*****************************************************************************
 *  @brief	find
	功能描述：
		查找指定元素，找到返回指定元素的迭代器，找不到返回结束迭代器end()
	函数原型：
		find(iterator beg, iterator end, value);
		// 按值查找元素，找到返回指定位置迭代器，找不到返回结束迭代器位置
			// beg 开始迭代器
			// end 结束迭代器
			// value 查找的元素
	注意：find 的底层源码中用到==判断是否找到value，对于查找自定义数据类型，需要重载==运算符
 *****************************************************************************/
//find 查找内置数据类型
static void a_test01()
{
	/* 1、查找内置数据类型 */
	cout << "** find 查找内置数据类型 **" << endl;

	vector<int> vec1;
	for (int i = 0; i < 5; i++)
	{
		vec1.push_back(i);
	}

	//find 查找是否存在 5 这个数
	vector<int>::iterator it = find(vec1.begin(), vec1.end(), 5);
	if (it == vec1.end())
	{
		cout << "没找到" << endl;
	}
	else
	{
		cout << "找到了：" << *it << endl;
	}
}

//find 查找自定义数据类型
class Person17
{
public:
	Person17(string name, int age)
	{
		m_Name = name;
		m_Age = age;
	}
	//查找的底层源码中用到==，为适应自定义数据类型，需要重载==运算符
	bool operator==(const Person17& p) //要加const，因为只是作比较，不允许修改
	{
		if (this->m_Name == p.m_Name && this->m_Age == p.m_Age)
		{
			return true;
		}
		return false;
	}
	string m_Name;
	int m_Age;
};

static void a_test02()
{
	/* 2、查找自定义数据类型 */
	cout << "** find 查找自定义数据类型 **" << endl;

	vector<Person17> vecP1;

	Person17 p1("小吴", 10);
	Person17 p2("悟空", 20);
	vecP1.push_back(p1);
	vecP1.push_back(p2);
	//vecP1.push_back(Person17("小吴", 10));
	//vecP1.push_back(Person17("悟空", 20));

	Person17 pp("悟空", 20); //在容器中要查找的人

	//find 查找是否存在 pp 这个人
	vector<Person17>::iterator it2 = find(vecP1.begin(), vecP1.end(), pp);//查找的源码中用到==，为适应自定义数据类型，需要重载==运算符
	if (it2 == vecP1.end()) 
	{
		cout << "没找到" << endl;
	}
	else
	{
		cout << "找到了  姓名：" << it2->m_Name << " 年龄：" << it2->m_Age << endl;
	}
}


/*****************************************************************************
 *  @brief	find_if
	功能描述：
		按条件查找元素
	函数原型：
		find_if(iterator beg, iterator end, _Pred);
		// 按值查找元素，找到则返回指定位置迭代器，找不到返回结束迭代器位置
			// beg 开始迭代器
			// end 结束迭代器
			// _Pred 函数或者谓词（返回bool类型的仿函数）

		find 第三个参数为要查找的数据
		find_if 第三个参数是函数或谓词(相当于是条件)

 *****************************************************************************/
//find_if 查找内置数据类型
class GreaterTwo
{
public:
	bool operator()(int val)
	{
		return val > 2;
	}
};

static void a_test03()
{
	cout << endl << "** find_if 条件查找内置数据类型 **" << endl;

	vector<int> vec;
	for (int i = 0; i < 5; i++)
	{
		vec.push_back(i);
	}
	//查找容器中 大于2 的第一个元素
	vector<int>::iterator it = find_if(vec.begin(), vec.end(), GreaterTwo());
	if (it == vec.end())
	{
		cout << "未找到" << endl;
	}
	else
	{
		cout << "找到了：" << *it << endl;
	}
}

//find_if 查找自定义数据类型
class Person18
{
public:
	Person18(string name, int age)
	{
		m_Name = name;
		m_Age = age;
	}
	string m_Name;
	int m_Age;
};

class Greater20
{
public:
	bool operator()(const Person18& p)
	{
		return p.m_Age > 20;
	}
};

static void a_test04()
{
	cout << endl << "** find_if 条件查找自定义数据类型 **" << endl;

	vector<Person18> vecP1;
	Person18 p1("小吴", 10);
	Person18 p2("悟空", 100);
	Person18 p3("八戒", 80);
	vecP1.push_back(p1);
	vecP1.push_back(p2);
	vecP1.push_back(p3);

	//查找容器中 年龄大于20 的第一个元素
	vector<Person18>::iterator it = find_if(vecP1.begin(), vecP1.end(), Greater20());

	if (it == vecP1.end())
	{
		cout << "未找到" << endl;
	}
	else
	{
		cout << "找到了：姓名：" << it->m_Name << " 年龄：" << it->m_Age << endl;
	}

	//查找容器中 年龄大于20 的所有元素
	while (it != vecP1.end())
	{
		cout << "找到了：姓名：" << it->m_Name << " 年龄：" << it->m_Age << endl;
		it++;
	}
}

/*****************************************************************************
 *  @brief	adjacent_find
	功能描述：
		查找相邻重复元素
	函数原型：
		adjacent_find(iterator beg, iterator end);
		// 查找相邻重复元素,返回相邻元素的第一个位置的迭代器，找不到返回结束迭代器位置
			// beg 开始迭代器
			// end 结束迭代器

 *****************************************************************************/
static void a_test05()
{
	cout << endl << "** adjacent_find 查找相邻重复的元素 **" << endl;

	vector<int> vec1;
	vec1.push_back(3);
	vec1.push_back(4);
	vec1.push_back(3); //和上一个 3 不相邻
	vec1.push_back(5);
	vec1.push_back(5); //5 相邻

	vector<int>::iterator it = adjacent_find(vec1.begin(), vec1.end());
	if (it == vec1.end())
	{
		cout << "没有相邻重复的元素" << endl;
	}
	else
	{
		cout << "相邻重复的元素为：" << *it << endl;//5
	}

}

/*****************************************************************************
 *  @brief	 binary_search
	功能描述：
		二分法查找指定元素是否存在，只适用于有序升序序列
	函数原型：
		bool binary_search(iterator beg, iterator end, value);
		// 查找指定的元素，查到 返回true 否则false
			// beg 开始迭代器
			// end 结束迭代器
			// value 查找的元素
		
		注意: 二分查找法效率很高，但容器中元素必须为有序的

 *****************************************************************************/
static void a_test06()
{
	cout << endl << "** binary_search 二分查找 **" << endl;

	vector<int> vec;
	for (int i = 0; i < 5; i++)
	{
		vec.push_back(i);
	}

	//二分查找：只适用于有序序列
	bool ret = binary_search(vec.begin(), vec.end(), 4);
	if (ret)
	{
		cout << "找到了查询元素" << endl;
	}
	else
	{
		cout << "没找到查询元素" << endl;
	}
}

/*****************************************************************************
 *  @brief	count
	功能描述：
		统计容器中某元素个数
	函数原型：
		int count(iterator beg, iterator end, value);
		// 统计元素出现次数，返回个数
			// beg 开始迭代器
			// end 结束迭代器
			// value 统计的元素
	
	注意：统计自定义数据类型时候，需要配合重载 operator==
	底层源码用到了 == ，对于自定义类型，需要在Person类中重载==，类似于 find 查找自定义数据类型
 *****************************************************************************/
 //1、统计内置数据类型
static void a_test07()
{
	cout << endl << "** count 统计容器中某元素个数 **" << endl;

	vector<int> vec;
	vec.push_back(20);
	vec.push_back(10);
	vec.push_back(30);
	vec.push_back(10);
	vec.push_back(10);

	int num = count(vec.begin(), vec.end(), 10);
	cout << "元素 10 出现次数：" << num << endl;//3

}

//2、统计自定义数据类型
class Person19
{
public:
	Person19(string name, int age)
	{
		m_Name = name;
		m_Age = age;
	}
	bool operator==(const Person19& p) //要加const
	{
		if (this->m_Age == p.m_Age)
		{
			return true;
		}
		return false;
	}
	string m_Name;
	int m_Age;
};
static void a_test08()
{
	vector<Person19> vecP1;
	Person19 p1("小吴", 10);
	Person19 p2("悟空", 100);
	Person19 p3("八戒", 80);
	Person19 p4("悟净", 80);

	vecP1.push_back(p1);
	vecP1.push_back(p2);
	vecP1.push_back(p3);
	vecP1.push_back(p4);

	Person19 pp("小美", 80);

	int num = count(vecP1.begin(), vecP1.end(), pp); 
	//直接运行错误，底层源码用到了 == ，对于自定义类型，需要在Person类中重载==，类似于 find 查找自定义数据类型

	cout << "与 小美 同岁的人数为：" << num << endl;//2
}

/*****************************************************************************
 *  @brief	count_if
	功能描述：
		按条件统计元素个数
	函数原型：
		int count_if(iterator beg, iterator end, _Pred);
		// 按条件统计元素出现次数，返回个数 int型
			// beg 开始迭代器
			// end 结束迭代器
			// _Pred 谓词
 *****************************************************************************/
//1、按条件统计内置数据类型
class Greater10
{
public:
	bool operator()(int val)
	{
		return val > 10;
	}
};
static void a_test09()
{
	cout << endl << "** count_if 统计容器中内置数据类型某元素个数 **" << endl;

	vector<int> vec;
	vec.push_back(20);
	vec.push_back(10);
	vec.push_back(30);
	vec.push_back(10);
	vec.push_back(10);

	int num = count_if(vec.begin(), vec.end(), Greater10());
	cout << "大于10的元素的个数为：" << num << endl;//2
}

//2、按条件统计自定义数据类型
class Person20
{
public:
	Person20(string name, int age)
	{
		m_Name = name;
		m_Age = age;
	}
	string m_Name;
	int m_Age;
};

class Greater30
{
public:
	bool operator()(const Person20& p) //const
	{
		return p.m_Age > 30;
	}
};
static void a_test10()
{
	cout << endl << "** count_if 统计容器中自定义类型某元素个数 **" << endl;

	vector<Person20> vecP1;
	Person20 p1("小吴", 10);
	Person20 p2("悟空", 100);
	Person20 p3("八戒", 80);
	Person20 p4("悟净", 80);

	vecP1.push_back(p1);
	vecP1.push_back(p2);
	vecP1.push_back(p3);
	vecP1.push_back(p4);

	int num = count_if(vecP1.begin(), vecP1.end(), Greater30());
	cout << "大于30的元素的个数为：" << num << endl;//3

}

/*****************************************************************************
 *  @brief	main

 *****************************************************************************/
int main26_2()
{
	//find 查找内置数据类型
	a_test01();
	//find 查找自定义数据类型
	a_test02();

	//find_if 查找内置数据类型
	a_test03();
	//find_if 查找自定义数据类型
	a_test04();

	//adjacent_find 查找相邻重复元素
	a_test05();

	//binary_search 二分查找法
	a_test06();

	//count 统计内置数据类型
	a_test07();
	//count 统计自定义数据类型
	a_test08();

	//count_if 统计内置数据类型
	a_test09();
	//count_if 统计自定义数据类型
	a_test10();

	return 0;
}