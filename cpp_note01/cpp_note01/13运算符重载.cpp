
/*
运算符重载概念：
	对已有的运算符重新进行定义，赋予其另一种功能，以适应不同的自定义数据类型
		+  -  *  /  ++  --  =  >  <  == !=  () 

	对于内置的数据类型进行操作，编译器知道如何运算，但对于自定义的数据类型，就不知道如何运算了，此时要重载

	运算符重载的函数名写法为：
		函数返回类型 operator 运算符号；如 void operator+(){} 加号重载； Person operator<<(){} 左移重载
		//可以利用 成员函数 或 全局函数 实现
	注意：
		对于内置的数据类型的表达式的的运算是不可能改变的，如 int a=1; int b=2; a+b 则一定等于3，这种不会因为重载得到别的结果
		不要滥用运算符重载
		//AA01 operator+(int num1, int num2){} //错误，不能对内置数据类型表达式的运算符进行更改
*/


#include<iostream>
using namespace std;


/*****************************************************************************
 *  @brief	加号运算符重载 + - * /
 *				如 实现两个类对象的加和
 *****************************************************************************/

/**
 * @brief	用AA01类创建两个对象，直接相加求和，会报错
 *			通过成员函数或全局函数重载加号运算符可解决
 */
class AA01
{
public:
	int m_A;
	int m_B;

public:
	AA01() {};
	AA01(int a, int b)
	{
		this->m_A = a;
		this->m_B = b;
	}
	//普通成员函数实现+号运算
	AA01 addNum(AA01& aa)
	{
		AA01 temp;
		temp.m_A = this->m_A + aa.m_A;
		temp.m_B = this->m_B + aa.m_B;
		return temp;
	}
	//1、通过成员函数重载+号
	/*
	AA01 operator+(AA01& aa)  //双目运算符，成员函数要有一个参数
	{
		AA01 temp;
		temp.m_A = this->m_A + aa.m_A;
		temp.m_B = this->m_B + aa.m_B;
		return temp;
	} */

};
//2、通过全局函数重载+号（和1不能共存）
AA01 operator+(AA01& aa1, AA01& aa2)  //双目运算符，全局函数要有俩参数
{
	AA01 temp;
	temp.m_A = aa1.m_A + aa2.m_A;
	temp.m_B = aa1.m_B + aa2.m_B;
	return temp;
}

//运算符重载，也可以发生函数重载
AA01 operator+(AA01& aa1, int num)
{
	AA01 temp;
	temp.m_A = aa1.m_A + num;
	temp.m_B = aa1.m_B + num;
	return temp;
}

//AA01 operator+(int num1, int num2){} //错误，不能对内置数据类型表达式的运算符进行更改


/**
 * @brief	通过add_reload_test测试加号运算符重载的效果
 */
void add_reload_test()
{
	AA01 aa1(10, 20);
	AA01 aa2(10, 20);

	AA01 aa3 = aa2.addNum(aa1);  //普通成员函数

	//1、通过成员函数重载+号
	//AA01 aa4 = aa1 + aa2;  //运算符重载调用的简化方式，要想使类型为 AA01 的数据相加，需要定义运算符重载 AA01 operator+(AA01& aa)
	//AA01 aa5 = aa1.operator+(aa2);  //运算符重载调用的本质，两种调用方式都可以
	//cout << "成员函数加号运算符重载：aa5.m_A = " << aa5.m_A << "   aa5.m_B = " << aa5.m_B << endl;

	//2、通过全局函数重载+号
	AA01 aa6 = aa1 + aa2;  // 20 40
	AA01 aa7 = operator+(aa1, aa2);  //本质， 20 40
	cout << "全局函数加号运算符重载：aa6.m_A = " << aa6.m_A << "   aa6.m_B = " << aa6.m_B << endl;

	//运算符重载函数 发生 函数重载
	AA01 aa8 = operator+(aa1, 1);
	cout << "运算符重载 且 函数重载：aa8.m_A = " << aa8.m_A << "   aa7.m_B = " << aa8.m_B << endl;

}



/*****************************************************************************
 * @brief	左移运算符重载  <<
 *				如 p为类对象，使 cout<< p << endl; 语句合法
 * 
 * @attention	不能利用成员函数重载 左移运算符，因为无法实现cout在<<符号的左侧
 *****************************************************************************/

