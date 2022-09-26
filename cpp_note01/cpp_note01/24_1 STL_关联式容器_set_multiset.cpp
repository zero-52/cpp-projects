/*****************************************************************************
无论是哪种序列式容器，其存储的都是 C++ 基本数据类型（诸如 int、double、float、string 等）或使用结构体、类自定义类型的元素。
例如，存储 int 类型元素的 vector 容器：std::vector<int> primes {2, 3, 5, 13};


关联式容器则大不一样，此类容器在存储元素值的同时，还会为各元素额外再配备一个值（又称为“键”，
其本质也是一个 C++ 基础数据类型或自定义类型的元素），它的功能是在使用关联式容器的过程中，如果
已知目标元素的键的值，则直接通过该键就可以找到目标元素，而无需再通过遍历整个容器的方式。

弃用序列式容器，转而选用关联式容器存储元素，往往就是看中了关联式容器可以快速查找、
读取或者删除所存储的元素，同时该类型容器插入元素的效率也比序列式容器高。

也就是说，使用关联式容器存储的元素，都是一个一个的“键值对”（ <key,value> ），这是和序列式容器最大的不同。
此外，序列式容器中存储的元素默认都是未经过排序的，而关联式容器存储，默认会根据各元素的键值的大小做升序排序。


*注：关联式容器所具备的这些特性，归咎于 STL 标准库在实现该类型容器时，底层选用了 「红黑树」这种数据结构来组织和存储各个键值对。


排序容器（关联式容器）：
	包括 set 集合容器、multiset多重集合容器、map映射容器以及 multimap 多重映射容器。
	排序容器中的元素默认是由小到大排序好的，即便是插入元素，元素也会插入到适当位置。
	所以关联容器在查找时具有非常好的性能。

关联式容器名称	特点
	set			定义在 <set> 头文件中，使用该容器存储的数据，各个元素键和值完全相同，且各个元素的值不能
				重复（保证了各元素键的唯一性）。该容器会自动根据各个元素的键（其实也就是元素值）的大小进行升序排序（调用 std::less<T>）。

	multiset	定义在 <set> 头文件中，和 set 容器唯一的不同在于，multiset 容器中存储元素的值可以重复（一旦值重复，则意味着键也是重复的）。
		
	map			定义在 <map> 头文件中，使用该容器存储的数据，其各个元素的键必须是唯一的（即不能重复），
				该容器会根据各元素键的大小，默认进行升序排序（调用 std::less<T>）。
		
	multimap	定义在 <map> 头文件中，和 map 容器唯一的不同在于，multimap 容器中存储元素的键可以重复。
	
	
哈希容器（或称无序关联容器）：
	C++ 11 新加入 4 种关联式容器，分别是 
		unordered_set 哈希集合、unordered_multiset 哈希多重集合、
		unordered_map 哈希映射、unordered_multimap 哈希多重映射。
	
	和关联式容器一样，无序容器也使用键值对（pair 类型）的方式存储数据。本质上的不同为：
		关联式容器的底层实现采用的树存储结构，更确切的说是红黑树结构；
		无序容器的底层实现采用的是哈希表的存储结构。
	
	严格来说，它们也属于关联式容器，但哈希容器底层采用的是哈希表，而不是红黑树

	C++ STL 底层采用哈希表实现无序容器时，会将所有数据存储到一整块连续的内存空间中，
	并且当数据存储位置发生冲突时，解决方法选用的是“链地址法”（又称“开链法”）
		
基于底层实现采用了不同的数据结构，因此和关联式容器相比，无序容器具有以下 2 个特点：
	1、无序容器内部存储的键值对是无序的，各键值对的存储位置取决于该键值对中的键，或者说由哈希函数确定
	2、和关联式容器相比，无序容器擅长通过指定键查找对应的值（平均时间复杂度为 O(1)）；
	   但对于使用迭代器遍历容器中存储的元素，无序容器的执行效率则不如关联式容器。

无序容器名称				功能
	unordered_map 		存储键值对 <key, value> 类型的元素，其中各个键值对键的值不允许重复，且该容器中存储的键值对是无序的。
	unordered_multimap	和 unordered_map 唯一的区别在于，该容器允许存储多个键相同的键值对。
	unordered_set		不再以键值对的形式存储数据，而是直接存储数据元素本身（当然也可以理解为，该容器存储的全部都是键 key 和值 value 相等的键值对，
						正因为它们相等，因此只存储 value 即可）。另外，该容器存储的元素不能重复，且容器内部存储的元素也是无序的。
	unordered_multiset	和 unordered_set 唯一的区别在于，该容器允许存储值相同的元素。


set/ multiset 容器
	所有元素都会在插入时自动被排序
	
	本质：
		set/multiset属于关联式容器，底层结构是用二叉树实现。
	
	区别：
		set 不允许容器中有重复的元素
		multiset 允许容器中有重复的元素

	set构造和赋值
		功能描述：创建set容器以及赋值

	构造：
		set<T> st; //默认构造函数：
		set(const set &st); //拷贝构造函数
	赋值：
		set& operator=(const set &st); //重载等号操作符


set大小和交换
	功能描述：
		统计set容器大小以及交换set容器
	函数原型：
		size(); //返回容器中元素的数目
		empty(); //判断容器是否为空
		swap(st); //交换两个集合容器


set插入和删除
	功能描述：
		set容器进行插入数据和删除数据
	函数原型：
		insert(elem); //在容器中插入元素。
		//set的insert参数可以带位置pos，但没有意义，因为插入后都会升序排序，与序列式容器略有不同

		erase(pos); //删除pos迭代器所指的元素，返回下一个元素的迭代器。
		erase(beg, end); //删除区间[beg,end)的所有元素 ，返回下一个元素的迭代器。
		erase(elem); //删除容器中值为elem的元素。相当于前面容器的 remove(elem) 操作
		clear(); //清除所有元素


set查找和统计
	功能描述：
		对set容器进行查找数据以及统计数据
	函数原型：
		find(key); //查找key是否存在,若存在，返回该键的元素的迭代器；若不存在，返回set.end()迭代器;
		count(key); //统计key的元素个数


 set和multiset区别
	学习目标：
		掌握set和multiset的区别
	区别：
		set不可以插入重复数据，而multiset可以
		set插入数据的同时会返回插入结果，表示插入是否成功
		multiset不会检测数据，因此可以插入重复数据


pair键值对创建
	 考虑到“键值对”并不是普通类型数据，C++ STL 标准库提供了 pair 类模板，其专门用来将 2 个普通元素
	 first 和 second（可以是 C++ 基本数据类型、结构体、类自定的类型）创建成一个新元素<first, second>

	功能描述：
		成对出现的数据，利用对组可以返回两个数据
	两种创建方式：
		pair<type, type> p; //默认构造
		pair<type, type> p(value1, value2); //初始化
		pair<type, tyoe> p(p1); //拷贝构造，借助另一个 pair 对象，创建新的 pair 对象
		pair<type, type> p(make_pair(value1, value2));//移动构造
		//pair<type, type> p = make_pair(value1, value2);//移动构造（隐式法）

	pair 对象重载了 <、<=、>、>=、==、!= 这 6 个的运算符
	对于进行比较的 2 个 pair 对象，先比较 pair.first 元素的大小，相等则继续比较 pair.second 元素的大小。

	swap() 成员函数：能够互换 2 个 pair 对象的键值对，交换前提是这2个pair对象的键和值的类型要相同


set容器排序
	学习目标：
		set容器默认排序规则为从小到大，掌握如何改变排序规则
	主要技术点：
		利用仿函数，可以改变排序规则
	注意：
		set 和 map 容器排序，是在<>里设置排序规则，set<int, ClassName> set1;
		且第二个参数只能写仿函数的类名（后面不加小括号），不能是全局函数名
 *****************************************************************************/
