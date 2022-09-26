/*****************************************************************************
 *  @brief	list容器（又称双向循环链表容器）
	功能： 将数据进行链式存储。STL中的链表是一个双向循环链表

	链表（list）是一种物理存储单元上非连续的存储结构，数据元素的逻辑顺序是通过链表中的指针链接实现的
		链表的组成：链表由一系列结点组成，每个结点包含：数据域、指针域
		结点的组成：一个是存储数据元素的 数据域，另一个是存储下一个结点地址的 指针域

	由于链表的存储方式并不是连续的内存空间，因此链表list中的迭代器只支持前移和后移，属于双向迭代器

	list的优点：
		采用动态存储分配，不会造成内存浪费和溢出
		链表执行插入和删除操作十分方便，修改指针即可，不需要移动大量元素

	list的缺点：
		链表灵活，但是空间占用较大，除了 数据域 还要存储 指针域
		链式存储，容器遍历时间耗费较大，没有连续存储的数组遍历速度快
		不支持随机访问，不支持 L1[2], L1.at(2) = 40 ,L1.begin()+2 等直接访问操作
		
	注：list有一个重要的性质，插入操作和删除操作都不会造成原有list迭代器的失效，这在vector是不成立的。
		比如，vector插入后满了，继续插会新开辟空间，但原有迭代器还指向原来的空间，所以失效。
		而list插入删除只需要更改指针域，迭代器并不会失效，除非删除迭代器所指向的元素。

	总结：STL中 list 和 vector 是两个最常被使用的容器，各有优缺点。
		  要基于优缺点和使用场景灵活使用容器，以达最优效率


list容器构造函数
	功能描述：创建list容器
	
	函数原型：
		list<T> lst; //list采用采用模板类实现,对象的默认构造形式：
		list(beg,end); //构造函数将[beg, end)区间中的元素拷贝给本身。
		list(n,elem); //构造函数将n个elem拷贝给本身。
		list(const list &lst); //拷贝构造函数。


list容器 赋值和交换
	功能描述：
		给list容器进行赋值，以及交换list容器
	函数原型：
		list& operator=(const list &lst); //重载等号操作符
		assign(beg, end); //将[beg, end)区间中的数据拷贝赋值给本身。
		assign(n, elem); //将n个elem拷贝赋值给本身。
		swap(lst); //将lst与本身的元素互换。


list容器 大小操作
	功能描述：
		对list容器的大小进行操作
	函数原型：
		size(); //返回容器中元素的个数
		empty(); //判断容器是否为空
		resize(num); //重新指定容器的长度为num，若容器变长，则以默认值填充新位置。
		​			 //如果容器变短，则末尾超出容器长度的元素被删除。
		resize(num, elem); //重新指定容器的长度为num，若容器变长，则以elem值填充新位置。
						   //如果容器变短，则末尾超出容器长度的元素被删除。


list 插入和删除
	功能描述：
		对list容器进行数据的插入和删除
	函数原型：
		push_back(elem);//在容器尾部加入一个元素
		push_front(elem);//在容器开头插入一个元素
		pop_back();//删除容器中最后一个元素
		pop_front();//从容器开头移除第一个元素

		insert(pos,elem);//在pos位置插elem元素的拷贝，返回新数据的位置。
		insert(pos,n,elem);//在pos位置插入n个elem数据，无返回值。
		insert(pos,beg,end);//在pos位置插入[beg,end)区间的数据，无返回值。

		erase(pos);//删除pos位置的数据，返回下一个数据的位置。
		erase(beg,end);//删除[beg,end)区间的数据，返回下一个数据的位置。
		remove(elem);//删除容器中所有与elem值匹配的元素。
		clear();//移除容器的所有数据

	//注意：list容器链式存储，不支持随机访问，迭代器也不支持随机访问。
	//list容器只能对迭代器++，而vector可以++、+n


list 数据存取
	功能描述：
		对list容器中数据进行存取
	函数原型：
		front(); //返回第一个元素。
		back(); //返回最后一个元素。
	注意：list容器为链式存储，存储空间不连续，不能用 [下标] 或 at()的方式存取数据
		  迭代器也不支持随机访问


list 反转和排序
	功能描述：
		将容器中的元素反转，以及将容器中的数据进行排序
	函数原型：
		obj.reverse(); //反转链表，注意和 vector容器 的预留空间 reserve(int len) 很像
		obj.sort(); //链表排序。
	
	可以通过全局函数或仿函数指定排序规则，
		L1.sort(myCompare_func); //全局回调函数，指定排序规则
		L1.sort(MyListSort());  //仿函数类名()，指定排序规则

	注意，不支持随机访问迭代器的容器，不能用标准算法头文件的sort() 函数排序
	//sort(L1.begin(), L1.end());//错误

排序案例
	注意：对如自定义数据类型如Person类，不能直接使用sort进行排序，
		  因为函数并不知道按照哪个属性进行排序，需要利用回调函数或仿函数指定排序规则

	案例描述：
		将Person自定义数据类型进行排序，Person中属性有姓名、年龄、身高
		排序规则：按照年龄进行升序，如果年龄相同按照身高进行降序

	总结：
		对于自定义数据类型，必须要指定排序规则，否则编译器不知道如何进行排序
		高级排序只是在排序规则上再进行一次逻辑规则制定，并不复杂
 *****************************************************************************/

