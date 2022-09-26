/*
* string 类虽然不是STL 的组成部分，但设计它时考虑到了STL。
例如，它包含begin()、end()、rbegin()和rend()等成员，因此可以使用STL接口。也有人称为string容器。

string
	本质：
		string是C++风格的字符串，而string本质上是一个类

	string和char * 区别：
		char* 是一个指针
		string是一个类，类内部封装了char * ，管理这个字符串，是一个char * 型的容器。

	特点：
		string 类内部封装了很多成员方法
		例如：查找find，拷贝copy，删除delete 替换replace，插入insert
		string管理char * 所分配的内存，不用担心复制越界和取值越界等，由类内部进行负责

	string构造函数：
		构造函数原型：
			string(); //默认构造函数。创建一个空的字符串 例如: string str;
			string(const char* s); //有参构造函数。使用字符串s初始化
			string(const string& str); //拷贝构造函数。使用一个string对象初始化另一个string对象
			string(int n, char c); //使用n个字符c初始化
		string的多种构造方式没有可比性，灵活使用即可

	string的赋值操作：
		给string字符串进行赋值
		赋值的函数原型：
			//通过 =运算符重载 赋值
			string& operator=(const char* s); //char*类型字符串 赋值给当前的字符串
			string& operator=(const string &s); //把字符串s赋给当前的字符串
			string& operator=(char c); //字符赋值给当前的字符串

			//通过 string类的成员函数assign 赋值：assign将一个容器中的元素复制到另一个容器
			string& assign(const char *s); //把字符串s赋给当前的字符串
			string& assign(const char *s, int n); //把字符串s的前n个字符赋给当前的字符串
			string& assign(const string &s); //把字符串s赋给当前字符串
			string& assign(int n, char c); //用n个字符c赋给当前字符串

	string的拼接操作：
		实现在字符串末尾拼接字符串
		函数原型：
			string& operator+=(const char* str); //重载+=操作符
			string& operator+=(const char c); //重载+=操作符
			string& operator+=(const string& str); //重载+=操作符
			string& append(const char *s); //把字符串s连接到当前字符串结尾
			string& append(const char *s, int n); //把字符串s的前n个字符连接到当前字符串结尾
			string& append(const string &s); //同operator+=(const string& str)
			string& append(const string &s, int pos, int n);//字符串s中从pos开始的n个字符连接到字符串结尾
		注意：
			中文一个字占两个字符
			起始下标从0开始

	string的查找和替换操作
 		查找：查找指定字符串是否存在
		替换：在指定的位置替换字符串
		函数原型：
			int find(const string& str, int pos = 0) const; //查找str第一次出现位置,从pos开始查找
			int find(const char* s, int pos = 0) const; //查找s第一次出现位置,从pos开始查找
			int find(const char* s, int pos, int n) const; //从pos位置查找s的前n个字符第一次位置
			int find(const char c, int pos = 0) const; //查找字符c第一次出现位置
			int rfind(const string& str, int pos = npos) const; //查找str最后一次位置,从pos开始查找
			int rfind(const char* s, int pos = npos) const; //查找s最后一次出现位置,从pos开始查找
			int rfind(const char* s, int pos, int n) const; //从pos查找s的前n个字符最后一次位置
			int rfind(const char c, int pos = 0) const; //查找字符c最后一次出现位置
			string& replace(int pos, int n, const string& str); //替换从pos开始n个字符为字符串str
			string& replace(int pos, int n,const char* s); //替换从pos开始的n个字符为字符串s
		总结：
			find查找是从左往后，rfind从右往左
			find、rfind找到字符串后返回查找的第一个字符位置，找不到返回-1
			replace在替换时，要指定从哪个位置起，多少个字符，替换成什么样的字符串

	字符串比较
 		按字符的ASCII码进行对比
			= 返回 0
			> 返回 1
			< 返回 -1
		函数原型：
			int compare(const string &s) const; //与字符串s比较
			int compare(const char *s) const; //与字符串s比较
		总结：
			字符串对比主要是用于比较两个字符串是否相等，判断谁大谁小的意义并不是很大

	字符串下标读写/存取字符
		string中单个字符读写/存取方式有两种 str[下标] 和 str.at()
		函数原型：
			char& operator[](int n); //重载[]，通过[下标]方式读写/存取字符
			char& at(int n); //通过at方法读写/存取字符

	字符串的插入和删除
 		函数原型：
			string& insert(int pos, const char* s); //在指定位置插入字符串
			string& insert(int pos, const string& str); //在指定位置插入字符串
			string& insert(int pos, int n, char c); //在指定位置插入n个字符c
			string& erase(int pos, int n = npos); //删除从Pos开始的n个字符

	字符串的子串获取
		函数原型：
			string substr(int pos = 0, int n = npos) const; //返回由pos开始的n个字符组成的字符串

	字符串的方法搭配使用，可以很灵活。
*/

