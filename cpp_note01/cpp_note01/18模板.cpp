/*****************************************************************************
 *  @brief	c++除了面向对象的思想外 还有 泛型编程思想，泛型编程的思想主要就是模板
模板：
 	函数模板
 	类模板
模板的特点：
 	模板不可以直接使用，它只是一个框架
 	模板的通用性很强，但并不是万能的
 		
函数模板作用：
	建立一个通用函数，其函数返回值类型和形参类型可以不具体指定，用一个虚拟的类型来代表。

语法：
	template<typename T>
	函数声明或定义
解释：
	template --- 声明创建模板
	typename --- 表面其后面的符号是一种数据类型，可以用class代替
	T --- 通用的数据类型，名称可以替换，通常为大写字母
总结：
	函数模板利用关键字 template
	使用函数模板有两种方式：自动类型推导、显示指定类型func<int>()
	模板的目的是为了提高复用性，将类型参数化
注意：
	自动类型推导，必须推导出一致的数据类型T，才可以使用
	模板必须要确定出T的数据类型，才可以使用，要么自动推导，要么显示指定

案例

普通函数与函数模板的隐式类型转换问题：
 	普通函数调用时可以发生自动类型转换
 	函数模板调用时，如果利用自动类型推导，不会发生隐式类型转换
 	如果利用参数列表<>显示指定类型的方式，可以发生隐式类型转换
	
	建议：多使用显示指定类型的方式调用函数模板

函数模板调用规则：
	1. 如果函数模板和普通函数都可以实现，优先调用普通函数
	2. 可以通过空模板参数列表<>来强制调用函数模板
	3. 函数模板也可以发生重载
	4. 如果函数模板可以产生更好的匹配,优先调用函数模板

模板的局限性
 	模板并不是万能的

 	可以将函数模板重载，变为具体化的模板，使T的数据类型能传入自定义数据类型
 	当然函数模板重载具体化后，不再具有通用性

	注：学习模板不是为了写模板，而是在STL中能够运用系统提供的模板

类模板：
	建立一个通用类，类中的成员 数据类型可以不具体制定，用一个虚拟的类型来代表。
	语法：
		template<typename T>
		类定义
	解释：
		template -- - 声明创建模板
		typename -- - 表面其后面的符号是一种数据类型，可以用class代替
		T-- - 通用的数据类型，名称可以替换，通常为大写字母

	类模板 和 函数模板 区别
		1. 类模板没有自动类型推导的使用方式
		2. 类模板在模板参数列表中可以有默认参数


类模板中成员函数和普通类中成员函数创建时机是有区别的：
	普通类中的成员函数一开始就可以创建
	类模板中的成员函数在调用时才创建，因为调用时才能确定数据类型


类模板对象做函数参数
	1. 形参指定传入的类型 - 直接指定对象的数据类型（最常用） void printFunc1(Person07<string, int>& p)
	2. 参数模板化 - 将对象中的参数变为模板进行传递  void printFunc2(Person07<T1, T2>& p)
	3. 整个类模板化 - 将这个对象类型 模板化进行传递  void printFunc3(T& p)


类模板与继承
 	当父类是类模板时，子类继承时，注意：
 		1、继承时，要显示指定父类模板参数类型列表，如果不指定，编译器无法给予类分配内存
			class Son1 :public Person08<int>

 		2、如果想灵活指定出父类中T的类型，子类也需要变为类模板
			template<typename T1, typename T2>
			class Son2 :public Person08<T2>

 	注意：子类和父类都为类模板时，调用父类成员必须加 this指针


类模板成员函数在类内定义、类外实现时
	需要加上类模板的参数列表<Type1, Type2>
 	template<class T1, class T2>  //
 	void Person<T1, T2>::showPerson(){ } //类模板成员的类外实现

	void Person::showPerson(){ } //普通类成员的类外实现


类模板的分文件编写注意事项
 	问题：
		类模板中成员函数创建时机是在调用阶段，导致分文件编写时链接不到

	解决方式1：直接包含.cpp源文件
	解决方式2：（常用）将声明和实现写到同一个文件中，并更改后缀名为.hpp，hpp是约定的名称，并不是强制


类模板与友元
 	类模板的友元全局函数：
		1、类内实现，直接声明为友元并实现即可
 		2、类外实现，指定为友元时需要加 空参数列表<>，并在类定义前面声明类和声明函数
		//1、类内实现
		friend void showPerson12_1(Person12<T1,T2> p) 
		{
			//注意：虽然在类内，但为全局函数，所以要传参，不能用this指针
		}

		//2、类外实现
		template<typename T1, typename T2>
		class Person12; //声明类

		template<typename T1, typename T2>
		void showPerson12_2(Person12<T1, T2> p); //声明全局函数
		//首先在类定义前面作上述声明，类声明 和 全局函数声明

 		friend void showPerson12_2<>(Person12<T1, T2> p); //类内指定为友元

		//类外实现时同样要声明模板
		template<typename T1,typename T2>
		void showPerson12_2(Person12<T1, T2> p){ }

 *****************************************************************************/


