/*
	引用：
		给变量起别名（相当于一个数据两个名字，别名或原变量任一被修改，数据会同时受影响）
		本质：在c++内部实现是一个指针常量。（类和对象的this指针：本质也是指针常量）
		指针常量：指针指向不可改，也说明了为什么引用不可更改
	语法：
		数据类型& 别名 = 变量名  //如int& b = a;  //本质是 int * const b = &a;
	注意：	
		引用必须初始化
		引用在初始化后，不可以改变
		C++推荐使用引用技术，语法更方便，指针操作由编译器自动完成


	常量引用：
		作用： 常量引用主要用来修饰形参，防止误操作

		在函数形参列表中，可以加const修饰形参，防止形参改变实参
	*/

#include<iostream>
using namespace std;


//值传递：形参不可修饰实参
void swap01(int a, int b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}

//地址传递：形参可修饰实参
void swap02(int* a, int* b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

//引用传递：形参可修饰实参：可以简化指针修饰实参
void swap03(int& a, int& b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}

//引用做函数返回值

//不要返回局部变量的引用
int& test01()
{
	int a1 = 10;
	return a1;  // 栈区，函数执行完毕即被释放
}

//引用做返回值时，函数调用可以作为左值
int& test02()
{
	static int a2 = 20; //全局区，程序结束才被os释放
	return a2;
}

//常量引用：const修饰引用，防止形参修改实参
void showValue(const int& a)
{
	//a = a * 2; // const修饰不能作为左值被赋值修改，即只读
	cout << a << endl;
}



/** 函数调用 **/

/** 
	* 默认参数
		1. 如果某个位置参数有默认值，那么从这个位置往后，从左向右，必须都要设定默认值
		2. 有默认参数时，函数声明和函数定义 二者中只能有一个设定默认参数，否则报错   
		void func01(int a, int b = 10, int c = 20);   

	* 占位参数：形参中只指定数据类型，不写变量名
		void func02(int a, int);
	
	* 默认参数与占位参数
		void func03(int a, int b = 10, int = 20);
**/

void func01(int a, int b = 10, int c = 20);  //函数声明

//默认参数
//int func01(int a, int b = 10, int c = 20)  //报错，提示重定义默认参数
void func01(int a, int b, int c)
{
	cout << "函数默认参数：" << a + b + c << endl;
}


//占位参数
void func02(int a, int)
{
	cout << "占位参数：只需要指定数据类型  " << a << endl;
}

//默认参数与占位参数
void func03(int a, int b =10, int =20)
{
	cout << "默认参数与占位参数：指定数据类型 = xxx  " << a+b << endl;
}


/** 函数重载 **/
/*
	作用：函数名可以相同，提高复用性

	函数重载需满足条件：
		1.函数要在同一个作用域下
		2.函数名称相同
		3.函数参数类型不同 或者 个数不同 或者 顺序不同；即函数名相同，但形参列表不一致

	注意 : 函数的返回值类型不同不可以作为函数重载的条件
*/
void func04()
{
	cout << "函数04" << endl;
}

void func04(int a)
{
	cout << "函数04的重载" << endl;
}

void func04(int a, float b)
{
	cout << "函数04的重载" << endl;
}

void func04(float a, int b)
{
	cout << "函数04的重载" << endl;
}

//错误，函数的返回值类型不同不可以作为函数重载的条件
//int func04()
//{
//	cout << "函数04的重载" << endl;
//}


// 函数重载：引用传递，引用作为重载条件
void func05(int& a)
{
	cout << "函数重载，引用传递： func05(int& a)" << endl;
}

void func05(const int& a)
{
	cout << "函数重载，引用传递： func05(const int& a)" << endl;
}

/** 函数重载碰到默认参数时 ：报错，调用出现二义性，要避免 **/
void func06(int a)
{
	cout << "函数重载碰到默认参数：func06(int a)" << endl;
}
void func06(int a, int b = 10)
{
	cout << "函数重载碰到默认参数：func06(int a, int b = 10)" << endl;
}


int main6()
{
	int a = 10;
	int c = 100;
	//int& b;  // 错误，引用必须要初始化
	//int& c = 10; // 错误，不能把 int 转为 int & ；因为数字10在常量区，而引用需要在合法的内存空间，如栈区，堆区的数据
	int& b = a;  
	//int& b = c;  // 错误，引用一旦初始化，不可以改变

	cout << "变量a的值为：" << a << endl;
	cout << "引用b的值为：" << b <<endl;

	b = 20;  //a,b的数据都会被修改

	cout << "变量a的值为：" << a << endl;
	cout << "引用b的值为：" << b << endl;


	/*形参类型*/

	cout << endl << "函数调用，形参的不同：" << endl;
	
	a = 10;
	c = 20;
	cout << "原始：a = " << a << "  c = " << c << endl;
	
	//普通变量做函数参数
	swap01(a, c);
	cout << "swap01 值传递： a = " << a << "  c = " << c << endl;

	//指针做函数参数
	swap02(&a, &c);
	cout << "swap02 地址传递： a = " << a << "  c = " << c << endl;

	//引用做函数参数
	a = 10;
	c = 20;
	swap03(a, c); //形参相当于实参的别名
	cout << "swap03 引用传递： a = " << a << "  c = " << c << endl;


	//引用做函数返回值
	int &t_a1 = test01();
	cout << "不要返回局部变量的引用：" << t_a1 << endl;  //一般结果为脏数，若结果正常是因为编译器做了保留
	cout << "不要返回局部变量的引用：" << t_a1 << endl;

	int& t_a2 = test02();
	cout << "返回静态变量的引用：" << t_a2 << endl; //因为是全局区，程序结束才被os释放，结果正确
	cout << "返回静态变量的引用：" << t_a2 << endl;

	//引用做函数返回值时，函数调用可以作为左值
	test02() = 20000;
	cout << "函数调用做左值：" << t_a2 << endl;  //20000
	cout << "函数调用做左值：" << test02() << endl;  //20000



	/* 引用的本质是：在c++内部实现是一个指针常量. */
	int aaa = 123;
	int& ref = aaa;  //检测到为引用，内部解引用转换为 int* const ref = &aaa; 函数形参为引用时，原理相同。
	ref = 345; //发现ref是引用，自动帮我们解引用转换为: *ref = xxx;

	cout << "aaa = " << aaa << endl;
	cout << "ref = " << ref << endl;  //自动解引用

	/* 常量引用 */
		//作用： 常量引用主要用来修饰形参，防止误操作
		//在函数形参列表中，可以加const修饰形参，防止形参改变实参
	const int& bbb = 40;
	cout << "常量引用：" << bbb << endl;

	const int& ccc = aaa;
	cout << "常量引用：" << ccc << endl;


	//函数中利用常量引用，防止在函数中误操作修改实参
	int ddd = 50;
	showValue(ddd);

	

	/* 函数调用 */

	/** 函数默认参数 
		1. 如果某个位置参数有默认值，那么从这个位置往后，从左向右，必须都要设定默认值
		2. 如果函数声明有默认值，函数实现的时候就不能有默认参数
	**/

	func01(10);
	func01(10, 20);
	func01(10, 20, 30);

	//占位参数
	func02(10, 2);

	//默认参数与占位参数
	func03(10);



	/**  函数重载  **/
	func04();
	func04(5);
	func04(5, 3.14);
	func04(3.14, 5);

	//函数重载：引用传递
	int a5 = 11;
	func05(a5);  

	const int a6 = 22;
	func05(a6);  //调用相当于 const int& a6 = 22
	func05(22);  //调用 func05(const int& a)，而不是func05(int& a)，因为 int& a = 22 不合法


	//函数重载时碰到默认参数时
	//func06(10);  //报错，调用出现二义性

	return 0;
}

