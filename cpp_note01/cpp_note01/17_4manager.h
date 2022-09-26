#pragma once
#include<iostream>
using namespace std;
#include"17_2workers.h"

//经理类职工，成员声明
class Manager :public AbstractWorker
{
public:
	//构造函数
	Manager(int id, string name, int dId);

	//显示个人信息
	virtual void showInfo();

	//获取岗位名称
	virtual string getDeptName();
};
