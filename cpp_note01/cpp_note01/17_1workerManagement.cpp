 
/*****************************************************************************
 *  @brief	17_1 职工管理类函数实现
 *		负责实现：
 *			与用户的沟通界面菜单
 *			对职工增删改查操作
 *			与文件的读写交互
 *
 *****************************************************************************/

#include"17_1workerManagement.h"

//职工管理类的函数实现
WorkerManagement::WorkerManagement()
{
	//初始化属性
	//this->m_workersNum = 0;//职工人数初始化为0
	//this->m_workersArr = NULL;
	
	//初始化属性改进
	//1、文件不存在
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	if (!ifs.is_open())
	{
		//cout << "文件不存在，初始化属性" << endl;
		
		this->m_workersNum = 0;
		this->m_workersArr = NULL;
		this->m_flag_fileIsEmpty = true;  //文件不存在

		ifs.close();
		return;
	}

	//2、文件存在，数据为空
	// c++判断文件是否为空，可以读入一个字符，判断是否为文件结束符
	//文件结束符是文件最后一个字符的下一个字符0xFF，eof() 读到文件结束符0xFF时返回true。
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//cout << "文件存在，但文件为空文件" << endl;

		this->m_workersNum = 0;
		this->m_workersArr = NULL;
		this->m_flag_fileIsEmpty = true;  

		ifs.close();
		return;
	}

	//3、文件存在且有数据
	int num = this->get_worker_num();
	//cout << "已有职工人数：" << num << endl;
	this->m_workersNum = num;  //文件存在时更新人数

	//开辟空间
	this->m_workersArr = new AbstractWorker * [this->m_workersNum];
	//将文件中的已有数据更新到数组
	this->init_workerArr();

	//测试文件存在且有数据时，代码是否正常
	//for (int i = 0; i < this->m_workersNum; i++)
	//{
	//	//输出乱码的：打开文本文档，另存为，将编码格式改成ANSI，保存，替换
	//	cout << this->m_workersArr[i]->m_Id << " "
	//		<< this->m_workersArr[i]->m_Name << " "
	//		<< this->m_workersArr[i]->m_DeptId << endl;
	//}

	this->m_flag_fileIsEmpty = false;

}

void WorkerManagement::show_Menu()
{
	cout << "****************************************" << endl;
	cout << "*******  欢迎使用职工管理系统  *********" << endl;
	cout << "**********   0：退出管理系统  **********" << endl;
	cout << "**********   1：增加职工信息  **********" << endl;
	cout << "**********   2：显示职工信息  **********" << endl;
	cout << "**********   3：删除离职职工  **********" << endl;
	cout << "**********   4：修改职工信息  **********" << endl;
	cout << "**********   5：查找职工信息  **********" << endl;
	cout << "**********   6：按照编号排序  **********" << endl;
	cout << "**********   7：清空所有文档  **********" << endl;
	cout << "****************************************" << endl;
	cout << endl;

}
 
//退出系统
void WorkerManagement::exit_system()
{
	cout << "已退出职工管理系统，欢迎再次使用" << endl;
	system("pause");  //按任意键退出
	exit(0);  //退出程序
}

/*****************************************************************************
 *  @brief	增加职工信息
 *	用户在批量创建时，可能会创建不同种类的职工
 *	如果想将所有不同种类的员工都放入到一个数组中，可以将所有员工的指针维护到一个数组里
 *	如果想在程序中维护这个不定长度的数组，可以将数组创建到堆区，并利用 AbstractWorker** 的指针维护
 *****************************************************************************/