class AA02
{
	friend ostream& operator<<(ostream& out, AA02& aa);  //设为友元
private:
	int m_A;
	int m_B;
public:
	AA02() 
	{
		m_A = 10;
		m_B = 20;
	}
	//1、不能利用成员函数重载 左移运算符，因为无法实现cout在<<符号的左侧
	/*void operator<<(cout)  //aa.operator(cout) 简化方式等价于 aa << cout ，与原意不符
	{

	}*/
};
//2、只能利用全局函数重载左移运算符

/**
 * @brief	全局函数重载左移运算符
 * 
 * @param	out 输出流数据类型，流对象不能复制拷贝，故不能采用值传递
 * @param	aa  AA02对象，本质为符号 << 右侧的参数
 *
 * @return	返回类型为 ostream& 引用，为的是支持链式调用：如 cout << aa <<endl;
 */
//void operator<<(ostream& out, AA02& aa)  
ostream& operator<<(ostream& out, AA02& aa) //operator<<(cout, aa) 本质为 cout << aa
{
	out << "  左移运算符重载：m_A = " << aa.m_A << "  m_B = " << aa.m_B;
	return out;
}   


void shiftLeft_reload_test()
{
	AA02 aa;
	//cout << aa;  //如果不重载，直接输出自定义类型对象 aa，报错

	//左移运算符重载后
	operator<<(cout, aa); //本质 cout << aa;
	cout << aa; 

	cout << endl; //注意：内置数据类型，调用的是c++自身的cout，而不是重载的

	//cout << aa << endl;  //如果返回为void不返回引用，报错，本质 cout << aa;  void << endl;
	//因为 void operator<<(ostream& out, AA02& aa)使 cout<<aa 返回为空，不能链式调用，需要返回cout引用才可
	cout << aa << endl;  //本质 cout << aa;  cout << endl;

}



/*****************************************************************************
 * @brief	递增运算符重载 ++ --
 *				注意：前置递增(可链式) 和 后置递增(不可链式)
 *
*****************************************************************************/

class MyInt
{
	friend ostream& operator<<(ostream& out, MyInt myNum);
private:
	int m_Num;
public:
	MyInt()
	{
		m_Num = 0;
	}
	//1、成员函数重载 前置递增运算符 ++a
	MyInt& operator++()  //返回引用，以支持链式调用，（单目运算符，成员函数不用形参）
	{
		m_Num++;
		return *this;

	}
	//1、成员函数重载 后置递增运算符 a++
	MyInt operator++(int) //注意：返回为值传递，若返回为引用，则返回了局部变量的引用
						  //禁止返回局部变量的引用，故后置递增不可链式调用，自带后置也不可链式调用（int做占位参数）
	{
		MyInt temp = *this;
		m_Num++;
		return temp;
	}

};

//因为要用到 cout 输出自定义类型，进行测试，需要 重载下运算符<<
ostream& operator<<(ostream& out, MyInt myNum)
{
	out << myNum.m_Num;
	return out;
}

void autoIncrement_reload_test()
{
	//MyInt a;  ++a;  a++;
	MyInt a;
	cout << "递增运算符" << endl;
	cout << "初始 a = " << a << endl; //0  重载<<
	cout << "  ++a  = " << ++a << endl; //1  且支持 ++(++a) 链式
	cout << "此时 a = " << a << endl; //1

	MyInt b;
	cout << "初始 b = " << b << endl; //0
	cout << "  b++  = " << b++ << endl; //0  不支持 (b++)++ 链式
	cout << "此时 b = " << b << endl; //1

}


/*****************************************************************************
 * @brief	赋值运算符重载 =
 *				Person p1; Person p2;   p2 = p1; 
 *				//系统默认的赋值是浅拷贝，如果存在堆资源，手动释放内存可能导致多次释放同一堆空间，导致错误
 *				//通过重载赋值运算符实现 深拷贝 即可解决问题
*****************************************************************************/

