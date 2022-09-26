/**
* 职工管理系统可以用来管理公司内所有员工的信息

	本教程主要利用C++来实现一个基于多态的职工管理系统

	公司中职工分为三类：普通员工、经理、老板，显示信息时，需要显示职工编号、职工姓名、职工岗位、以及职责

	普通员工职责：完成经理交给的任务

	经理职责：完成老板交给的任务，并下发任务给员工

	老板职责：管理公司所有事务

	管理系统中需要实现的功能如下：

		退出管理程序：退出当前管理系统
		增加职工信息：实现批量添加职工功能，将信息录入到文件中，职工信息为：职工编号、姓名、部门编号
		显示职工信息：显示公司内部所有职工的信息
		删除离职职工：按照编号删除指定的职工
		修改职工信息：按照编号修改职工个人信息
		查找职工信息：按照职工的编号或者职工的姓名进行查找相关的人员信息
		按照编号排序：按照职工编号，进行排序，排序规则由用户指定
		清空所有文档：清空文件中记录的所有职工信息 （清空前需要再次确认，防止误删）

	分析：职工分为三类，可以将三类职工抽象到一个类中，利用多态管理不同的职工种类
*/

#include<iostream>
#include"17_1workerManagement.h"
#include"17_2workers.h"
#include"17_3employee.h"
#include"17_4manager.h"
#include"17_5Boss.h"

void test()
{
	/*Employee employee(1,"张三",2);
	employee.showInfo(); 为了实现多态，要用父类指针指向子类对象 */

	AbstractWorker* worker = NULL;
	worker = new Employee(1, "张三", 1);
	worker->showInfo();
	delete worker;

	cout << endl;
	worker = new Manager(2, "李四", 2);
	worker->showInfo();
	delete worker;

	cout << endl;
	worker = new Boss(3, "王五", 3);
	worker->showInfo();
	delete worker;
}


int main17()
{
	WorkerManagement wm;
	
	int choice = 0;
	while (true)
	{
		//test();

		wm.show_Menu();
		cout << "请输入您的需求：" << endl;
		cin >> choice;

		switch (choice)
		{
		case 0:  
			wm.exit_system();
			break;
		case 1:  // 如果case分支中有大段代码，建议中花括号括起来
			wm.add_worker_info();   //地址传递，需要能修改主函数的实参
			break;
		case 2:
			wm.show_worker_info();
			break;
		case 3:
			wm.del_worker_info();
			break;
		case 4:
			wm.modify_worker_info();
		case 5:
			wm.find_worker_info();
			break;
		case 6:
			wm.sort();
			break;
		case 7:
			wm.clear_all_info();
			break;

		default:
			system("cls");
			break;
		}
	}


	return 0;
	
}