void WorkerManagement::add_worker_info()
{
	cout << "请输入添加职工的数量" << endl;
	int addNum = 0;
	cin >> addNum;

	if (addNum > 0)
	{
		//添加
		int newWorkersNum = this->m_workersNum + addNum; //新人数 = 原来人数 + 新增数量
		
		//因为这是动态的数组，所以需要开辟新空间
		//AbstractWorker* newSpaceArr = new AbstractWorker[newWorkersNum]; //错误，不能使用抽象类创建对象，这里数组里表示AbstractWorker类型的对象
		
		AbstractWorker** newSpaceArr = new AbstractWorker * [newWorkersNum]; //但可以用抽象类创建指针类型，这里数组里表示AbstractWorker*类型的对象
		//二级指针，这里一级用于接收 new 指针，二级因为抽象类不能实例化，所以创建类指针

		//将原来空间下的数据，拷贝到新空间下,先判断原先有无数据
		if (this->m_workersNum != NULL)
		{
			//将原数据拷贝到新空间下
			for (int i = 0; i < this->m_workersNum; i++)
			{
				newSpaceArr[i] = this->m_workersArr[i];
			}
		}

		//把新数据添加上
		for (int i = 0; i < addNum; i++)
		{
			int id;
			string name;
			int deptId;
			cout << "请输入第【" << i + 1 << "】个新增职工的信息" << endl;
			cout << "请输入第【" << i + 1 << "】个新增职工的id：" << endl;
			cin >> id;
			
			cout << "请输入第【" << i + 1 << "】个新增职工的姓名：" << endl;
			cin >> name;

			cout << "请选择第【" << i + 1 << "】个新增职工的岗位：" << endl;
			cout << "1 - 普通；  2 - 经理；  3 - 老板" << endl;
			cin >> deptId;

			AbstractWorker* workerPtr = NULL;
			switch (deptId)
			{
			case 1:
				workerPtr = new Employee(id, name, deptId);
				break;
			case 2:
				workerPtr = new Manager(id, name, deptId);
				break;
			case 3:
				workerPtr = new Boss(id, name, deptId);
				break;
			default:
				break;
			}
			newSpaceArr[this->m_workersNum + i] = workerPtr;
			
		}
		
		//释放原有空间
		delete[] this->m_workersArr;

		//更改新空间的指向
		this->m_workersArr = newSpaceArr;

		//更新职工人数
		this->m_workersNum = newWorkersNum;

		//更新文件不为空的标志
		this->m_flag_fileIsEmpty = false;

		//提示添加成功
		cout << "添加成功" << addNum << "个职工" << endl;

		//保存到文件
		this->save_to_file();

	}
	else
	{
		//不添加，输入有误
		cout << "输入有误" << endl;
	}

	//按任意键后，清屏返回上级目录
	system("pause");
	system("cls");
}


/*****************************************************************************
 *  @brief	文件交互 - 写文件
 *	功能描述：对文件进行读写
 *	在上一个添加功能中，我们只是将所有的数据添加到了内存中，一旦程序结束就无法保存了
 *	因此文件管理类中需要一个与文件进行交互的功能，对于文件进行读写操作
 *****************************************************************************/

void WorkerManagement::save_to_file()
{
	fstream ofs;
	ofs.open(FILENAME, ios::out);  //写文件

	//将每个人的数据写入到文件中
	for (int i = 0; i < this->m_workersNum; i++)
	{
		cout << "************" << endl;
		ofs << this->m_workersArr[i]->m_Id << " "
			<< this->m_workersArr[i]->m_Name << " "
			<< this->m_workersArr[i]->m_DeptId << endl;
	}
	ofs.close();

}

/*****************************************************************************
 *  @brief	文件交互 - 读文件
 *	功能描述：将文件中的内容读取到程序中
 *	虽然我们实现了添加职工后保存到文件的操作，但是每次开始运行程序，并没有将文件中数据读取到程序中
 *	而我们的程序功能中还有清空文件的需求
 *		因此构造函数初始化数据的情况分为三种
 *			第一次使用，文件未创建
 *			文件存在，但是数据被用户清空
 *			文件存在，并且保存职工的所有数据
 *****************************************************************************/

//读文件在构造函数中完成


//统计存在文件中已有的人数
int WorkerManagement::get_worker_num()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;  //临时保存读出的数据
	string name;
	int deptId;

	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> deptId)
	{
		num++;
	}
	return num;
}


