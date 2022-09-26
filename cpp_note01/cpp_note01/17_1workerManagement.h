#pragma once
#include<iostream>
using namespace std;
#include"17_2workers.h"
#include"17_3employee.h"
#include"17_4manager.h"
#include"17_5Boss.h"

#include<fstream>
#define  FILENAME	"17workers_data.txt"

//职工管理类，负责实现：
			//与用户的沟通界面菜单
			//对职工增删改查操作
			//与文件的读写交互

//职工管理类，成员声明，实现在cpp文件中
class WorkerManagement
{
public:

	//构造函数
	WorkerManagement();

	//展示菜单
	void show_Menu();

	//退出系统
	void exit_system();

	/* 增加职工信息：由于职工有三种，可以将职工放入同一数组，因数组要同类型数据，故用父类类型 */
	//记录职工人数
	int m_workersNum;
	//职工数组指针
	AbstractWorker** m_workersArr;  //抽象类不能实例化，但能创建指针，而数组里的类型也为指针类型，故为二级指针
	//二级指针，后面要使用 AbstractWorker** newSpace = new AbstractWorker * [new_workersNum];

	//增加职工
	void add_worker_info();

	//文件交互：保存到文件
	void save_to_file();

	//读之前判断文件是否为空
	bool m_flag_fileIsEmpty;

	//统计存在的文件中已有的人数
	int get_worker_num();

	//文件交互：从文件读
	void read_from_file();

	//初始化数组
	void init_workerArr();

	//显示职工信息
	void show_worker_info();

	//判断职工是否存在，存在返回索引，不存在返回-1
	int worker_is_exist(int id);
	int worker_is_exist(string name);

	//删除职工信息
	void del_worker_info();

	//修改职工信息
	void modify_worker_info();

	//查找职工：编号查找，姓名查找
	void find_worker_info();

	//排序函数
	void sort();

	//清空文件操作
	void clear_all_info();

	//析构函数
	~WorkerManagement();
};