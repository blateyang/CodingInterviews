#include <iostream>
using namespace std;

//-----------��������--------
/*
1.���ܣ�����5,10
2.�߽磺����0,1 
*/ 
//������͵ĳ���ⷨ��ʹ�ù�ʽ��ѭ�����ߵݹ���⣬������Ҫ����ʹ�������� 
//�ⷨ1�����ù��캯��ʵ��ѭ�� 
class Temp
{//��static������ر����ͺ�����ʹ��Ϊ�����У�����ͬʵ�������� 
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
	Temp *ans = new Temp[n];	//�Զ�����n�ι��캯�� 
	delete []ans;
	ans = NULL;
	return Temp::GetSum();
}

//�ⷨ2�������麯��ʵ�ֵݹ�
class A;
A *arr[2];

class A
{
	public:
		virtual int sum(int n){ //������麯���䵱�ݹ���Ľ�ɫ 
			return 0;
		}
 };
 
class B:public A
{
	public:
		virtual int sum(int n){ //��������麯��ִ�еݹ���̣�!!n��n��0ʱΪtrue(1)����nΪ0ʱ��Ϊfalse(0) 
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

//�ⷨ3�����ú���ָ��ʵ�ֵݹ� 
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