#include<iostream>
using namespace std;
#include <list>
#include <algorithm>
#include <vector>


/*****************************************************************************
 *  @brief	list容器构造
		功能描述：创建list容器
	
		函数原型：
			list<T> lst; //list采用采用模板类实现,对象的默认构造形式：
			list(beg,end); //构造函数将[beg, end)区间中的元素拷贝给本身。
			list(n,elem); //构造函数将n个elem拷贝给本身。
			list(const list &lst); //拷贝构造函数。

 *****************************************************************************/
void printList(const list<int>& L)
{
	//for (list<int>::const_iterator it = L.begin(); it < L.end(); it++) //注意：与前面不同，小于会报错
	for (list<int>::const_iterator it = L.begin(); it != L.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}
void l_test01()
{
	cout << "** list容器构造 **" << endl;
	//创建list容器
	list<int> L1;//默认构造

	list<int> L0{ 1,2,3 }; //构造并初始化
	printList(L0); //1 2 3

	//添加数据
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	

	//遍历容器
	printList(L1); //10 20 30

	//区间方式构造
	//list<int> L2(L1.begin()+1, L1.end()); //报错，注意：链式存储不支持随机访问，+1会报错
	list<int> L2(L1.begin(), L1.end());
	printList(L2); //10 20 30

	//拷贝构造
	list<int> L3(L1);
	printList(L3); //10 20 30

	//n个elem构造
	list<int> L4(5, 3);
	printList(L4);//3 3 3 3 3 

}

/*****************************************************************************
 *  @brief	list容器 赋值和交换
		功能描述：
			给list容器进行赋值，以及交换list容器
		函数原型：
			list& operator=(const list &lst); //重载等号操作符
			assign(beg, end); //将[beg, end)区间中的数据拷贝赋值给本身。
			assign(n, elem); //将n个elem拷贝赋值给本身。
			swap(lst); //将lst与本身的元素互换。

 *****************************************************************************/
void l_test02()
{
	cout << endl << "** list容器赋值与交换 **" << endl;

	list<int> L1;

	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);

	printList(L1);//10 20 30 40

	//赋值
	list<int> L2;
	L2 = L1;
	printList(L2);//10 20 30 40

	list<int> L3;
	L3.assign(L2.begin(), L2.end());
	printList(L3);//10 20 30 40

	list<int> L4;
	L4.assign(5, 3);
	printList(L4);//3 3 3 3 3

	//两个列表交换
	L4.swap(L3);
	printList(L4);//10 20 30 40
	printList(L3);//3 3 3 3 3

}
/*****************************************************************************
*  @brief	list容器 大小操作
	功能描述：
		对list容器的大小进行操作
	函数原型：
		size(); //返回容器中元素的个数
		empty(); //判断容器是否为空
		resize(num); //重新指定容器的长度为num，若容器变长，则以默认值填充新位置。
		​			 //如果容器变短，则末尾超出容器长度的元素被删除。
		resize(num, elem); //重新指定容器的长度为num，若容器变长，则以elem值填充新位置。
						   //如果容器变短，则末尾超出容器长度的元素被删除。
*****************************************************************************/
void l_test03()
{
	cout << endl << "** list容器大小操作 **" << endl;

	list<int> L1;

	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);

	//判断容器是否为空
	if (L1.empty())
	{
		cout << "L1为空" << endl;
	}
	else
	{
		cout << "L1不为空" << endl;
		cout << "L1容器 的大小为 L1.size() = " << L1.size() << endl; //3

	}

	//重新指定大小
	L1.resize(5);
	printList(L1); //10 20 30 0 0 

	L1.resize(7, 'a');
	printList(L1); //10 20 30 0 0 97 97

}

