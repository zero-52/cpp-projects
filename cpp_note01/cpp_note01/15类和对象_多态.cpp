/*****************************************************************************
 *  @file     xxx.h
 *  @brief    cpp 多态：减少代码冗余
 *
 *  @author   Tod
 *  @version  1.0.1(版本号)
 *  @email    xxxxxx@xxx.com
 *  @date     2022-09-3
 *****************************************************************************/


/*****************************************************************************
 *  @brief	多态
多态：
	//多态分为两类
		静态多态: 函数重载 和 运算符重载 属于静态多态，复用函数名
		动态多态: 派生类 和 虚函数 实现运行时多态 
	虚函数：
		父类中对应函数前面加 virtual 关键字，即为虚函数
			
	静态多态和动态多态区别：
		静态联编：静态多态的函数地址早绑定 - 编译阶段确定函数地址，即编译时多态
		动态联编：动态多态的函数地址晚绑定 - 运行阶段确定函数地址，即运行时多态（通过虚函数表现）

	//多态满足条件：
		1、继承：多态一定发生在子类和父类之间
		2、重写：子类重写父类中的虚函数 (重写：函数返回值类型 函数名 参数列表 完全一致称为重写，注意与重载的区别)
	//多态使用条件：
		3、父类的指针或引用指向子类对象
			
	tip：c++中允许父子类型相互转换，不需要强制类型转换，即父类的引用或指针可以直接指向子类对象
		 如 Parent & parent = son，或者函数传参父子类之间进行转换

//多态原理剖析
	
	多态案例1

多态的优点：
 	代码组织结构清晰
 	可读性强
 	利于前期和后期的扩展以及维护

注：C++开发提倡利用多态设计程序架构，因为多态优点很多


纯虚函数 和 抽象类：
 	在多态中，通常父类的虚函数实现是无意义的，主要都是调用子类重写的内容
 	因此，可以将 虚函数 改为 纯虚函数，若类中包含至少一个纯虚函数，该类则称为 抽象类

 	纯虚函数语法：
 		virtual 返回值类型 函数名(参数列表) = 0;
 		如 virtual void func(int a, int b) = 0;  //纯虚函数：不做任何事
 
 	抽象类的特点：
 		无法实例化对象（但能创建指针），抽象类只能做基类
 		除非抽象类的子类重写抽象类中的所有纯虚函数，否则子类也属于抽象类，导致子类也无法实例化对象
 
	多态案例2

虚析构 和 纯虚析构：
 
	//多态使用时，如果子类中有属性开辟到堆区并在子类析构函数中释放掉，而多态需要父类指针或引用指向子类对象，
	//那么在释放掉该父类指针资源时，会调用父类的析构函数，但是却无法调用到子类的析构函数，导致子类中的堆区数据未被释放，可能引起内存泄露。
		
	解决方式：将父类中的 析构函数 改为 虚析构 或者 纯虚析构函数

	虚析构和纯虚析构共性：
		可以解决父类指针释放时无法释放子类对象的问题
		都需要有具体的函数实现（纯虚析构需要在类外加类作用域定义）

	虚析构和纯虚析构区别：
		如果是纯虚析构，该类属于抽象类，无法实例化对象

	虚析构语法：
		virtual ~类名(){ }

	纯虚析构语法：
		virtual ~类名() = 0;  //纯虚析构不止要声明，还要对函数定义，因为释放父类指针时需要调用
		//一旦存在纯虚析构，类就变为抽象类，不可实例化
		//纯虚析构代码在类外实现
		类名::~类名(){ }  //纯虚析构类外定义

	注意：不论是虚析构还是纯虚析构均需要代码实现

	总结：
		​ 1. 虚析构或纯虚析构就是用来解决通过父类指针释放子类对象
		​ 2. 如果子类中没有堆区数据，可以不写为虚析构或纯虚析构
		​ 3. 拥有纯虚析构函数的类也属于抽象类

	多态案例3
 *****************************************************************************/

#include<iostream>
using namespace std;

/*****************************************************************************
 *  @brief	静态多态（静态联编） 与 动态多态（动态联编）
 *									
 *				静态多态: 函数重载 和 运算符重载 属于静态多态，复用函数名
 *				动态多态: 派生类 和 虚函数 实现运行时多态
 *****************************************************************************/

