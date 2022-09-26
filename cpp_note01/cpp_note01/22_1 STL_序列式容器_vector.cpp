/*
STL 提供有 3 类标准容器：序列容器、排序容器和哈希容器，其中后两类容器有时也统称为关联容器。

	序列容器：
		主要包括 vector 向量容器、list 列表容器以及 deque 双端队列容器。
		之所以被称为序列容器，是因为元素在容器中的位置同元素的值无关，即容器不是排序的。
		将元素插入容器时，指定在什么位置，元素就会位于什么位置。


vector容器
	功能：
		vector数据结构和数组非常相似，也称为单端数组
		尾部插入和删除很方便，头部插入和删除需要移动元素，数据量越大，效率越低

	vector与普通数组区别：
		不同之处在于数组是静态空间，而vector可以动态扩展，可以进行元素的插入和删除

	动态扩展：
		并不是在原空间之后续接新空间，而是找更大的内存空间，然后将原数据拷贝新空间，释放原空间

	vector容器的迭代器是支持随机访问的迭代器(类似数组)

vector容器构造函数
	功能描述：
		创建vector容器
	函数原型：
		vector<T> v; //采用模板实现类实现，默认构造函数
		vector(v.begin(), v.end()); //将v[begin(), end())前闭后开区间中的元素拷贝给本身。
		vector(n, elem); //构造函数将n个elem拷贝给本身。
		vector(const vector &vec); //拷贝构造函数。

给vector容器赋值
	函数原型：
		vector& operator=(const vector &vec);//重载等号操作符
		assign(begin, end); //将[begin, end)区间中的数据拷贝赋值给本身。
		assign(n, elem); //将n个elem拷贝赋值给本身。

vector容器的容量和大小
	对vector容器的容量和大小操作
	函数原型：
		empty(); //判断容器是否为空，为空返回true
		capacity(); //容器的容量
		size(); //返回容器中元素的个数
		resize(int num); //重新指定容器的长度为num，若容器变长，则以默认值填充新位置。
		​				 //如果容器变短，则末尾超出容器长度的元素被删除。
		resize(int num, elem); //重新指定容器的长度为num，若容器变长，则以elem值填充新位置。
		​					   //如果容器变短，则末尾超出容器长度的元素被删除

对vector容器进行插入、删除操作
	函数原型：
		push_back(elem); //尾部插入元素elem
		pop_back(); //删除最后一个元素
		insert(const_iterator pos, elem); //迭代器指向位置pos插入元素elem
		insert(const_iterator pos, int count,elem);//迭代器指向位置pos插入count个元素elem
		erase(const_iterator pos); //删除迭代器指向的元素
		erase(const_iterator start, const_iterator end);//删除迭代器从start到end之间的元素
		clear(); //删除容器中所有元素

	注意：insert 和 erase 的参数是迭代器，指定位置插入和删除可以在迭代器上加减索引数字


vector容器中数据的读写/存取操作
	除了用迭代器获取vector容器中元素，[ ]和at也可以
	函数原型：
		operator[]; //读取或写入索引下标所指的数据
		at(int idx); //读取或写入索引idx所指的数据
		front(); //返回容器中第一个数据元素
		back(); //返回容器中最后一个数据元素


vector互换容器
	功能描述：
		实现两个容器内元素进行互换
	函数原型：
		swap(vec); // 将vec与本身的元素互换

	**借用匿名对象，巧用 swap 进行容器互换，可以达到实用的收缩内存的效果


vector提前预留空间，以减少容器动态扩展容量的次数
		功能描述：
			减少vector在动态扩展容量时的扩展次数
		函数原型：
			reserve(int len);//容器预留len个元素长度，预留位置未被初始化，元素不可访问，访问报错。
			注意：和resize不同，resize 变长后，默认初始化，直接访问不会报错

注意：对于支持随机访问的迭代器的容器，如vector deque等都可以利用sort、reverse标准算法进行排序，需要包含算法头文件
      对于不支持随机访问的容器，如list等，不能用标准算法的sort函数，可用自身容器的成员函数.sort()实现排序。

vector排序
	可以通过全局函数或仿函数指定排序规则
		sort(vec1.begin(),vec1.end(),mySortFunc); //全局回调函数
		sort(vec1.begin(),vec1.end(),MySortClass); //仿函数
*/