#include<iostream>
using namespace std;

/*****************************************************************************
 *  @brief	string构造函数：
	构造函数原型：
		string(); //默认构造函数。创建一个空的字符串 例如: string str;
		string(const char* s); //有参构造函数。使用字符串s初始化
		string(const string& str); //拷贝构造函数。使用一个string对象初始化另一个string对象
		string(int n, char c); //使用n个字符c初始化
	string的多种构造方式没有可比性，灵活使用即可

 *****************************************************************************/
void s_test01()
{
	//调用string类的默认构造函数 string(); //创建一个空的字符串 例如: string str;
	string s1; 
	cout << "s1 = " << s1 << endl; // 

	//调用string类的有参构造函数 string(const char* s);//使用字符串s初始化
	const char* str1 = "hello world";
	string s2(str1); 
	cout << "s2 = " << s2 << endl; //hello world

	//调用string类的拷贝构造函数 string(const string& str);//使用一个string对象初始化另一个string对象
	string s3(s2); 
	cout << "s3 = " << s3 << endl; //hello world

	//调用string类的有参构造函数 string(int n, char c); //使用n个字符c初始化
	string s4(5, 'w'); 
	cout << "s4 = " << s4 << endl; //wwwww
}

/*****************************************************************************
 *  @brief	string的赋值操作
 *	
	赋值的函数原型：
		//通过 =运算符重载 赋值
		string& operator=(const char* s); //char*类型字符串 赋值给当前的字符串
		string& operator=(const string &s); //把字符串s赋给当前的字符串
		string& operator=(char c); //字符赋值给当前的字符串
		
		//通过 string类的成员函数assign 赋值：assign将一个容器中的元素复制到另一个容器
		string& assign(const char *s); //把字符串s赋给当前的字符串
		string& assign(const char *s, int n); //把字符串s的前n个字符赋给当前的字符串
		string& assign(const string &s); //把字符串s赋给当前字符串
		string& assign(int n, char c); //用n个字符c赋给当前字符串
 *****************************************************************************/
void s_test02()
{
	cout << endl << "通过 =运算符重载 赋值 " << endl;

	string str1;
	str1 = "hello"; //=运算符重载 string& operator=(const char* s);//char*类型字符串 赋值给当前的字符串
	cout << "str1 = " << str1 << endl; //hello

	string str2;
	str2 = str1;  //=运算符重载 string& operator=(const string & s);//把字符串s赋给当前的字符串
	cout << "str2 = " << str2 << endl; //hello

	string str3;
	str3 = 'a'; //=运算符重载 string& operator=(char c);//字符赋值给当前的字符串
	cout << "str3 = " << str3 << endl;//a

	//****************************************
	cout << "通过 string 的成员函数 赋值 " << endl;

	string str4;
	str4.assign("hello2"); //成员函数赋值 string& assign(const char *s); //把字符串s赋给当前的字符串
	cout << "str4 = " << str4 << endl;//hello2


	string str5;
	str5.assign("hello2", 4);//成员函数赋值 string& assign(const char *s, int n); //把字符串s的前n个字符赋给当前的字符串
	cout << "str5 = " << str5 << endl; //hell

	string str5_2;
	string c = "hello2";
	str5_2.assign(c, 3); //第一个参数如果是字符串常量则按从头到第n个字符赋值，如果是字符串变量的话，则从第n个字符开始到字符串结尾赋值
	cout << "str5_2 = " << str5_2 << endl; //lo2
	

	string str6;
	str6.assign(str5);//成员函数赋值 string& assign(const string &s); //把字符串s赋给当前字符串
	cout << "str6 = " << str6 << endl; //hell

	string str7;
	str7.assign(5, 'w');//成员函数赋值 string& assign(int n, char c); //用n个字符c赋给当前字符串
	cout << "str7 = " << str7 << endl; //wwwww

	string str8;
	str8.assign("123456", 1, 3); //从字符串的第1个字符开始向后数3个字符赋值给字符串str8
	cout << "str8 = " << str8 << endl;//234
	/*说明
	 *如果第三个参数大于字符串本身的长度，则赋值到该字符串末尾
	 *如：string a="123";
		  string b="456";
		  a.assign(b,1,4); 结果为 a="56";
	 *如果第二个参数大于字符串本身长度则赋值为空
	 *如：a.assign(b,3,4); 结果为 a="";
	 *第二个参数最大不能超过字符串长度加一，否则程序会运行错误。
	 因为string字符串后面会有一个"\n"符号，这个符号虽然不算在字符串长度里面，但是会占一个字符的空间。
	 所以超过字符串长度加一后会出现std::out_of_range的错误。
	 */

}

