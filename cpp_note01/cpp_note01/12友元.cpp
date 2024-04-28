#include<iostream>
using namespace std;

/*
	��������ļ��п���(Public)�����������(Private)
	�����������Ŀ��˶����Խ�ȥ���������������˽�еģ�Ҳ����˵ֻ�����ܽ�ȥ
	�����أ���Ҳ����������ĺù��ۺû��ѽ�ȥ��

�ڳ������Щ˽������ Ҳ�������������һЩ������������з��ʣ�����Ҫ�õ���Ԫ�ļ���

��Ԫ��Ŀ�ľ�����һ������������ ������һ������˽�г�Ա
��Ԫ�Ĺؼ���Ϊ�� friend

��Ԫ������ʵ�֣�
	1. ȫ�ֺ�������Ԫ ��ȫ�ֺ�������������ʵ�֣�Ҳ����������ʵ�֣�
		ʵ���� ȫ�ֺ���func() ���� ĳ��A ��˽�г�Ա 
		��Ҫ�� ��A�� �� ȫ�ֺ���() ��Ϊ��Ԫ

	2. ������Ԫ
		ʵ��һ�� ��A ���Է�����һ�� ��B ��˽�г�Ա 
		��Ҫ�� ��B �� �� ��A ��Ϊ��Ԫ

	3. ��Ա��������Ԫ
		ʵ����һ����ĳ�Ա���� A::visit() ���� ��һ�� ��B ��˽�г�Ա 
		��Ҫ�� ��B �� �� A �ĳ�Ա���� ��Ϊ ��Ԫ    
		
	ע�⣺
		���õ� 3.��Ԫ��Ա���� ʱ����ע����Ԫ��������Ԫ����֮����໥������ǰ��˳�򲻿ɴ�

	���ӣ�
		��� ��Ҫ�� ��BBB �� �� AAA �ĳ�Ա����visit() ��Ϊ ��Ԫ   
				
		�ڸ������У���AAA�����ȶ��壬������BBB�Ͳ��ܽ���AAA�ĳ�Ա����ָ��Ϊ��Ԫ��
		Ȼ����ֻ���ڶ�������BBB֮�󣬲��ܶ�����AAA�ĸó�Ա������
		��һ��Ľ��������ȶ������ Ҫ��Ϊ��Ԫ�ĳ�Ա�������࣬���ܽ��ó�Ա������Ϊ��Ԫ����һ���棬����Ԥ��������ͷǳ�Ա��������������Ϊ��Ԫ��
			
*/

/*** 1. ȫ�ֺ�������Ԫ �� 
		ʵ����ȫ�ֺ������� ĳ����� ��˽�г�Ա 
		��Ҫ�� Building01 ���� ��ȫ�ֺ�����Ϊ��Ԫ
		*/
class Building01
{
	//1��ȫ�ֺ�������Ԫ�� ָ������ȫ�ֺ���Ϊ��Ԫ�����ڸ�ȫ�ֺ����п��Է��� Building01 ��� private ��Ա
	friend void goodFriend(Building01 build01);  //��Ԫȫ�ֺ���������������������ʵ�֣�Ҳ����������ʵ��

	//2��������Ԫ�� ָ�� LaoWang�� Ϊ��Ԫ���Ϳ���ͨ�� LaoWang����� ���� Building01 ������˽�г�Ա
	friend class LaoWang;

	//3����һ��ĳ�Ա��������Ԫ�� ָ�� ĳ���µĳ�Ա���� Ϊ��Ԫ����ͨ���ó�Ա�������� ��ǰ��Building01�����˽�г�Ա
	//friend void ����::��Ա����();

public:
	string m_DrawingRoom;  //����
private:
	string m_BedRoom;  //����

public:
	Building01()  //���캯��
	{
		m_DrawingRoom = "����";
		m_BedRoom = "����";
	}
};

void goodFriend(Building01 build01)  //�βε�ȻҲ������ ָ�봫�� �� ���ô���
{
	cout << "ȫ�ֺ��� ����Ԫ���� �����build01 �Ĺ��г�Ա��" << build01.m_DrawingRoom << endl;

	//���ⲻ�ܷ���˽�г�Ա�������� Building01 ����ָ����ȫ�ֺ���Ϊ friend
	cout << "ȫ�ֺ��� ����Ԫ���� �����build01 ��˽�г�Ա��" << build01.m_BedRoom << endl; 
}

void test12()
{
	Building01 build01;

	goodFriend(build01);
}


