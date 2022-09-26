
/*****************************************************************************
 *  @brief	文件操作
 *		程序运行时产生的数据都属于临时数据，程序一旦运行结束就会被释放
 *		为了记录下来一些数据，通过文件可以使数据持久化
 
 		文件类型：
 			1. 文本文件 ：文件以文本的 ASCII码 形式存储在计算机中
			2. 二进制文件 ：文件以文本的 二进制形式 存储在计算机中，用户一般不能直接读懂它们
  
 		C++中对文件操作需要包含头文件 <fstream>
 		操作文件的三大类：
 			ofstream ：写操作（output file）
 			ifstream ：读操作（input file）
 			 fstream ：读写操作
  
 		文本文件写文件步骤：
 			1. 包含头文件   
					#include <fstream>
			2. 创建流对象  
					ofstream ofs;
			3. 指定文件路径与打开方式
					ofs.open("文件路径",打开方式);
			4. 写数据<<
					ofs << "写入的数据";
			5. 关闭文件
					ofs.close();

   ​
			文件打开方式：

			| 打开方式    | 解释								 |
			| ----------- | ------------------------------------ |
			| ios::in     | 为读文件而打开文件					 |
			| ios::out    | 为写文件而打开文件					 |
			| ios::ate    | 初始位置：文件尾 (at the end)	     |
			| ios::app    | 追加方式写文件 (append)				 |
			| ios::trunc  | 如果文件存在先删除，再创建 (truncate)|
			| ios::binary | 二进制方式							 |

			注意：文件打开方式可以配合使用，利用|操作符

			例如：ios::binary | ios:: out  //用二进制方式写文件

		文本文件读文件步骤：
			1. 包含头文件
					#include <fstream>
			2. 创建流对象
					ifstream ifs;
			3. 打开文件并判断文件是否打开成功
					ifs.open("文件路径",打开方式);   ifs.is_open()
			4. 读数据
					四种方式读取
			5. 关闭文件
					ifs.close();

		二进制文件写文件
			二进制方式写文件主要利用流对象调用成员函数 write

			函数原型 ：ostream& write(const char * buffer,int len); //用于二进制文件写

			参数解释：字符指针buffer指向内存中一段存储空间。len是读写的字节数

		二进制文件读文件
			二进制方式读文件主要利用流对象调用成员函数 read

			函数原型：istream& read(char *buffer,int len);  //用于二进制文件读

			参数解释：字符指针buffer指向内存中一段存储空间。len是读写的字节数

		注意：要实现以二进制形式读写文件，<< 和 >> 将不再适用，需要使用 C++ 标准库专门提供的 read() 和 write() 成员方法。
		其中，read() 方法用于以二进制形式从文件中读取数据；write() 方法用于以二进制形式将数据写入文件。

		二进制文件操作，不单单可以操作内置数据类型int，string，float 等，还可以操作自定义数据类型
 *****************************************************************************/


#include<iostream>
using namespace std;
#include<fstream>
#include<string>


/*****************************************************************************
 *  @brief	文本文件写文件 
 *
 *****************************************************************************/
void writeTextFile()
{
	cout << endl << "文本文件写操作" << endl;

	//1、包含头文件 #include<fstream>
	
	//2、创建流对象
	ofstream ofs; 
	
	//3、打开文件，指定打开方式
	ofs.open("./16TextFile.txt", ios::out);	//如果文件不存在，则创建，文件存在，写入直接覆盖原数据
	
	//4、写数据
	cout << "这是文本文件写入数据测试，请查看文件" << endl;  
	ofs << "姓名：李四" << endl;  //endl此时在文件中也表示换行
	ofs << "性别：男" << endl;
	ofs << "年龄：20" << endl;

	/*string str1 = "hello";
	ofs.write((const char*)&str1, sizeof(str1)); 用于二进制文件写才用的 */

	//5、关闭文件
	ofs.close(); 
}

/*****************************************************************************
 *  @brief	文本文件读文件
 *
 *****************************************************************************/