/*****************************************************************************
 *  @brief	string的拼接操作
 *	实现在字符串末尾拼接字符串
	
	函数原型：
		string& operator+=(const char* str); //重载+=操作符
		string& operator+=(const char c); //重载+=操作符
		string& operator+=(const string& str); //重载+=操作符
		string& append(const char *s); //把字符串s连接到当前字符串结尾
		string& append(const char *s, int n); //把字符串s的前n个字符连接到当前字符串结尾
		string& append(const string &s); //同operator+=(const string& str)
		string& append(const string &s, int pos, int n);//字符串s中从pos开始的n个字符连接到字符串结尾
	注意：中文一个字占两个字符
 *****************************************************************************/
void s_test03()
{
	cout << endl << "通过 +=运算符重载 实现字符串拼接 " << endl;

	//重载+=操作符 实现拼接
	string str1 = "我";
	str1 += "爱学习";  //string& operator+=(const char* str); //重载+=操作符
	cout << "str1 = " << str1 << endl; //我爱学习

	str1 += 'C'; //string& operator+=(const char c); //重载+=操作符
	cout << "str1 = " << str1 << endl; //我爱学习C

	string str2 = " C++ Python";
	str1 += str2; //string& operator+=(const string& str); //重载+=操作符
	cout << "str1 = " << str1 << endl; //我爱学习C C++ Python

	cout << "通过 string成员函数 实现字符串拼接 " << endl;

	//成员函数 实现拼接
	string str3 = "I";
	str3.append(" Love ");  //string& append(const char *s); //把字符串s连接到当前字符串结尾
	cout << "str3 = " << str3 << endl; //I Love

	str3.append("C C++ Python", 5); //string& append(const char *s, int n); //把字符串s的前n个字符连接到当前字符串结尾
	cout << "str3 = " << str3 << endl;//I Love C C++

	string str4 = " Python Java";
	str3.append(str4); //string& append(const string &s); //同operator+=(const string& str)
	cout << "str3 = " << str3 << endl;//I Love C C++ Python Java

	str3.append(str4, 0, 7); //string& append(const string & s, int pos, int n);//字符串s中从pos开始的n个字符连接到字符串结尾
	cout << "str3 = " << str3 << endl; //I Love C C++ Python Java Python

	str3.append(" 加油啊啊", 0, 5); //注意：中文一个字占两个字符
	cout << "str3 = " << str3 << endl; //I Love C C++ Python Java Python 加油
	

}


/*****************************************************************************
 *  @brief	string的查找和替换操作
 *	查找：查找指定字符串是否存在
 *	替换：在指定的位置替换字符串

	函数原型：（常函数）
		int find(const string& str, int pos = 0) const; //查找str第一次出现位置,从pos开始查找，找不到返回-1
		int find(const char* s, int pos = 0) const; //查找s第一次出现位置,从pos开始查找
		int find(const char* s, int pos, int n) const; //从pos位置查找s的前n个字符第一次位置
		int find(const char c, int pos = 0) const; //查找字符c第一次出现位置
		
		int rfind(const string& str, int pos = npos) const; //查找str最后一次位置,从pos开始查找
		int rfind(const char* s, int pos = npos) const; //查找s最后一次出现位置,从pos开始查找
		int rfind(const char* s, int pos, int n) const; //从pos查找s的前n个字符最后一次位置
		int rfind(const char c, int pos = 0) const; //查找字符c最后一次出现位置
		
		string& replace(int pos, int n, const string& str); //将从pos开始的n个字符替换为字符串str
		string& replace(int pos, int n,const char* s); //将从pos开始的n个字符替换为字符串s
	总结：
		find查找是从左往后，rfind从右往左
		find、rfind找到字符串后返回查找的第一个字符位置，找不到返回-1
		replace在替换时，要指定从哪个位置起，多少个字符，替换成什么样的字符串
 *****************************************************************************/