class Animals
{
public:
	void speak()  //静态多态的函数地址早绑定 - 编译阶段确定函数地址
	{
		cout << "动物在说话" << endl;
	}
	//虚函数：函数前面加上virtual关键字，变成虚函数，使编译器在编译的时候不能确定函数调用地址。
	virtual void speak2()  //动态多态的函数地址晚绑定 - 运行阶段确定函数地址
	{
		cout << "动物在说话 2" << endl;
	}
};

class Cat :public Animals
{
public:
	void speak()
	{
		cout << "猫咪在说话" << endl;
	}
	virtual void speak2()  //重写virtual时，可以不带virtual关键字
	{
		cout << "猫咪在说话 2" << endl;
	}
};
class Dog :public Animals
{
public:
	void speak()
	{
		cout << "狗狗在说话" << endl;
	}
	virtual void speak2()
	{
		cout << "狗狗在说话 2" << endl;
	}
};

void doSpeak(Animals& anim)   // Animals & anim = cat; //c++中允许父子类型的相互转换，不需要强制类型转换。
{
	anim.speak();//由于形参把接收的子类实参转换为了父类Animals，所以调用的是Animals的函数
}
void doSpeak2(Animals& anim)
{
	anim.speak2();  //多态：针对同一接口，因传入对象不同调用也不同
}

void test20()
{
	/* 静态多态，函数重载 或 运算符重载，前面已经讲过，不再讲 */

	/* 不使用虚函数时，编译时已经绑定函数地址，由于形参为父类，所以即使传入不同子类对象，默认调用仍为父类函数 */
	Cat cat;
	doSpeak(cat);  //动物在说话

	Dog dog;
	doSpeak(dog);  //动物在说话
	
	/* 我们希望传入什么对象，那么就调用什么对象的函数。
	   即运行时根据传入对象绑定函数地址，在父类中被重写的函数前加 virtual 即可实现 */
	
	/* 动态多态： 虚函数，使编译器在编译的时候不能确定函数调用*/
	Cat cat2;
	doSpeak2(cat2);  //猫咪在说话

	Dog dog2;
	doSpeak2(dog2);  //狗狗在说话

}


//多态原理剖析
void test21()
{
	//如果类中不存在非静态成员属性，则sizeof = 1，但如果同时 存在虚函数，则sizeof = 8
	cout << "sizeof(Animals) = " << sizeof(Animals) << endl; //4或8，依照多少位机器而定

	/* 之所以为8，是因为类中由于virtual实际存放了一个虚函数表指针 vfptf，指向了虚函数表 vftable，
	   虚函数表中存放数据偏移地址，子类继承时，同样会把该指针和表继承下来，由于virtual存在且在子类中重写，
	   则子类中的数据地址将替换继承下来的vftable中的数据，调用时则传入什么对象就调用什么对象的函数
	*/
}


/*****************************************************************************
 *  @brief	多态案例1
 *		分别利用普通写法和多态技术，设计实现两个操作数进行运算的计算器类
 *			
 *		多态的优点：
 *			代码组织结构清晰
 *			可读性强
 *			利于前期和后期的扩展以及维护
 *****************************************************************************/

//普通写法实现计算器
class Calculator1
{
public:
	int m_Num1;
	int m_Num2;
public:
	Calculator1()
	{
		cout << endl << "**** 这是一个简易计算器，支持加减 ****" << endl;
	}
	int getResult(string oper)
	{
		if (oper == "+")
		{
			return m_Num1 + m_Num2;
		}
		else if (oper == "-")
		{
			return m_Num1 - m_Num2;
		}
		//如果想扩展新的功能，需要修改源代码，而多态的方式只需往后追加扩展
		//在真实开发中，提倡 开闭原则：对扩展进行开放，对修改进行关闭
	}

};
void test22()
{
	Calculator1 c1;
	c1.m_Num1 = 10;
	c1.m_Num2 = 20;
	cout << endl << "普通写法实现计算器" << endl;
	cout << "相加的结果 Num1 + Num2 = " << c1.getResult("+") << endl;
	cout << "相加的结果 Num1 - Num2 = " << c1.getResult("-") << endl;
}

