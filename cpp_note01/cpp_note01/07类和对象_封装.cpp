
/* 具有相同性质的对象我们抽象为类

	 类中的属性和方法统称为成员
		属性：又称为成员属性或成员变量
		行为：又称为成员函数或成员方法
*/

/* 封装、继承、多态 

	封装： 
		语法：
			class 类名{ 访问权限： 属性 / 行为 };

			//访问权限：都可在类内实现定义，或在类外定义，只是访问权限不同
				公有权限 public：    成员 可在类内访问，也可在类外访问
				保护权限 protected： 成员 可在类内访问，不可在类外访问（儿子可以访问父亲保护成员）
				私有权限 private：   成员 可在类内访问，不可在类外访问（儿子不可访问父亲私有成员）
			//建议将成员属性设置为私有，然后对外提供公有的函数接口
			
		
		将属性和行为作为一个整体，表现事物
		将属性和行为加以权限控制

	链式编程思想
		
	继承：

	多态：


*/
#include<iostream>
using namespace std;


//设计一个圆类，计算其周长

const double PI = 3.14;

class Circle
{
	//访问权限
public:

	//属性
	int c_r;

	//行为
	int zhouchang()
	{
		return 2 * PI * c_r;
	}
};


// 设计一个学生类，属性有姓名和学号，可以给姓名和学号赋值，可以显示学生的姓名和学号
class Student
{
public:
	string name;
	//string gender;   定义两个string 变量为啥报错了？？
	int stu_id;

	void setInfo(string n, int id)
	{
		name = n;
		stu_id = id;
	}
	void showInfo()
	{
		cout << "姓名：" << name << "\t" << "学号：" << stu_id << endl;
	}
};


//不同访问权限
class Person
{
public:
	string name;

protected:
	string car;

private:
	string password;
	void func3();

public:
	void func()
	{
		name = "张三";
		car = "奥迪";
		password = "123321";
	}
	void func2();  //也可以类外实现函数定义
};
//类外实现成员函数定义
void Person::func2()
{
	cout << "类外实现公有成员函数定义" << endl;
}
void Person::func3()  //私有成员函数也可以类外实现
{
	cout << "类外实现私有成员函数定义" << endl;
}



//struct和class的唯一区别是默认权限不同
struct S1
{
	int c;  //结构体成员默认为公有权限
};
class C2
{
	int c;  //类成员默认为私有权限
};


//成员属性设置为私有
	//优点1：将所有成员属性设置为私有，在类内通过方法访问，可以自己控制读写权限
	//优点2：对于写权限，我们可以检测数据写入的有效性

class people
{
private:
	string m_Name; //可读可写  姓名

	int m_Age = 25; //读+写检测  年龄

	string m_Lover; //只写  情人
public:
	//名字写权限
	void setName(string name)
	{
		m_Name = name;
	}
	//名字读权限
	string getName()
	{
		return m_Name;
	}
	//年龄读权限
	int getAge()
	{
		return m_Age;
	}
	//年龄写权限，并检测数据有效性
	void setAge(int age)
	{
		if (age < 0 || age>150)
		{
			m_Age = 0;
			cout << "输入数据无效！" << endl;
			return;
		}
		m_Age = age;
	}
	//情人只写权限
	void setLover(string lover)
	{
		m_Lover = lover;
	}
};


//链式编程思想
class AddTest
{
public:
	int m_Sum;
	
	AddTest addNum(int a)  //值方式返回，每次相当于复制一份新对象出来，已经不是当前对象本身
	{
		this->m_Sum += a;
		return *this;
	}

	AddTest& addNum2(int a) //引用方式返回，相当于给当前对象起了别名
	{
		this->m_Sum += a;
		return *this;
	}
};

void add_test()
{
	AddTest addt1;
	addt1.m_Sum = 0;
	addt1.addNum(10).addNum(10); //值方式返回，由于每次创建了新对象，链式调用实际上只对当前对象执行一次
	cout << "值方式返回，和 = " << addt1.m_Sum << endl;  //10

	AddTest addt2;
	addt2.m_Sum = 0;
	cout << "引用方式返回，和 = " << addt2.addNum(10).addNum(10).m_Sum << endl; //20

	AddTest addt3;
	addt3.m_Sum = 0;
	addt3.addNum2(10).addNum2(10);  //引用方式返回，每次调用的都是当前对象
	cout << "引用方式返回，和 = " << addt3.m_Sum << endl; //20

}




int main7()
{
	//创建对象
	Circle C1;
	C1.c_r = 10; //属性赋值

	//圆的周长为
	cout << "圆的周长为：" << C1.zhouchang() << endl;


	Student stu1;
	//stu1.setInfo("小屋", "男",123456);  //可以用行为对属性赋值
	stu1.name = "小吴";
	stu1.stu_id = 123456;
	stu1.showInfo();

	Student stu2;
	stu2.setInfo("张三", 789789);
	stu2.showInfo();


	//访问权限初体验
	Person p01;
	p01.name = "李四";    //公有权限 类外可访问
	//p01.car = "奔驰";    //保护权限 类外访问不到
	//p01.password = "123"; //私有权限 类外访问不到
	p01.func();


	/** 在C++中 struct和class唯一的区别就在于 默认的访问权限不同

		区别：
			struct 默认权限为公有
			class 默认权限为私有
	*/
	struct S1 s1;
	s1.c = 2;

	C2 c2;
	//c2.c = 2 //错误，55不可访问


	//成员属性设置为私有
	people p1;
	//姓名可读可写
	//p1.m_Name = "王五"; //私有属性不可类外访问
	p1.setName("王五");
	cout << "姓名为：" << p1.getName() << endl;

	//年龄读
	cout << "年龄为：" << p1.getAge() << endl;
	//年龄写
	p1.setAge(2000);
	p1.setAge(20);
	cout << "年龄为：" << p1.getAge() << endl;

	//情人只写，没有读权限
	p1.setLover("小红");


	/* 链式编程思想 */
	add_test();
	return 0;

}