#include<iostream>
using namespace std;

/*****************************************************************************
 *  @brief	模板初体验 
 *
 *****************************************************************************/


//交换整型函数
void swapInt(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

//交换浮点型函数
void swapDouble(double& a, double& b) {
	double temp = a;
	a = b;
	b = temp;
}

//利用模板提供通用的交换函数
template<typename T>
void swapTemplate(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

// 模板函数调用时必须要确定出T的数据类型，才可以使用，要么自动推导，要么显示指定
template<class T>
void func()  // 所以对于无形参的函数调用要显示指定一个类型出来，如 func<int>();
{
	cout << "func 调用" << endl;
}

void test28()
{
	int a = 10;
	int b = 20;
	char c = 'a';

	//swapInt(a, b);

	//利用模板实现交换
	//1、自动类型推导
	swapTemplate(a, b);
	//swapTemplate(a, c);//错误，模板T不明确，自动类型推导，推导出的T类型必须一致，这里推导出一个为int，一个为char
	cout << "a = " << a << endl;//20
	cout << "b = " << b << endl;//10

	//2、显示指定类型
	swapTemplate<int>(a, b);
	cout << "a = " << a << endl;//10
	cout << "b = " << b << endl;//20
	
	//swapTemplate<int>(a, c);//错误，无法将参数2从char转换为T&，（此处如果采用值传递就运行正常）

	
	//func(); //错误，无形参模板不能独立使用，必须确定出T的类型
	func<int>(); //利用显示指定类型的方式，给T一个类型，才可以使用该模板
}


/*****************************************************************************
 *  @brief	模板案例
 *		利用函数模板封装一个排序的函数，可以对不同数据类型数组进行排序
 *		排序规则从大到小，排序算法为选择排序
 *		分别利用char数组和int数组进行测试
 *****************************************************************************/

template<typename T>
void mySwap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

template<typename T>
void mySort(T arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		int max = i;//最大数的下标
		for (int j = i + 1; j < len; j++)
		{
			if (arr[max] < arr[j])
			{
				max = j;
			}
		}
		
		if (max != i)
		{
			//如果最大数的下标不是i，交换两者，还可以在写个模板
			mySwap(arr[max], arr[i]);
		}
	}
}

template<typename T>
void myPrint(T arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}

void test29()
{
	int Arr1[] = { 1,2,3,4,5,6 };
	int len1 = sizeof(Arr1) / sizeof(int);
	mySort(Arr1, 6);
	myPrint(Arr1, 6);

	char Arr2[] = "cbadef";
	int len2 = sizeof(Arr2) / sizeof(char);
	mySort(Arr2, 6);
	myPrint(Arr2, 6);

}

/*****************************************************************************
 *  @brief	普通函数与函数模板的区别：
 *		普通函数调用时可以发生自动类型转换
 *		函数模板调用时，如果利用自动类型推导，不会发生隐式类型转换
 *		如果利用参数列表<>显示指定类型的方式，可以发生隐式类型转换
 *	建议：多使用显示指定类型的方式调用函数模板
 *****************************************************************************/
int myAdd01(int a, int b)
{
	return a + b;
}

template<typename T>
int myAdd02(T a, T b)
{
	return a + b;
}

void test30()
{
	int a = 10;
	int b = 10;
	char c = 'a';

	//普通函数可以发生隐式类型转换
	cout << "普通函数 a+b = " << myAdd01(a, b) << endl;//10+10=20
	cout <<"普通函数 a+c = " << myAdd01(a, c) << endl;//10+97=107

	//函数模板,显示指定类型，可以发生隐式类型转换
	cout << "函数模板 a+b = " << myAdd02(a, b) << endl;//10+10=20
	//cout << "函数模板 a+c = " << myAdd02(a, c) << endl;//错误，T指代不明
	cout << "函数模板 a+c = " << myAdd02<int>(a, c) << endl;//10+97=107
}


/*****************************************************************************
 *  @brief	函数模板的调用规则：
	1. 如果函数模板和普通函数声明或定义相同，优先调用普通函数
	2. 可以通过空模板参数列表<>来强制调用函数模板
	3. 函数模板也可以发生重载
	4. 如果函数模板可以产生更好的匹配,优先调用函数模板
	当然：通常不会让 函数模板 与 普通函数 定义相同
 *****************************************************************************/

void myTest01(int a, int b)
{
	cout << "调用普通函数" << endl;
}

template<typename T>
void myTest01(T a, T b)
{
	cout << "调用函数模板" << endl;
}
//函数模板也可以发生重载
template<typename T>
void myTest01(T a, T b, T c)
{
	cout << "调用函数模板的重载" << endl;
}

void test31()
{
	cout << endl;

	int a = 10;
	int b = 10;

	//1. 如果函数模板和普通函数定义相同，优先调用普通函数
	myTest01(a, b);

	//2. 可以通过空模板参数列表<>来强制调用函数模板
	myTest01<>(a, b);

	//3. 函数模板也可以发生重载
	myTest01(a, b, 100);

	//4. 如果函数模板可以产生更好的匹配, 优先调用函数模板
	char c = 'a';
	char d = 'b';
	myTest01(c, d);
}


/*****************************************************************************
 *  @brief	模板的局限性
 *				模板并不是万能的
 * 
 *			可以将函数模板重载，变为具体化的模板，使T的数据类型能传入自定义数据类型
 *			当然函数模板重载具体化后，不再具有通用性
 * 
 *****************************************************************************/
template<typename T>
void f0(T a, T b)
{
	a = b;
}
//在上述代码中提供的赋值操作，如果传入的a和b是一个数组，就无法实现了

//再例如：

template<typename T>
void f1(T a, T b)
{
	if (a > b) {  }
}
//在上述代码中，如果T的数据类型传入的是像Person这样的自定义数据类型，也无法正常运行

template<typename T>
void f2(T& a, T& b)
{
	if (a.m_Age > b.m_Age) {
		cout << "传入自定义数据类型" << endl;
	}
}
//上述代码，可以传入Person类，或传入也有相同的成员属性的别的类，不能传入内置数据类型，通用性并不强

//因此C++为了解决这种问题，提供模板的重载，可以为这些特定的类型提供具体化的模板

//"*****************************************"
class Person02
{
public:
	string m_Name;
	int m_Age;
	Person02(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
};

template<typename T>
bool myCompare(T& a, T& b)
{
	if (a == b)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//模板重载
template<> bool myCompare(Person02& p1, Person02& p2) //指定了形参为Person02类型，具体化了，该函数不再具有通用性
{
	if (p1.m_Name == p2.m_Name && p1.m_Age == p2.m_Age)
	{
		return true;
	}
	else
	{
		return false;
	}
}

class Person03
{
public:
	string m_Name;
	int m_Age;
	Person03(string name, int age)
	{
		m_Name = name;
		m_Age = age;
	}

};


void test32()
{
	cout << endl;
	int a = 10;
	int b = 10;
	bool ret = myCompare(a, b);
	if (ret)
	{
		cout << "a == b" << endl;
	}
	else
	{
		cout << "a != b" << endl;
	}

	//Person02 p1("Tom", 10);
	//Person02 p2("Tom", 10);
	//bool ret2 = myCompare(p1, p2); //报错
	
	//如果要比较类对象，应该对函数模板重载
	//（前面学过运算符重载也可以实现比较类对象）
	Person02 p1("Tom", 10);
	Person02 p2("Tom", 10);
	bool ret2 = myCompare(p1, p2);
	if (ret2)
	{
		cout << "p1 == p2" << endl;
	}
	else
	{
		cout << "p1 != p2" << endl;
	}

	//注意：函数模板重载为具体化的模板后，该具体化模板不具有通用性
	/*Person03 p3("Dav", 20);
	Person03 p4("Dav", 30);
	bool ret3 = myCompare(p3, p4); //报错
	if (ret3)
	{
		cout << "p3 == p4" << endl;
	}
	else
	{
		cout << "p3 != p4" << endl;
	}*/
}


/*****************************************************************************
 *  @brief	类模板作用：
		建立一个通用类，类中的成员 数据类型可以不具体制定，用一个虚拟的类型来代表。
		
		语法：
			template<typename T>
			类
		解释：
			template -- - 声明创建模板
			typename -- - 表面其后面的符号是一种数据类型，可以用class代替
			T-- - 通用的数据类型，名称可以替换，通常为大写字母
		
		类模板 和 函数模板 区别
			1. 类模板没有自动类型推导的使用方式
			2. 类模板在模板参数列表中可以有默认参数
 *****************************************************************************/
//类模板
template<typename NameType, typename AgeType, typename GenderType = string>  //类模板的参数列表中可以有默认参数
class Person04
{
public:
	NameType m_Name;
	AgeType m_Age;
	GenderType m_Gender;

	Person04(NameType name, AgeType age, GenderType gender)
	{
		m_Name = name;
		m_Age = age;
		m_Gender = gender;
	}
	void show_info()
	{
		cout << "类模板" << endl;
		cout << "姓名：" << m_Name << "  年龄：" << m_Age << "  性别：" << m_Gender << endl;
	}
};
void test33()
{
	cout << endl;
	Person04<string, int, string> p1("Tom", 18, "男"); // <string, int, string> 为模板参数列表
	Person04<string, int> p2("Tom", 18, "男"); // 默认参数，可以不指定类型
	p2.show_info();

	//Person04 p2("孙悟空", 999, "男");  //错误，类模板不能自动推导类型，必须显示指定

}

/*****************************************************************************
 *  @brief 类模板中成员函数和普通类中成员函数创建时机是有区别的：
		普通类中的成员函数一开始就可以创建
		类模板中的成员函数在调用时才创建，因为调用时才能确定数据类型
 *			
 *****************************************************************************/
class Person05
{
public:
	void show_person5()
	{
		cout << "show Person05" << endl;
	}
};

class Person06
{
public:
	void show_person6()
	{
		cout << "show Person06" << endl;
	}
};

template<typename T>
class myPerson
{
public:
	T obj;
	void func1() { obj.show_person5(); }
	void func2() { obj.show_person6(); }
};

void test34()
{
	cout << endl << "类模板中的成员函数在调用时才创建" << endl;
	myPerson<Person05> p5; //类模板的成员函数在调用时才创建，这会并不报错。
	p5.func1();
	//p5.func2();//报错，因为show_person6 是Person6类才有的成员，也说明类模板函数调用时才会创建成员函数
}


/*****************************************************************************
 *  @brief	类模板对象做函数参数
 *		1. 形参指定传入的类型   --- 直接指定对象的数据类型（最常用）
 *		2. 参数模板化           --- 将对象中的参数变为模板进行传递
 *		3. 整个类模板化         --- 将这个对象类型 模板化进行传递
 *
 *****************************************************************************/
template<typename NameType, typename AgeType>
class Person07
{
public:
	NameType m_Name;
	AgeType m_Age;
	Person07(NameType name, AgeType age)
	{
		m_Name = name;
		m_Age = age;
	}
	void showPerson7()
	{
		cout << "name: " << this->m_Name << "  age: " << this->m_Age << endl;
	}
};

//1、类模板对象做函数参数，形参指定传入类型
void printFunc1(Person07<string, int>&p)
{
	p.showPerson7();
}

//2、类模板对象做函数参数，参数模板化
template<typename T1, typename T2>
void printFunc2(Person07<T1, T2>& p)
{
	p.showPerson7();
}

//3、类模板对象做函数参数，整个类模板化
template<typename T>
void printFunc3(T& p)
{
	p.showPerson7();
}


void test35()
{
	cout << endl;

	//1、类模板对象做函数参数，形参指定传入类型（最常用）
	Person07<string, int> p7_1("孙悟空", 100);
	printFunc1(p7_1);

	//2、类模板对象做函数参数，参数模板化+类型指定
	Person07<string, int> p7_2("沙僧", 80);
	printFunc2(p7_2);

	//3、类模板对象做函数参数，整个类模板化+类型指定
	Person07<string, int> p7_3("八戒", 70);
	printFunc3(p7_3);
}

/*****************************************************************************
 *  @brief	类模板与继承
 *	当父类是类模板时，子类继承时，注意：
 *		1、继承时，要显示指定父类模板参数类型列表<Type1,...>，如果不指定，编译器无法给予类分配内存
 *		2、如果想灵活指定出父类中T的类型，子类也需要变为类模板
 *		注意：子类和父类都为类模板时，调用父类成员必须加 this指针
 * 
 *****************************************************************************/

template<typename T1> //父类为模板
class Person08
{
public:
	T1 m;
};

//class Son08 :public Person08 //错误，必须指定继承父类的T1类型，否则不知道分配多大内存空间
class Son08_1:public Person08<int> //将父类的模板类型指定为int
{
public:
	void show()
	{
		cout << "子类继承的父类为类模板：m = " << m << endl;

	}
};

//如果想灵活的指定父类中的T类型，子类也需要变为类模板
template<typename T1,typename T2>
class Son08_2 :public Person08<T2> 
{
public:
	T1 obj;
	void show()
	{
		//cout << "子类 父类 均为 类模板：obj = " << obj << "  m = " << m << endl;//错误
		//注意：子类和父类都为类模板时，调用父类成员必须加 this指针
		cout << "子类 父类 均为 类模板：obj = " << obj << "  m = " << this->m << endl;
		cout << "T1 的类型为：" << typeid(T1).name() << endl;
		cout << "T2 的类型为：" << typeid(T2).name() << endl;
	}
};
void test36()
{
	cout << endl;

	Son08_1 son1;
	son1.m = 5;
	son1.show();

	Son08_2<int, char> son2;  //int 传给 T1，char 传给 T2
	son2.obj = 10;
	son2.m = 'a';
	son2.show();

}


/*****************************************************************************
 *  @brief	类模板成员函数的类内定义、类外实现
 *		需要加上类模板的参数列表<Type1, Type2>
 *		void Person::showPerson(){ } //普通类成员的类外实现
 * 
 *		template<class T1, class T2>  //
 *		void Person<T1, T2>::showPerson(){ } //类模板成员的类外实现
 *
 *****************************************************************************/
 //类模板中成员函数类外实现
template<class T1, class T2>
class Person09 {
public:
	//成员函数类内声明
	Person09(T1 name, T2 age);
	void showPerson();

public:
	T1 m_Name;
	T2 m_Age;
};

//构造函数 类外实现
//Person09::Person09(T1 name, T2 age) //普通类成员的类外实现
template<class T1, class T2>
Person09<T1, T2>::Person09(T1 name, T2 age) 
{
	this->m_Name = name;
	this->m_Age = age;
}

//成员函数 类外实现
template<class T1, class T2>
void Person09<T1, T2>::showPerson() {
	cout << "姓名: " << m_Name << " 年龄:" << this->m_Age << endl;
}

void test37()
{
	cout << endl << "类模板的类内定义，类外实现" << endl;
	Person09<string, int> p9("Tom", 20);
	p9.showPerson();
}

/*****************************************************************************
 *  @brief	类模板的分文件编写注意事项
 *	问题：
		类模板中成员函数创建时机是在调用阶段，导致分文件编写时链接不到
			
	解决方式1：直接包含.cpp源文件
	解决方式2：（常用）将声明和实现写到同一个文件中，并更改后缀名为.hpp，hpp是约定的名称，并不是强制
 *
 *****************************************************************************/

//1、第一种解决方式

//#include "18_person10.h" 
//由于类模板中成员函数是在调用时创建的，常规引入头文件，编译器并不能看到对应cpp文件中的函数定义，导致分文件编写时链接不到
#include "18_person10.cpp" //导入cpp文件，而cpp文件中又引入了.h文件，所以编译器都能链接到
void test38()
{
	cout << endl << "类模板的分文件编写：直接包含 cpp 文件" << endl;
	Person10<string, int> p10("Jerry", 19); //直接包含 .cpp 文件可正常运行
	p10.showPerson();

}

//2、第二种解决方式（常用）：将.h和.cpp内容写在一个文件中，并命名为.hpp后缀
#include "18_person11.hpp"
void test39()
{
	cout << endl << "类模板的分文件编写：创建 hpp 文件" << endl;
	Person11<string, int> p11("Jerry", 18); //直接包含 .cpp 文件可正常运行
	p11.showPerson();

}

/*****************************************************************************
 *  @brief	类模板与友元
 	类模板的友元全局函数：
		1、类内实现，直接声明为友元并实现即可
 		2、类外实现，指定为友元时需要加 空参数列表<>，并在类定义前面声明类和声明函数
		//1、类内实现
		friend void showPerson12_1(Person12<T1,T2> p) 
		{
			//注意：虽然在类内，但为全局函数，所以要传参，不能用this指针
		}

		//2、类外实现
		template<typename T1, typename T2>
		class Person12; //声明类

		template<typename T1, typename T2>
		void showPerson12_2(Person12<T1, T2> p); //声明全局函数
		//首先在类定义前面作上述声明，类声明 和 全局函数声明

 		friend void showPerson12_2<>(Person12<T1, T2> p); //类内指定为友元

		//类外实现时同样要声明模板
		template<typename T1,typename T2>
		void showPerson12_2(Person12<T1, T2> p){ }
 *****************************************************************************/

template<typename T1, typename T2>
class Person12;

template<typename T1, typename T2>
void showPerson12_2(Person12<T1, T2> p);  //上面四行代码是友元全局函数类外实现时需要提前声明

template<typename T1,typename T2>
class Person12
{
	//友元全局函数，类内实现
	friend void showPerson12_1(Person12<T1,T2> p) //注意：虽然在类内，但为全局函数，所以要传参，不能用this指针
	{
		cout << "类模板的友元全局函数，类内实现" << endl;
		cout << "姓名：" << p.m_Name << "  年龄：" << p.m_Age << endl;
	}

	//友元全局函数，类外实现（加空参数列表<>，并在类前面声明或函数实现）
	//friend void showPerson12_2(Person12<T1, T2> p);
	friend void showPerson12_2<>(Person12<T1, T2> p);

public:
	Person12(T1 name, T2 age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
private:
	T1 m_Name;
	T2 m_Age;
	
};

//类模板的友元全局函数，类外实现要声明模板
template<typename T1,typename T2>
void showPerson12_2(Person12<T1, T2> p)
{
	cout << "类模板的友元全局函数，类外实现（复杂）" << endl;
	cout << "姓名：" << p.m_Name << "  年龄：" << p.m_Age << endl;
}

void test40()
{
	//类模板友元，类内实现
	Person12<string, int> p1("小吴", 22);
	showPerson12_1(p1);

	//类模板友元，类外实现
	Person12<string, int> p2("小华", 13);
	showPerson12_2(p2);
}


/*****************************************************************************
 *  @brief	main 函数
 *
 *****************************************************************************/

int main18() {
	//模板自动类型推导 和 显示类型指定
	test28();

	//案例
	test29();

	//普通函数与函数模板的隐式类型转换问题
	test30();

	//函数模板调用规则
	test31();

	//函数模板重载，具体化
	test32();

	//类模板
	test33();

	//类模板中的成员函数在调用时才创建
	test34();
	
	//类模板对象做函数参数
	test35();


	//类模板的继承
	test36();

	//类模板的类内定义，类外实现
	test37();

	//类模板分文件编写注意事项：第一种解决方式 直接包含 cpp 文件
	test38();

	//类模板分文件编写：第二种解决方式 hpp 文件
	test39();

	//类模板的友元
	test40();

	system("pause");

	return 0;
}