//利用多态实现计算器  
class Calculator2  
{
public:
	int m_Num1;
	int m_Num2;
	virtual int getReult()  //多态需满足的条件：虚函数  重写
	{
		return 0;
	}
};
class AddCalculator :public Calculator2
{
public:
	virtual int getReult()  //多态需满足的条件：虚函数  重写
	{
		return m_Num1 + m_Num2;
	}
};
class SubCalculator :public Calculator2
{
public:
	virtual int getReult()
	{
		return m_Num1 - m_Num2;
	}
};

void test23()
{
	cout << "多态写法实现计算器" << endl;
	
	//多态使用的条件 ：父类指针或引用指向子类对象
	
	Calculator2* abc = new AddCalculator;
	//加法
	abc->m_Num1 = 10;
	abc->m_Num2 = 10;	
	cout << "相加的结果 Num1 + Num2 = " << abc->getReult() << endl;
	delete abc; //堆数据用完记得释放，注意：释放只是释放了堆区的数据，指针变量仍存在

	//减法
	abc = new SubCalculator;
	abc->m_Num1 = 10;
	abc->m_Num2 = 10;
	cout << "相加的结果 Num1 - Num2 = " << abc->getReult() << endl;

	//后续需要扩展乘法等功能，只需要追加扩展即可，很方便
}


/*****************************************************************************
 *  @brief	纯虚函数 和 抽象类
 *		在多态中，通常父类的虚函数实现是无意义的，主要都是调用子类重写的内容
 *		因此，可以将 虚函数 改为 纯虚函数，若类中包含至少一个纯虚函数，该类则称为 抽象类
 *
 *	纯虚函数语法：
 *		virtual 返回值类型 函数名(参数列表) = 0;
 *		如 virtual void func(int a, int b) = 0;  //纯虚函数：不做任何事
 *
 *	抽象函数的特点：
 *		无法实例化对象（但能创建指针），抽象类只能做基类
 *		除非抽象类的子类重写抽象类中的所有纯虚函数，否则子类也属于抽象类，导致子类也无法实例化对象
 *****************************************************************************/
class AbstractClass01   //含有纯虚函数的类称为抽象类：无法实例化对象
{
public:
	//纯虚函数：不做任何事           
	virtual void func() = 0;
};

class Son05 :public AbstractClass01  
{
public:
	virtual void func()  //抽象类的子类必须重写抽象类中的纯虚函son数，否则子类也属于抽象类
	{
		cout << endl << "子类重写父类纯虚函数" << endl;
	}
};

void test24()
{
	
	//AbstractClass01 aaa;  //错误，抽象类不能实例化对象
	//new AbstractClass01;  //错误，抽象类不能实例化对象

	Son05 son; //子类重写父类的纯虚函数后才可以实例化对象，否则报错
	son.func();  //直接调用

	//多态，new 哪个对象，调用哪个对象的方法
	AbstractClass01* bs6 = new Son05;
	bs6->func();  //多态调用
}



/*****************************************************************************
 *  @brief	多态案例2
 *		制作饮品的大致流程为：煮水 - 冲泡 - 倒入杯中 - 加入辅料
 *		利用多态技术实现本案例，提供抽象制作饮品基类，提供子类制作咖啡和茶叶
 *****************************************************************************/
class AbstractDrinking  //抽象类
{
public:
	//煮水 纯虚函数
	virtual void Boil() = 0;
	//冲泡 纯虚函数
	virtual void Brew() = 0;
	//倒入杯中 
	virtual void PourInCup() = 0;
	//加辅料
	virtual void PutSth() = 0;

	//制作饮品
	void makeDrink()
	{
		Boil();
		Brew();
		PourInCup();
		PutSth();
	}
};

//制作咖啡
class Coffee :public AbstractDrinking
{
	//煮水 纯虚函数
	virtual void Boil()
	{
		cout << "开始煮水" << endl;
	}
	//冲泡 纯虚函数
	virtual void Brew()
	{
		cout << "开始冲泡咖啡" << endl;
	}
	//倒入杯中 
	virtual void PourInCup()
	{
		cout << "将咖啡倒入杯中" << endl;
	}
	//加辅料
	virtual void PutSth()
	{
		cout << "加辅料：放入糖和牛奶" << endl;
	}
};

