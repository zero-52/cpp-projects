/*
	对象成员：类的成员是另一个类的对象
		考虑：	当B类中有对象A作为成员，A为对象成员，
				那么当创建B对象时，A与B的构造和析构的顺序是谁先谁后？
		答案：
			先调用对象成员A的构造函数，再调用当前类B的构造函数（先有零件，再有成品）
			析构函数调用顺序与构造相反（先拆整机，再拆零件；实际就是栈先进后出）


	静态成员： 在成员变量或成员函数前加 static，所有对象共享一份数据

		静态成员变量：  static int m_A;
			所有对象共享同一份数据，节省内存
			在编译阶段分配内存
			必须在类内声明，类外全局区域初始化。如int Member::m_A = 100;
		注：初始化时可以赋初值，也可以不赋值。如果不赋值，那么会被默认初始化为 0

		静态成员函数：   Member::setB(11); //这种语法只能用于静态成员
			所有对象共享同一个函数
			静态成员函数只能访问静态成员变量（因为静态成员是共享的，如果里面访问了非静态成员变量，无法区分是哪个对象的）
			可以类内定义，也可类外定义

		访问静态成员：
			静态成员变量既可以通过对象名访问，也可以通过类名访问，但要遵循 private、protected 和 public 关键字的访问权限限制

			对于在类的public部分说明的静态数据成员，在类外可直接访问，但在使用时必须用类名指明所属的类。方式为：类名::成员数据。

			对于在类的 private、protected部分说明的静态数据成员，则只能由类的成员函数间接访问，其访问方法与访问类中普通数据成员的访问方法完全一样，但在类的外部不能访问

		注：
		static 成员变量和普通 static 变量一样，都在内存分区中的全局数据区分配内存，到程序结束时才释放。
		这就意味着，static 成员变量不随对象的创建而分配内存，也不随对象的销毁而释放内存。
		而普通成员变量在对象创建时分配内存，在对象销毁时释放内存。

	C++中，成员变量 和 成员函数 是分开存储的
		只有非静态成员变量才属于类的对象上，其它的都属于整个类而不是某个对象

	this指针：
		本质是指针常量： 类名* const this  （引用& 的本质也是指针常量）


	常函数与常对象：
		常函数：
			成员函数后加const我们称为这个函数为常函数: 如 void func() const {  }
			常函数内不可以修改成员属性
			成员属性声明时加关键字 mutable 或 static 后，在常函数中依然可以修改（相当于常函数中给成员属性上了锁，而mutable是钥匙）

		常对象：
			创建对象前加const称该对象为常对象：const 类名 对象名;
			常对象也不能修改指针指向的值
			常对象只能调用 常函数 或 静态成员函数
	
*/

#include<iostream>
using namespace std;

/* 对象成员：类的成员是另一个类的对象
	考虑：	当B类中有对象A作为成员，A为对象成员，
			那么当创建B对象时，A与B的构造和析构的顺序是谁先谁后？
	答案：
		先调用对象成员的构造函数，再调用当前类的构造函数（先有零件，再有成品）
		析构函数调用顺序与构造相反（先拆整机，再拆零件；实际就是栈先进后出）
	*/
class Phone
{
public:
	string phoneName; //手机品牌
	Phone(string name)
	{
		phoneName = name;
		cout << "Phone 构造函数调用" << endl;
	}
	~Phone()
	{
		cout << "Phone 析构函数调用" << endl << endl;
	}
};
class Person2
{
public:
	string sName;
	Phone pName;
	Person2(string sname, string pname) :sName(sname), pName(pname)
	{
		cout << "Person2 构造函数调用" << endl;
	}
	~Person2()
	{
		cout << "Person2 析构函数调用" << endl;
	}
};

void test07()
{
	Person2 perpon2("张三", "华为mate80");
	//构造的顺序是 ：先调用对象成员的构造函数，再调用当前类的构造函数	
	//且析构顺序与构造相反
}


