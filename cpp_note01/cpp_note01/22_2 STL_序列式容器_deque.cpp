/*
deque容器
	功能：
		双端数组，可以方便地对头端尾端进行插入删除操作，也是动态扩展容量和大小
	
	deque与vector区别：
		vector对于头部的插入删除效率低，数据量越大，效率越低
		vector访问元素时的速度会比deque快,这和两者内部实现有关
		（vector中的元素存在连续的线性空间，deque 容器中存储元素并不能保证所有元素都存储到连续的内存空间中。）
		deque相对而言，对头部的插入删除无需移动元素，故头插头删速度回比vector快

	deque内部工作原理:

		deque内部有个中控器，维护每段缓冲区中的内容，缓冲区中存放真实数据

		中控器维护的是每个缓冲区的地址，使得使用deque时像一片连续的内存空间

	deque容器的迭代器也是支持随机访问的

deque容器构造：（对比vector，容器的很多操作都是相似的）
	函数原型：
		deque<T> deqT; //默认构造函数
		deque(beg, end); //构造函数将[beg, end)区间中的元素拷贝给本身。begin和end为迭代器
		deque(n, elem); //构造函数将n个elem拷贝给本身。
		deque(const deque &deq); //拷贝构造函数

deque容器赋值操作：
	函数原型：
		deque& operator=(const deque &deq); //重载等号操作符
		assign(begin, end); //将[begin, end)区间中的数据拷贝赋值给本身。
		assign(n, elem); //将n个elem拷贝赋值给本身。


deque大小操作
	功能描述：
		对deque容器的大小进行操作
	函数原型：
		deque.empty(); //判断容器是否为空，为空返回true
		deque.size(); //返回容器中元素的个数
		deque.resize(num); //重新指定容器的长度为num,若容器变长，则以默认值填充新位置。
		​				   //如果容器变短，则末尾超出容器长度的元素被删除。
		deque.resize(num, elem); //重新指定容器的长度为num,若容器变长，则以elem值填充新位置。
		​					     //如果容器变短，则末尾超出容器长度的元素被删除。
		
	注意：deque没有容量capacity的概念，因为可以无限的放入数据

deque 插入和删除
	功能描述：
		向deque容器中插入和删除数据
	函数原型：
		两端插入操作：
			push_back(elem); //尾插，在容器尾部添加一个数据
			push_front(elem); //头插，在容器头部插入一个数据
			pop_back();		//尾删，删除容器最后一个数据
			pop_front();	//头删，删除容器第一个数据
		指定位置操作：
			insert(iterator_pos, elem); //在pos位置插入一个elem元素的拷贝，返回新数据的位置。
			insert(iterator_pos, n, elem); //在pos位置插入n个elem数据，无返回值。
			insert(iterator_pos, iterator_beg, iterator_end); //在pos位置插入[beg,end)区间的数据，无返回值。

		erase(iterator_beg, iterator_end); //删除[beg,end)区间的数据，返回下一个数据的位置。
		erase(iterator_pos); //删除pos位置的数据，返回下一个数据的位置。
		clear();	//清空容器的所有数据

	*注意：insert 和 erase 的参数是迭代器，指定位置插入和删除可以在迭代器上加减索引数字

deque 数据读写/存取
	功能描述：
		对deque 中的数据的存取操作
		除了用迭代器获取deque容器中元素，[ ]和at也可以
	函数原型：
		operator[]; //读取或写入索引下标所指的数据
		at(int idx); //读取或写入索引idx所指的数据
		front(); //返回容器中第一个数据元素
		back(); //返回容器中最后一个数据元素

deque 排序
	功能描述：
		利用算法实现对deque容器进行排序
	算法：
		#include<algorithm>  //需要包含标准算法头文件
		sort(iterator_beg, iterator_end) //对beg和end区间内元素进行排序，默认升序
		reverse(iterator_beg, iterator_end) //对beg和end区间内元素进行反转

	注意：对于支持随机访问的迭代器的容器，都可以利用sort、reverse算法进行排序
*/

#include<iostream>
using namespace std;
#include<deque>
#include <algorithm>