//制作茶叶
class Tea :public AbstractDrinking
{
	//煮水 纯虚函数
	virtual void Boil()
	{
		cout << "开始煮水" << endl;
	}
	//冲泡 纯虚函数
	virtual void Brew()
	{
		cout << "开始冲泡茶叶" << endl;
	}
	//倒入杯中 
	virtual void PourInCup()
	{
		cout << "将茶叶水倒入杯中" << endl;
	}
	//加辅料
	virtual void PutSth()
	{
		cout << "加辅料：放入枸杞" << endl;
	}
};

void startMake(AbstractDrinking* abstDrink)  
{
	abstDrink->makeDrink();
	delete abstDrink;  //因为传递的是堆数据，记得释放
}

void test25()
{
	startMake(new Coffee);

	startMake(new Tea);
}



/*****************************************************************************
 *  @brief	虚析构 和 纯虚析构
 * 
	//多态使用时，如果子类中有属性开辟到堆区并在子类析构函数中释放掉，而多态需要父类指针或引用指向子类对象，
	//那么在释放掉该父类指针资源时，会调用父类的析构函数，但是却无法调用到子类的析构函数，导致子类中的堆区数据未被释放，可能引起内存泄露。
		
	解决方式：将父类中的 析构函数 改为 虚析构或者纯虚析构函数

	虚析构和纯虚析构共性：
		可以解决父类指针释放释放时无法释放子类对象的问题
		父类中都需要有具体的函数实现（纯虚析构代码在类外实现）

	虚析构和纯虚析构区别：
		如果是纯虚析构，该类属于抽象类，无法实例化对象

	虚析构语法：
		virtual ~类名(){}

	纯虚析构语法：
		virtual ~类名() = 0;  //纯虚析构不止要声明，还要代码实现，因为释放父类指针时需要调用
		//一旦存在纯虚析构，类就变为抽象类，不可实例化
		//纯虚析构代码在类外实现
		类名::~类名(){}  //注意：不论是虚析构还是纯虚析构均需要代码实现

	总结：
		​ 1. 虚析构或纯虚析构就是用来解决通过父类指针释放子类对象
		​ 2. 如果子类中没有堆区数据，可以不写为虚析构或纯虚析构
		​ 3. 拥有纯虚析构函数的类也属于抽象类
 *
 *****************************************************************************/

class Animal2
{
public:
	Animal2()
	{
		cout << "父类Animal2 的构造函数" << endl;
	}

	virtual void speak() = 0; //纯虚函数

	/*~Animal2()  
	{
		cout << "父类Animal2 的析构函数" << endl;

	}*/

	/* 1、虚析构 */
	//virtual ~Animal2() //为了在能释放父类指针时，子类析构能被调用，要变成 虚析构 或 纯虚析构
	//{
	//	cout << "父类Animal2 的虚析构函数" << endl;
	//}

	/* 2、纯虚析构 */
	virtual ~Animal2() = 0;  //注意：纯虚析构函数不止要声明还要实现，有了纯虚析构，类就变为抽象类，无法实例化

	//注意：不论是虚析构还是纯虚析构均需要代码实现
};
//纯虚析构实现
Animal2::~Animal2()
{
	cout << "Animals2 的纯虚析构函数实现" << endl;
}

class Cat2 :public Animal2
{
public:
	Cat2(string name)
	{
		cout << "子类Cat2 的构造函数" << endl;
		
		m_Name = new string(name);  //堆区
	}

	void speak()
	{
		cout << *m_Name << "小猫在说话" << endl;
	}

	~Cat2()  //子类析构，当释放父类指针时，父类析构被调用，子类析构并未被调用，除非将 父类的析构函数，变为 虚析构 或 纯虚析构
	{
		cout << "子类Cat2 的析构函数" << endl;
		if (m_Name != NULL)
		{
			delete m_Name;  //释放堆区
			m_Name = NULL;
		}
	}

	string* m_Name;
	
};

void test26()
{
	Animal2* animal02 = new Cat2("Tom");
	animal02->speak();

	delete animal02;
	//在释放父类指针时，会调用父类的析构函数，却调用不到 子类Cat2 的析构函数，导致子类堆数据无法释放
	//除非将 父类的析构函数，变为 虚析构 或 纯虚析构 （与 虚函数 或 纯虚函数 特性相同）

}


