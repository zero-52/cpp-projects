#pragma once
#include<iostream>
using namespace std;

//因为职工有三类：老板，经理，普通职工，建立抽象类，利用多态来管理

//职工抽象基类，成员声明
class AbstractWorker
{
public:

	//显示个人信息
	virtual void showInfo() = 0;
	//获取岗位名称
	virtual string getDeptName() = 0;

	int m_Id; //职工编号
	string m_Name; //职工姓名
	int m_DeptId; //职工所在部门名称编号，用编号是为了后面添加职工方便
};
