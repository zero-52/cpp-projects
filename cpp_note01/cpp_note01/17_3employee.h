#pragma once
#include<iostream>
using namespace std;
#include "17_2workers.h"

//普通职工头文件，成员声明
class Employee :public AbstractWorker
{
public:
	//构造函数
	Employee(int id, string name, int dId);

	//显示个人信息
	virtual void showInfo();

	//获取岗位名称
	virtual string getDeptName();
};