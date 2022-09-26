/***** 案例-员工分组

案例描述
	公司今天招聘了10个员工（ABCDEFGHIJ），10名员工进入公司之后，需要指派员工在那个部门工作
	员工信息有: 姓名 工资组成；部门分为：策划、美术、研发
	随机给10名员工分配部门和工资
	通过multimap进行信息的插入 key(部门编号) value(员工)
	分部门显示员工信息

实现步骤
	1. 创建10名员工，放到vector中
	2. 遍历vector容器，取出每个员工，进行随机分组
	3. 分组后，将员工部门编号作为key，具体员工作为value，放入到multimap容器中
	4. 分部门显示员工信息
*/
#include<iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;

#define CEHUA	0
#define MEISHU	1
#define YANFA	2

class Staff
{
public:
	Staff(string name, int salary)
	{
		m_Name = name;
		m_Salary = salary;
	}
	string m_Name;
	int m_Salary;
};

//创建员工
void createStaff(vector<Staff>& vec)
{
	string id = "ABCDEFGHIJ";
	string str = "员工";
	for (int i = 0; i < 10; i++)
	{
		string name = str + id[i];
		int salary = rand() % 91 + 10; //年薪10~100w

		Staff sta(name, salary);

		vec.push_back(sta);
	}
}

//随机分配员工所在部门
void setDepartment(vector<Staff>& vec, multimap<int, Staff>& mmap)
{
	for (vector<Staff>::iterator it = vec.begin(); it != vec.end(); it++)
	{
		//部门随机
		int deptId = rand() % 3;//0 1 2

		//在multimap中插入 key 和 value
		mmap.insert(make_pair(deptId, *it));
	}
}

//展示各个部门的员工信息
void showStaff(multimap<int, Staff>& mmap)
{
	cout << "策划部门员工：" << endl;

	multimap<int, Staff>::iterator mpos = mmap.find(CEHUA); //记录策划部门第一个员工位置
	int count = mmap.count(CEHUA); //统计策划部门员工个数
	int index = 0;
	for (; mpos != mmap.end() && index < count; mpos++, index++)
	{
		cout << "姓名：" << mpos->second.m_Name << " 工资：" << mpos->second.m_Salary << endl;
	}

	cout << endl << "美术部门员工：" << endl;

	mpos = mmap.find(MEISHU); //记录策划部门第一个员工位置
	count = mmap.count(MEISHU); //统计策划部门员工个数
	index = 0;
	for (; mpos != mmap.end() && index < count; mpos++, index++)
	{
		cout << "姓名：" << mpos->second.m_Name << " 工资：" << mpos->second.m_Salary << endl;
	}

	cout << endl << "研发部门员工：" << endl;

	mpos = mmap.find(YANFA); //记录策划部门第一个员工位置
	count = mmap.count(YANFA); //统计策划部门员工个数
	index = 0;
	for (; mpos != mmap.end() && index < count; mpos++, index++)
	{
		cout << "姓名：" << mpos->second.m_Name << " 工资：" << mpos->second.m_Salary << endl;
	}
}

int main24_3()
{
	srand((unsigned int)time(NULL));
	vector<Staff> vecStaff;
	//创建员工
	createStaff(vecStaff);

	//测试
	//for (int i = 0; i < vecStaff.size(); i++)
	//{
	//	cout << vecStaff[i].m_Name << "  "<< vecStaff[i].m_Salary << endl;
	//}

	//员工分组
	multimap<int, Staff> mapStaff;
	setDepartment(vecStaff, mapStaff);

	//分组显示员工
	showStaff(mapStaff);
	return 0;
}