/*****************************************************************************
*  @brief	list 插入和删除
	功能描述：
		对list容器进行数据的插入和删除
	函数原型：
		push_back(elem);//在容器尾部加入一个元素
		push_front(elem);//在容器开头插入一个元素
		pop_back();//删除容器中最后一个元素
		pop_front();//从容器开头移除第一个元素
		
		insert(pos,elem);//在pos位置插elem元素的拷贝，返回新数据的位置。
		insert(pos,n,elem);//在pos位置插入n个elem数据，无返回值。
		insert(pos,beg,end);//在pos位置插入[beg,end)区间的数据，无返回值。

		erase(beg,end);//删除[beg,end)区间的数据，返回下一个数据的位置。
		erase(pos);//删除pos位置的数据，返回下一个数据的位置。
		remove(elem);//删除容器中所有与elem值匹配的元素。
		clear();//移除容器的所有数据

	//注意：list容器链式存储，不支持随机访问，迭代器也不支持随机访问。
	//list容器只能对迭代器++，而vector可以++、+n
*****************************************************************************/
void l_test04()
{
	cout << endl << "** list容器插入删除操作 **" << endl;

	list<int> L1;
	//尾插
	L1.push_back(10);
	//头插
	L1.push_front(20);
	L1.push_front(30);

	printList(L1); //30 20 10

	//头删
	L1.pop_front();
	printList(L1); //20 10

	//insert 插入
	L1.insert(++++L1.begin(), 30); //注意：插到别的位置，list只能对迭代器++，而vector可以++、+n
	printList(L1); //20 10 30
	//插入n个elem
	L1.insert(L1.begin(), 2, 3); 
	printList(L1); //3 3 20 10 30
	//插入区间
	L1.insert(--L1.end(), L1.begin(), L1.end()); 
	printList(L1); //3 3 20 10 3 3 20 10 30 30


	//删除迭代器指定元素
	L1.erase(L1.begin());
	printList(L1); //3 20 10 3 3 20 10 30 30
	//删除迭代器区间
	L1.erase(++L1.begin(), ----L1.end());
	printList(L1); //3 30 30

	//移除指定元素
	L1.remove(30); //移除等于30的所有元素
	printList(L1); //3

	//清空
	L1.clear();//

}


/*****************************************************************************
*  @brief	 list 数据存取
	功能描述：
		对list容器中数据进行存取
	函数原型：
		front(); //返回第一个元素。
		back(); //返回最后一个元素。
	注意：list容器为链式存储，存储空间不连续，不能用 [下标] 或 at()的方式存取数据，迭代器也不支持随机访问
*****************************************************************************/
void l_test05()
{
	cout << endl << "** list容器数据存取 **" << endl;

	list<int> L1;
	L1.push_back(10);
	L1.push_back(20);

	//L1[0] = 30; //错误，
	//L1.at(0) = 30; //错误，链式存储不支持随机访问

	//验证迭代器是不支持随机访问的
	list<int>::iterator it = L1.begin();
	//it = it + 3;//错误，不支持跳跃访问
	//it += 1;//错误
	it++; //支持递增
	it--; //支持递减，支持递增和递减也说明了是双向迭代器
	++it;
	--it;

	cout << "第一个元素为：L1.front() = " << L1.front() << endl;
	cout << "最后一个元素为：L1.back() = " << L1.back() << endl;
}


