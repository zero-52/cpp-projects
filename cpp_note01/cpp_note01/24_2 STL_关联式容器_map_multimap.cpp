/*
	关联式容器的底层实现采用的是红黑树结构；
	无序容器的底层实现采用的是哈希表的存储结构。

	关联式容器可以快速查找、读取或者删除所存储的元素，同时该类型容器插入元素的效率也比序列式容器高。

	使用关联式容器存储的元素，都是一个一个的“键值对”（ <key,value> ）
	序列式容器中存储的元素默认都是未经过排序的，而关联式容器存储，默认会根据各元素的键值的大小做升序排序。

关联式容器名称	特点
	set			定义在 <set> 头文件中，使用该容器存储的数据，各个元素键和值完全相同，且各个元素的值不能
				重复（保证了各元素键的唯一性）。该容器会自动根据各个元素的键（其实也就是元素值）的大小进行升序排序（调用 std::less<T>）。

	multiset	定义在 <set> 头文件中，和 set 容器唯一的不同在于，multiset 容器中存储元素的值可以重复（一旦值重复，则意味着键也是重复的）。
		
	map			定义在 <map> 头文件中，使用该容器存储的数据，其各个元素的键必须是唯一的（即不能重复），
				该容器会根据各元素键的大小，默认进行升序排序（调用 std::less<T>）。
		
	multimap	定义在 <map> 头文件中，和 map 容器唯一的不同在于，multimap 容器中存储元素的键可以重复。
	
	

map/ multimap容器
	map中所有元素都是pair，创建时要指定两个类型
	pair中第一个元素为key（键值），起到索引作用，第二个元素为value（实值）
	所有元素都会根据元素的键值自动排序

	本质：
		map/multimap属于关联式容器，底层结构是用二叉树实现。
	
	优点：
		可以根据key值快速找到value值
		map容器高性能高效率，使用频次仅次于 vector 和 list
	
	map和multimap区别：
		map 不允许容器中有重复key值元素
		multimap 允许容器中有重复key值元素

		
map构造和赋值
	功能描述：
		对map容器进行构造和赋值操作
	函数原型：
		构造：
			map<T1, T2> mp; //map默认构造函数:
			map(const map &mp); //拷贝构造函数
		赋值：
			map& operator=(const map &mp); //重载等号操作符
	

map大小和交换
	功能描述：
		统计map容器大小以及交换map容器
	函数原型：
		size(); //返回容器中元素的数目
		empty(); //判断容器是否为空
		swap(st); //交换两个集合容器


map插入和删除
	功能描述：
		map容器进行插入数据和删除数据
	函数原型：
		insert(elem); //在容器中插入对组元素。
		erase(pos); //删除pos迭代器所指的元素，返回下一个元素的迭代器。
		erase(beg, end); //删除区间[beg,end)的所有元素 ，返回下一个元素的迭代器。
		erase(key); //删除容器中值为key的元素。
		clear(); //清除所有元素


map查找和统计
	功能描述：
		对map容器进行查找数据以及统计数据
	函数原型：
		find(key); //查找key是否存在,若存在，返回该键的元素的迭代器；若不存在，返回map.end();
		count(key); //统计key的元素个数


map容器排序
	学习目标：
		map容器默认排序规则为 按照key值进行 从小到大排序，掌握如何改变排序规则
	主要技术点:
		利用仿函数，可以改变排序规则
		对于自定义数据类型，map要指定排序规则,同set容器

*/

#include<iostream>
#include <map>
using namespace std;

/*****************************************************************************
 *  @brief	map构造和赋值
	功能描述：
		对map容器进行构造和赋值操作
	函数原型：
		构造：
			map<T1, T2> mp; //map默认构造函数:
			map(const map &mp); //拷贝构造函数
		赋值：
			map& operator=(const map &mp); //重载等号操作符

 *****************************************************************************/
void printMap(map<int, int>& m)
{
	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "key = " << (*it).first << " val = " << (*it).second << endl;
	}
	cout << endl;
	/*for (int i = 0; i < m.size(); i++)
	{
		cout << m[i] << " ";
	}*/
}
void m_test01()
{
	cout << "** map容器构造和赋值操作 **" << endl;

	map<int, int> m1; //每个元素都是pair对组，要指定两个元素类型

	//map容器的元素总是成对出现，插入时要使用对组
	pair<int, int> p1(4, 40);
	m1.insert(p1);
	m1.insert(pair<int, int>(1, 10));  //pair<int, int>(1, 10) 匿名pair对象
	m1.insert(pair<int, int>(3, 20));  
	m1.insert(pair<int, int>(2, 80));  

	printMap(m1);//自动按照key进行排序  
	
	//拷贝构造
	map<int, int>m2(m1);
	printMap(m2);//
	
	//赋值
	map<int, int>m3;
	m3 = m2;
	printMap(m3);//
}

