#include <iostream>
using namespace std;

//-----测试用例------
/*
1.功能：相加数均为正数、均为负数、一正一负、含有0、产生进位/不产生进位 
*/ 
int Add(int num1, int num2)
{//思路：分析十进制数和二进制数均满足的加法运算三步走规律：1.直接相加不计进位（位异或实现） 
//		2.计算进位值（位与实现） 3.将进位值和直接相加的值再相加。重复进行直至不在产生进位 
	int sum, sumWithoutCarry;
	sum = sumWithoutCarry = num1 ^ num2;
	int carry = (num1 & num2)<<1; //移位符<<两边的对象不要搞错了，左边是被移位的对象 
	while(carry) //也可采用直到型结构，可少用一个sum变量 
	{
//		cout<<sumWithoutCarry<<" "<<carry<<endl;
		sum = sumWithoutCarry ^ carry;
		carry = (sumWithoutCarry & carry)<<1;
		sumWithoutCarry = sum; 
	 } 
	return sum;
}

int main()
{
	int n1, n2;
	while(cin>>n1>>n2)
		cout<<Add(n1, n2)<<endl;
	return 0;
}