/*****************************************************************************
*  @brief	list 反转和排序
	功能描述：
		将容器中的元素反转，以及将容器中的数据进行排序
	函数原型：
		obj.reverse(); //反转链表，注意和 vector容器 的预留空间 reserve(int len) 很像
		obj.sort(); //链表排序。
	
	可以通过全局函数或仿函数指定排序规则，
		L1.sort(myCompare_func); //全局回调函数，指定排序规则
		L1.sort(MyListSort());  //仿函数类名()，指定排序规则
	
	注意，不支持随机访问迭代器的容器，不能用标准算法头文件的sort() 函数排序
	//sort(L1.begin(), L1.end());//错误

*****************************************************************************/
//全局函数实现降序
bool myCompare_func(int a, int b)
{	//回调函数，实现降序
	return a > b;
}
//仿函数实现降序
class MyListSort
{
public:
	bool operator()(int a, int b)
	{	//回调函数，实现降序
		return a > b;
	}
};
void l_test06()
{
	cout << endl << "** list容器反转和排序 **" << endl;

	list<int> L1;
	L1.push_back(10);
	L1.push_back(30);
	L1.push_back(20);

	printList(L1);//10 30 20

	L1.reverse();
	cout << "反转后：" << endl;
	printList(L1);//20 30 10

	//用容器的成员函数进行排序，默认升序
	L1.sort();
	cout << "升序后：" << endl;
	printList(L1); //10 20 30

	//注意，不支持随机访问迭代器的容器，不能用标准算法头文件的sort() 函数排序
	//sort(L1.begin(), L1.end());//错误

	//要想实现降序，可以sort升序后，再reverse反转；或者指定回调函数或仿函数
	cout << "降序后：" << endl;
	//L1.sort(myCompare_func); //通过回调函数指定排序规则，实现降序
	L1.sort(MyListSort()); //通过仿函数 类名() 指定排序规则，实现降序
	printList(L1);
}


/*****************************************************************************
*  @brief	排序案例
 	注意：对如自定义数据类型如Person类，不能直接使用sort进行排序，
	      因为函数并不知道按照哪个属性进行排序，需要利用回调函数或仿函数指定排序规则

	案例描述：
		将Person自定义数据类型进行排序，Person中属性有姓名、年龄、身高
		排序规则：按照年龄进行升序，如果年龄相同按照身高进行降序
	
	总结：
		对于自定义数据类型，必须要指定排序规则，否则编译器不知道如何进行排序
		高级排序只是在排序规则上再进行一次逻辑规则制定，并不复杂

*****************************************************************************/
class Person14
{
public:
	Person14(string name, int age, int height) 
	{
		m_Name = name;
		m_Age = age;
		m_Height = height;
	}
	string m_Name;
	int m_Age;
	int m_Height;
};

//回调函数指定排序规则
bool comparePerson14(Person14& p1, Person14& p2)
{
	/*只按照年龄做升序，一行代码即可
	return p1.m_Age < p2.m_Age;
	*/

	//高级排序，按照年龄做升序，年龄相同按照身高进行降序
	if (p1.m_Age == p2.m_Age)
	{
		return p1.m_Height > p2.m_Height; //年龄相同按照身高进行降序
	}
	return p1.m_Age < p2.m_Age; //年龄做升序
}

void mySort()
{
	cout << endl << "** 实现对自定义数据类型的排序 **" << endl;

	list<Person14> L1;

	//准备数据
	Person14 p1("刘备", 35, 175);
	Person14 p2("曹操", 45, 180);
	Person14 p3("孙权", 40, 170);
	Person14 p4("赵云", 25, 190);
	Person14 p5("张飞", 35, 160);
	Person14 p6("关羽", 35, 200);

	//放入容器
	L1.push_back(p1);
	L1.push_back(p2);
	L1.push_back(p3);
	L1.push_back(p4);
	L1.push_back(p5);
	L1.push_back(p6);

	for (list<Person14>::iterator it = L1.begin(); it != L1.end(); it++)
	{
		cout << "姓名：" << (*it).m_Name << " 年龄：" << (*it).m_Age << " 身高：" << (*it).m_Height << endl;
	}

	cout << endl << "---排序后：---" << endl;

	//L1.sort(); //错误，对于自定义数据类型，不能直接使用sort()，要指定排序规则
	L1.sort(comparePerson14); //指定排序规则

	for (list<Person14>::iterator it = L1.begin(); it != L1.end(); it++)
	{
		cout << "姓名：" << (*it).m_Name << " 年龄：" << (*it).m_Age << " 身高：" << (*it).m_Height << endl;
	}



}