class Person03 
{
public:
	int* m_p;
public:
	Person03(int age)
	{
		//m_A = &age; //注意：不能这样写，指针指向了局部变量
		m_p = new int(age);
	}
	~Person03()
	{
		if (m_p != NULL)
		{
			delete m_p;
			m_p = NULL;
		}
	}
	//赋值运算符重载
	Person03& operator=(Person03& p)  //返回引用，支持链式
	{
		//m_p = p.m_p  //默认赋值运算符提供的是浅拷贝，实际就是这行代码

		//先判断对象自身是否有属性在堆区，有则释放，再深拷贝
		if (m_p != NULL)
		{
			delete m_p;
			m_p = NULL;
		}
		//深拷贝
		m_p = new int(*p.m_p);

		return *this;
	}
};
void fuzhi_reload_test()
{
	Person03 p1(12);
	Person03 p2(25);
	
	//赋值运算符重载前
	//p2 = p1; //对于默认的赋值运算符 是成员的浅拷贝。
	// 所以此时 指针 p2.m_A 是 p1.m_A 里存放的地址的复制，故指针指向的内容相同，若当析构释放堆空间会被释放两次而报错
	//cout << (int)p1.m_p << "\t" << *p1.m_p << endl;
	//cout << (int)p2.m_p << "\t" << *p2.m_p << endl;  //不释放堆时，二者结果完全相同


	//赋值运算符重载后
	p2 = p1;
	cout << (int)p1.m_p << "\t" << *p1.m_p << endl;
	cout << (int)p2.m_p << "\t" << *p2.m_p << endl; //因为是深拷贝，此时地址不再相同

	Person03 p3(35);
	p3 = p2 = p1;  //链式
	cout << *p3.m_p << endl;

}



/*****************************************************************************
 * @brief	关系运算符重载  >  <  ==  !=
 *				让两个自定义类型对象进行比较
*****************************************************************************/

class AA03
{
private:
	string m_Car;
	int m_Money;
public:
	AA03(string car, int m)
	{
		m_Car = car;
		m_Money = m;
	}
	//关系运算符重载 ==
	bool operator==(AA03 &aa)
	{
		if (m_Car == aa.m_Car && m_Money == aa.m_Money)
		{
			return true;
		}
		return false;
	}
	bool operator!=(AA03& aa)
	{
		if (m_Car == aa.m_Car && m_Money == aa.m_Money)
		{
			return false;
		}
		return true;

		/* 上下两种方式都行 
		if (m_Car != aa.m_Car || m_Money != aa.m_Money)
		{
			return true;
		}
		return false;*/
	}

};
void relation_reload_test()
{
	AA03 aa1("红旗", 20);
	AA03 aa2("红旗", 20);
	AA03 aa3("比亚迪", 20);
	/*重载前报错
	if (aa1 == aa2)
	{

	}*/
	if (aa1 == aa2)
	{
		cout << "类 对象aa1 和 aa2 相等" << endl;
	}
	if (aa1 != aa3)
	{
		cout << "类 对象aa1 和 aa3 不相等" << endl;
	}
}



/*****************************************************************************
 * @brief	函数调用运算符重载  ()
 *				由于重载后使用的方式非常像函数的调用，因此称为仿函数
 *				仿函数没有固定写法，非常灵活
*****************************************************************************/
class MyPrint
{

public:
	void operator()(string str1)
	{
		cout << str1;
	}
};
//与普通函数对比
void myPrint2(string str2)
{
	cout << str2;
}

void funcCall_reload_test()
{
	MyPrint myPrint;
	myPrint("hello world"); //函数调用重载，由于使用起来非常类似函数调用，故称仿函数
	cout << endl;

	myPrint2("hello world"); //普通全局函数
	cout << endl;
}

//仿函数很灵活，参数个数，返回类型等很随便
class MyAdd
{
public:
	int operator()(int a,int b)
	{
		return a + b;
	}
};
void myAdd_test()
{
	MyAdd myAdd;
	int ret = myAdd(1, 2);
	cout << ret << endl;

	//MyAdd(); //匿名对象：类名()
	//MyAdd()(2, 3); //匿名对象+仿函数 = 匿名函数对象
	cout << "匿名对象+仿函数 = 匿名函数对象  " << MyAdd()(2, 3) << endl;
}


/*****************************************************************************
 * @brief	main 函数
 * 
*****************************************************************************/
int main13()
{
	/* 加号运算符重载 */
	cout << endl << "加号移运算符重载" << endl;
	add_reload_test();

	/* 左移运算符重载 */
	cout << endl << "左移运算符重载" << endl;
	shiftLeft_reload_test();

	/* 递增运算符重载 */
	cout << endl;
	autoIncrement_reload_test();

	/* 赋值运算符重载 */
	cout << endl << "赋值运算符重载" << endl;
	fuzhi_reload_test();

	/* 关系运算符重载 */
	cout << endl << "关系运算符重载" << endl;
	relation_reload_test();

	/* 函数调用括号重载 */
	cout << endl << "函数调用括号重载：仿函数" << endl;
	funcCall_reload_test();

	//匿名函数对象
	myAdd_test();

	return 0;
}