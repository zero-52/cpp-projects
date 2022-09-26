#include<iostream>
using namespace std;

//添加联系人：向通讯录中添加新人，信息包括（姓名、性别、年龄、联系电话、家庭住址）最多记录1000人
//显示联系人：显示通讯录中所有联系人信息
//删除联系人：按照姓名进行删除指定联系人
//查找联系人：按照姓名查看指定联系人信息
//修改联系人：按照姓名重新修改指定联系人
//清空联系人：清空通讯录中所有信息
//退出通讯录：退出当前使用的通讯录

#define MAX		1000

//联系人信息结构体
struct PersonInfo
{
	string name;
	int gender; //1男，2女
	int age;
	string phone;
	string address;

};

//通讯录结构体
struct AddressBooks
{
	struct PersonInfo personArr[MAX];
	int personCount;  //通讯录中当前人员个数

};

void showMenu(void)
{
	cout << "\n******* 通讯录系统 ****" << endl << endl;
	cout << "\t1：添加联系人" << endl;
	cout << "\t2：显示联系人" << endl;
	cout << "\t3：删除联系人" << endl;
	cout << "\t4：查找联系人" << endl;
	cout << "\t5：修改联系人" << endl;
	cout << "\t6：清空联系人" << endl;
	cout << "\t0：退出系统" << endl;
}

void addInfo(struct AddressBooks * addrBooks)
{
	if (addrBooks->personCount == MAX)
	{
		cout << "通讯录已满，不可添加！！" << endl;
		return;
	}
	string name;
	cout << "请输入姓名：" << endl;
	cin >> name;
	addrBooks->personArr[addrBooks->personCount].name = name;

	
	cout << "请输入性别：" << endl;
	cout << "1--男 , 2--女" << endl;
	int sex = 0;
	while (true)
	{
		cin >> sex;
		if (sex == 1 || sex == 2)  //性别只有两种，要设置限制
		{
			addrBooks->personArr[addrBooks->personCount].gender = sex;
			break;
		}
		cout << "输入错误！请重新输入：" << endl;
	}
	
	cout << "请输入年龄：" << endl;
	int age = 0;
	while (true)
	{
		cin >> age;
		if (age > 0 && age <= 120)
		{
			addrBooks->personArr[addrBooks->personCount].age = age;
			break;
		}
		cout << "年龄输入有误，请重新输入：" << endl;
	}

	cout << "请输入电话：" << endl;
	cin >> addrBooks->personArr[addrBooks->personCount].phone;

	cout << "请输入住址：" << endl;
	cin >> addrBooks->personArr[addrBooks->personCount].address;

	addrBooks->personCount++;
	
	cout << "添加成功" << endl;

	system("pause"); //显示 请按任意键继续…
	system("cls"); // 清空屏幕

}

void showInfo(struct AddressBooks* addrBooks)
{
	if (addrBooks->personCount == 0)
	{
		cout << "通讯录为空！！" << endl;
		return;
	}
	for (int i = 0; i < addrBooks->personCount; i++)
	{
		cout << "姓名：" << addrBooks->personArr[i].name << "\t";
		cout << "性别：" << ( addrBooks->personArr[i].gender == 1?"男": "女") << "\t";
		cout << "年龄：" << addrBooks->personArr[i].age << "\t";
		cout << "电话：" << addrBooks->personArr[i].phone << "\t";
		cout << "住址：" << addrBooks->personArr[i].address << endl;
	}
	cout << "显示成功" << addrBooks->personCount << endl;
	system("pause");
	system("cls");
}

//删除联系人
void delInfo(struct AddressBooks* addrBooks)
{
	if (addrBooks->personCount == 0)
	{
		cout << "通讯录为空！！" << endl;
		return;
	}
	cout << "请输入要删除联系人的名字：" << endl;
	string name;
	cin >> name;
	for (int i = 0; i < addrBooks->personCount; i++)
	{
		if (name == addrBooks->personArr[i].name)
		{
			addrBooks->personArr[i] = addrBooks->personArr[addrBooks->personCount-1];
			addrBooks->personCount--;
			cout << "删除成功！" << endl;
		}
		else
		{
			cout << "未找到该联系人！" << endl;
		}
	}
	system("pause");
	system("cls");
}