#include<iostream>
using namespace std;
#include<vector>
/*****************************************************************************
 *  @brief	vector容器构造
 * 	函数原型：
		vector<T> v; //采用模板实现类实现，默认构造函数
		vector(v.begin(), v.end()); //将v[begin(), end())前闭后开区间中的元素拷贝给本身。
		vector(n, elem); //构造函数将n个elem拷贝给本身。
		vector(const vector &vec); //拷贝构造函数。
 *
 *****************************************************************************/
void printVector(vector<int>& vec)
{
	//for (vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
	//for (vector<int>::iterator it = vec.begin(); it < vec.end(); it++)
	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << " ";
	}
	cout << endl;
}

void v_test01()
{
	cout << endl << "** vector容器构造 **" << endl;
	//默认构造
	vector<int> vec1;
	for (int i = 0; i < 5; i++)
	{
		vec1.push_back(i);
	}
	printVector(vec1); //0 1 2 3 4

	//通过区间的方式构造
	vector<int> vec2(vec1.begin(), vec1.end()); //vec1.begin() vec1.end() 为迭代器
	printVector(vec2);//0 1 2 3 4

	//n个elem方式构造
	vector<int> vec3(5, 3);
	printVector(vec3);//3 3 3 3 3

	//拷贝构造
	vector<int> vec4(vec3);
	printVector(vec4);//3 3 3 3 3

}


/*****************************************************************************
 *  @brief	给vector容器赋值
		函数原型：
			vector& operator=(const vector &vec);//重载等号操作符
			assign(begin, end); //将[begin, end)区间中的数据拷贝赋值给本身。
			assign(n, elem); //将n个elem拷贝赋值给本身。
 
 *****************************************************************************/
void v_test02()
{
	cout << endl << "** vector容器赋值 **" << endl;
	vector<int> vec1;
	for (int i = 0; i < 5; i++)
	{
		vec1.push_back(i);
	}
	printVector(vec1);  //0 1 2 3 4

	//重载等号操作符赋值
	vector<int> vec2 = vec1;
	printVector(vec2); //0 1 2 3 4

	//assign方法赋值
	vector<int> vec3;
	vec3.assign(vec2.begin(), vec2.end());
	printVector(vec3); //0 1 2 3 4

	//n个elem方式赋值
	vector<int> vec4;
	vec4.assign(5, 3);
	printVector(vec4); //3 3 3 3 3
}


/*****************************************************************************
 *  @brief	vector容器的容量和大小
	对vector容器的容量和大小操作
	函数原型：
		empty(); //判断容器是否为空，为空返回true
		capacity(); //容器的容量
		size(); //返回容器中元素的个数
		resize(int num); //重新指定容器的长度为num，若容器变长，则以默认值填充新位置。
		​			     //如果容器变短，则末尾超出容器长度的元素被删除。
		resize(int num, elem); //重新指定容器的长度为num，若容器变长，则以elem值填充新位置。
		​					   //如果容器变短，则末尾超出容器长度的元素被删除

 *****************************************************************************/
