
/*
��������ظ��
	�����е���������½��ж��壬��������һ�ֹ��ܣ�����Ӧ��ͬ���Զ�����������
		+  -  *  /  ++  --  =  >  <  == !=  () 

	�������õ��������ͽ��в�����������֪��������㣬�������Զ�����������ͣ��Ͳ�֪����������ˣ���ʱҪ����

	��������صĺ�����д��Ϊ��
		������������ operator ������ţ��� void operator+(){} �Ӻ����أ� Person operator<<(){} ��������
		//�������� ��Ա���� �� ȫ�ֺ��� ʵ��
	ע�⣺
		�������õ��������͵ı��ʽ�ĵ������ǲ����ܸı�ģ��� int a=1; int b=2; a+b ��һ������3�����ֲ�����Ϊ���صõ���Ľ��
		��Ҫ�������������
		//AA01 operator+(int num1, int num2){} //���󣬲��ܶ������������ͱ��ʽ����������и���
*/


#include<iostream>
using namespace std;


/*****************************************************************************
 *  @brief	�Ӻ���������� + - * /
 *				�� ʵ�����������ļӺ�
 *****************************************************************************/

/**
 * @brief	��AA01�ഴ����������ֱ�������ͣ��ᱨ��
 *			ͨ����Ա������ȫ�ֺ������ؼӺ�������ɽ��
 */
class AA01
{
public:
	int m_A;
	int m_B;

public:
	AA01() {};
	AA01(int a, int b)
	{
		this->m_A = a;
		this->m_B = b;
	}
	//��ͨ��Ա����ʵ��+������
	AA01 addNum(AA01& aa)
	{
		AA01 temp;
		temp.m_A = this->m_A + aa.m_A;
		temp.m_B = this->m_B + aa.m_B;
		return temp;
	}
	//1��ͨ����Ա��������+��
	/*
	AA01 operator+(AA01& aa)  //˫Ŀ���������������Ա����Ҫ��һ������
	{
		AA01 temp;
		temp.m_A = this->m_A + aa.m_A;
		temp.m_B = this->m_B + aa.m_B;
		return temp;
	} */

};
//2��ͨ��ȫ�ֺ�������+�ţ��� ��1��ͨ����Ա��������+�š� ���ܹ��棩
AA01 operator+(AA01& aa1, AA01& aa2)  //˫Ŀ�������������ȫ�ֺ���Ҫ��������
{
	AA01 temp;
	temp.m_A = aa1.m_A + aa2.m_A;
	temp.m_B = aa1.m_B + aa2.m_B;
	return temp;
}

//���������ʱ��Ҳ���Է�����������
AA01 operator+(AA01& aa1, int num)
{
	AA01 temp;
	temp.m_A = aa1.m_A + num;
	temp.m_B = aa1.m_B + num;
	return temp;
}

//AA01 operator+(int num1, int num2){} //���󣬲��ܶ������������ͱ��ʽ����������и���


/**
 * @brief	ͨ��add_reload_test���ԼӺ���������ص�Ч��
 */
void add_reload_test()
{
	AA01 aa1(10, 20);
	AA01 aa2(10, 20);

	AA01 aa3 = aa2.addNum(aa1);  //��ͨ��Ա����

	//1��ͨ����Ա��������+��
	//AA01 aa4 = aa1 + aa2;  //��������ص��õļ򻯷�ʽ��Ҫ��ʹ����Ϊ AA01 ��������ӣ���Ҫ������������� AA01 operator+(AA01& aa)
	//AA01 aa5 = aa1.operator+(aa2);  //��������ص��õı��ʣ����ֵ��÷�ʽ������
	//cout << "��Ա�����Ӻ���������أ�aa5.m_A = " << aa5.m_A << "   aa5.m_B = " << aa5.m_B << endl;

	//2��ͨ��ȫ�ֺ�������+��
	AA01 aa6 = aa1 + aa2;  // 20 40
	AA01 aa7 = operator+(aa1, aa2);  //���ʣ� 20 40
	cout << "ȫ�ֺ����Ӻ���������أ�aa6.m_A = " << aa6.m_A << "   aa6.m_B = " << aa6.m_B << endl;

	//��������غ��� ���� ��������
	AA01 aa8 = operator+(aa1, 1);
	cout << "��������� �� �������أ�aa8.m_A = " << aa8.m_A << "   aa7.m_B = " << aa8.m_B << endl;

}



/*****************************************************************************
 * @brief	�������������  <<
 *				�� pΪ�����ʹ cout<< p << endl; ���Ϸ�
 * 
 * @attention	�������ó�Ա�������� �������������Ϊ�޷�ʵ��cout��<<���ŵ����
 *****************************************************************************/

