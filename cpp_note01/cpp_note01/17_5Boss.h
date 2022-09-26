#pragma once
#include<iostream>
using namespace std;
#include"17_2workers.h"

//老板类 函数声明
class Boss :public AbstractWorker
{
public:
	//构造函数
	Boss(int id, string name, int dId);

	//显示个人信息
	virtual void showInfo();

	//获取岗位名称
	virtual string getDeptName();
};