/*** 2. ������Ԫ��
		ʵ��һ����LaoWang�Ķ�����Է�����һ����Building01�Ķ����˽�г�Ա 
		��Ҫ�� Building01 ���� �� LaoWang�� ��Ϊ��Ԫ
		*/
class LaoWang
{
public:
	LaoWang()
	{
		//���� Building01 ����
		//�������new������ֻ��Building building ������  LaoWang() ִ�н���֮��building�����ͷ�
		//֮���ٵ���building������Ծͻ���ʵ���ָ��Ȼ���������Ҫ��new���ٶ�������
		build02 = new Building01;

	}
	//���ڷ��� building ���������
	void visit()
	{
		cout << "LaoWang���ڷ��� ��һ������� bulid02 �Ĺ��г�Ա��" << build02->m_DrawingRoom << endl;

		//���ⲻ�ɷ���˽�г�Ա�������� Building01 ����ָ����ǰ��LaoWang Ϊ friend
		cout << "LaoWang���ڷ��� ��һ������� bulid02 ��˽�г�Ա��" << build02->m_BedRoom << endl;  

		cout << "LaoWang���ڷ��� ��һ������� bulid03 �Ĺ��г�Ա��" << build03.m_DrawingRoom << endl;
		cout << "LaoWang���ڷ��� ��һ������� bulid03 ��˽�г�Ա��" << build03.m_BedRoom << endl;
	}
public:
	Building01* build02; //C++������һ������ָ��ʱû�з����ڴ棬��ʱ������� Building01 �Ĺ��캯��
	Building01 build03;
};

void test13()
{
	LaoWang laowang;
	laowang.visit();
}


/*** 3. ��Ա��������Ԫ ��
		ʵ����һ����ĳ�Ա���� AAA::visit() ���� ��һ������� BBB:: ��˽�г�Ա 
		��Ҫ�� BBB ���� �� AAA �ĳ�Ա���� ��Ϊ ��Ԫ    
		
		ע�⣺
			���õ���Ԫ��Ա����ʱ����ע����Ԫ��������Ԫ����֮����໥������ǰ��˳�򲻿ɴ�
			�ڸ������У���AAA�����ȶ��壬������BBB�Ͳ��ܽ���AAA�ĳ�Ա����ָ��Ϊ��Ԫ��
			Ȼ����ֻ���ڶ�������BBB֮�󣬲��ܶ�����AAA�ĸó�Ա������
			��һ��Ľ��������ȶ������ Ҫ��Ϊ��Ԫ�ĳ�Ա�������࣬���ܽ��ó�Ա������Ϊ��Ԫ����һ���棬����Ԥ��������ͷǳ�Ա��������������Ϊ��Ԫ��
			*/
class BBB; //����BBB��
class AAA
{
private:
	BBB *bbb;
public:

	AAA(); // ���ڣ��ù��캯���� �õ���BBB�࣬���Թ��캯��Ҫ�� BBB�� ��������ٶ���

	void visit();  //�ú���Ϊ�� BBB ����Ԫ������������������ ��BBB ����
	
};

class BBB
{
	//��һ��AAA�ĳ�Ա��������Ԫ��    ָ�� ĳ���µĳ�Ա���� Ϊ��Ԫ����ͨ���ó�Ա�������� ��ǰ������˽�г�Ա
	friend void AAA::visit();

public:
	string m_DrawingRoom;  //����
private:
	string m_BedRoom;  //����

public:
	BBB()  //���캯��
	{
		m_DrawingRoom = "����";
		m_BedRoom = "����";
	}
};
AAA::AAA()
{
	bbb = new BBB;
}
void AAA::visit()
{
	cout << "XiaoWu���ڷ��� ��һ������� bulid04 �Ĺ��г�Ա��" << bbb->m_DrawingRoom << endl;

	cout << "XiaoWu���ڷ��� ��һ������� bulid04 ��˽�г�Ա��" << bbb->m_BedRoom << endl;
	//�������ⲻ�ɷ���˽�г�Ա�������� BBB ����ָ����ǰ���Ա���� AAA::visit() Ϊ friend

}

void test14()
{
	AAA xw;
	xw.visit();
}



int main12()
{
	/* 1. ȫ�ֺ�������Ԫ*/
	cout << "ȫ�ֺ�������Ԫ" << endl;
	test12();

	/* 2. ������Ԫ��һ������Է�����һ�����˽�г�Ա */
	cout << endl << "������Ԫ" << endl;
	test13();


	test14();
	return 0;
}