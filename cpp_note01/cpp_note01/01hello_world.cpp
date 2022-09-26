/*
在 C/C++ 中static的作用
1、总的来说
	（1）在修饰变量的时候，static 修饰的静态局部变量只执行初始化一次，而且延长了局部变量的生命周期，直到程序运行结束以后才释放。
	（2）static 修饰全局变量的时候，这个全局变量只能在本文件中访问，不能在其它文件中访问，即便是 extern 外部声明也不可以。
	（3）static 修饰一个函数，则这个函数的只能在本文件中调用，不能被其他文件调用。
	（4）static 修饰的变量存放在全局数据区的静态变量区，包括全局静态变量和局部静态变量，都在全局数据区分配内存。初始化的时候自动初始化为 0。
	（5）不想被释放的时候，可以使用static修饰。比如修饰函数中存放在栈空间的数组。如果不想让这个数组在函数调用结束释放可以使用 static 修饰。
	（6）考虑到数据安全性（当程序想要使用全局变量的时候应该先考虑使用 static）。

2、静态变量与普通变量
	静态全局变量有以下特点：
		（1）静态变量都在全局数据区分配内存，包括后面将要提到的静态局部变量;
		（2）未经初始化的静态全局变量会被程序自动初始化为0（在函数体内声明的自动变量的值是随机的，除非它被显式初始化，而在函数体外被声明的自动变量也会被初始化为 0）；
		（3）静态全局变量在声明它的整个文件都是可见的，而在文件之外是不可见的。

	优点：静态全局变量不能被其它文件所用；其它文件中可以定义相同名字的变量，不会发生冲突。

3、全局变量和全局静态变量的区别：
	1）全局变量是不显式用 static 修饰的全局变量，全局变量默认是有外部链接性的，作用域是整个工程，在一个文件内定义的全局变量，在另一个文件中，通过 extern 全局变量名的声明，就可以使用全局变量。
	2）全局静态变量是显式用 static 修饰的全局变量，作用域是声明此变量所在的文件，其他的文件即使用 extern 声明也不能使用。
		
4、静态局部变量有以下特点：
	（1）该变量在全局数据区分配内存；
	（2）静态局部变量在程序执行到该对象的声明处时被首次初始化，即以后的函数调用不再进行初始化；
	（3）静态局部变量一般在声明处初始化，如果没有显式初始化，会被程序自动初始化为 0；
	（4）它始终驻留在全局数据区，直到程序运行结束。但其作用域为局部作用域，当定义它的函数或语句块结束时，其作用域随之结束。

	
tip： 
	不管什么类型的指针，占用字节都一样，32位机占4字节，64位机占8字节
	cout << sizeof(int*) << endl;  //查看
*/


#include <iostream>  //包含输入输出流的头文件
using namespace std;  //使用标准命名空间

// 单行注释 //

// 多行注释 /* */

#define DAY		7

//学生结构体定义
struct student
{
	//成员列表
	string name;  //姓名
	int age;      //年龄
	int score;    //分数
};

//教师结构体定义
struct teacher
{
	//成员列表
	int id; //职工编号
	string name;  //教师姓名
	int age;   //教师年龄
	struct student stu; //子结构体 学生
};

//值传递：形参不能修饰实参
void printStudent(struct student stu)
{
	stu.age = 28;
	cout << "子函数中 姓名：" << stu.name << " 年龄： " << stu.age << " 分数：" << stu.score << endl;
}

//地址传递：形参能修饰实参
void printStudent2(struct student* stu)
{
	stu->age = 28;
	cout << "子函数中 姓名：" << stu->name << " 年龄： " << stu->age << " 分数：" << stu->score << endl;
}

//地址传递 + const
void printStudent3(const struct student* stu)
{
	//stu->age = 28; // 报错，因为加入了const修饰形参，一旦修改就会报错，防止误操作导致主函数的成员值被修改（即只读，不允许写）
	cout << "const修饰形参 姓名：" << stu->name << " 年龄： " << stu->age << " 分数：" << stu->score << endl;
}


//静态变量只初始化一次，后续再调用函数也不会被重新初始化
void static_test()
{
	static int s_test = 10;
	s_test += 5;
	cout << "静态变量只初始化一次，后续再调用函数也不会被重新初始化 s_test = " << s_test << endl;
}