/*****************************************************************************
 *  @brief	多态案例3
 *	电脑主要组成部件为 CPU（用于计算），显卡（用于显示），内存条（用于存储）
	将每个零件封装出抽象基类，并且提供不同的厂商生产不同的零件，例如Intel厂商和Lenovo厂商
	创建电脑类提供让电脑工作的函数，并且调用每个零件工作的接口
	测试时组装三台不同的电脑进行工作
 *****************************************************************************/
//抽象出每个零件的类
class Cpu
{
public:
	//纯虚函数，抽象计算函数
	virtual void calculator() = 0;
};

class VideoCard
{
public:
	virtual void show() = 0;
};

class Memory
{
public:
	virtual void storage() = 0;
};

//Intel厂商生产的零件类
class IntelCpu :public Cpu
{
public:
	virtual void calculator()
	{
		cout << "IntelCpu 开始计算了！" << endl;
	}
};

class IntelVideoCard :public VideoCard
{
public:
	virtual void show()
	{
		cout << "IntelVideoCard 开始显示了！" << endl;
	}
};
class IntelMemory :public Memory
{
public:
	virtual void storage()
	{
		cout << "IntelMemory 开始运行了！" << endl;
	}
};

//Hasee厂商生产的零件类
class HaseeCpu :public Cpu
{
public:
	virtual void calculator()
	{
		cout << "HaseeCpu 开始计算了！" << endl;
	}
};

class HaseeVideoCard :public VideoCard
{
public:
	virtual void show()
	{
		cout << "HaseeVideoCard 开始显示了！" << endl;
	}
};
class HaseeMemory :public Memory
{
public:
	virtual void storage()
	{
		cout << "HaseeMemory 开始运行了！" << endl;
	}
};

class Computer 
{
public:
	Computer(Cpu* cpu, VideoCard* vc, Memory* mm)  //满足多态。实参为子类 new的对象，形参为其父类，还需要释放
	{
		//m_cpu = new Cpu;抽象类不允许实例化
		m_cpu = cpu;
		m_vc = vc;
		m_mm = mm;

	}
	//提供工作函数
	void working()
	{
		m_cpu->calculator();
		m_vc->show();
		m_mm->storage();

	}
	~Computer()
	{
		cout << "computer 的析构函数，释放堆数据" << endl;
		//释放cpu零件
		if (m_cpu != NULL)
		{
			delete m_cpu;
			m_cpu = NULL;
		}
		//释放显卡零件
		if (m_vc != NULL)
		{
			delete m_vc;
			m_vc = NULL;
		}
		//释放内存零件
		if (m_mm != NULL)
		{
			delete m_mm;
			m_mm = NULL;
		}
	}
	//Cpu cpu; 抽象类不能实例化
	Cpu* m_cpu;
	VideoCard* m_vc;
	Memory* m_mm;
};

void test27()
{
	//第一台电脑零件
	Cpu* intelCpu = new IntelCpu;
	VideoCard* intelCard = new IntelVideoCard;
	Memory* intelMem = new IntelMemory;

	//第一台电脑
	cout << endl << "第一台电脑" << endl;
	//Computer computer1(intelCpu, intelCard, intelMem);
	//computer1.working();
	Computer* computer1 = new Computer(intelCpu, intelCard, intelMem);
	computer1->working();
	delete computer1;

	//第二台电脑
	cout << endl << "第二台电脑" << endl;
	Computer* computer2 = new Computer(new HaseeCpu, new HaseeVideoCard, new HaseeMemory);
	computer2->working();
	delete computer2;

	//第三台电脑
	cout << endl << "第三台电脑" << endl;
	Computer* computer3 = new Computer(new HaseeCpu, new IntelVideoCard, new HaseeMemory);
	computer3->working();
	delete computer3;
}

/*****************************************************************************
 *  @brief	main 函数
 *
 *****************************************************************************/
int main15()
{
	//静态联编 和 动态联编
	test20();

	//多态原理剖析
	test21();

	//普通写法实现计算器
	test22();

	//多态实现计算器
	test23();

	//纯虚函数 和 抽象类
	test24();

	//多态案例2
	test25();

	//虚析构 和 纯虚析构
	cout << endl;
	test26();

	cout << endl;
	//多态案例3
	test27();


	return 0;
}