//初始化数组，根据职工的数据以及职工数据，初始化WorkerManagement中的 m_workersArr 指针
void WorkerManagement::init_workerArr()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int deptId;

	int index = 0; //索引编号
	while (ifs >> id && ifs >> name && ifs >> deptId)
	{
		AbstractWorker* worker = NULL;
		if (deptId == 1) //普通员工
		{
			worker = new Employee(id, name, deptId);

		}
		else if (deptId == 2)
		{
			worker = new Manager(id, name, deptId);
		}
		else if (deptId == 3)
		{
			worker = new Boss(id, name, deptId);
		}

		//放到数组中
		this->m_workersArr[index] = worker;
		index++;
	}
	ifs.close();
}


//显示职工信息
void WorkerManagement::show_worker_info()
{
	if (this->m_flag_fileIsEmpty)
	{
		cout << "文件不存在或数据为空" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_workersNum; i++)
		{
			this->m_workersArr[i]->showInfo();
		}
	}
	system("pause");
	system("cls");
}

//判断职工是否存在，存在返回索引，不存在返回-1
int WorkerManagement::worker_is_exist(int id)
{
	int index = -1;
	for (int i = 0; i < this->m_workersNum; i++)
	{
		if (this->m_workersArr[i]->m_Id == id)
		{
			index = i;
			break;
		}
	}
	return index;
}

//重载
int WorkerManagement::worker_is_exist(string name)
{
	int index = -1;
	for (int i = 0; i < this->m_workersNum; i++)
	{
		if (this->m_workersArr[i]->m_Name == name)
		{
			index = i;
			break;
		}
	}
	return index;
}

//删除职工信息
void WorkerManagement::del_worker_info()
{
	if (this->m_flag_fileIsEmpty)
	{
		cout << "文件不存在或数据为空" << endl;
		return;
	}
	else
	{
		cout << "请输入按编号删除还是按名字删除：" << endl;
		cout << "1 - 编号删除，2 - 名字删除" << endl;
		int id;
		string name;
		int choice;
		cin >> choice;
		if (choice == 1)
		{
			cout << "请输入要删除的id" << endl;
			cin >> id;
			int index = this->worker_is_exist(id);
			if (index != -1)
			{
				//this->m_workersArr[index] = this->m_workersArr[this->m_workersNum];
				for (int i = index; i < this->m_workersNum; i++)
				{
					this->m_workersArr[i] = this->m_workersArr[i + 1];
				}
				this->m_workersNum--;

				this->save_to_file();
				cout << "删除成功" << endl;
			}
			else
			{
				cout << "删除失败，查无此人" << endl;
			}
			//删除后如果文件为空，将标志置位
			if (this->m_workersNum == 0)
			{
				this->m_flag_fileIsEmpty = true;
			}
			
		}
		else
		{
			cout << "并没有开发，请用编号查询" << endl;
		}
	}
	system("pause");
	system("cls");
	
}


//修改职工信息
void WorkerManagement::modify_worker_info()
{
	if (this->m_flag_fileIsEmpty)
	{
		cout << "文件不存在或数据为空" << endl;
		return;
	}
	else
	{
		cout << "请输入要修改的职工编号：" << endl;
		
		cout << "请输入要删除的id" << endl;
		int id;
		cin >> id;

		int index = this->worker_is_exist(id);
		if (index != -1)
		{
			delete this->m_workersArr[index];

			int newId;
			string newName;
			int newDept;

			cout << "查找到职工，请输入新id：" << endl;
			cin >> newId;
			
			cout << "查找到职工，请输入新名字：" << endl;
			cin >> newName;
			
			cout << "查找到职工，请输入新岗位：" << endl;
			cout << "1 - 普通职工，2 - 经理，3 - 老板" << endl;
			cin >> newDept;

			AbstractWorker* worker = NULL;
			switch (newDept)
			{
			case 1:
				worker = new Employee(newId, newName, newDept);
			case 2:
				worker = new Manager(newId, newName, newDept);
			case 3:
				worker = new Boss(newId, newName, newDept);
			default:
				break;
			}
			//更新数据到数组中
			this->m_workersArr[index] = worker;

			this->save_to_file();

			cout << "修改成功" << endl;
		}
		else
		{
			cout << "修改失败，查无此人" << endl;
		}
	}
	system("pause");
	system("cls");
}

