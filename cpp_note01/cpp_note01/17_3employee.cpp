#include"17_3employee.h"

//普通职工类的函数实现

Employee::Employee(int id, string name, int dId)
{
	m_Id = id;
	m_Name = name;
	m_DeptId = dId;
}

void Employee::showInfo()
{
	cout << "职工编号：" << m_Id 
		 << "\t职工姓名：" << m_Name
		 << "\t岗位：" << this->getDeptName() 
		 << "\t岗位职责：完成经理交给的任务" << endl; //职工所在部门名称编号
}

string Employee::getDeptName()
{
	return string("普通职工");
}