/*****************************************************************************
 *  @brief	deque容器构造：与vector同
	函数原型：
		deque<T> deq; //默认构造函数
		deque(iterator_begin, iterator_end); //构造函数将[begin, end)区间中的元素拷贝给本身。
		deque(n, elem); //构造函数将n个elem拷贝给本身。
		deque(const deque &deq); //拷贝构造函数

 *****************************************************************************/
void printDeque(const deque<int>& deq)  //只读
{
	//注意常量容器的迭代器必须为const_iterator
	for (deque<int>::const_iterator it = deq.begin(); it < deq.end(); it++)
	{
		//*it = 0; //常量容器不可修改
		cout << *it << " ";
	}
	cout << endl;
}

void d_test01()
{
	cout << "** deque容器构造 **" << endl;

	//默认构造函数
	deque<int> deq1;
	for (int i = 0; i < 5; i++)
	{
		deq1.push_back(i);
	}
	printDeque(deq1); //0 1 2 3 4 

	//区间构造
	deque<int> deq2(deq1.begin(), deq1.end());
	printDeque(deq2); //0 1 2 3 4

	//n个elem方式构造
	deque<int> deq3(5, 3);
	printDeque(deq3); //3 3 3 3 3

	//拷贝构造函数构造
	deque<int> deq4(deq3);
	printDeque(deq4); //3 3 3 3 3

}


/*****************************************************************************
 *  @brief	deque容器赋值操作：与vector同
		函数原型：
			deque& operator=(const deque &deq); //重载等号操作符
			assign(iterator_begin, iterator_end); //将[begin, end)区间中的数据拷贝赋值给本身。
			assign(n, elem); //将n个elem拷贝赋值给本身。

 *****************************************************************************/
void d_test02()
{
	deque<int> deq1;
	for (int i = 0; i < 5; i++)
	{
		deq1.push_back(i);
	}

	cout << endl << "** deque容器赋值操作 **" << endl;

	printDeque(deq1); //0 1 2 3 4

	//重载等号运算符赋值
	deque<int> deq2;
	deq2 = deq1;
	printDeque(deq2); //0 1 2 3 4

	//assign方法赋值
	deque<int> deq3;
	deq3.assign(deq2.begin() + 2, deq2.end());
	printDeque(deq3); //2 3 4

	//assign 的 n个elem赋值
	deque<int> deq4;
	deq4.assign(5, 3);
	printDeque(deq4);//3 3 3 3 3

}

/*****************************************************************************
 *  @brief	deque大小操作
	功能描述：
		对deque容器的大小进行操作
	函数原型：
		deque.empty(); //判断容器是否为空，为空返回true
		deque.size(); //返回容器中元素的个数
		deque.resize(num); //重新指定容器的长度为num,若容器变长，则以默认值填充新位置。
		​				   //如果容器变短，则末尾超出容器长度的元素被删除。
		deque.resize(num, elem); //重新指定容器的长度为num,若容器变长，则以elem值填充新位置。
		​					     //如果容器变短，则末尾超出容器长度的元素被删除。
		
	注意：deque没有容量capacity的概念，因为可以无限的放入数据

 *****************************************************************************/
void d_test03()
{
	deque<int> deq1;
	for (int i = 0; i < 5; i++)
	{
		deq1.push_back(i);
	}

	cout << endl << "** 对deque容器的大小进行操作 **" << endl;

	printDeque(deq1); //0 1 2 3 4

	if (deq1.empty())
	{
		cout << "deq1容器为空！" << endl;
	}
	else
	{
		cout << "deq1容器不为空！" << endl;
		cout << "deq1的大小为：" << deq1.size() << endl; //5
		//注意：deque没有容量capacity的概念，因为可以无限的放入数据
	}

	//重新指定大小
	deq1.resize(10); 
	printDeque(deq1); //0 1 2 3 4 0 0 0 0 0

	deq1.resize(15, -1);
	printDeque(deq1); //0 1 2 3 4 0 0 0 0 0 -1 -1 -1 -1 -1
}