void s_test04()
{
	cout << endl << "通过 string成员函数 实现字符串查找 " << endl;

	/* 查找 */
	string str1 = "abcdefde";
	int pos1 = str1.find("de"); //3
	cout << "pos1 = " << pos1 << endl;

	int pos2 = str1.find("df"); //-1，找不到返回-1
	cout << "pos2 = " << pos2 << endl;

	//find和rfind的区别：rfind从右往左查，或者说查找最后一次出现的位置
	int pos3 = str1.rfind("de"); //6
	cout << "pos3 = " << pos3 << endl;

	int pos4 = str1.rfind("df"); //-1，找不到返回-1
	cout << "pos4 = " << pos4 << endl;


	/* 替换 */
	string str2 = "abcdef";
	str2.replace(1, 2, "1111"); //将从1开始的2个字符替换为1111
	cout << "str2 = " << str2 << endl; //a1111def

}


/*****************************************************************************
 *  @brief	字符串比较
 *		按字符的ASCII码进行对比
			= 返回 0
			> 返回 1
			< 返回 -1

		函数原型：
			int compare(const string &s) const; //与字符串s比较
			int compare(const char *s) const; //与字符串s比较
		总结：
			字符串对比主要是用于比较两个字符串是否相等，判断谁大谁小的意义并不是很大
 *****************************************************************************/
void s_test05()
{
	cout << endl << "通过 string成员函数 实现字符串比较 " << endl;

	/* str1.compare(str2) */
	string str1 = "abcd";
	string str2 = "abcd";
	int ret1 = str1.compare(str2); //0
	cout << "ret1 = " << ret1 << endl;

	int ret2 = str1.compare("abc"); //1
	cout << "ret2 = " << ret2 << endl;
	
	/* strcmp(str1,str2) */
	cout << strcmp("abc", "abc") << endl;//0
	cout << strcmp("abcd", "abc") << endl;//1
	//cout << strcmp(str1, str2) << endl;//错误，只能传const char *s，不能传string
}

/*****************************************************************************
 *  @brief	字符串下标读写/存取字符
			string中单个字符读写/存取方式有两种 str[下标] 和 str.at()
		函数原型：
			char& operator[](int n); //重载[]，通过[下标]方式读写/存取字符
			char& at(int n); //通过at方法读写/存取字符
 *
 *****************************************************************************/
void s_test06()
{
	cout << endl << "字符串下标存取字符 " << endl;
	string str1 = "hello";

	//1、通过 [下标] 访问字符串
	for (int i = 0; i < str1.size(); i++)
	{
		cout << str1[i] << "  ";
	}
	cout << endl;

	//2、通过 at方法 访问字符串
	for (int i = 0; i < str1.size(); i++)
	{
		cout << str1.at(i) << "  ";
	}
	cout << endl;

	//修改单个字符
	str1[0] = 'x'; //xello
	str1.at(1) = 'x'; //xxllo
	cout << "str1 = " << str1 << endl;

}

/*****************************************************************************
 *  @brief	字符串的插入和删除
 *		函数原型：
			string& insert(int pos, const char* s); //在指定位置插入字符串
			string& insert(int pos, const string& str); //在指定位置插入字符串
			string& insert(int pos, int n, char c); //在指定位置插入n个字符c
			string& erase(int pos, int n = npos); //删除从Pos开始的n个字符
 *****************************************************************************/
void s_test07()
{
	cout << endl << "字符串的插入与删除 " << endl;

	string str1 = "hello";
	str1.insert(1, "222");
	cout << "str1 = " << str1 << endl;//h222ello

	str1.erase(1, 3); 
	cout << "str1 = " << str1 << endl; //hello

}

/*****************************************************************************
 *  @brief	字符串的子串获取
 *	函数原型：
		string substr(int pos = 0, int n = npos) const; //返回由pos开始的n个字符组成的字符串
 *****************************************************************************/
void s_test08()
{
	cout << endl << "字符串的子串获取 " << endl;

	string str1 = "abcdef";
	string subStr1;
	subStr1 = str1.substr(0, 3);
	cout << "subStr1 = " << subStr1 << endl; //abc

	//找出用户名
	string email = "zhangsan@sina.com";
	int pos = email.find('@');//8
	string userName = email.substr(0, pos);
	cout << "userName = " << userName << endl;//zhangsan
}


/*****************************************************************************
 *  @brief	main
 *
 *****************************************************************************/
int main21()
{

	//字符串的构造函数
	s_test01();

	//字符串赋值
	s_test02();

	//字符串拼接
	s_test03();

	//字符串查找和替换
	s_test04();

	//字符串比较
	s_test05();

	//字符串下标存取字符
	s_test06();

	//字符串的插入与删除
	s_test07();

	//字符串的子串获取
	s_test08();

	return 0;
}