class AA02
{
	friend ostream& operator<<(ostream& out, AA02& aa);  //��Ϊ��Ԫ
private:
	int m_A;
	int m_B;
public:
	AA02() 
	{
		m_A = 10;
		m_B = 20;
	}
	//1���������ó�Ա�������� �������������Ϊ�޷�ʵ��cout��<<���ŵ����
	/*void operator<<(cout)  //aa.operator(cout) �򻯷�ʽ�ȼ��� aa << cout ����ԭ�ⲻ��
	{

	}*/
};
//2��ֻ������ȫ�ֺ����������������

/**
 * @brief	ȫ�ֺ����������������
 * 
 * @param	out ������������ͣ��������ܸ��ƿ������ʲ��ܲ���ֵ����
 * @param	aa  AA02���󣬱���Ϊ���� << �Ҳ�Ĳ���
 *
 * @return	��������Ϊ ostream& ���ã�Ϊ����֧����ʽ���ã��� cout << aa <<endl;
 */
//void operator<<(ostream& out, AA02& aa)  
ostream& operator<<(ostream& out, AA02& aa) //operator<<(cout, aa) ����Ϊ cout << aa
{
	out << "  ������������أ�m_A = " << aa.m_A << "  m_B = " << aa.m_B;
	return out;
}   


void shiftLeft_reload_test()
{
	AA02 aa;
	//cout << aa;  //��������أ�ֱ������Զ������Ͷ��� aa������

	//������������غ�
	operator<<(cout, aa); //���� cout << aa;
	cout << aa; 

	cout << endl; //ע�⣺�����������ͣ����õ���c++�����cout�����������ص�

	//cout << aa << endl;  //�������Ϊvoid���������ã��������� cout << aa;  void << endl;
	//��Ϊ void operator<<(ostream& out, AA02& aa)ʹ cout<<aa ����Ϊ�գ�������ʽ���ã���Ҫ����cout���òſ�
	cout << aa << endl;  //���� cout << aa;  cout << endl;

}



/*****************************************************************************
 * @brief	������������� ++ --
 *				ע�⣺ǰ�õ���(����ʽ) �� ���õ���(������ʽ)
 *
*****************************************************************************/

class MyInt
{
	friend ostream& operator<<(ostream& out, MyInt myNum);
private:
	int m_Num;
public:
	MyInt()
	{
		m_Num = 0;
	}
	//1����Ա�������� ǰ�õ�������� ++a
	MyInt& operator++()  //�������ã���֧����ʽ���ã�����Ŀ���������Ա���������βΣ�
	{
		m_Num++;
		return *this;

	}
	//1����Ա�������� ���õ�������� a++
	MyInt operator++(int) //ע�⣺����Ϊֵ���ݣ�������Ϊ���ã��򷵻��˾ֲ�����������
						  //��ֹ���ؾֲ����������ã��ʺ��õ���������ʽ���ã��Դ�����Ҳ������ʽ���ã�int��ռλ������
	{
		MyInt temp = *this;
		m_Num++;
		return temp;
	}

};

//��ΪҪ�õ� cout ����Զ������ͣ����в��ԣ���Ҫ �����������<<
ostream& operator<<(ostream& out, MyInt myNum)
{
	out << myNum.m_Num;
	return out;
}

void autoIncrement_reload_test()
{
	//MyInt a;  ++a;  a++;
	MyInt a;
	cout << "���������" << endl;
	cout << "��ʼ a = " << a << endl; //0  ����<<
	cout << "  ++a  = " << ++a << endl; //1  ��֧�� ++(++a) ��ʽ
	cout << "��ʱ a = " << a << endl; //1

	MyInt b;
	cout << "��ʼ b = " << b << endl; //0
	cout << "  b++  = " << b++ << endl; //0  ��֧�� (b++)++ ��ʽ
	cout << "��ʱ b = " << b << endl; //1

}


/*****************************************************************************
 * @brief	��ֵ��������� =
 *				Person p1; Person p2;   p2 = p1; 
 *				//ϵͳĬ�ϵĸ�ֵ��ǳ������������ڶ���Դ���ֶ��ͷ��ڴ���ܵ��¶���ͷ�ͬһ�ѿռ䣬���´���
 *				//ͨ�����ظ�ֵ�����ʵ�� ��� ���ɽ������
*****************************************************************************/