/*****************************************************************************
 *  @brief	map大小和交换
	功能描述：
		统计map容器大小以及交换map容器
	函数原型：
		size(); //返回容器中元素的数目
		empty(); //判断容器是否为空
		swap(st); //交换两个集合容器
 *****************************************************************************/
void m_test02()
{
	cout << endl << "** map容器大小和交换操作 **" << endl;

	map<int, int> m1;
	
	pair<int, int> p1(1, 10);
	m1.insert(p1);
	m1.insert(pair<int,int>(2,20));
	m1.insert(pair<int, int>(3, 30));

	//判断容器是否为空
	if (m1.empty())
	{
		cout << "m1容器为空" << endl;
	}
	else
	{
		cout << "m1容器不为空" << endl;
		cout << "m1容器的大小为：m1.size() = " << m1.size() << endl;//3
	}

	//交换
	map<int, int> m2;
	m2.insert(pair<int, int>(4, 100));
	m2.insert(pair<int, int>(5, 200));
	cout << "交换前：" << endl;
	printMap(m1);
	printMap(m2);

	m2.swap(m1);
	cout << "交换后：" << endl;
	printMap(m1);
	printMap(m2);

}

/*****************************************************************************
 *  @brief	map插入和删除
	功能描述：
		map容器进行插入数据和删除数据
	函数原型：
		insert(elem); //在容器中插入对组元素。
		erase(pos); //删除pos迭代器所指的元素，返回下一个元素的迭代器。
		erase(beg, end); //删除区间[beg,end)的所有元素 ，返回下一个元素的迭代器。
		erase(key); //删除容器中值为key的元素。
		clear(); //清除所有元素
 *****************************************************************************/
void m_test03()
{
	cout << endl << "** map容器插入和删除操作 **" << endl;

	map<int, int> m1;

	//插入方式1
	m1.insert(pair<int, int>(1, 100));
	m1.insert(pair<int, int>(1, 1000)); //注意：不允许插入相同的 key，无效语句，但也不报错

	//插入方式2
	m1.insert(make_pair(2, 200)); //这个比较方便，不用指定模板参数类型<>

	//插入方式3
	m1.insert(map<int, int>::value_type(3, 300)); //难记，看懂即可

	//插入方式4
	m1[3] = 400; //不建议采用这种方式插入，因为如果该 key已经存在，会直接修改为新value
	
	cout << m1[5] << endl; //注意：用 [] 访问不存在的 key ，会直接创建对应值为 0的对组<key, 0>
						// 如 key = 5，value = 0
	printMap(m1);

	//删除，迭代器方式
	m1.erase(++m1.begin());
	printMap(m1);

	//删除，以key删除
	m1.erase(3);//删除 key=3 的对组
	printMap(m1);

	//删除，以迭代器区间删除
	m1.erase(++m1.begin(), m1.end());
	printMap(m1);

	//清空
	m1.clear();
	printMap(m1);
}


/*****************************************************************************
*  @brief	map查找和统计
	功能描述：
		对map容器进行查找数据以及统计数据
	函数原型：
		find(key); //查找key是否存在,若存在，返回该键的元素的迭代器；若不存在，返回map.end();
		count(key); //统计key的元素个数
 *****************************************************************************/
void m_test04()
{
	cout << endl << "** map容器查找和统计操作 **" << endl;

	map<int, int> m1;
	m1.insert(make_pair(1, 100));
	m1.insert(make_pair(2, 200));
	m1.insert(make_pair(3, 300));

	//查找
	map<int,int>::iterator mit = m1.find(2); //查找 key=2 的对组，接收返回的迭代器
	if (mit != m1.end())
	{
		cout << "查找成功  key = " << (*mit).first << " value = " << (*mit).second << endl;
	}
	else
	{
		cout << "查无此数" << endl;
	}

	//统计
	int num = m1.count(3);
	cout << "key = 3的对组数量为：" << num << endl; 
	//map 不允许 key 重复，要么数量为 1，要么为 0，multimap 允许 key 重复
}


/*****************************************************************************
*  @brief	map容器排序
	学习目标：
		map容器默认排序规则为 按照key值进行 从小到大排序，掌握如何改变排序规则
	主要技术点:
		利用仿函数，可以改变排序规则
		对于自定义数据类型，map要指定排序规则,同set容器
 *****************************************************************************/
class MyMapSort
{
public:
	bool operator()(int a, int b) const
	{
		//降序排序
		return a > b;
	}
};
void m_test05()
{
	map<int, int> m1;
	m1.insert(make_pair(1, 10)); //插入默认按 key 进行升序排序
	m1.insert(make_pair(2, 20));
	m1.insert(make_pair(3, 30));
	m1.insert(make_pair(4, 40));
	printMap(m1);

	cout << "按key降序排序:" << endl;
	//在创建时，指定排序规则为key降序排序
	map<int, int, MyMapSort> m2;
	m2.insert(make_pair(1, 10)); 
	m2.insert(make_pair(2, 20));
	m2.insert(make_pair(3, 30));
	m2.insert(make_pair(4, 40));
	
	for (map<int, int, MyMapSort>::iterator it = m2.begin(); it != m2.end(); it++)
	{
		cout << "key = " << it->first << " val = " << it->second << endl;
	}
}

