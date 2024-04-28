#include<iostream>
using namespace std;

/*
	生活中你的家有客厅(Public)，有你的卧室(Private)
	客厅所有来的客人都可以进去，但是你的卧室是私有的，也就是说只有你能进去
	但是呢，你也可以允许你的好闺蜜好基友进去。

在程序里，有些私有属性 也想让类外特殊的一些函数或者类进行访问，就需要用到友元的技术

友元的目的就是让一个函数或者类 访问另一个类中私有成员
友元的关键字为： friend

友元的三种实现：
	1. 全局函数做友元 （全局函数可以在类外实现，也可以在类内实现）
		实现用 全局函数func() 访问 某类A 的私有成员 
		需要在 类A中 将 全局函数() 设为友元

	2. 类做友元
		实现一个 类A 可以访问另一个 类B 的私有成员 
		需要在 类B 中 将 类A 设为友元

	3. 成员函数做友元
		实现用一个类的成员函数 A::visit() 访问 另一个 类B 的私有成员 
		需要在 类B 中 将 A 的成员函数 设为 友元    
		
	注意：
		当用到 3.友元成员函数 时，需注意友元声明和友元定义之间的相互依赖，前后顺序不可错。

	例子：
		如果 需要在 类BBB 中 将 AAA 的成员函数visit() 设为 友元   
				
		在该例子中，类AAA必须先定义，否则类BBB就不能将类AAA的成员函数指定为友元。
		然而，只有在定义了类BBB之后，才能定义类AAA的该成员函数。
		更一般的讲，必须先定义包含 要作为友元的成员函数的类，才能将该成员函数设为友元。另一方面，不必预先声明类和非成员函数来将它们设为友元。
			
*/

/*** 1. 全局函数做友元 ： 
		实现用全局函数访问 某类对象 的私有成员 
		需要在 Building01 类中 将全局函数设为友元
		*/
class Building01
{
	//1、全局函数做友元： 指定下面全局函数为友元，则在该全局函数中可以访问 Building01 类的 private 成员
	friend void goodFriend(Building01 build01);  //友元全局函数可以类内声明，类外实现；也可以在类内实现

	//2、类做友元： 指定 LaoWang类 为友元，就可以通过 LaoWang类对象 访问 Building01 类对象的私有成员
	friend class LaoWang;

	//3、另一类的成员函数做友元： 指定 某类下的成员函数 为友元，可通过该成员函数访问 当前类Building01对象的私有成员
	//friend void 类名::成员函数();

public:
	string m_DrawingRoom;  //客厅
private:
	string m_BedRoom;  //卧室

public:
	Building01()  //构造函数
	{
		m_DrawingRoom = "客厅";
		m_BedRoom = "卧室";
	}
};

void goodFriend(Building01 build01)  //形参当然也可以用 指针传递 或 引用传递
{
	cout << "全局函数 做友元访问 类对象build01 的公有成员：" << build01.m_DrawingRoom << endl;

	//类外不能访问私有成员，除非在 Building01 类中指定该全局函数为 friend
	cout << "全局函数 做友元访问 类对象build01 的私有成员：" << build01.m_BedRoom << endl; 
}

void test12()
{
	Building01 build01;

	goodFriend(build01);
}


/*** 2. 类做友元：
		实现一个类LaoWang的对象可以访问另一个类Building01的对象的私有成员 
		需要在 Building01 类中 将 LaoWang类 设为友元
		*/
class LaoWang
{
public:
	LaoWang()
	{
		//创建 Building01 对象
		//如果不用new，单纯只用Building building ；则在  LaoWang() 执行结束之后building将被释放
		//之后再调用building里的属性就会访问到空指针然后出错，所以要用new开辟堆区数据
		build02 = new Building01;

	}
	//用于访问 building 对象的属性
	void visit()
	{
		cout << "LaoWang正在访问 另一个类对象 bulid02 的公有成员：" << build02->m_DrawingRoom << endl;

		//类外不可访问私有成员，除非在 Building01 类中指定当前类LaoWang 为 friend
		cout << "LaoWang正在访问 另一个类对象 bulid02 的私有成员：" << build02->m_BedRoom << endl;  

		cout << "LaoWang正在访问 另一个类对象 bulid03 的公有成员：" << build03.m_DrawingRoom << endl;
		cout << "LaoWang正在访问 另一个类对象 bulid03 的私有成员：" << build03.m_BedRoom << endl;
	}
public:
	Building01* build02; //C++中声明一个对象指针时没有分配内存，此时不会调用 Building01 的构造函数
	Building01 build03;
};

void test13()
{
	LaoWang laowang;
	laowang.visit();
}


/*** 3. 成员函数做友元 ：
		实现用一个类的成员函数 AAA::visit() 访问 另一个类对象 BBB:: 的私有成员 
		需要在 BBB 类中 将 AAA 的成员函数 设为 友元    
		
		注意：
			当用到友元成员函数时，需注意友元声明和友元定义之间的相互依赖，前后顺序不可错。
			在该例子中，类AAA必须先定义，否则类BBB就不能将类AAA的成员函数指定为友元。
			然而，只有在定义了类BBB之后，才能定义类AAA的该成员函数。
			更一般的讲，必须先定义包含 要作为友元的成员函数的类，才能将该成员函数设为友元。另一方面，不必预先声明类和非成员函数来将它们设为友元。
			*/
class BBB; //声明BBB类
class AAA
{
private:
	BBB *bbb;
public:

	AAA(); // 由于，该构造函数中 用到了BBB类，所以构造函数要在 BBB类 定义后面再定义

	void visit();  //该函数为类 BBB 的友元，必须类内声明，在 类BBB 后定义
	
};

class BBB
{
	//另一类AAA的成员函数做友元：    指定 某类下的成员函数 为友元，可通过该成员函数访问 当前类对象的私有成员
	friend void AAA::visit();

public:
	string m_DrawingRoom;  //客厅
private:
	string m_BedRoom;  //卧室

public:
	BBB()  //构造函数
	{
		m_DrawingRoom = "客厅";
		m_BedRoom = "卧室";
	}
};
AAA::AAA()
{
	bbb = new BBB;
}
void AAA::visit()
{
	cout << "XiaoWu正在访问 另一个类对象 bulid04 的公有成员：" << bbb->m_DrawingRoom << endl;

	cout << "XiaoWu正在访问 另一个类对象 bulid04 的私有成员：" << bbb->m_BedRoom << endl;
	//错误，类外不可访问私有成员，除非在 BBB 类中指定当前类成员函数 AAA::visit() 为 friend

}

void test14()
{
	AAA xw;
	xw.visit();
}



int main12()
{
	/* 1. 全局函数做友元*/
	cout << "全局函数做友元" << endl;
	test12();

	/* 2. 类做友元：一个类可以访问另一个类的私有成员 */
	cout << endl << "类做友元" << endl;
	test13();


	test14();
	return 0;
}