void v_test03()
{
	cout << endl << "** vector容器的容量和大小 **" << endl;
	vector<int> vec1;
	for (int i = 0; i < 10; i++)
	{
		vec1.push_back(i);
	}
	printVector(vec1);  //0 1 2 3 4 5 6 7 8 9

	//容器是否为空
	if (vec1.empty()) //如果为真，则容器为空
	{
		cout << "vec1容器为空！" << endl;
	}
	else
	{
		cout << "vec1容器不为空！" << endl;
		//容器的容量和大小
		cout << "vec1容器的容量为：" << vec1.capacity() << endl;//13，容量为动态扩展，capacity≥size
		cout << "vec1容器的大小为：" << vec1.size() << endl;//10
	}

	//重新指定容器大小，变大以默认字符填充，变小直接舍弃
	vec1.resize(15); 
	printVector(vec1);  //0 1 2 3 4 5 6 7 8 9 0 0 0 0 0 

	vec1.resize(10);
	printVector(vec1);  //0 1 2 3 4 5 6 7 8 9

	//重新指定大小，以指定元素填充
	vec1.resize(15,-1);
	printVector(vec1);  //0 1 2 3 4 5 6 7 8 9 -1 -1 -1 -1 -1

}


/*****************************************************************************
 *  @brief	对vector容器进行插入、删除操作
	函数原型：
		push_back(elem); //尾部插入元素elem
		pop_back(); //删除最后一个元素
		insert(const_iterator pos, elem); //迭代器指向位置pos插入元素elem
		insert(const_iterator pos, int count,elem);//迭代器指向位置pos插入count个元素elem
		insert(const_iterator pos, iterator_beg, iterator_end); //在pos位置插入[beg,end)区间的数据，无返回值。
		erase(const_iterator pos); //删除迭代器指向的元素
		erase(const_iterator start, const_iterator end);//删除迭代器从start到end之间的元素
		clear(); //删除容器中所有元素

	注意：insert 和 erase 的参数是迭代器，指定位置插入和删除可以在迭代器上加减索引数字
 *****************************************************************************/

void v_test04()
{
	cout << endl << "** 对vector容器进行插入、删除操作 **" << endl;

	vector<int> vec1;
	//尾插
	vec1.push_back(10);
	vec1.push_back(20);
	vec1.push_back(30);
	printVector(vec1);//10 20 30

	//尾删
	vec1.pop_back();
	printVector(vec1);//10 20

	//插入：第一个参数为迭代器
	vec1.insert(vec1.begin(), 30);//30 10 20
	vec1.insert(vec1.begin()+1, 40);
	printVector(vec1);//30 40 10 20

	//插入：第一个参数为迭代器，插入n个元素
	vec1.insert(vec1.begin(), 2, 100);
	printVector(vec1);//100 100 30 40 10 20

	//在第一个参数的位置，插入后两个参数范围内的数据
	vec1.insert(vec1.begin()+1, vec1.end()-2, vec1.end());
	printVector(vec1); //100 10 20 100 30 40 10 20

	//删除：第一个参数为迭代器
	vec1.erase(vec1.begin());
	printVector(vec1);//10 20 100 30 40 10 20

	vec1.erase(vec1.begin(),vec1.end()-2);
	printVector(vec1);//10 20

	//清空
	vec1.clear();
	printVector(vec1);//

}

/*****************************************************************************
 *  @brief	vector容器中数据的读写/存取操作
		除了用迭代器获取vector容器中元素，[ ]和at也可以
 	函数原型：
		operator[]; //读取或写入索引下标所指的数据
		at(int idx); //读取或写入索引idx所指的数据
		front(); //返回容器中第一个数据元素
		back(); //返回容器中最后一个数据元素
 
 *****************************************************************************/
void v_test05()
{
	cout << endl << "** vector容器中数据的读写/存取操作 **" << endl;

	vector<int> vec1;
	vec1.push_back(10);
	vec1.push_back(20);
	printVector(vec1); //10 20

	//读取下标对应的值 vec[下标]  vec.at(下标)
	cout << "vec1[0] = " << vec1[0] << endl; //10
	cout << "vec1.at(0) = " << vec1.at(0) << endl; //10

	//修改下标所对应的值，同string
	vec1[1] = 10;
	printVector(vec1); //10 20

	vec1.at(1) = 30;
	printVector(vec1); //10 30

	//读取第一个和最后一个元素
	cout << "获取第一个元素为 vec1.front() = " << vec1.front() << endl; //10
	cout << "获取最后一个元素为 vec1.back() = " << vec1.back() << endl; //30

}