#include<iostream>
#include <set>
using namespace std;

/*****************************************************************************
 *  @brief	set容器 构造和赋值操作
	功能描述：创建set容器以及赋值
	
	注意：
		set 不允许容器中有重复的元素
		所有元素都会在插入时自动被排序

	构造：
		set<T> st; //默认构造函数：
		set(const set &st); //拷贝构造函数
	赋值：
		set& operator=(const set &st); //重载等号操作符
 *****************************************************************************/
void printSet(set<int>& s)
{
	for (set<int>::iterator it = s.begin(); it != s.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	/*for (int i = 0; i < s.size(); i++)
	{
		cout << s[i] << " "; //报错
	}*/
}
void set_test01()
{
	cout << "** set容器 构造和赋值操作 **" << endl;

	//默认构造
	set<int> set1;

	//set没有 push、pop 成员，只能用 insert 插入
	set1.insert(10);//set的insert参数可以带位置pos，但没有意义，因为插入后都会升序排序
	set1.insert(30);
	set1.insert(20);
	printSet(set1); //10 20 30  set容器自动排序

	set1.insert(20);
	printSet(set1); //10 20 30  集合容器不允许元素重复

	//拷贝构造
	set<int> set2(set1);
	printSet(set2); //10 20 30

	//赋值
	set<int> set3;
	set3 = set2;
	printSet(set3); //10 20 30

}

/*****************************************************************************
 *  @brief	set大小和交换
	功能描述：
		统计set容器大小以及交换set容器
	函数原型：
		size(); //返回容器中元素的数目
		empty(); //判断容器是否为空
		swap(st); //交换两个集合容器
 *****************************************************************************/
void set_test02()
{
	cout << endl << "** set容器 大小和交换操作 **" << endl;

	set<int> set1;
	set1.insert(10);
	set1.insert(20);
	set1.insert(30);

	//判断是否为空
	if (set1.empty())
	{
		cout << "set容器 为空！" << endl;
	}
	else
	{
		cout << "set容器 不为空！" << endl;
		cout << "set1容器的大小为：set1.size() = " << set1.size() << endl; //3
	}

	set<int> set2;
	set2.insert(5);
	set2.insert(6);
	//交换容器
	set2.swap(set1);
	printSet(set1);//5 6
	printSet(set2);//10 20 30
}

/*****************************************************************************
 *  @brief	set插入和删除
	功能描述：
		set容器进行插入数据和删除数据
	函数原型：
		insert(elem); //在容器中插入元素。
		//set的insert参数可以带位置pos，但没有意义，因为插入后都会升序排序，与序列式容器略有不同

		erase(pos); //删除pos迭代器所指的元素，返回下一个元素的迭代器。
		erase(beg, end); //删除区间[beg,end)的所有元素 ，返回下一个元素的迭代器。
		erase(elem); //删除容器中值为elem的元素。相当于前面容器的 remove(elem) 操作
		clear(); //清除所有元素

 *****************************************************************************/
void set_test03()
{
	cout << endl << "** set容器 插入和删除操作 **" << endl;

	set<int> set1;
	//插入
	set1.insert(20);
	set1.insert(10);
	set1.insert(30);
	set1.insert(40);
	printSet(set1);//10 20 30 40

	//删除 
	set1.erase(set1.begin());
	printSet(set1); //20 30 40

	set1.erase(30); //删除指定元素，类似 remove
	printSet(set1); //20 40

	//清空
	set1.erase(set1.begin(), set1.end());
	set1.clear();
	printSet(set1);

}

/*****************************************************************************
 *  @brief	set查找和统计
	功能描述：
		对set容器进行查找数据以及统计数据
	函数原型：
		find(key); //查找key是否存在,若存在，返回该键的元素的迭代器；若不存在，返回set.end()迭代器;
		count(key); //统计key的元素个数
 *****************************************************************************/
void set_test04()
{
	cout << endl << "** set容器 查找和统计操作 **" << endl;

	set<int> set1;
	//插入
	set1.insert(20);
	set1.insert(10);
	set1.insert(30);
	set1.insert(40);

	//查找
	set<int>::iterator itpos = set1.find(30); //查找返回迭代器，故用迭代器接收
	if (itpos != set1.end())
	{
		cout << "找到元素：" << *itpos << endl;
	}
	else
	{
		cout << "未找到该元素" << endl;
	}

	//统计(对于set而言，统计个数无非 1 或 0个，multiset不同)
	cout << "统计元素为 40 的个数：set1.count(40) = " << set1.count(40) << endl;
	cout << "统计元素为 1 的个数：set1.count(1) = " << set1.count(1) << endl;

}

/*****************************************************************************
 *  @brief	set和multiset区别
	学习目标：
		掌握set和multiset的区别
	区别：
		set不可以插入重复数据，而multiset可以
		set插入数据的同时会返回插入结果，表示插入是否成功
		multiset不会检测数据，因此可以插入重复数据

 *****************************************************************************/
void set_test05()
{
	cout << endl << "** set和multiset区别 **" << endl;

	//insert返回的是对组类型，可以用pair对组接收查看信息
	set<int> set2;
	pair<set<int>::iterator, bool>  ret = set2.insert(10);//第二个参数bool类型表示是否插入成功
	if (ret.second) //ret.second 表示为pair对组的第二个参数
	{
		cout << "第一次插入成功!" << endl;
	}
	else 
	{
		cout << "第一次插入失败!" << endl;
	}

	ret = set2.insert(10);
	if (ret.second) 
	{
		cout << "第二次插入成功!" << endl;
	}
	else 
	{
		cout << "第二次插入失败!" << endl;
	}

	//set
	set<int> set1;
	set1.insert(10);
	set1.insert(10);

	printSet(set1);//10

	//multiset
	multiset<int> mset1;
	mset1.insert(10);
	mset1.insert(10);

	for (multiset<int>::iterator it = mset1.begin(); it != mset1.end(); it++)
	{
		cout << *it << " ";//10 10
	}
	cout << endl;

}


/*****************************************************************************
 *  @brief	pair键值对创建
	 考虑到“键值对”并不是普通类型数据，C++ STL 标准库提供了 pair 类模板，其专门用来将 2 个普通元素
	 first 和 second（可以是 C++ 基本数据类型、结构体、类自定的类型）创建成一个新元素<first, second>
		
	功能描述：
		成对出现的数据，利用对组可以返回两个数据
	两种创建方式：
		pair<type, type> p; //默认构造
		pair<type, type> p(value1, value2); //初始化
		pair<type, tyoe> p(p1); //拷贝构造，借助另一个 pair 对象，创建新的 pair 对象
		pair<type, type> p(make_pair(value1, value2));//移动构造
		//pair<type, type> p = make_pair(value1, value2);//移动构造

	pair 对象重载了 <、<=、>、>=、==、!= 这 6 个的运算符
	对于进行比较的 2 个 pair 对象，先比较 pair.first 元素的大小，相等则继续比较 pair.second 元素的大小。

	swap() 成员函数：能够互换 2 个 pair 对象的键值对，交换前提是这2个pair对象的键和值的类型要相同
 *****************************************************************************/

void pair_test()
{
	cout << endl << "** pair对组创建 **" << endl;

	//默认构造
	pair<string, int> p1;
	p1.first = "小吴";
	p1.second = 26;
	cout << "p1 姓名：" << p1.first << " 年龄：" << p1.second << endl;

	//初始化构造
	pair<string, int> p2("Tom", 20);
	cout << "p2 姓名：" << p2.first << " 年龄：" << p2.second << endl;

	//拷贝构造
	pair<string, int> p3(p2);
	cout << "p3 姓名：" << p3.first << " 年龄：" << p3.second << endl;

	//移动构造
	pair<string, int> p4(make_pair("Jerry", 22));
	cout << "p4 姓名：" << p4.first << " 年龄：" << p4.second << endl;

	//交换
	cout << "交换后：" << endl;
	p4.swap(p3); //交换的前提是这 2 个 pair对象 的键和值的类型要相同
	cout << "p3 姓名：" << p3.first << " 年龄：" << p3.second << endl;
	cout << "p4 姓名：" << p4.first << " 年龄：" << p4.second << endl;


	//比较运算符重载
	pair <string, int> pair1("STL教程", 20);
	pair <string, int> pair2("C++教程", 20);
	pair <string, int> pair3("C++教程", 30);
	//pair1和pair2的key不同，value相同 => 不同
	if (pair1 != pair2) {
		cout << "pair1 != pair2" << endl;
	}
	//pair2和pair3的key相同，value不同 => 不同
	if (pair2 != pair3) {
		cout << "pair2 != pair3" << endl;
	}

}

/*****************************************************************************
 *  @brief	set容器排序
	学习目标：
		set容器默认排序规则为从小到大，掌握如何改变排序规则
	主要技术点：
		利用仿函数，可以改变排序规则
	注意：
		set 和 map 容器排序，是在<>里设置排序规则，set<int, ClassName> set1;
	    且第二个参数只能写仿函数的类名，不能是全局函数名

 *****************************************************************************/
//利用仿函数指定排序规则
class MySetSort
{
public:
	//()运算符重载，调用格式很像函数调用，又称仿函数
	bool operator()(int a, int b) const  //要加上const变为常函数，否则报错
	{
		return a > b;
	}
};
//全局函数
bool mySetSort_func(int a, int b)
{
	return a > b;
}
/* 对内置数据类型排序 */
void set_test06()
{
	cout << endl << "** set容器排序 **" << endl;
	cout << "内置数据类型排序" << endl;

	set<int> set1;
	set1.insert(20);
	set1.insert(50);
	set1.insert(30);//记得关联式容器插入时自动排序哦

	for (set<int>::iterator it = set1.begin(); it != set1.end(); it++)
	{
		cout << *it << " "; //20 30 50
	}
	cout << endl;

	//由于插入时自动排序，所以关联式容器要想指定排序规则，要在数据插入前指定排序方式
	//在创建set容器时，指定排序规则为从大到小
	
	//set<int, mySetSort_func> set2; //错误，第二个参数只能是仿函数类名，不能是全局函数名
	set<int, MySetSort> set2; //指定第二个参数为自定义排序规则的类名
	set2.insert(20);
	set2.insert(50);
	set2.insert(30);

	for (set<int, MySetSort>::iterator it = set2.begin(); it != set2.end(); it++)
	{
		cout << *it << " "; //50 30 20
	}
	cout << endl;
}

/* 对自定义数据类型排序 */
class Person16
{
public:
	Person16(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	string m_Name;
	int m_Age;
};

class MySetSort2
{
public:
	bool operator()(const Person16& p1, const Person16& p2) const
	{
		//按照年龄降序
		return p1.m_Age > p2.m_Age;
	}
};

void set_test07()
{
	cout << "自定义数据类型排序" << endl;

	//创建时就指定仿函数为排序规则
	set<Person16, MySetSort2> set1;
	Person16 p1("刘备", 23);
	Person16 p2("关羽", 27);
	Person16 p3("张飞", 25);
	Person16 p4("赵云", 21);
	Person16 p5("赵x", 21); //按照年龄排序，则如果年龄相同，即使名字不同，也算是重复数据，插入不进来

	set1.insert(p1);
	set1.insert(p2);
	set1.insert(p3);
	set1.insert(p4);
	set1.insert(p5);

	for (set<Person16, MySetSort2>::iterator it = set1.begin(); it != set1.end(); it++)
	{
		cout << "姓名：" << (*it).m_Name << " 年龄：" << (*it).m_Age << endl;
	}
}


/*****************************************************************************
 *  @brief	main

 *****************************************************************************/
int main24_1()
{
	//set容器构造和赋值
	set_test01();

	//set容器大小操作
	set_test02();

	//set容器插入和删除
	set_test03();

	//set容器查找和统计
	set_test04();

	//set和multiset的区别
	set_test05();

	//pair键值对创建
	pair_test();

	//set容器排序：内置数据类型
	set_test06();

	//set容器排序：自定义数据类型
	set_test07();

	return 0;
}

/*
 set 容器常用成员方法
	成员方法		功能
	begin()		返回指向容器中第一个（注意，是已排好序的第一个）元素的双向迭代器。如果 set 容器用 const 限定，则该方法返回的是 const 类型的双向迭代器。
	end()		返回指向容器最后一个元素（注意，是已排好序的最后一个）所在位置后一个位置的双向迭代器，通常和 begin() 结合使用。如果 set 容器用 const 限定，则该方法返回的是 const 类型的双向迭代器。
	rbegin()	返回指向最后一个（注意，是已排好序的最后一个）元素的反向双向迭代器。如果 set 容器用 const 限定，则该方法返回的是 const 类型的反向双向迭代器。
	rend()		返回指向第一个（注意，是已排好序的第一个）元素所在位置前一个位置的反向双向迭代器。如果 set 容器用 const 限定，则该方法返回的是 const 类型的反向双向迭代器。
	cbegin()	和 begin() 功能相同，只不过在其基础上，增加了 const 属性，不能用于修改容器内存储的元素值。
	cend()		和 end() 功能相同，只不过在其基础上，增加了 const 属性，不能用于修改容器内存储的元素值。
	crbegin()	和 rbegin() 功能相同，只不过在其基础上，增加了 const 属性，不能用于修改容器内存储的元素值。
	crend()		和 rend() 功能相同，只不过在其基础上，增加了 const 属性，不能用于修改容器内存储的元素值。
	find(val)	在 set 容器中查找值为 val 的元素，如果成功找到，则返回指向该元素的双向迭代器；反之，则返回和 end() 方法一样的迭代器。另外，如果 set 容器用 const 限定，则该方法返回的是 const 类型的双向迭代器。
	lower_bound(val)	返回一个指向当前 set 容器中第一个大于或等于 val 的元素的双向迭代器。如果 set 容器用 const 限定，则该方法返回的是 const 类型的双向迭代器。
	upper_bound(val)	返回一个指向当前 set 容器中第一个大于 val 的元素的迭代器。如果 set 容器用 const 限定，则该方法返回的是 const 类型的双向迭代器。
	equal_range(val)	该方法返回一个 pair 对象（包含 2 个双向迭代器），其中 pair.first 和 lower_bound() 方法的返回值等价，pair.second 和 upper_bound() 方法的返回值等价。也就是说，该方法将返回一个范围，该范围中包含的值为 val 的元素（set 容器中各个元素是唯一的，因此该范围最多包含一个元素）。
	empty()		若容器为空，则返回 true；否则 false。
	size()		返回当前 set 容器中存有元素的个数。
	max_size()	返回 set 容器所能容纳元素的最大个数，不同的操作系统，其返回值亦不相同。
	insert()	向 set 容器中插入元素。
	erase()		删除 set 容器中存储的元素。
	swap()		交换 2 个 set 容器中存储的所有元素。这意味着，操作的 2 个 set 容器的类型必须相同。
	clear()		清空 set 容器中所有的元素，即令 set 容器的 size() 为 0。
	emplace()	在当前 set 容器中的指定位置直接构造新元素。其效果和 insert() 一样，但效率更高。
	emplace_hint()	在本质上和 emplace() 在 set 容器中构造新元素的方式是一样的，不同之处在于，使用者必须为该方法提供一个指示新元素生成位置的迭代器，并作为该方法的第一个参数。
	count(val)	在当前 set 容器中，查找值为 val 的元素的个数，并返回。注意，由于 set 容器中各元素的值是唯一的，因此该函数的返回值最大为 1。

注意，虽然 multiset 容器和 set 容器拥有的成员方法完全相同，但由于 multiset 容器允许存储多个值相同的元素，
因此诸如 count()、find()、lower_bound()、upper_bound()、equal_range()等方法，更常用于 multiset 容器。
*/