#include "18_person10.h"

/*
类模板的分文件编写
	问题：
	类模板中成员函数创建时机是在调用阶段，导致分文件编写时链接不到

	解决方式1：直接包含.cpp源文件
*/
template<typename T1, typename T2>
Person10<T1, T2>::Person10(T1 name, T2 age)
{
	this->m_Name = name;
	m_Age = age;
}

template<typename T1, typename T2>
void Person10<T1, T2>::showPerson()
{
	cout << "姓名：m_Name = " << m_Name << endl;
	cout << "年龄：m_Age = " << m_Age << endl;
}