void readTextFile()
{
	cout << endl << "文本文件读操作" << endl;

	//1、包含头文件 #include<fstream>

	//2、创建流对象
	ifstream ifs;

	//3、打开文件，指定打开方式
	ifs.open("./16TextFile.txt", ios::in);	//如果文件不存在，则报错

	if (!ifs.is_open()) //ifs.is_open() 打开成功返回true
	{
		cout << "文件打开失败" << endl;
	}

	//4、读数据

	//第一种读方式：每次读一个字符串（以空格和换行为分割点）
	cout << endl << "第一种读方式" << endl;
	char buf1[1024] = { 0 };
	while (ifs >> buf1)  //读完后返回flase
	{
		cout << buf1 << endl;
	}

	//5、关闭文件
	ifs.close();

	//第二种读方式：每次读一行
	ifs.open("./16TextFile.txt", ios::in);
	cout << endl << "第二种读方式" << endl;
	char buf2[1024] = { 0 };
	while (ifs.getline(buf2, sizeof(buf2)))
	{
		cout << buf2 << endl;

	}
	ifs.close();

	//第三种读方式：每次读一行
	ifs.open("./16TextFile.txt", ios::in);
	cout << endl << "第三种读方式" << endl;
	string buf3;
	while (getline(ifs, buf3))  //需要包含 string头文件
	{
		cout << buf3 << endl;
	}
	ifs.close();

	//第四种读方式(单字符方式读取，速度不如前面)
	ifs.open("./16TextFile.txt", ios::in);
	cout << endl << "第四种读方式" << endl;
	char c;
	while ((c = ifs.get()) != EOF)  //End Of File
	{
		cout << c;
	}

	//5、关闭文件
	ifs.close();
}


/*****************************************************************************
 *  @brief	二进制文件写入
 *				二进制方式写文件主要利用流对象调用成员函数 write
 *
 *				函数原型 ：ostream& write(const char * buffer,int len);
 *
 *				参数解释：字符指针buffer指向内存中一段存储空间。len是读写的字节数
 *
 *		二进制文件操作，不单单可以操作内置数据类型int，string，float 等，还可以操作自定义数据类型
 *****************************************************************************/
class PPP
{
public:
	char m_Name[64];
	//string m_major;  //用char，不要用c++的string，否则读该成员会报错
	int m_Age;
};

void writeBinaryFile()
{
	cout << endl << "二进制文件写操作" << endl;

	//1、包含头文件 #include<fstream>

	//2、创建流对象
	//ofstream ofs;
	ofstream ofs("./16BinaryFile.txt", ios::out | ios::binary); //也可以在创建对象时指定路径和方式

	//3、打开文件，指定打开方式
	//ofs.open("./16BinaryFile.txt", ios::out | ios::binary);  //注意打开方式

	//4、写数据（写入数据后打开文件查看时，乱码很正常，读出数据看正确与否即可）
	//PPP person = { "张三", "电子信息",20 };
	PPP person = { "张三", 20 };
	ofs.write((const char*)&person, sizeof(PPP));  //write函数用于二进制写

	//5、关闭文件
	ofs.close();

}


/*****************************************************************************
 *  @brief	二进制文件读文件
				二进制方式读文件主要利用流对象调用成员函数 read

				函数原型：istream& read(char* buffer, int len);  //用于二进制文件读

				参数解释：字符指针buffer指向内存中一段存储空间。len是读写的字节数
 *****************************************************************************/
class PPP2
{
public:
	char m_Name[64];
	//string m_major; //用char，不要用c++的string，否则读该成员会报错
	int m_Age;
};
void readBinaryFile()
{
	cout << endl << "二进制文件读操作" << endl;
	//1、包含头文件 #include<fstream>

	//2、创建流对象
	ifstream ifs;

	//3、打开文件，指定打开方式，并判断是否打开成功
	ifs.open("./16BinaryFile.txt", ios::in | ios::binary);  //注意打开方式

	if (!ifs.is_open())
	{
		cout << "文件打开失败" << endl;
		return;
	}

	//4、读数据
	PPP2 person2;
	ifs.read((char*)&person2, sizeof(PPP2));	//read函数用于二进制读
	cout << "姓名：" << person2.m_Name << endl;
	//cout << "专业：" << person2.m_major << endl;
	cout << "年龄：" << person2.m_Age << endl;

	//5、关闭文件
	ifs.close();

}

/*****************************************************************************
 *  @brief	main 函数
 *
 *****************************************************************************/
int main16()
{
	/* 往文本文件写数据 */
	writeTextFile();

	cout << endl;
	/* 从文本文件读数据 */
	readTextFile();

	/* 往二进制文件写数据 */
	writeBinaryFile();

	/* 往二进制文件读数据 */
	readBinaryFile();

	return 0;
}