class Person03 
{
public:
	int* m_p;
public:
	Person03(int age)
	{
		//m_A = &age; //ע�⣺��������д��ָ��ָ���˾ֲ�����
		m_p = new int(age);
	}
	~Person03()
	{
		if (m_p != NULL)
		{
			delete m_p;
			m_p = NULL;
		}
	}
	//��ֵ���������
	Person03& operator=(Person03& p)  //�������ã�֧����ʽ
	{
		//m_p = p.m_p  //Ĭ�ϸ�ֵ������ṩ����ǳ������ʵ�ʾ������д���

		//���ж϶��������Ƿ��������ڶ����������ͷţ������
		if (m_p != NULL)
		{
			delete m_p;
			m_p = NULL;
		}
		//���
		m_p = new int(*p.m_p);

		return *this;
	}
};
void fuzhi_reload_test()
{
	Person03 p1(12);
	Person03 p2(25);
	
	//��ֵ���������ǰ
	//p2 = p1; //����Ĭ�ϵĸ�ֵ����� �ǳ�Ա��ǳ������
	// ���Դ�ʱ ָ�� p2.m_A �� p1.m_A ���ŵĵ�ַ�ĸ��ƣ���ָ��ָ���������ͬ�����������ͷŶѿռ�ᱻ�ͷ����ζ�����
	//cout << (int)p1.m_p << "\t" << *p1.m_p << endl;
	//cout << (int)p2.m_p << "\t" << *p2.m_p << endl;  //���ͷŶ�ʱ�����߽����ȫ��ͬ


	//��ֵ��������غ�
	p2 = p1;
	cout << (int)p1.m_p << "\t" << *p1.m_p << endl;
	cout << (int)p2.m_p << "\t" << *p2.m_p << endl; //��Ϊ���������ʱ��ַ������ͬ

	Person03 p3(35);
	p3 = p2 = p1;  //��ʽ
	cout << *p3.m_p << endl;

}



/*****************************************************************************
 * @brief	��ϵ���������  >  <  ==  !=
 *				�������Զ������Ͷ�����бȽ�
*****************************************************************************/

class AA03
{
private:
	string m_Car;
	int m_Money;
public:
	AA03(string car, int m)
	{
		m_Car = car;
		m_Money = m;
	}
	//��ϵ��������� ==
	bool operator==(AA03 &aa)
	{
		if (m_Car == aa.m_Car && m_Money == aa.m_Money)
		{
			return true;
		}
		return false;
	}
	bool operator!=(AA03& aa)
	{
		if (m_Car == aa.m_Car && m_Money == aa.m_Money)
		{
			return false;
		}
		return true;

		/* �������ַ�ʽ���� 
		if (m_Car != aa.m_Car || m_Money != aa.m_Money)
		{
			return true;
		}
		return false;*/
	}

};
void relation_reload_test()
{
	AA03 aa1("����", 20);
	AA03 aa2("����", 20);
	AA03 aa3("���ǵ�", 20);
	/*����ǰ����
	if (aa1 == aa2)
	{

	}*/
	if (aa1 == aa2)
	{
		cout << "�� ����aa1 �� aa2 ���" << endl;
	}
	if (aa1 != aa3)
	{
		cout << "�� ����aa1 �� aa3 �����" << endl;
	}
}



/*****************************************************************************
 * @brief	�����������������  ()
 *				�������غ�ʹ�õķ�ʽ�ǳ������ĵ��ã���˳�Ϊ�º���
 *				�º���û�й̶�д�����ǳ����
*****************************************************************************/
class MyPrint
{

public:
	void operator()(string str1)
	{
		cout << str1;
	}
};
//����ͨ�����Ա�
void myPrint2(string str2)
{
	cout << str2;
}

void funcCall_reload_test()
{
	MyPrint myPrint;
	myPrint("hello world"); //�����������أ�����ʹ�������ǳ����ƺ������ã��ʳƷº���
	cout << endl;

	myPrint2("hello world"); //��ͨȫ�ֺ���
	cout << endl;
}

//�º������������������������͵Ⱥ����
class MyAdd
{
public:
	int operator()(int a,int b)
	{
		return a + b;
	}
};
void myAdd_test()
{
	MyAdd myAdd;
	int ret = myAdd(1, 2);
	cout << ret << endl;

	//MyAdd(); //������������()
	//MyAdd()(2, 3); //��������+�º��� = ������������
	cout << "��������+�º��� = ������������  " << MyAdd()(2, 3) << endl;
}


/*****************************************************************************
 * @brief	main ����
 * 
*****************************************************************************/
int main13()
{
	/* �Ӻ���������� */
	cout << endl << "�Ӻ������������" << endl;
	add_reload_test();

	/* ������������� */
	cout << endl << "�������������" << endl;
	shiftLeft_reload_test();

	/* ������������� */
	cout << endl;
	autoIncrement_reload_test();

	/* ��ֵ��������� */
	cout << endl << "��ֵ���������" << endl;
	fuzhi_reload_test();

	/* ��ϵ��������� */
	cout << endl << "��ϵ���������" << endl;
	relation_reload_test();

	/* ���������������� */
	cout << endl << "���������������أ��º���" << endl;
	funcCall_reload_test();

	//������������
	myAdd_test();

	return 0;
}