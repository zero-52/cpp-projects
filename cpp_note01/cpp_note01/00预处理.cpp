/*
命名空间：
	namespace 空间名字 { 变量或函数 }  如 namespace first_space { void func() {} }
	空间名字::变量或函数;			  如 first_space::func();

	using namespace 空间名字; //在调用时不用在前面加上该空间名字，后续代码将用其指定命名空间中的名称
	命名空间定义也可以发生嵌套，调用时加::作用域即可


预处理：
	所有的预处理器指令都是以井号（#）开头，只有空格字符可以出现在预处理指令之前。
	预处理指令不是 C++ 语句，所以它们不会以分号（;）结尾。

	#include 指令。这个宏用于把头文件包含到源文件中。

	C++ 还支持很多预处理指令，比如 #include、#define、#if、#else、#line 等
	
	指令的一般形式是：
		#define macro-name replacement-text
		在该文件中后续出现的所有宏都将会在程序编译之前被替换为 replacement-text。

	参数宏
		#define MIN(a,b) (a<b ? a : b)

	条件编译
		#ifdef NULL
			#define NULL 0
		#endif

	# 和 ## 运算符
		# 和 ## 预处理运算符在 C++ 和 ANSI/ISO C 中都是可用的。
		# 运算符会把 replacement-text 令牌转换为用引号引起来的字符串。
		## 运算符用于连接两个令牌
*/

#include<iostream>
using namespace std;

// 第一个命名空间
namespace first_space {
	void func() {
		cout << "Inside first_space" << endl;
	}
}
// 第二个命名空间
namespace second_space {
	void func() {
		cout << "Inside second_space" << endl;
	}
}



int main0()
{
	/* 命名空间 */
	first_space::func(); //调用第一命名空间的函数

	using namespace second_space; //using namespace 指定后续调用的默认命名空间
	func(); //调用第二命名空间的函数

	using namespace std;
	return 0;

}

/*************** #define 原理 ********************** 
#define PI 3.14159

int main()
{

	cout << "Value of PI :" << PI << endl;

	return 0;
}
现在，让我们测试这段代码，看看预处理的结果。假设源代码文件已经存在，接下来使用 - E 选项进行编译，
并把结果重定向到 test.p。现在，如果您查看 test.p 文件，将会看到它已经包含大量的信息，而且在文件底部的值被改为如下：

$ gcc - E test.cpp > test.p

...
int main()
{

	cout << "Value of PI :" << 3.14159 << endl;

	return 0;
}
*/


/*
********* # 和 ## 运算符 实例 ************

#include <iostream>
using namespace std;

#define MKSTR( x ) #x

int main ()
{
	cout << MKSTR(HELLO C++) << endl;

	return 0;
}
当上面的代码被编译和执行时，它会产生下列结果：
	HELLO C++

让我们来看看它是如何工作的。不难理解，C++ 预处理器把下面这行：
cout << MKSTR(HELLO C++) << endl;

转换成了：
cout << "HELLO C++" << endl;

## 运算符用于连接两个令牌。下面是一个实例：

#define CONCAT( x, y )  x ## y
当 CONCAT 出现在程序中时，它的参数会被连接起来，并用来取代宏。
例如，程序中 CONCAT(HELLO, C++) 会被替换为 "HELLO C++"，如下面实例所示。

实例
#include <iostream>
using namespace std;

#define concat(a, b) a ## b
int main()
{
   int xy = 100;

   cout << concat(x, y);
   return 0;
}
当上面的代码被编译和执行时，它会产生下列结果：
	100

让我们来看看它是如何工作的。不难理解，C++ 预处理器把下面这行：
cout << concat(x, y);

转换成了：
cout << xy;
*/