#include"17_5Boss.h"

//老板类 函数实现
Boss::Boss(int id, string name, int dId)
{
	m_Id = id;
	m_Name = name;
	m_DeptId = dId;
}

//显示个人信息
void Boss::showInfo()
{
	cout << "职工编号：" << m_Id
		<< "\t职工姓名：" << m_Name
		<< "\t岗位：" << this->getDeptName()
		<< "\t岗位职责：管理公司所有事务" << endl; //职工所在部门名称编号
}

//获取岗位名称
string Boss::getDeptName()
{
	return string("老板");
}