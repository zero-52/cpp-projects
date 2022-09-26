#pragma once
#include<iostream>
using namespace std;

/*
类模板的分文件编写
	问题：
	类模板中成员函数创建时机是在调用阶段，导致分文件编写时链接不到

	解决方式1：直接包含.cpp源文件
*/
template<typename T1, typename T2>
class Person10
{
public:
	Person10(T1 name, T2 age);
	void showPerson();
public:
	T1 m_Name;
	T2 m_Age;
};
