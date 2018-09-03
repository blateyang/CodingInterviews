#include <iostream>
using namespace std;

//-----------测试用例--------
/*
1.功能：输入5,10
2.边界：输入0,1 
*/ 
//数列求和的常规解法是使用公式、循环或者递归求解，而该题要求不能使用这三种 
//解法1：利用构造函数实现循环 
class Temp
{//用static声明相关变量和函数，使其为类所有，被不同实例对象共享 
	private:
		static unsigned N;
		static unsigned Sum;
	public:
		Temp()
		{ ++N; Sum += N;}
		static void Reset(){
			N = 0; Sum = N;
		}
		static unsigned GetSum(){
			return Sum;
		}
 };
 
unsigned Temp::N = 0;
unsigned Temp::Sum = 0;

int sumSolution1(int n)
{
	if(n < 1)
		return 0;
	Temp::Reset(); 
	Temp *ans = new Temp[n];	//自动调用n次构造函数 
	delete []ans;
	ans = NULL;
	return Temp::GetSum();
}

//解法2：利用虚函数实现递归
class A;
A *arr[2];

class A
{
	public:
		virtual int sum(int n){ //基类的虚函数充当递归基的角色 
			return 0;
		}
 };
 
class B:public A
{
	public:
		virtual int sum(int n){ //派生类的虚函数执行递归过程，!!n在n非0时为true(1)，在n为0时，为false(0) 
			return arr[!!n]->sum(n-1) + n;
		} 
};

int sumSolution2(int n)
{
	if(n < 1)
		return 0;
	A a;
	B b;
	arr[0] = &a;
	arr[1] = &b;
	return arr[1]->sum(n);
}

//解法3：利用函数指针实现递归 
typedef int (*fun)(int n);
int Solution3Terminate(int n)
{
	return 0;
}

int sumSolution3(int n)
{
	fun f[2] = {Solution3Terminate, sumSolution3};
	return f[!!n](n-1) + n;
}

int main()
{
	cout<<sumSolution3(1);
	return 0;
}
