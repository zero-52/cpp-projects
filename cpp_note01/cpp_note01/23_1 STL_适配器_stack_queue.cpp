/*****************************************************************************

STL 提供了3种容器适配器，分别为 stack 栈适配器、queue 队列适配器以及 priority_queue 优先权队列适配器

模板 B 将不适合直接拿来用的模板 A 变得适用了，因此我们可以将模板 B 称为 B 适配器。
容器适配器也是同样的道理，简单的理解容器适配器，其就是将不适用的序列式容器（包括 vector、deque 和 list）变得适用。
容器适配器的底层实现和模板 A、B 的关系是完全相同的，即通过封装某个序列式容器，并重新组合该容器中包含的成员函数，使其满足某些特定场景的需要。

//容器适配器本质上还是容器，被归类为序列式容器，只不过此容器模板类的实现，利用了大量其它基础容器模板类中已经写好的成员函数。
当然，如果必要的话，容器适配器中也可以自创新的成员函数。

需要注意的是，STL 中的容器适配器，其内部使用的基础容器并不是固定的，用户可以在满足特定条件的多个基础容器中自由选择。
 

* stack容器适配器
 	所采用基础容器需包含以下成员函数：
		empty()
		size()
		back()
		push_back()
		pop_back()
	满足条件的基础容器有 vector、deque、list。 默认使用的基础容器为 deque	

	概念：stack是一种先进后出(First In Last Out,FILO)的数据结构，它只有一个出口
		  只能在栈顶操作元素

	栈中只有顶端的元素才可以被外界访问使用，因此栈不允许有遍历行为，要想使用其它元素，需要先出栈
	
	栈中进入数据称为 --- 入栈 push
	栈中弹出数据称为 --- 出栈 pop

stack 常用接口
	功能描述：栈容器常用的对外接口

	构造函数：
		stack<T,Container=deque<T>> stk;//模板类提供了 2 个参数，第一个参数指定类型，通过指定第二个模板类型参数，来指定基础容器vector、deque、list
		//只要该基础容器支持 empty()、size()、back()、push_back()、pop_back() 这 5 个成员函数即可
		
		stack(const stack &stk); //拷贝构造函数
		
	赋值操作：
		stack& operator=(const stack &stk); //重载等号操作符
		
	数据存取：
		push(elem); //向栈顶添加元素
		pop(); //从栈顶移除第一个元素
		top(); //返回栈顶元素
		
	大小操作：
		empty(); //判断堆栈是否为空
*		size(); //返回栈的大小
*****************************************************************************/

/****************************************************************************
* queue 容器适配器
	所采用基础容器需包含以下成员函数：
		empty()
		size()
		front()
		back()
		push_back()
		pop_front()
	满足条件的基础容器有 deque、list。默认使用的基础容器为 deque

	Queue是一种先进先出(First In First Out,FIFO)的数据结构，它有两个出口
	队列容器只允许队尾一端新增元素，从队头一端移除元素

	队列中只有队头和队尾才可以被外界使用，因此队列不允许有遍历行为，要想访问中间元素，需要将前面的先出队

	队列中进数据称为 --- 入队 push
	队列中出数据称为 --- 出队 pop

queue 常用接口
	功能描述：栈容器常用的对外接口

	构造函数：
		stack<T,Container=deque<T>> que; //默认构造；第二个参数指定基础容器，deque、list
		queue(const queue &que); //拷贝构造函数

	赋值操作：
		queue& operator=(const queue &que); //重载等号操作符

	数据存取：
		push(elem); //往队尾添加元素
		pop(); //从队头移除第一个元素
		back(); //返回最后一个元素
		front(); //返回第一个元素

	大小操作：
		empty(); //判断堆栈是否为空
*		size(); //返回栈的大小
*****************************************************************************/

#include<iostream>
using namespace std;
#include <stack>
#include <queue>
#include <list>

/*****************************************************************************
 *  @brief	stack 栈容器 ：先进后出

 *****************************************************************************/
void stk_test01()
{
	//默认构造
	stack<int> stk; 


	//入栈
	stk.push(10);
	stk.push(20);
	stk.push(30);
	
	//拷贝构造
	stack<int> stk2(stk);
	
	cout << "栈的大小为：stk.size() = " << stk.size() << endl;//3
	cout << "栈的大小为：stk2.size() = " << stk2.size() << endl;//3

	//只要栈不为空，查看栈顶，并执行出栈操作
	while (!stk.empty())
	{
		cout << "查看栈顶元素：stk.top() = " << stk.top() << endl;
		//出栈
		stk.pop();
	}
	cout << "栈的大小为：stk.size() = " << stk.size() << endl;//0
	cout << "栈的大小为：stk2.size() = " << stk2.size() << endl;//3

	//stack 基础容器指定为list
	list<int> L1{ 1,2,3 };
	stack<int, list<int>> stk3(L1); //stk2的栈顶元素为3，不是1
	//stack 第 2 个模板参数必须显式指定为 list<int>，否则 stack 底层将默认使用 deque 容器

	stack<int, list<int>> stk4(stk3); //stack 基础容器为list的拷贝构造
	
}


