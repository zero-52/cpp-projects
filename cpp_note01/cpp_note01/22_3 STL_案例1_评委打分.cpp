/*
案例-评委打分

有5名选手：选手ABCDE，10个评委分别对每一名选手打分，去除最高分，去除评委中最低分，取平均分。

实现步骤:
	创建五名选手，放到vector中
	遍历vector容器，取出来每一个选手，执行for循环，可以把10个评分打分存到deque容器中
	sort算法对deque容器中分数排序，去除最高和最低分（分数放在deque里方便掐头去尾）
	deque容器遍历一遍，累加总分
	获取平均分
*/
#include<iostream>
using namespace std;
#include<vector>
#include<deque>
#include <algorithm>

//选手类
class Player
{
public:
	string m_Name;
	int m_Score;
	Player(string name, int score)
	{
		this->m_Name = name;
		this->m_Score = score;
	}
};

//创建选手
void createPlayer(vector<Player>& vec)
{
	string id = "ABCDE";
	for (int i = 0; i < 5; i++)
	{
		string name = "选手";
		name += id[i];

		int score = 0; //初始分设为0
		Player p(name, score);
		//将创建的Player对象放到容器中
		vec.push_back(p);
	}

}

//打分
void setScore(vector<Player>& vec)
{
	for (int i = 0; i < vec.size(); i++)
	{
		deque<int> deq;
		for (int j = 0; j < 10; j++)
		{
			int score = rand() % 41 + 60; //60~100，伪随机，加上随机数种子变为真随机
			deq.push_back(score);
			
		}
		//打印出随机评分
		cout << "选手：" << vec[i].m_Name << "  得分：" << endl;
		for (int t = 0; t < deq.size(); t++)
		{
			cout << deq[t] << " ";
		}
		cout << endl;
	
		
		//排序
		sort(deq.begin(), deq.end());
		//去除最高分和最低分
		deq.pop_back();
		deq.pop_front();
		
		int avg = 0;
		for (int m = 0; m < deq.size(); m++)
		{
			avg += deq[m]; //累加
		}
		avg = avg / deq.size();
		vec[i].m_Score = avg;
	}

}


//显示选手的最终得分
void showScore(vector<Player>& vec)
{
	for (vector<Player>::iterator it = vec.begin(); it < vec.end(); it++)
	{
		cout << "姓名：" << it->m_Name << "  平均得分：" << it->m_Score << endl;
	}
}

/*****************************************************************************
 *  @brief	main

 *****************************************************************************/
int main22_3()
{
	//加随机数种子
	srand((unsigned int)time(NULL));

	//创建vector容器，用于存放5名选手
	vector<Player> vec;

	//创建选手
	createPlayer(vec);

	//测试是否创建选手成功
	/*for (int i = 0; i < 5; i++)
	{
		cout << "姓名：" << vec[i].m_Name << "  分数：" << vec[i].m_Score << endl;
	}*/

	//打分
	setScore(vec);

	//显示最后得分
	cout << endl;
	showScore(vec);


	return 0;
}