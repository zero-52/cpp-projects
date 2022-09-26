#include<iostream>
using namespace std;

/* 
设计一个英雄的结构体，包括成员姓名，年龄，性别;创建结构体数组，数组中存放5名英雄。

通过冒泡排序的算法，将数组中的英雄按照年龄进行升序排序，最终打印排序后的结果。

五名英雄信息如下：

		{"刘备",23,"男"},
		{"关羽",22,"男"},
		{"张飞",20,"男"},
		{"赵云",21,"男"},
		{"貂蝉",19,"女"},
*/

struct Hero
{
	string name;
	int age;
	string gender;

};

// 冒泡排序，按年龄升序
void bubbleSort(struct Hero heroArr[], int len)
{
	struct Hero temp = { "0",0,"0" };
	for (int i = 0; i < len - 1; i++)
	{
		for (int j = 0; j < len - i - 1; j++)
		{
			if (heroArr[j].age > heroArr[j + 1].age)
			{
				temp = heroArr[j + 1];
				heroArr[j + 1] = heroArr[j];
				heroArr[j] = temp;
			}
		}
	}
	cout << "排序后打印：" << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << "姓名：" << heroArr[i].name << "  性别：" << heroArr[i].gender << "  年龄：" << heroArr[i].age << endl;
	}
}

int main3()
{
	struct Hero heroArr[5] = {
		{"刘备",23,"男"},
		{"关羽",22,"男"},
		{"张飞",25,"男"},
		{"赵云",21,"男"},
		{"貂蝉",19,"女"},
	};

	cout << "排序前打印：" << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << "姓名：" << heroArr[i].name << "  性别：" << heroArr[i].gender << "  年龄：" << heroArr[i].age << endl;
	}

	int len = sizeof(heroArr) / sizeof(heroArr[0]);

	bubbleSort(heroArr, len);
	

	/* *** 冒泡排序
	int arr[] = { 5, 7, 3, 9, 1 };
	int len = sizeof(arr) / sizeof(arr[0]);
	int temp = 0;
	for (int i = 0; i < len-1; i++)
	{
		for (int j = 0; j < len-i-1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j+1];
				arr[j + 1] = arr[j];
				arr[j] = temp;
			}
		}
	}
	for (int i = 0; i < 5; i++)
	{
		cout << arr[i] << endl;
	}
	*/
	
	return 0;
}