/*****************************************************************************
 *  @brief	vector互换容器
	功能描述：
		实现两个容器内元素进行互换
	函数原型：
		swap(vec); // 将vec与本身的元素互换

	借用匿名对象，巧用 swap 进行容器互换，可以达到实用的收缩内存的效果

 *****************************************************************************/
void v_test06()
{
	cout << endl << "** vector利用 swap() 互换容器 **" << endl;

	vector<int> vec1;
	for (int i = 0; i < 10000; i++)
	{
		vec1.push_back(i);
	}
	cout << "vec1的容量为 ：" << vec1.capacity() << endl; //12138
	cout << "vec1的大小为 ：" << vec1.size() << endl; //10000

	//创建 vec1 的匿名对象，匿名容器的容量和大小以原容器的实际大小size为准
	cout << "匿名容器的 容量==大小 = " << vector<int>(vec1).capacity() << endl; //10000


	/** 巧用 swap 进行容器互换，可以收缩内存 */
	cout << endl;
	vec1.resize(3); //对原容量为12138的容器重新指定大小
	cout << "重新指定大小后 vec1的容量为 ：" << vec1.capacity() << endl; //12138
	cout << "重新指定大小后 vec1的大小为 ：" << vec1.size() << endl; //3

	//可见容器的实际数据大小变为了3，但占用容量并无变化，浪费内存，可用匿名对象解决
	//cout << "匿名容器的 容量==大小 = " << vector<int>(vec1).capacity() << endl; //3

	vector<int>(vec1).swap(vec1); 
	//本质相当于先创建vec1的匿名对象obj，该匿名对象obj的 容量==大小==3
	//由于匿名对象随用随亡，所以再交换容器将匿名对象的数据保存至vec1，而原vec1的数据保存在了即将消亡的匿名对象obj里。
	
	cout << endl;
	cout << "巧用 swap 进行容器互换后 vec1的容量为 ：" << vec1.capacity() << endl; //3
	cout << "巧用 swap 进行容器互换后 vec1的大小为 ：" << vec1.size() << endl; //3
}

/*****************************************************************************
 *  @brief	vector提前预留空间，以减少容器动态扩展容量的次数
		功能描述：
			减少vector在动态扩展容量时的扩展次数
		函数原型：
			reserve(int len);//容器预留len个元素长度，预留位置未被初始化，元素不可访问，访问报错。
			注意：和resize不同，resize 变长后，默认初始化，直接访问不会报错
 *
 *****************************************************************************/
void v_test07()
{
	cout << endl << "** vector预留空间，以减少容器动态扩展容量的次数 **" << endl;
	
	/* 预留空间前 */
	cout << endl << "reserve 预留空间前：" << endl;
	vector <int>vec1;

	//统计动态扩展内存的次数代码，妙啊妙啊！！
	int num = 0; //记录开辟内存的次数
	int* p = NULL; //用于判断是否开辟了内存
	for (int i = 0; i < 10000; i++)
	{
		//这10000次追加数据，不是一次性直接分配好的内存，而是容器在动态扩展空间
		vec1.push_back(i);

		if (p != &vec1[0])
		{
			p = &vec1[0];
			num++;
		}
	}
	cout << "预留空间前，这10000次追加数据，一共开辟内存 " << num << " 次" << endl;//24次

	
	/* 预留空间后 */
	//利用 reserve 提前预留空间，可以减少开辟内存的次数
	cout << endl << "reserve 预留空间后：" << endl;

	vector <int>vec2;
	vec2.reserve(10000); //预留空间

	int num2 = 0; //记录开辟内存的次数
	int* p2 = NULL; //用于判断是否开辟了内存
	for (int i = 0; i < 10000; i++)
	{
		vec2.push_back(i);

		if (p2 != &vec2[0])
		{
			p2 = &vec2[0];
			num2++;
		}
	}
	cout << "预留空间后，这10000次追加数据，一共开辟内存 " << num2 << " 次" << endl;//1次
	
}