/*****************************************************************************
 *  @brief	deque 插入和删除
	功能描述：
		向deque容器中插入和删除数据
	函数原型：
		两端插入操作：
			push_back(elem); //尾插，在容器尾部添加一个数据
			push_front(elem); //头插，在容器头部插入一个数据
			pop_back();		//尾删，删除容器最后一个数据
			pop_front();	//头删，删除容器第一个数据
		指定位置操作：
			insert(iterator_pos, elem); //在pos位置插入一个elem元素的拷贝，返回新数据的位置。
			insert(iterator_pos, n, elem); //在pos位置插入n个elem数据，无返回值。
			insert(iterator_pos, iterator_beg, iterator_end); //在pos位置插入[beg,end)区间的数据，无返回值。
		
		erase(iterator_beg, iterator_end); //删除[beg,end)区间的数据，返回下一个数据的位置。
		erase(iterator_pos); //删除pos位置的数据，返回下一个数据的位置。
		clear();	//清空容器的所有数据

	注意：insert 和 erase 的参数是迭代器，指定位置插入和删除可以在迭代器上加减索引数字
 *****************************************************************************/
void d_test04()
{
	cout << endl << "** deque 插入和删除操作 **" << endl;

	deque<int> deq1;
	//尾插
	deq1.push_back(10);
	deq1.push_back(20);
	//头插
	deq1.push_front(30);
	deq1.push_front(40);

	printDeque(deq1); //40 30 10 20

	//尾删
	deq1.pop_back();
	//头删
	deq1.pop_front();

	printDeque(deq1); //30 10

	//insert插入
	deq1.insert(deq1.begin(), 100);
	printDeque(deq1); //100 30 10

	//insert插入n个elem
	deq1.insert(deq1.begin(), 2, 3);
	printDeque(deq1); //3 3 100 30 10

	//insert以区间插入到第一个参数的位置
	deq1.insert(deq1.begin() + 3, deq1.begin(), deq1.begin() + 2);
	printDeque(deq1);//3 3 100 3 3 30 10

	deque<int> deq2;
	deq2.push_back(11);
	deq2.push_back(11);
	deq2.insert(deq2.begin() + 1, deq1.end() - 2, deq1.end()); //在deq2的1位置插入deq1的区间数据
	printDeque(deq2); //11 30 10 11

	//删除
	deq2.erase(deq2.begin() + 1);
	printDeque(deq2); //11 10 11

	//删除某区间
	deq2.erase(deq2.begin(), deq2.end() - 1);
	printDeque(deq2); //11

	//清空
	deq2.clear();
	printDeque(deq2);// 

}	

/*****************************************************************************
 *  @brief	deque 数据读写/存取
	功能描述：
		对deque 中的数据的存取操作
		除了用迭代器获取deque容器中元素，[ ]和at也可以
	函数原型：
		operator[]; //读取或写入索引下标所指的数据
		at(int idx); //读取或写入索引idx所指的数据
		front(); //返回容器中第一个数据元素
		back(); //返回容器中最后一个数据元素
 *****************************************************************************/
void d_test05()
{
	cout << endl << "** deque 数据读写/存取操作 **" << endl;

	deque<int> deq1;
	deq1.push_back(10);
	deq1.push_back(20);
	deq1.push_back(30);
	deq1.push_back(40);

	cout << "第一个deque的元素为 deq1[0] = " << deq1[0] << endl; //10
	cout << "第二个deque的元素为 deq1.at(1) = " << deq1.at(1) << endl; //20

	cout << "第一个deque的元素为 deq1.front() = " << deq1.front() << endl; //10
	cout << "最后一个deque的元素为 deq1.back() = " << deq1.back() << endl; //40

	deq1.front() = 100;
	deq1.at(1) = 200;
	printDeque(deq1); //100 200 30 40

	
}

/*****************************************************************************
 *  @brief	deque 排序
		功能描述：
			利用算法实现对deque容器进行排序
		算法：
			#include<algorithm>  //需要包含标准算法头文件
			sort(iterator_beg, iterator_end) //对beg和end区间内元素进行排序，默认升序
			reverse(iterator_beg, iterator_end) //对beg和end区间内元素进行反转
		
		注意：对于支持随机访问的迭代器的容器，都可以利用sort、reverse算法进行排序
 *****************************************************************************/