/*****************************************************************************
*  @brief	main

*****************************************************************************/
int main22_4()
{
	//list容器构造
	l_test01();

	//list容器赋值和交换
	l_test02();

	//list容器大小操作
	l_test03();
	
	//list容器插入删除操作
	l_test04();

	//list容器数据存取
	l_test05();

	//list容器反转和排序
	l_test06();

	//对自定义数据类型进行排序
	mySort();

	return 0;
}

/****** 《list 容器所有的成员函数》 **************
	成员函数	功能
	begin()		返回指向容器中第一个元素的双向迭代器。
	end()		返回指向容器中最后一个元素所在位置的下一个位置的双向迭代器。
	rbegin()	返回指向最后一个元素的反向双向迭代器。
	rend()		返回指向第一个元素所在位置前一个位置的反向双向迭代器。
	cbegin()	和 begin() 功能相同，只不过在其基础上，增加了 const 属性，不能用于修改元素。
	cend()		和 end() 功能相同，只不过在其基础上，增加了 const 属性，不能用于修改元素。
	crbegin() 	和 rbegin() 功能相同，只不过在其基础上，增加了 const 属性，不能用于修改元素。
	crend()		和 rend() 功能相同，只不过在其基础上，增加了 const 属性，不能用于修改元素。
	empty()		判断容器中是否有元素，若无元素，则返回 true；反之，返回 false。
	size()		返回当前容器实际包含的元素个数。
	max_size()	返回容器所能包含元素个数的最大值。这通常是一个很大的值，一般是 232-1，所以我们很少会用到这个函数。
	front()		返回第一个元素的引用。
	back()		返回最后一个元素的引用。
	assign()	用新元素替换容器中原有内容。
	emplace_front()	在容器头部生成一个元素。该函数和 push_front() 的功能相同，但效率更高。
	push_front()	在容器头部插入一个元素。
	pop_front()		删除容器头部的一个元素。
	emplace_back()	在容器尾部直接生成一个元素。该函数和 push_back() 的功能相同，但效率更高。
	push_back()		在容器尾部插入一个元素。
	pop_back()		删除容器尾部的一个元素。
	emplace()		在容器中的指定位置插入元素。该函数和 insert() 功能相同，但效率更高。
	insert() 	在容器中的指定位置插入元素。
	erase()		删除容器中一个或某区域内的元素。
	swap()		交换两个容器中的元素，必须保证这两个容器中存储的元素类型是相同的。
	resize()	调整容器的大小。
	clear()		删除容器存储的所有元素。
	splice()	将一个 list 容器中的元素插入到另一个容器的指定位置。
	remove(val)		删除容器中所有等于 val 的元素。
	remove_if()		删除容器中满足条件的元素。
	unique()	删除容器中相邻的重复元素，只保留一个。
	merge()		合并两个事先已排好序的 list 容器，并且合并之后的 list 容器依然是有序的。
	sort()		通过更改容器中元素的位置，将它们进行排序。
	reverse()	反转容器中元素的顺序。

除此之外，C++ 11 标准库还新增加了 begin() 和 end() 这 2 个函数，和 list 容器包含的 begin() 
和 end() 成员函数不同，标准库提供的这2 个函数的操作对象，既可以是容器，还可以是普通数组。
当操作对象是容器时，它和容器包含的 begin() 和 end() 成员函数的功能完全相同；如果操作对象是
普通数组，则 begin() 函数返回的是指向数组第一个元素的指针，同样 end() 返回指向数组中最后一
个元素之后一个位置的指针（注意不是最后一个元素）。
*/