//查找联系人
void findInfo(struct AddressBooks* addrBooks)
{
	if (addrBooks->personCount == 0)
	{
		cout << "通讯录为空！！" << endl;
		return;
	}
	cout << "请输入要查找联系人的名字：" << endl;
	string name;
	cin >> name;
	for (int i = 0; i < addrBooks->personCount; i++)
	{
		if (name == addrBooks->personArr[i].name)
		{
			cout << "\t姓名：" << addrBooks->personArr[i].name << "\t 性别：" << addrBooks->personArr[i].gender << "\t年龄：" << addrBooks->personArr[i].age
				<< "\t电话：" << addrBooks->personArr[i].phone << "\t住址：" << addrBooks->personArr[i].address << endl;
			cout << "查找成功！" << endl;
		}
		else
		{
			cout << "未找到该联系人！" << endl;
		}
	}
	system("pause");
	system("cls");
}

//修改联系人
void modifyInfo(struct AddressBooks* addrBooks)
{
	if (addrBooks->personCount == 0)
	{
		cout << "通讯录为空！！" << endl;
		return;
	}
	cout << "请输入要修改联系人的名字：" << endl;
	string name;
	cin >> name;
	for (int i = 0; i < addrBooks->personCount; i++)
	{
		if (name == addrBooks->personArr[i].name)
		{
			cout << "请输入姓名：" << endl;
			cin >> name;
			addrBooks->personArr[i].name = name;


			cout << "请输入性别：" << endl;
			cout << "1--男 , 2--女" << endl;
			int sex = 0;
			while (true)
			{
				cin >> sex;
				if (sex == 1 || sex == 2)  //性别只有两种，要设置限制
				{
					addrBooks->personArr[i].gender = sex;
					break;
				}
				cout << "输入错误！请重新输入：" << endl;
			}

			cout << "请输入年龄：" << endl;
			int age = 0;
			while (true)
			{
				cin >> age;
				if (age > 0 && age <= 120)
				{
					addrBooks->personArr[i].age = age;
					break;
				}
				cout << "年龄输入有误，请重新输入：" << endl;
			}

			cout << "请输入电话：" << endl;
			cin >> addrBooks->personArr[i].phone;

			cout << "请输入住址：" << endl;
			cin >> addrBooks->personArr[i].address;
			cout << "修改成功！" << endl;
		}
		else
		{
			cout << "未找到该联系人！" << endl;
		}
	}
	system("pause");
	system("cls");
}

//清空联系人
void clearInfo(struct AddressBooks* addrBooks)
{
	addrBooks->personCount = 0;  // 逻辑清空，不需要把所有数据都抹除
	cout << "通讯录已清空！" << endl;
	system("pause");
	system("cls");

}

int main4()
{
	struct AddressBooks addrBooks;
	addrBooks.personCount = 0; //初始化联系人数量

	short cmd = 0;
	while (true)
	{
		// 显示菜单
		showMenu();


		cout << "请输入一条指令：" << endl;
		cin >> cmd;
		switch (cmd)
		{
		case 1:  // 如果case分支中有大段代码，建议中花括号括起来
			addInfo(&addrBooks);   //地址传递，需要能修改主函数的实参
			break;
		case 2:
			showInfo(&addrBooks);
			break;
		case 3:
			delInfo(&addrBooks);
			break;
		case 4:
			findInfo(&addrBooks);
			break;
		case 5:
			modifyInfo(&addrBooks);
			break;
		case 6:
			clearInfo(&addrBooks);
			break;
		case 0:
			cout << "欢迎再次使用" << endl;
			system("pause");
			return 0;

		default:
			break;
		}
	}
	

	return 0;

}