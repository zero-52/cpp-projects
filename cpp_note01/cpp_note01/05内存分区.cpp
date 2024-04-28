/*
C++程序在执行时，将内存大致划分为4个区域

	代码区：存放函数体的二进制代码，由操作系统进行管理的

	全局区：存放 全局变量 和 全局或局部静态变量 以及 常量（字符串常量、const修饰的全局常量）

	栈区：由编译器自动分配释放, 存放函数的参数值, 局部变量等

	堆区：由程序员分配和释放, 若程序员不释放, 程序结束时由操作系统回收
*/

/*
程序运行前：
	​ 在程序编译后，生成了exe可执行程序，未执行该程序前分为两个区域

	​ 代码区：

		​ 存放 CPU 执行的机器指令

		​ 代码区是共享的，共享的目的是对于频繁被执行的程序，只需要在内存中有一份代码即可

		​ 代码区是只读的，使其只读的原因是防止程序意外地修改了它的指令

	​ 全局区：

		​ 全局变量和静态变量存放在此.

		​ 全局区还包含了常量区, 字符串常量和其他常量也存放在此.

		​ 该区域的数据在程序结束后由操作系统释放.
*/

/*
程序运行后
	栈区：

		​由编译器自动分配释放, 存放函数的参数值,局部变量等

		​注意事项：不要返回局部变量的地址，栈区开辟的数据由编译器自动开辟和释放

	堆区：

		​由程序员开辟与释放,若程序员不释放,程序结束时由操作系统回收

		在C++中主要利用new在堆区开辟内存，并返回该数据对应类型的指针；用delete释放。new 数据类型()，如int * p = new int(10); delete p;


	注：
		全局数据区的变量都有默认的初始值 0，而动态数据区（堆区、栈区）变量的默认值是不确定的，一般认为是垃圾值。
		
		delete 释放堆区内存后，只是释放了堆区内存，指针变量仍然存在

	
*/

#include<iostream>
using namespace std;

//全局变量
int g_a = 0;
int g_b = 0;

//const修饰的全局变量
const int const_g_e = 0;
const int const_g_f = 0;


/*注意：不要返回局部变量的地址，函数被释放后，变量中的数据为脏数 */
int* func()  //如果有形参，也被放在栈区
{
	int a = 10;  //局部变量放在栈区
	return &a;
}

// 堆区，new的基本用法
int* func2()
{
	//用new在堆区开辟内存，返回的是该内存数据的地址，可用指针接收
	int* pp = new int(10); //指针 本质也是局部变量，放在栈区，但指针所指向地址中的数据放在堆区
	//delete pp; //手动释放堆区
	return pp;
}

//在堆区用new开辟数组
void newArr()
{
	int* pArr = new int[10]; //注意在堆区用new开辟数组，与开辟单个内存的区别
	cout << "在堆区用new开辟数组：" << endl;
	for (int i = 0; i < 10; i++)
	{
		pArr[i] = i * 2;
		cout << "\t" << pArr[i] << endl;
	}

	delete[] pArr;  // 释放数组，注意：要加中括号表示释放的是数组
}


int main5()
{
	/**** 全局区 ****/
	cout << "** 全局区：**" << endl;

	//全局变量
	cout << "全局变量 g_a 的地址：" << (int)&g_a << endl;
	cout << "全局变量 g_b 的地址：" << (int)&g_b << endl;

	//静态变量
	static int static_c = 0;
	static int static_d = 0;
	cout << "静态变量 static_c 的地址：" << (int)&static_c << endl;
	cout << "静态变量 static_d 的地址：" << (int)&static_d << endl;

	// 字符串常量
	cout << "字符串常量的地址：" << (int)&"hello" << endl;
	cout << "字符串常量的地址：" << (int)&"world" << endl;

	//const修饰的全局常量
	cout << "const修饰的全局变量 const_g_e 的地址：" << (int)&const_g_e << endl;
	cout << "const修饰的全局变量 const_g_f 的地址：" << (int)&const_g_f << endl;

	/******************************************************************/
	cout << endl;

	/**** 栈区 ****/
	cout << "** 栈区：**" << endl;

	//局部变量
	int l_a = 0;
	int l_b = 0;
	cout << "局部变量 l_a 的地址：" << (int)&l_a << endl;
	cout << "局部变量 l_b 的地址：" << (int)&l_b << endl;

	//const 修饰的局部常量
	const int const_l_a = 0;
	const int const_l_b = 0;
	cout << "const修饰的局部常量 const_l_a 的地址：" << (int)&const_l_a << endl;
	cout << "const修饰的局部常量 const_l_b 的地址：" << (int)&const_l_b << endl;

	//返回局部变量的地址后果
	int* p = func();
	cout << *p << endl; //如果能返回正确的值，是因为编译器做了保留
	cout << *p << endl; //
	cout << *p << endl; //
	cout << *p << endl; //


	/******************************************************************/
	cout << endl;

	/**** 堆区 ****/
	cout << "** 堆区：**" << endl;

	//new的基本用法
	int* pp = func2();
	cout << "堆区的值：" << *pp << endl;
	delete pp; //delete手动释放堆区


	//在堆区用new开辟数组
	newArr();


	//验证 delete 释放堆区内存后，只是释放了堆区内存，指针变量仍然存在
	int a = 6;
	int* temp = new int(55);
	cout << "temp = " << *temp << "  地址 = " << (int)&temp << endl;
	delete temp;
	temp = &a;
	cout << "temp = " << *temp << "  地址 = " << (int)&temp << endl;

	system("pause");
	return 0;


}