/* 静态成员：在成员变量或成员函数前加 static
	静态成员变量：	static int m_A;
		所有对象共享同一份数据
		在编译阶段分配内存
		无论公有私有，必须在类内声明，类外全局区域初始化。如int Member::m_A = 100;

	注：初始化时可以赋初值，也可以不赋值。如果不赋值，那么会被默认初始化为 0

	静态成员函数：	Member::setB(11); //这种语法只能用于静态成员
		所有对象共享同一个函数
		静态成员函数只能访问静态成员变量（因为静态成员是共享的，如果里面访问了非静态成员变量，无法区分是哪个对象的）
		可以类内定义，也可类外定义

	访问静态成员：
		静态成员变量既可以通过对象名访问，也可以通过类名访问，但要遵循 private、protected 和 public 关键字的访问权限限制

		对于在类的public部分说明的静态数据成员，在类外可直接访问，但在使用时必须用类名指明所属的类。方式为：类名::成员数据。

		对于在类的 private、protected部分说明的静态数据成员，则只能由类的成员函数间接访问，其访问方法与访问类中普通数据成员的访问方法完全一样，但在类的外部不能访问

	注：
	static 成员变量和普通 static 变量一样，都在内存分区中的全局数据区分配内存，到程序结束时才释放。
	这就意味着，static 成员变量不随对象的创建而分配内存，也不随对象的销毁而释放内存。
	而普通成员变量在对象创建时分配内存，在对象销毁时释放内存。
*/

class Member
{
public:
	//静态成员变量
	static int m_A;  //类内声明
	int m_C;
private:
	static int m_B;  //私有成员也必须先在类外初始化
public:
	void test()
	{
		m_C = 10;
		m_B = 20; //普通成员函数也可以访问静态成员变量
	}
	//静态成员函数
	static void setB(int b) {
		m_B = b;  //必须先在类外初始化，此句才不报错
		//m_C = 10;  //错误，静态成员函数只能访问静态成员变量，但普通成员函数也可以访问静态成员变量
	}
	static int getB() {
		cout << "成员函数间接访问private成员 m_B = " << m_B << endl;
		return m_B;
	}
};

int Member::m_A = 100; //类外初始化，必须在全局区域，注意加作用域
int Member::m_B = 100; //私有成员也必须先在类外初始化

void test08()
{
	Member m1;
	cout << "静态成员 m1.m_A = " << m1.m_A << endl; //100  对象名.成员 的方式访问

	Member m2;
	m2.m_A = 200;
	cout << "静态成员 m2.m_A = " << m2.m_A << endl;  //200
	cout << "静态成员 m1.m_A = " << m1.m_A << endl;  //200，所有成员共享一份数据，所以有一个发生改变，都改变
	cout << "类名::静态成员 的方式访问静态成员 Member::m_A = " << Member::m_A << endl;  //200，类名::静态成员 的方式访问（非静态成员不能这样访问）

	//cout << "Member::m_B = " << Member::m_B << endl;  //错误，类外不能直接访问私有成员


	//Member::test(); //错误，这种语法只能用于静态成员
	m2.test(); //非静态成员函数也可以访问静态成员变量
	Member::getB(); //静态成员函数独有的调用方式

	//通过成员函数访问非公有静态成员
	Member::setB(11);
	m2.getB(); // 11
	m2.setB(12);
	m1.getB(); // 12
}


/**** C++中，成员变量 和 成员函数 是分开存储的
	只有非静态成员变量才属于类的对象上，其它的都属于整个类而不是某个对象
*/

class A1 { };  //空类，空类所建对象占1字节
class A2 { int m_A; };  //非静态成员变量，属于类所建的对象上
class A3 { int m_A; static int m_B; };  //静态成员变量，属于类，不属于类所建的对象上
class A4 { int m_A; static int m_B; void func() {} };  //非静态成员函数，属于类，不属于类所建的对象上
class A5 { int m_A; static int m_B; void func() {} static void func2() {} };  //静态成员函数，属于类，不属于类所建的对象上

void test09()
{
	A1 a1;
	cout << "sizeof(a1) = " << sizeof(a1) << endl; // 1字节，空类所建对象占1字节
	A2 a2;
	cout << "sizeof(a2) = " << sizeof(a2) << endl; // 4字节，非静态成员变量，属于类所建的对象上
	A3 a3;
	cout << "sizeof(a3) = " << sizeof(a3) << endl; // 4字节，  静态成员变量，属于类，不属于类所建的对象上
	A4 a4;
	cout << "sizeof(a4) = " << sizeof(a4) << endl; // 4字节，非静态成员函数，属于类，不属于类所建的对象上
	A5 a5;
	cout << "sizeof(a5) = " << sizeof(a5) << endl; // 4字节，  静态成员函数，属于类，不属于类所建的对象上

}


