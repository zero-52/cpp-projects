//19 类和模板案例，通用数组设计

#pragma once
#include<iostream>
using namespace std;

template <typename T>
class MyArray
{
public:
	//有参构造
	MyArray(int capacity)
	{
		cout << "有参构造函数调用" << endl;
		this->m_Capacity = capacity;
		this->m_Size = 0;

		this->pAddress = new T[this->m_Capacity];
	}

	//拷贝构造（因为堆区数据的存在，所以要采用深拷贝）
	MyArray(const MyArray& obj)
	{
		cout << "拷贝构造函数调用" << endl;

		this->m_Capacity = obj.m_Capacity;
		this->m_Size = obj.m_Size;  //普通数据，浅拷贝

		this->pAddress = new T[this->m_Capacity]; //堆数据，深拷贝
		//如果传入对象中已经存在一部分数组数据，拷贝过来
		for (int i = 0; i < obj.m_Size; i++)
		{
			this->pAddress[i] = obj.pAddress[i];
		}
	}

	//operator= 运算符重载，防止浅拷贝的问题，返回引用，以支持链式调用
	MyArray& operator=(const MyArray& arr)
	{
		cout << "等号运算符重载函数调用" << endl;
		//先判断本对象的原堆区是否有数据，有先释放
		if (this->pAddress != NULL)
		{
			delete[] this->pAddress;
			this->pAddress = NULL;
			this->m_Size = 0;
			this->m_Capacity = 0;
		}
		
		//深拷贝
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		this->pAddress = new T[arr.m_Capacity];
		for (int i = 0; i < this->m_Size; i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}
		return *this;
	}

	//尾插法
	void Tail_Insert(const T& val)
	{
		//首先判断是否存满
		if (this->m_Capacity == this->m_Size)
		{
			cout << "数组已满，不可插入" << endl;
			return;
		}
		this->pAddress[this->m_Size] = val; //在数组末尾插入数据
		this->m_Size++; //更新当前数组大小
	}

	//尾删法
	void Tail_Del()
	{
		//让用户访问不到最后一个元素即可，逻辑删除
		if (this->m_Size == 0)
		{
			cout << "元素为空，不可删除" << endl;
			return;
		}
		this->m_Size--;
	}

	//通过[下标]的方式访问数组，重载[]运算符。返回引用可以做左值进行修改。
	T& operator[](int index)  //不返回T&的话，就相当于又创建了一个对象，做左值更改的是这个新对象的值
	{
		if (index >= this->m_Size)
		{
			cout << "超出索引值" << endl;
			exit(0);
		}
		return this->pAddress[index];
	}

	//返回数组容量
	int getCapacity()
	{
		return this->m_Capacity;
	}

	//返回数组大小
	int getCurrentSize()
	{
		return this->m_Size;
	}

	//析构函数
	~MyArray()
	{
		if (this->pAddress != NULL)
		{
			cout << "析构函数调用" << endl;
			delete[] this->pAddress;
			this->pAddress = NULL; //释放后，指向NULL，防止变为野指针

		}
	}
	
private:
	T* pAddress; //指针指向堆区开辟的真实数组
	int m_Capacity; //数组容量
	int m_Size; //数组当前大小
};