/*****************************************************************************
 *  @brief	main
 *
 *****************************************************************************/
int main22_1()
{
	//vector容器构造
	v_test01();

	//vector容器赋值
	v_test02();

	//vector容器的容量和大小
	v_test03();

	//对vector容器进行插入、删除操作
	v_test04();

	//vector容器中数据的读写/存取操作
	v_test05();

	//巧用 swap 进行容器互换，以收缩内存
	v_test06();

	//vector提前预留空间
	v_test07();
	return 0;
}

/************ 《vector 容器的成员函数》 **************
	函数成员	函数功能
	begin()		返回指向容器中第一个元素的迭代器。
	end()		返回指向容器最后一个元素所在位置后一个位置的迭代器，通常和 begin() 结合使用。
	rbegin()	返回指向最后一个元素的迭代器。
	rend()		返回指向第一个元素所在位置前一个位置的迭代器。
	cbegin()	和 begin() 功能相同，只不过在其基础上，增加了 const 属性，不能用于修改元素。
	cend()		和 end() 功能相同，只不过在其基础上，增加了 const 属性，不能用于修改元素。
	crbegin()	和 rbegin() 功能相同，只不过在其基础上，增加了 const 属性，不能用于修改元素。
	crend()		和 rend() 功能相同，只不过在其基础上，增加了 const 属性，不能用于修改元素。
	size()		返回实际元素个数。
	max_size()	返回元素个数的最大值。这通常是一个很大的值，一般是 232-1，所以我们很少会用到这个函数。
	resize()	改变实际元素的个数。
	capacity()	返回当前容量。
	empty()		判断容器中是否有元素，若无元素，则返回 true；反之，返回 false。
	reserve()	增加容器的容量。
	shrink _to_fit()	将内存减少到等于当前元素实际所使用的大小。
	operator[ ]		重载了 [ ] 运算符，可以向访问数组中元素那样，通过下标即可访问甚至修改 vector 容器中的元素。
	at()		使用经过边界检查的索引访问元素。
	front()		返回第一个元素的引用。
	back()		返回最后一个元素的引用。
	data()		返回指向容器中第一个元素的指针。
	assign()	用新元素替换原有内容。
	push_back()	在序列的尾部添加一个元素。
	pop_back()	移出序列尾部的元素。
	insert()	在指定的位置插入一个或多个元素。
	erase()		移出一个元素或一段元素。
	clear()		移出所有的元素，容器大小变为 0。
	swap()		交换两个容器的所有元素。
	emplace()	在指定的位置直接生成一个元素。
	emplace_back()	在序列尾部生成一个元素。

	注意：emplace_back()和push_back()的区别：
		emplace_back() 和 push_back() 的区别，就在于底层实现的机制不同。
		push_back() 向容器尾部添加元素时，首先会创建这个元素，然后再将这个元素拷贝或者移动到
		容器中（如果是拷贝的话，事后会自行销毁先前创建的这个元素）；而 emplace_back() 在实现
		时，则是直接在容器尾部创建这个元素，省去了拷贝或移动元素的过程。所以效率更高

除此之外，C++ 11 标准库还新增加了 begin() 和 end() 这 2 个函数，和 vector 容器包含的 begin()
和 end() 成员函数不同，标准库提供的这 2 个函数的操作对象，既可以是容器，还可以是普通数组。当
操作对象是容器时，它和容器包含的 begin() 和 end() 成员函数的功能完全相同；如果操作对象是普通
数组，则 begin() 函数返回的是指向数组第一个元素的指针，同样 end() 返回指向数组中最后一个元素
之后一个位置的指针（注意不是最后一个元素）。

vector 容器还有一个 std::swap(x , y) 非成员函数（其中 x 和 y 是存储相同类型元素
的  vector 容器），它和 swap() 成员函数的功能完全相同，仅使用语法上有差异。
*/