/**** this指针 ：this指针指向被调用的成员函数所属的对象，*this就是对象本身
*
	本质：this指针其实是个指针常量，指针指向不可修改

	每一个非静态成员函数只会诞生一份函数实例，也就是说多个同类型的对象会共用一块代码
	那么问题是：这一块代码是如何区分那个对象调用自己的呢？

	c++通过提供特殊的对象指针，this指针，解决上述问题。

	this指针是隐含在每一个非静态成员函数内的一种指针
	this指针不需要定义，直接使用即可

	this指针的用途：
		当形参和成员变量同名时，可用this指针来区分
		在类的非静态成员函数中返回对象本身，可使用 return *this
*/
class Man
{
public:
	int age;

	//1、解决命名冲突
	Man(int age)
	{
		//this = NULL;  //指针常量，本质是 Man * const this，不可修改指向

		//age = age; //这样写得到的是错误的结果，会认为等号左右的age是同一个，本意应该是左侧的表示成员属性的age

		//用this指针防止这种同名的问题（this指针指向被调用的成员函数所属的对象）
		this->age = age;
	}
	//2、返回对象本身 *this，可用来实现链式调用
	Man& ManAddAge(Man& m)
	{
		this->age += m.age;
		return *this;
	}
	/*
	void ManAddAge(Man& m)  //这样定义不能链式调用
	{
		this->age += m.age;
	}*/

	/*体会 和 Man& 定义的区别，值传递的方式会复制一个新对象出来，已经不是当前对象本身；而Man& 是返回对象的引用（别名），一改都改
	Man ManAddAge(Man& m)
	{
		this->age += m.age;
		return *this;
	}*/


};
void test10()
{
	Man man01(15);
	cout << man01.age << endl;


	Man man02(25);
	//man02.ManAddAge(man01).ManAddAge(man01);  //void ManAddAge(Man& m) 这样定义时不能链式调用
	cout << "***" << endl;
	man02.ManAddAge(man01).ManAddAge(man01);  //链式编程思想
	cout << man02.age << endl;
}


/****
	常函数：
		成员函数后加const我们称为这个函数为常函数: 如 void func() const {  }
		常函数内不可以修改成员属性
		成员属性声明时加关键字 mutable 或 static 后，在常函数中依然可以修改（相当于常函数中给成员属性上了锁，而mutable是钥匙）

	常对象：
		创建对象前加const称该对象为常对象：const 类名 对象名;
		常对象也不能修改指针指向的值
		常对象只能调用 常函数 或 静态成员函数
*/
class Person3
{
public:
	int m_A;
	mutable int m_B;
	static int m_C;

	//常函数
	//相当于 const Person01 * const this，this指针指向不可改，指向的内容也不可改
	void constFunc() const
	{
		//m_A = 100; //错，常函数内不可以修改普通成员属性；本质是 this->m_A = 100; 
		m_B = 20; //除非成员属性有 mutable 或 static 修饰；才可修改，本质是 this->m_B = 20; 
		m_C = 66;
		cout << "常对象只能调用 常函数 或 静态成员函数" << endl;
	}
	//静态成员函数
	static void staticFunc()
	{
		cout << "常对象可以调用静态成员函数" << endl;
	}
	//普通函数
	void generalFunc()
	{
		m_A = 1;
		m_B = 2;
		cout << "常对象不可以调用普通成员函数" << endl;
	}
};
int Person3::m_C = 88;

void test11()
{
	//常对象
	const Person3 p3;
	//p3.m_A = 20;  //常对象也不能修改指针指向（成员属性）的值，除非有 mutable 或 static 修饰
	p3.m_B = 30;
	p3.m_C = 40;

	//常对象只能调用常函数或静态成员函数，因为普通函数能修改成员属性的值
	p3.constFunc();  //调用常函数
	p3.staticFunc();  //调用静态成员函数
	//p3.generalFunc(); //错误，不能调用普通函数

}

int main11()
{
	cout << endl << "有对象成员时，构造和析构的顺序是谁先谁后？" << endl;

	/* 对象成员：类的成员是另一个类的对象
		先调用对象成员的构造函数，再调用当前类的构造函数（先有零件，再有成品）
		析构函数调用顺序与构造相反（先拆整机，再拆零件；实际就是栈先进后出）
		*/
	test07();


	/* 静态成员：在成员变量或成员函数前加 static
		静态成员变量：
		静态成员函数：
	*/
	test08();


	cout << endl << "成员变量与成员函数是分开存储的：" << endl;
	/* 成员属性和成员函数是分开存储的 */
	test09();


	cout << endl << "this指针：" << endl;
	/* this指针 */
	test10();


	cout << endl << "常函数、常对象：" << endl;
	/* 常函数、常对象 */
	test11();

	return 0;
}