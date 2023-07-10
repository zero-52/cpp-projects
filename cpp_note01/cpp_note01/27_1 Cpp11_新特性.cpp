/*****************************************************************************
 *  @brief	C++ 11 新特性总结
		nullptr
		auto
		Lambda表达式
		for each
		...
 *****************************************************************************/

#include<iostream>
using namespace std;

/*****************************************************************************
 *  @brief	lambda表达式：
    [捕获列表](参数列表)[可选：mutable 可变规则] [可选：throw()异常说明] -> 返回值类型 { 函数体 }
         
         //推荐使用 [=](){ };    [=]()->bool{ };
         [] 表示不捕获任何变量
         [变量1, 变量2, ...] 捕获部分指定变量
         [=] 表示值传递方式捕获所有所在范围内的局部变量（包括this）
         [var] 表示值传递方式捕获指定变量var，在函数体内不可使用函数体外的其它变量
         [&] 表示引用传递方式捕捉所有所在范围内的局部变量（包括this），不推荐使用，有时会出错
         [&var] 表示引用传递捕捉变量var
         [this] 表示值传递方式捕捉当前的this指针
         [=,&a,&b] 表示以引用传递的方式捕捉变量a和b，以值传递方式捕捉其它所有变量。
         [&,a,this] 表示以值传递的方式捕捉变量a和this，引用传递方式捕捉其它所有变量。
    
     默认情况下Lambda函数总是一个const函数，不能直接对Lambda外定义的变量赋值（只读），需要用 mutable修饰 或 引用传递捕获才能修改外部变量。
        在使用 mutable修饰符 时，参数列表不可省略（即使参数为空也不可省略）
        mutable修饰，本质是拷贝个变量修改，修改不影响原变量自身
     如果Lambda表达式的返回值类型为 void，或函数中只有一个return语句时，此时可以省略返回值类型，会自动推导返回类型。
 *****************************************************************************/
void t01_Lambda()
{
    int a = 10;
    /*[=]() {
        cout << "a = " << a << endl;
    };*/

    /* 调用匿名函数：1、后面直接加(), 2、用函数指针接收，或者 3、用auto关键字定义变量接收 */
    //1、后面直接加小括号调用
    [=]()->void {
        cout << "a = " << a << endl; //10
    }(); 
    
    //2、用函数指针
    //从不带捕获列表的lambda 转换为函数指针
    void(*pFun1)();
    pFun1 = []()->void {
        //a = 20; //不可修改
        cout << "不带捕获列表的 lambda 转换为 函数指针" << endl;
    };
    pFun1();

    //从不带捕获列表的lambda 转换为函数指针，并给 lambda 传参
    void(*pFun11)(int&);  //参数是引用传递
    pFun11 = [](int& num)->void {
        num = 2 * num;
    };
    pFun11(a);
    cout << a << endl; //20


    //3、用 auto 关键字
    auto pFun2 = [=]()->void {
        cout << "a = " << a << endl; //20
    };
    pFun2();

    /* 修改 Lambda 中的变量 */
    //如果需要在Lambda里修改变量值，但不影响外面的变量本体，需要加 mutable 修饰
    auto pFun3 = [=]() mutable ->void {
        a = 22;
        cout << "a = " << a << endl; //22，只是修改了a的拷贝对象，Lambda外的a自身并没有被修改
    };
    pFun3(); 

    cout << a << endl; //20，外面的变量自身并没有被修改

    //如果需要在Lambda里修改变量值，并影响到Lambda外的本体，用引用的方式捕获变量
    auto pFun4 = [&]() mutable ->void {
        a = 33;
        cout << "a = " << a << endl; //33
    };
    pFun4();

    cout << a << endl; //33

 

}


 /*****************************************************************************
  *  @brief	main()
  * 
  *****************************************************************************/
int main27_1()
{
	cout << "C++ 11新特性" << endl;

    //Lambda表达式
    t01_Lambda();

	return 0;
}