//一个项目只能有一个main函数
int main1()
{
	/* 输出 */
	cout << "hello world" << endl;  //endl即 end line 是换行的意思
	cout << "hello C++\n";			//也可以用 \n 表示换行
	cout << "hello";
	
	/* 变量 */
	// C++在创建变量时，必须给变量一个初始值，否则会报错
	int a = 10;  
	cout << "a = " << a << endl;


	/* 常量：用于记录程序中不可更改的数据 */
	cout << "一周有：" << DAY << "天" << endl;  //宏常量
	const int month = 30;				// const 数据类型 修饰的常量
	cout << "一月有：" << month << "天" << endl;
	//DAY = 8;  //错误，不能对宏常量赋值
	//month = 28;  //错误，不能对 const 定义的常量进行赋值
	
	/* 整型：short ，int ，long， long long */

	/* 浮点型 */
	float f1 = 3.14f;  //在给float变量赋初值时，常在初值后面加小写f，否则是从默认的double转换为float，多做了一步转换
	cout << "f1 = " << f1 << endl;
	double d1 = 3.14;
	cout << "d1 = " << d1 << endl;  //无论单精度双精度，在黑窗口输出默认最多只显示6位有效数字

	cout << "float 占用内存空间为：sizeof(float) = " << sizeof(float) << endl;
	cout << "double 占用内存空间为：sizeof(double) = " << sizeof(double) << endl;

	/* 科学计数法 */
	float f2 = 3e2;  //3*10^2
	float f3 = 3e-2;  //3*10^(-2)
	cout << "f2 = " << f2 << endl;
	cout << "f3 = " << f3 << endl;


	/* 字符型 ：字符型变量并不是把字符本身放到内存中存储，而是将对应的ASCII编码放入到存储单元。a-97; A-65 */
	char ch = 'a';  //字符型必须是单引号，且单引号内只能有一个字符
	cout << "定义一个字符型变量：" << ch << endl;
	cout << ch << " 对应的ASCII码为：" << int(ch) << endl;


	/* 转义字符 */
	cout << "\\" << endl;
	cout << "\n" << endl;
	cout << "aa\tHello" << endl; 
	cout << "aaa\tHello" << endl; 
	cout << "aaaa\tHello" << endl;


	/* C风格字符串定义：char strName[];  如 char str1[] = "hello world" */
	char str_C[] = "hello world!";
	cout << "C风格字符串定义 " << str_C << endl;

	/* C++风格字符串定义：string 字符串名;  如 string str2 = "hello world" */
	string str_Cplus = "hello world!";  //需要#include <string>，vs2019以后的版本已经默认引入
	cout << "C++风格字符串定义 " << str_Cplus << endl;
	

	/* bool类型 */
	bool flag1 = true;
	cout << "bool: true = " << flag1 << endl;  // 1

	bool flag2 = false;
	cout << "bool: false = " << flag2 << endl;  //0


	int my1 = 10, my2 = 20, my3 = 30;
	my3 = my2 = my1;  //赋值从右往左看
	cout << my3 << "\t" << my2 << "\t" << my1 << endl; //10 10 10


	/* 数据输入 */

	//整型输入
	int aaa = 0;  //先定义变量用于接收数据
	cout << "请输入整型变量：" << endl;
	cin >> aaa;
	cout << "整型变量 a = " << aaa << endl;

	//浮点型输入
	double d = 0;
	cout << "请输入浮点型变量：" << endl;
	cin >> d;
	cout << "浮点型变量 d = " << d << endl;

	/*	+	-	*	/	%  加减乘除取余
	*	==  !=  >  <  >=  <=  比较运算符
	*	&&  ||  !    逻辑运算符
	*/

	//后置递增
	int a1 = 10;
	a1++; //等价于a = a + 1
	cout << a1 << endl; // 11

	//前置递增
	int b1 = 10;
	++b1;
	cout << b1 << endl; // 11

	//区别
	//前置递增先对变量进行++，再计算表达式
	int a2 = 10;
	int b2 = ++a2 * 10;
	cout << a2 << endl; // 11
	cout << b2 << endl;  // 110

	//后置递增先计算表达式，后对变量进行++
	int a3 = 10;
	int b3 = a3++ * 10;
	cout << a3 << endl; // 11
	cout << b3 << endl;  //100

	/* 指针，空指针、野指针 */

	/* const修饰指针：常量指针 、 指针常量 、 既修饰指针又修饰常量 */
	int aa = 10;
	int bb = 10;

	//常量指针：const修饰的是指针，指针指向可以改，指针指向的值不可以更改
	const int* p1 = &aa;
	p1 = &bb; //正确
	//*p1 = 100;  报错


	//指针常量：const修饰的是常量，指针指向不可以改，指针指向的值可以更改
	int* const p2 = &aa;
	//p2 = &bb; //错误
	*p2 = 100; //正确

	//const既修饰指针又修饰常量
	const int* const p3 = &aa;
	//p3 = &bb; //错误
	//*p3 = 100; //错误


	/* 结构体：自定义数据类型，一组数据类型的集合 
		语法：
			struct 结构体名 { 结构体成员列表 }；

		通过结构体创建变量的方式有三种：
			struct 结构体名 变量名
			struct 结构体名 变量名 = { 成员1值 ， 成员2值...}
			定义结构体时顺便创建变量
	*/

	/* 结构体数组：struct 结构体名 数组名[元素个数] = { {} , {} , ... {} } 
	* 首先定义好 student 结构体
		struct student arr[3]=
		{
			{"张三",18,80 },
			{"李四",19,60 },
			{"王五",20,70 }
		};

		cout << arr[0].name << arr[1].name <<endl;
	
	*/


	/* 结构体指针，用 -> 访问 */
	struct student stu1 = { "李四",19,60 };
	struct student* pstu1 = &stu1;
	pstu1->name = "指针李四";
	cout << "结构体指针 姓名：" << stu1.name << " 年龄： " << stu1.age << " 分数：" << stu1.score << endl;
	cout << "结构体指针 姓名：" << pstu1->name << " 年龄： " << pstu1->age << " 分数：" << pstu1->score << endl;


	/* 结构体嵌套 */
	struct teacher t1;
	t1.id = 10000;
	t1.name = "老王";
	t1.age = 40;

	t1.stu.name = "张同学";
	t1.stu.age = 18;
	t1.stu.score = 100;

	cout << "教师 职工编号： " << t1.id << " 姓名： " << t1.name << " 年龄： " << t1.age << endl;
	cout << "辅导学员 姓名： " << t1.stu.name << " 年龄：" << t1.stu.age << " 考试分数： " << t1.stu.score << endl;


	/* 结构体做函数参数 */

	student stu = { "张三",18,100 };
	//值传递
	printStudent(stu);
	cout << "主函数中 姓名：" << stu.name << " 年龄： " << stu.age << " 分数：" << stu.score << endl;

	//地址传递：同样影响主函数的数据
	printStudent2(&stu);  //将函数中的形参改为指针，可以节省内存空间，而且不会复制新的副本出来。
	cout << "主函数中 姓名：" << stu.name << " 年龄： " << stu.age << " 分数：" << stu.score << endl;


	/* 结构体指针做形参，用const修饰：虽然用指针可以节省内存空间，但当用指针做形参时，有时会因为误操作修改主函数成员的值，使用const变为常量指针做形参就可以防止误操作 */
	student stu2 = { "小吴",25,99 };
	printStudent3(&stu2);


	//静态变量只初始化一次，后续再调用函数也不会被重新初始化
	cout << endl << endl;
	static_test();  //15
	static_test(); //20，第二次调用时，不会对静态变量重新初始化
	//函数内的静态变量随函数执行结束，作用域也随之结束，但静态变量的数据始终在全局区，直到整个程序运行结束才释放。
	

	system("pause");
	return 0;
}


// 注释规范 

/*****************************************************************************
 *  @file     xxx.h
 *  @brief    cpp基础学习笔记
 *
 *  @author   Tod
 *  @version  1.0.1(版本号)
 *  @email    xxxxxx@xxx.com
 *  @date     2022-08-31
 *****************************************************************************/


 /**
  * @brief 函数简要说明
  * @param t1    参数1
  * @param t2    参数2
  *
  * @return 返回说明
  *     false： fail
  *     true： succeed
  */