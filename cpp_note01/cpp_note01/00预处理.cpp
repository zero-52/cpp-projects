/*
�����ռ䣺
	namespace �ռ����� { �������� }  �� namespace first_space { void func() {} }
	�ռ�����::��������;			  �� first_space::func();

	using namespace �ռ�����; //�ڵ���ʱ������ǰ����ϸÿռ����֣��������뽫����ָ�������ռ��е�����
	�����ռ䶨��Ҳ���Է���Ƕ�ף�����ʱ��::�����򼴿�


Ԥ����
	���е�Ԥ������ָ����Ծ��ţ�#����ͷ��ֻ�пո��ַ����Գ�����Ԥ����ָ��֮ǰ��
	Ԥ����ָ��� C++ ��䣬�������ǲ����Էֺţ�;����β��

	#include ָ���������ڰ�ͷ�ļ�������Դ�ļ��С�

	C++ ��֧�ֺܶ�Ԥ����ָ����� #include��#define��#if��#else��#line ��
	
	ָ���һ����ʽ�ǣ�
		#define macro-name replacement-text
		�ڸ��ļ��к������ֵ����� ����macro-name �������ڳ������֮ǰ���滻Ϊ replacement-text��

	������
		#define MIN(a,b) (a<b ? a : b)

	��������
		#ifdef NULL
			#define NULL 0
		#endif

	# �� ## �����
		# �� ## Ԥ����������� C++ �� ANSI/ISO C �ж��ǿ��õġ�
		# �������� replacement-text ����ת��Ϊ���������������ַ�����
		## ���������������������
*/

#include<iostream>
using namespace std;

// ��һ�������ռ�
namespace first_space {
	void func() {
		cout << "��һ�������ռ� first_space" << endl;
	}
}
// �ڶ��������ռ�
namespace second_space {
	void func() {
		cout << "�ڶ��������ռ� second_space" << endl;
	}
}



int main0()
{
	/* �����ռ� */
	first_space::func(); //���õ�һ�����ռ�ĺ���

	using namespace second_space; //using namespace ָ���������õ�Ĭ�������ռ�
	func(); //���õڶ������ռ�ĺ���

	using namespace std;
	return 0;

}

/*************** #define ԭ�� ********************** 
#define PI 3.14159

int main()
{
	cout << "Value of PI :" << PI << endl;
	return 0;
}
���ڣ������ǲ�����δ��룬����Ԥ����Ľ��������Դ�����ļ��Ѿ����ڣ�������ʹ�� - E ѡ����б��룬
���ѽ���ض��� test.p�����ڣ�������鿴 test.p �ļ������ῴ�����Ѿ�������������Ϣ���������ļ��еĺ걻��Ϊ���£�

$ gcc - E test.cpp > test.p

...
int main()
{

	cout << "Value of PI :" << 3.14159 << endl;

	return 0;
}
*/


/*
********* # �� ## ����� ʵ�� ************

#include <iostream>
using namespace std;

#define MKSTR( x ) #x

int main ()
{
	cout << MKSTR(HELLO C++) << endl;

	return 0;
}
������Ĵ��뱻�����ִ��ʱ������������н����
	HELLO C++

������������������ι����ġ�������⣬C++ Ԥ���������������У�
cout << MKSTR(HELLO C++) << endl;

ת�����ˣ�
cout << "HELLO C++" << endl;

## ��������������������ơ�������һ��ʵ����

#define CONCAT( x, y )  x ## y
�� CONCAT �����ڳ�����ʱ�����Ĳ����ᱻ����������������ȡ���ꡣ
���磬������ CONCAT(HELLO, C++) �ᱻ�滻Ϊ "HELLO C++"��������ʵ����ʾ��

ʵ��
#include <iostream>
using namespace std;

#define concat(a, b) a ## b
int main()
{
   int xy = 100;

   cout << concat(x, y);
   return 0;
}
������Ĵ��뱻�����ִ��ʱ������������н����
	100

������������������ι����ġ�������⣬C++ Ԥ���������������У�
cout << concat(x, y);

ת�����ˣ�
cout << xy;
*/