//查找职工
void WorkerManagement::find_worker_info()
{
	if (this->m_flag_fileIsEmpty)
	{
		cout << "文件不存在或数据为空" << endl;
		return;
	}
	else
	{
		cout << "请输入按编号查找还是按名字查找：" << endl;
		cout << "1 - 编号查找，2 - 名字查找" << endl;
		int id;
		string name;
		int choice;
		cin >> choice;
		if (choice == 1)
		{
			cout << "请输入要查找的id" << endl;
			cin >> id;
			int index = this->worker_is_exist(id);
			if (index != -1)
			{
				cout << "===查找成功===" << endl;
				this->m_workersArr[index]->showInfo();
			}
			else
			{
				cout << "查找失败，查无此人" << endl;
			}
			
			return;

		}
		else if (choice == 2)
		{
			cout << "请输入要查找的姓名" << endl;
			cin >> name;
			int index = this->worker_is_exist(name);
			if (index != -1)
			{
				cout << "===查找成功===" << endl;
				for (int i = index; i < this->m_workersNum; i++)//防止重名，从第一个查找名往后遍历
				{
					if (m_workersArr[i]->m_Name == name)
					{
						this->m_workersArr[i]->showInfo();
					}
				}
				
				
			}
			else
			{
				cout << "查找失败，查无此人" << endl;
			}
			return;
		}
		else 
		{
			cout << "输入有误" << endl;
		}
	}
	system("pause");
	system("cls");
	
}

//选择排序算法
//第一次从待排序的数据元素中选出最小（或最大）的一个元素，存放在序列的起始位置，
//然后再从剩余的未排序元素中寻找到最小（大）元素，然后放到已排序的序列的末尾。
void WorkerManagement::sort()
{
	if (this->m_flag_fileIsEmpty)
	{
		cout << "文件不存在或数据为空" << endl;
		system("pause");
		system("cls");
		return;
	}
	else
	{
		cout << "请输入排序方式：" << endl;
		cout << "1 - 按编号升序，2 - 按编号降序" << endl;

		int choice = 0;
		cin >> choice;

		for (int i = 0; i < this->m_workersNum; i++)
		{
			int minOrMax = i;//声明最大值最小值下标

			for (int j = i + 1; j < this->m_workersNum; j++)
			{
				if (choice == 1)
				{
					//升序
					if (this->m_workersArr[minOrMax]->m_Id > this->m_workersArr[j]->m_Id)
						minOrMax = j;  //最小值下标
				}
				else
				{
					//降序
					if (this->m_workersArr[minOrMax]->m_Id < this->m_workersArr[j]->m_Id)
						minOrMax = j; //最大值下标
				}
			}

			if (i != minOrMax)
			{
				AbstractWorker* temp = this->m_workersArr[i];
				this->m_workersArr[i] = this->m_workersArr[minOrMax];
				this->m_workersArr[minOrMax] = temp;
			}

		}
		cout << "排序成功，结果为：" << endl;
		this->save_to_file();
		this->show_worker_info();

	}
}

//清空所有信息
void WorkerManagement::clear_all_info()
{
	cout << "确认清空吗？";
	cout << "1-确认，2-返回" << endl;
	int choice;
	cin >> choice;
	if (choice == 1)
	{
		//清空文件
		ofstream ofs;
		ofs.open(FILENAME, ios::trunc);//trunc，删除文件后再重新创建
		ofs.close();

		if (this->m_workersArr != NULL) //数组不为空，把数组中的每个堆区内容释放干净，再释放数组
		{
			for (int i = 0; i < this->m_workersNum; i++)
			{
				//释放堆区的每个职工对象
				delete this->m_workersArr[i];
				this->m_workersArr[i] = NULL;
			}

			//释放堆区数组指针
			delete[] this->m_workersArr;
			this->m_workersNum = 0; //职工数量清零
			this->m_flag_fileIsEmpty = true; //标志
		}
		cout << "清空成功" << endl;

	}	
	
	system("pause");
	system("cls");
	
}

//析构函数实现
WorkerManagement::~WorkerManagement()
{

}