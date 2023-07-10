#include<iostream>
using namespace std;
/* 案例说明
每名老师带领5个学生，总共有3名老师，需求如下

设计学生和老师的结构体，其中在老师的结构体中，有老师姓名和一个存放5名学生的数组作为成员

学生的成员有姓名、考试分数，创建数组存放3名老师，通过函数给每个老师及所带的学生赋值

最终打印出老师数据以及老师所带的学生数据。 
*/


//学生结构体
struct Student 
{
	string name;
	int score;

};

//老师结构体
struct Teacher
{
	string name;
	struct Student stuArr[5];
};

void fuzhi(struct Teacher teaArr[], int len)
{
	string teaName = "老师";
	string stuName = "学生";
	string id = "ABCDE";
	for (int i = 0; i < len; i++)
	{
		teaArr[i].name = teaName + id[i];
		for (int j = 0; j < 5; j++)
		{
			teaArr[i].stuArr[j].name = stuName + id[j];
			teaArr[i].stuArr[j].score = rand() % 61 + 40;  
			//一般性：rand() % (b-a+1)+ a ;    就表示  a~b 之间的一个随机整数
			// rand() % a; 表示 0~（a-1）的范围
		}
	}
}

void printTeachers(struct Teacher teaArr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << teaArr[i].name << endl;
		for (int j = 0; j < 5; j++)
		{
			cout << "\t姓名：" << teaArr[i].stuArr[j].name << " 分数：" << teaArr[i].stuArr[j].score << endl;
		}
	}
}

int main2()
{
	
	//假设共有三个老师，每个老师5个学生（结构体数组里嵌套数组的赋值方法）
	struct Teacher teacherArr[3] = {
		{  "老师A", { {"stuA",10},{"stuB",20},{"stuC",30},{"stuD",40},{"stuE",50} }  },
		{  "老师B", { {"stuF",40},{"stuG",60},{"stuH",30},{"stuI",80},{"stuJ",100} }  },
		{  "老师C", { {"stuK",100},{"stuL",30},{"stuM",20},{"stuN",40},{"stuO",60} }  },
	};

	cout << teacherArr[0].name << "\t" << teacherArr[0].stuArr[0].name << teacherArr[0].stuArr[0].score << endl;
	cout << "\t" << teacherArr[0].stuArr[1].name << teacherArr[0].stuArr[1].score << endl;

	cout << teacherArr[1].name << "\t" << teacherArr[1].stuArr[0].name << teacherArr[1].stuArr[0].score << endl;


	//通过函数给每个老师及所带的学生赋值
	srand((unsigned int)time(NULL)); //随机数种子,每次运行随机数不相同，老版本要加头文件 #include <ctime>

	struct Teacher teaArray[3];
	int len = sizeof(teaArray) / sizeof(Teacher);

	fuzhi(teaArray, len);
	printTeachers(teaArray, len);

	system("pause");
	return 0;
}