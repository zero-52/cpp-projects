#include<iostream>
using namespace std;
/* ����˵��
ÿ����ʦ����5��ѧ�����ܹ���3����ʦ����������

���ѧ������ʦ�Ľṹ�壬��������ʦ�Ľṹ���У�����ʦ������һ�����5��ѧ����������Ϊ��Ա

ѧ���ĳ�Ա�����������Է���������������3����ʦ��ͨ��������ÿ����ʦ��������ѧ����ֵ

���մ�ӡ����ʦ�����Լ���ʦ������ѧ�����ݡ� 
*/


//ѧ���ṹ��
struct Student 
{
	string name;
	int score;

};

//��ʦ�ṹ��
struct Teacher
{
	string name;
	struct Student stuArr[5];
};

void fuzhi(struct Teacher teaArr[], int len)
{
	string teaName = "��ʦ";
	string stuName = "ѧ��";
	string id = "ABCDE";
	for (int i = 0; i < len; i++)
	{
		teaArr[i].name = teaName + id[i];
		for (int j = 0; j < 5; j++)
		{
			teaArr[i].stuArr[j].name = stuName + id[j];
			teaArr[i].stuArr[j].score = rand() % 61 + 40;  
			//һ���ԣ�rand() % (b-a+1)+ a ;    �ͱ�ʾ  a~b ֮���һ���������
			// rand() % a; ��ʾ 0~��a-1���ķ�Χ
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
			cout << "\t������" << teaArr[i].stuArr[j].name << " ������" << teaArr[i].stuArr[j].score << endl;
		}
	}
}

int main2()
{
	
	//���蹲��������ʦ��ÿ����ʦ5��ѧ�����ṹ��������Ƕ������ĸ�ֵ������
	struct Teacher teacherArr[3] = {
		{  "��ʦA", { {"stuA",10},{"stuB",20},{"stuC",30},{"stuD",40},{"stuE",50} }  },
		{  "��ʦB", { {"stuF",40},{"stuG",60},{"stuH",30},{"stuI",80},{"stuJ",100} }  },
		{  "��ʦC", { {"stuK",100},{"stuL",30},{"stuM",20},{"stuN",40},{"stuO",60} }  },
	};

	cout << teacherArr[0].name << "\t" << teacherArr[0].stuArr[0].name << teacherArr[0].stuArr[0].score << endl;
	cout << "\t" << teacherArr[0].stuArr[1].name << teacherArr[0].stuArr[1].score << endl;

	cout << teacherArr[1].name << "\t" << teacherArr[1].stuArr[0].name << teacherArr[1].stuArr[0].score << endl;


	//ͨ��������ÿ����ʦ��������ѧ����ֵ
	srand((unsigned int)time(NULL)); //���������,ÿ���������������ͬ���ϰ汾Ҫ��ͷ�ļ� #include <ctime>

	struct Teacher teaArray[3];
	int len = sizeof(teaArray) / sizeof(Teacher);

	fuzhi(teaArray, len);
	printTeachers(teaArray, len);

	system("pause");
	return 0;
}