void d_test06()
{
	cout << endl << "** deque 排序操作 **" << endl;

	deque<int> deq1;
	deq1.push_back(10);
	deq1.push_back(30);
	deq1.push_back(20);
	deq1.push_front(100);
	deq1.push_front(200);
	
	printDeque(deq1); //200 100 10 30 20 

	sort(deq1.begin()+1, deq1.end());  //默认升序，需要包含标准算法头文件
	printDeque(deq1); //200 10 20 30 100

	cout << "升序：" << endl;
	sort(deq1.begin(), deq1.end());  
	printDeque(deq1); //10 20 30 100 200 

	cout << "降序：" << endl;
	reverse(deq1.begin(), deq1.end()); //升序后反转即降序
	printDeque(deq1); //200 100 30 20 10

	//更多排序算法后续会讲

}

/*****************************************************************************
 *  @brief	main

 *****************************************************************************/
int main22_2()
{
	//deque容器构造
	d_test01();

	//deque容器赋值
	d_test02();

	//deque容器大小
	d_test03();

	//deque容器插入删除
	d_test04();

	//deque读写操作
	d_test05();

	//deque排序
	d_test06();
	return 0;
}

/*************** 《deque 容器的成员函数》 ****************

	函数成员	函数功能
	begin()		返回指向容器中第一个元素的迭代器。
	end()		返回指向容器最后一个元素所在位置后一个位置的迭代器，通常和 begin() 结合使用。
	rbegin()	返回指向最后一个元素的迭代器。
	rend()		返回指向第一个元素所在位置前一个位置的迭代器。
	cbegin()	和 begin() 功能相同，只不过在其基础上，增加了 const 属性，不能用于修改元素。
	cend()		和 end() 功能相同，只不过在其基础上，增加了 const 属性，不能用于修改元素。
	crbegin()	和 rbegin() 功能相同，只不过在其基础上，增加了 const 属性，不能用于修改元素。
	crend()		和 rend() 功能相同，只不过在其基础上，增加了 const 属性，不能用于修改元素。
	size()		返回实际元素个数。
	max_size()	返回容器所能容纳元素个数的最大值。这通常是一个很大的值，一般是 232-1，我们很少会用到这个函数。
	resize()	改变实际元素的个数。
	empty()		判断容器中是否有元素，若无元素，则返回 true；反之，返回 false。
	shrink _to_fit()	将内存减少到等于当前元素实际所使用的大小。
	at()		使用经过边界检查的索引访问元素。
	front()		返回第一个元素的引用。
	back()		返回最后一个元素的引用。
	assign()	用新元素替换原有内容。
	push_back()	在序列的尾部添加一个元素。
	push_front()	在序列的头部添加一个元素。
	pop_back()	移除容器尾部的元素。
	pop_front()	移除容器头部的元素。
	insert()	在指定的位置插入一个或多个元素。
	erase()	移除一个元素或一段元素。
	clear()	移出所有的元素，容器大小变为 0。
	swap()	交换两个容器的所有元素。
	emplace()	在指定的位置直接生成一个元素。
	emplace_front()	在容器头部生成一个元素。和 push_front() 的区别是，该函数直接在容器头部构造元素，省去了复制移动元素的过程。
	emplace_back()	在容器尾部生成一个元素。和 push_back() 的区别是，该函数直接在容器尾部构造元素，省去了复制移动元素的过程。

和 vector 相比，额外增加了实现在容器头部添加和删除元素的成员函数，同时删除了 capacity()、reserve() 和 data() 成员函数。

和 array、vector 相同，C++ 11 标准库新增的 begin() 和 end() 这 2 个全局函数也适用于 deque 容器。
这 2 个函数的操作对象既可以是容器，也可以是普通数组。当操作对象是容器时，它和容器包含的 begin() 和
end() 成员函数的功能完全相同；如果操作对象是普通数组，则 begin() 函数返回的是指向数组第一个元素的
指针，同样 end() 返回指向数组中最后一个元素之后一个位置的指针（注意不是最后一个元素）。

deque 容器还有一个std::swap(x , y) 非成员函数（其中 x 和 y 是存储相同类型元素的 deque 容器），它和 swap() 成员函数的功能完全相同，仅使用语法上有差异。
*/