/*****************************************************************************
 *  @brief	main

 *****************************************************************************/
int main24_2()
{
	//map容器的构造与赋值
	m_test01();

	//map容器的大小与交换
	m_test02();

	//map容器插入与删除
	m_test03();

	//map容器查找和统计
	m_test04();

	//map容器排序
	m_test05();

	return 0;
}

/*
map容器常用成员方法
	成员方法		功能
	begin()		返回指向容器中第一个（注意，是已排好序的第一个）键值对的双向迭代器。如果 map 容器用 const 限定，则该方法返回的是 const 类型的双向迭代器。
	end()		返回指向容器最后一个元素（注意，是已排好序的最后一个）所在位置后一个位置的双向迭代器，通常和 begin() 结合使用。如果 map 容器用 const 限定，则该方法返回的是 const 类型的双向迭代器。
	rbegin()	返回指向最后一个（注意，是已排好序的最后一个）元素的反向双向迭代器。如果 map 容器用 const 限定，则该方法返回的是 const 类型的反向双向迭代器。
	rend()		返回指向第一个（注意，是已排好序的第一个）元素所在位置前一个位置的反向双向迭代器。如果 map 容器用 const 限定，则该方法返回的是 const 类型的反向双向迭代器。
	cbegin()	和 begin() 功能相同，只不过在其基础上，增加了 const 属性，不能用于修改容器内存储的键值对。
	cend()		和 end() 功能相同，只不过在其基础上，增加了 const 属性，不能用于修改容器内存储的键值对。
	crbegin()	和 rbegin() 功能相同，只不过在其基础上，增加了 const 属性，不能用于修改容器内存储的键值对。
	crend()		和 rend() 功能相同，只不过在其基础上，增加了 const 属性，不能用于修改容器内存储的键值对。
	find(key)	在 map 容器中查找键为 key 的键值对，如果成功找到，则返回指向该键值对的双向迭代器；反之，则返回和 end() 方法一样的迭代器。另外，如果 map 容器用 const 限定，则该方法返回的是 const 类型的双向迭代器。
	lower_bound(key)	返回一个指向当前 map 容器中第一个大于或等于 key 的键值对的双向迭代器。如果 map 容器用 const 限定，则该方法返回的是 const 类型的双向迭代器。
	upper_bound(key)	返回一个指向当前 map 容器中第一个大于 key 的键值对的迭代器。如果 map 容器用 const 限定，则该方法返回的是 const 类型的双向迭代器。
	equal_range(key)	该方法返回一个 pair 对象（包含 2 个双向迭代器），其中 pair.first 和 lower_bound() 方法的返回值等价，pair.second 和 upper_bound() 方法的返回值等价。也就是说，该方法将返回一个范围，该范围中包含的键为 key 的键值对（map 容器键值对唯一，因此该范围最多包含一个键值对）。
	empty() 	若容器为空，则返回 true；否则 false。
	size()		返回当前 map 容器中存有键值对的个数。
	max_size()	返回 map 容器所能容纳键值对的最大个数，不同的操作系统，其返回值亦不相同。
	operator[]	map容器重载了 [] 运算符，只要知道 map 容器中某个键值对的键的值，就可以向获取数组中元素那样，通过键直接获取对应的值。
	at(key)		找到 map 容器中 key 键对应的值，如果找不到，该函数会引发 out_of_range 异常。
	insert()	向 map 容器中插入键值对。
	erase()	删除 map 容器指定位置、指定键（key）值或者指定区域内的键值对。后续章节还会对该方法做重点讲解。
	swap()	交换 2 个 map 容器中存储的键值对，这意味着，操作的 2 个键值对的类型必须相同。
	clear()	清空 map 容器中所有的键值对，即使 map 容器的 size() 为 0。
	emplace()	在当前 map 容器中的指定位置处构造新键值对。其效果和插入键值对一样，但效率更高。
	emplace_hint()	在本质上和 emplace() 在 map 容器中构造新键值对的方式是一样的，不同之处在于，使用者必须为该方法提供一个指示键值对生成位置的迭代器，并作为该方法的第一个参数。
	count(key)	在当前 map 容器中，查找键为 key 的键值对的个数并返回。注意，由于 map 容器中各键值对的键的值是唯一的，因此该函数的返回值最大为 1。

和 map 容器相比，multimap 未提供 at() 成员方法，也没有重载 [] 运算符。
这意味着，map 容器中通过指定键获取指定指定键值对的方式，将不再适用于 multimap 容器。
其实这很好理解，因为 multimap 容器中指定的键可能对应多个键值对，而不再是 1 个。
*/