/*****************************************************************************
 *  @brief	queue 队列容器 ：先进先出

 *****************************************************************************/

//这次用个自定义数据类型讲解
class Person15
{
public:
	Person15(string name, int age)
	{
		m_Name = name;
		m_Age = age;
	}
	string m_Name;
	int m_Age;
};

void que_test01()
{
	//默认构造
	queue<Person15> que;

	Person15 p1("孙悟空", 100);
	Person15 p2("沙和尚", 90);
	Person15 p3("八戒", 80);

	//入队
	que.push(p1);
	que.push(p2);
	que.push(p3);
	cout << "队列的大小为：que.size() = " << que.size() << endl;

	//判断队列是否为空，不空，查看队头队尾，出队
	while (!que.empty())
	{
		//查看队头
		cout << "查看队头元素-- 姓名： " << que.front().m_Name << "  年龄：" << que.front().m_Age << endl;
		//查看队尾
		cout << "查看队尾元素-- 姓名： " << que.back().m_Name << "  年龄：" << que.back().m_Age << endl;
		cout << endl;
		//出队（弹出队头元素）
		que.pop();
	}

	cout << "队列的大小为：que.size() = " << que.size() << endl;

}

/*****************************************************************************
 *  @brief	main

 *****************************************************************************/
int main23_1()
{
	//栈容器 stack
	cout << "** 栈容器 **" << endl << endl;
	stk_test01();

	//队列容器 queue
	cout <<endl << "** 队列容器 **" << endl << endl;
	que_test01();

	return 0;
}

/*
各适配器所使用的默认基础容器以及可供用户选择的基础容器，如下 所示。

	stack 容器适配器：	
 		所采用基础容器需包含以下成员函数：
			empty()
			size()
			back()
			push_back()
			pop_back()
		满足条件的基础容器有 vector、deque、list。	默认使用的基础容器为 deque	

	queue 容器适配器：
		所采用基础容器需包含以下成员函数：
			empty()
			size()
			front()
			back()
			push_back()
			pop_front()
		满足条件的基础容器有 deque、list。默认使用的基础容器为 deque	

	priority_queue 容器适配器：
		所采用基础容器需包含以下成员函数：
			empty()
			size()
			front()
			push_back()
			pop_back()
		满足条件的基础容器有vector、deque。	默认使用的基础容器为 vector

不同场景下，由于不同的序列式容器其底层采用的数据结构不同，因此容器适配器的执行效率也不尽相同。
但通常情况下，使用默认的基础容器即可。当然，我们也可以手动修改默认的基础容器
*/

/*
stack容器适配器支持的全部成员函数
	成员函数		功能
	empty()		当 stack 栈中没有元素时，该成员函数返回 true；反之，返回 false。
	size()		返回 stack 栈中存储元素的个数。
	top()		返回一个栈顶元素的引用，类型为 T&。如果栈为空，程序会报错。
	push(const T& val)	先复制 val，再将 val 副本压入栈顶。这是通过调用底层容器的 push_back() 函数完成的。
	push(T&& obj)	以移动元素的方式将其压入栈顶。这是通过调用底层容器的有右值引用参数的 push_back() 函数完成的。
	pop()		弹出栈顶元素。
	emplace(arg...)	arg... 可以是一个参数，也可以是多个参数，但它们都只用于构造一个对象，并在栈顶直接生成该对象，作为新的栈顶元素。
	swap(stack<T> & other_stack)	将两个 stack 适配器中的元素进行互换，需要注意的是，进行互换的 2 个 stack 适配器中存储的元素类型以及底层采用的基础容器类型，都必须相同。

	和其他序列容器相比，stack 是一类存储机制简单、提供成员函数较少的容器。


*queue容器适配器支持的全部成员函数
	成员函数		功能
	empty()		如果 queue 中没有元素的话，返回 true。
	size()		返回 queue 中元素的个数。
	front()		返回 queue 中第一个元素的引用。如果 queue 是常量，就返回一个常引用；如果 queue 为空，返回值是未定义的。
	back()		返回 queue 中最后一个元素的引用。如果 queue 是常量，就返回一个常引用；如果 queue 为空，返回值是未定义的。
	push(const T& obj)	在 queue 的尾部添加一个元素的副本。这是通过调用底层容器的成员函数 push_back() 来完成的。
	emplace()	在 queue 的尾部直接添加一个元素。
	push(T&& obj)	以移动的方式在 queue 的尾部添加元素。这是通过调用底层容器的具有右值引用参数的成员函数 push_back() 来完成的。
	pop()		删除 queue 中的第一个元素。
	swap(queue<T> &other_queue)	将两个 queue 容器适配器中的元素进行互换，需要注意的是，进行互换的 2 个 queue 容器适配器中存储的元素类型以及底层采用的基础容器类型，都必须相同。

和 stack 一样，queue 也没有迭代器，因此访问元素的唯一方式是遍历容器，通过不断移除访问过的元素，去访问下一个元素。
*/