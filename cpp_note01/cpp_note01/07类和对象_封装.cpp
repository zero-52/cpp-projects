
/* ������ͬ���ʵĶ������ǳ���Ϊ��

	 ���е����Ժͷ���ͳ��Ϊ��Ա
		���ԣ��ֳ�Ϊ��Ա���Ի��Ա����
		��Ϊ���ֳ�Ϊ��Ա�������Ա����
*/

/* ��װ���̳С���̬ 

	��װ�� 
		�﷨��
			class ����{ ����Ȩ�ޣ� ���� / ��Ϊ };

			//����Ȩ�ޣ�����������ʵ�ֶ��壬�������ⶨ�壬ֻ�Ƿ���Ȩ�޲�ͬ
				����Ȩ�� public��    ��Ա �������ڷ��ʣ�Ҳ�����������
				����Ȩ�� protected�� ��Ա �������ڷ��ʣ�������������ʣ����ӿ��Է��ʸ��ױ�����Ա��
				˽��Ȩ�� private��   ��Ա �������ڷ��ʣ�������������ʣ����Ӳ��ɷ��ʸ���˽�г�Ա��
			//���齫��Ա��������Ϊ˽�У�Ȼ������ṩ���еĺ����ӿ�
			
		
		�����Ժ���Ϊ��Ϊһ�����壬��������
		�����Ժ���Ϊ����Ȩ�޿���

	��ʽ���˼��
		
	�̳У�

	��̬��


*/
#include<iostream>
using namespace std;


//���һ��Բ�࣬�������ܳ�

const double PI = 3.14;

class Circle
{
	//����Ȩ��
public:

	//����
	int c_r;

	//��Ϊ
	int zhouchang()
	{
		return 2 * PI * c_r;
	}
};


// ���һ��ѧ���࣬������������ѧ�ţ����Ը�������ѧ�Ÿ�ֵ��������ʾѧ����������ѧ��
class Student
{
public:
	string name;
	//string gender;   ��������string ����Ϊɶ�����ˣ���
	int stu_id;

	void setInfo(string n, int id)
	{
		name = n;
		stu_id = id;
	}
	void showInfo()
	{
		cout << "������" << name << "\t" << "ѧ�ţ�" << stu_id << endl;
	}
};


//��ͬ����Ȩ��
class Person
{
public:
	string name;

protected:
	string car;

private:
	string password;
	void func3();

public:
	void func()
	{
		name = "����";
		car = "�µ�";
		password = "123321";
	}
	void func2();  //Ҳ��������ʵ�ֺ�������
};
//����ʵ�ֳ�Ա��������
void Person::func2()
{
	cout << "����ʵ�ֹ��г�Ա��������" << endl;
}
void Person::func3()  //˽�г�Ա����Ҳ��������ʵ��
{
	cout << "����ʵ��˽�г�Ա��������" << endl;
}



//struct��class��Ψһ������Ĭ��Ȩ�޲�ͬ
struct S1
{
	int c;  //�ṹ���ԱĬ��Ϊ����Ȩ��
};
class C2
{
	int c;  //���ԱĬ��Ϊ˽��Ȩ��
};


//��Ա��������Ϊ˽��
	//�ŵ�1�������г�Ա��������Ϊ˽�У�������ͨ���������ʣ������Լ����ƶ�дȨ��
	//�ŵ�2������дȨ�ޣ����ǿ��Լ������д�����Ч��

class people
{
private:
	string m_Name; //�ɶ���д  ����

	int m_Age = 25; //��+д���  ����

	string m_Lover; //ֻд  ����
public:
	//����дȨ��
	void setName(string name)
	{
		m_Name = name;
	}
	//���ֶ�Ȩ��
	string getName()
	{
		return m_Name;
	}
	//�����Ȩ��
	int getAge()
	{
		return m_Age;
	}
	//����дȨ�ޣ������������Ч��
	void setAge(int age)
	{
		if (age < 0 || age>150)
		{
			m_Age = 0;
			cout << "����������Ч��" << endl;
			return;
		}
		m_Age = age;
	}
	//����ֻдȨ��
	void setLover(string lover)
	{
		m_Lover = lover;
	}
};


//��ʽ���˼��
class AddTest
{
public:
	int m_Sum;
	
	AddTest addNum(int a)  //ֵ��ʽ���أ�ÿ���൱�ڸ���һ���¶���������Ѿ����ǵ�ǰ������
	{
		this->m_Sum += a;
		return *this;
	}

	AddTest& addNum2(int a) //���÷�ʽ���أ��൱�ڸ���ǰ�������˱���
	{
		this->m_Sum += a;
		return *this;
	}
};

void add_test()
{
	AddTest addt1;
	addt1.m_Sum = 0;
	addt1.addNum(10).addNum(10); //ֵ��ʽ���أ�����ÿ�δ������¶�����ʽ����ʵ����ֻ�Ե�ǰ����ִ��һ��
	cout << "ֵ��ʽ���أ��� = " << addt1.m_Sum << endl;  //10

	AddTest addt2;
	addt2.m_Sum = 0;
	cout << "���÷�ʽ���أ��� = " << addt2.addNum(10).addNum(10).m_Sum << endl; //20

	AddTest addt3;
	addt3.m_Sum = 0;
	addt3.addNum2(10).addNum2(10);  //���÷�ʽ���أ�ÿ�ε��õĶ��ǵ�ǰ����
	cout << "���÷�ʽ���أ��� = " << addt3.m_Sum << endl; //20

}




int main7()
{
	//��������
	Circle C1;
	C1.c_r = 10; //���Ը�ֵ

	//Բ���ܳ�Ϊ
	cout << "Բ���ܳ�Ϊ��" << C1.zhouchang() << endl;


	Student stu1;
	//stu1.setInfo("С��", "��",123456);  //��������Ϊ�����Ը�ֵ
	stu1.name = "С��";
	stu1.stu_id = 123456;
	stu1.showInfo();

	Student stu2;
	stu2.setInfo("����", 789789);
	stu2.showInfo();


	//����Ȩ�޳�����
	Person p01;
	p01.name = "����";    //����Ȩ�� ����ɷ���
	//p01.car = "����";    //����Ȩ�� ������ʲ���
	//p01.password = "123"; //˽��Ȩ�� ������ʲ���
	p01.func();


	/** ��C++�� struct��classΨһ����������� Ĭ�ϵķ���Ȩ�޲�ͬ

		����
			struct Ĭ��Ȩ��Ϊ����
			class Ĭ��Ȩ��Ϊ˽��
	*/
	struct S1 s1;
	s1.c = 2;

	C2 c2;
	//c2.c = 2 //����55���ɷ���


	//��Ա��������Ϊ˽��
	people p1;
	//�����ɶ���д
	//p1.m_Name = "����"; //˽�����Բ����������
	p1.setName("����");
	cout << "����Ϊ��" << p1.getName() << endl;

	//�����
	cout << "����Ϊ��" << p1.getAge() << endl;
	//����д
	p1.setAge(2000);
	p1.setAge(20);
	cout << "����Ϊ��" << p1.getAge() << endl;

	//����ֻд��û�ж�Ȩ��
	p1.setLover("С��");


	/* ��ʽ���˼�� */
	add_test();
	return 0;

}