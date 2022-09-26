#pragma once


/*
类模板的分文件编写
	问题：
	类模板中成员函数创建时机是在调用阶段，导致分文件编写时链接不到

	解决方式2：将声明和实现写到同一个文件中，并更改后缀名为.hpp，hpp是约定的名称，并不是强制

*/
template<typename T1, typename T2>
class Person11
{
public:
	Person11(T1 name, T2 age);
	void showPerson();
public:
	T1 m_Name;
	T2 m_Age;
};
template<typename T1, typename T2>
Person11<T1, T2>::Person11(T1 name, T2 age)
{
	this->m_Name = name;
	m_Age = age;
}

template<typename T1, typename T2>
void Person11<T1, T2>::showPerson()
{
	cout << "姓名：m_Name = " << m_Name << endl;
	cout << "年龄：m_Age = " << m_Age << endl;
}

