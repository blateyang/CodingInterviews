#include <iostream>
#include <vector>
using namespace std;

//------------测试用例----------------
/*
1.功能：n<10;n的各位全为1；部分为1 ；均不为1
2.负面：n<1 
*/ 
////低效但直观的思路：遍历1~n，对每个数用“除10取余法“求出其含有的1的个数，累加得到答案，复杂度为n*log(n) 
//int numberOfN(int n)
//{
//	int count = 0;
//	while(n)
//	{
//		if(n%10 == 1)
//			++count;
//		n /= 10;
//	}
//	return count;
//}
//
//int NumberOf1Between1AndN(int n) 
//{
//	int result = 0;
//	if(n < 1)
//		return result;
//	for(int i=1; i<=n; ++i)
//		result += numberOfN(i);
//	return result;
//}

//递归迭代的思路：先求出n的位数len;将n分成最高位n_hi和剩下的len-1位n_low；计算最高位出现1的
//				次数num1hi；计算剩下的len-1位出现1的次数num1low=n_hi*(len-1)*10^(len-2)；
//				最后返回num1hi+num1low+f(n_low)
int DigitsOfN(int n)
{
	int digits = 0;
	while(n)
	{
		++digits;
		n /= 10;
	}
	return digits;
}

int powerBase10(int n)
{
	int result = 1;
	for(int i=0; i!=n; ++i)
		result *= 10;
	return result; 
}

int NumberOf1Between1AndNIter(int n, int digits)
{
	if(n<10)  //递归基 
		return (n==0)? 0:1;
	//将n划分成最高位部分和剩下的digits-1位 
	int base = powerBase10(digits-1); 
	int n_low = n%base;
	int n_highest = n/base;
	//计算最高位出现1的次数
	int timesHigh= base; //默认为base个 
	if(n_highest == 1)
		timesHigh = n_low+1;
	//计算后digits-1位出现1的次数
	int timesLow = n_highest*(digits-1)*powerBase10(digits-2);
	//递归计算剩下的n_low部分 
	return timesHigh+timesLow+NumberOf1Between1AndNIter(n_low, digits-1); 	 
}

int NumberOf1Between1AndN(int n) 
{
	int result = 0;
	if(n>=1)
	{
		int digits = DigitsOfN(n);
		result = NumberOf1Between1AndNIter(n, digits);
	}
	return result;
}

int main()
{
	int n;
	while(cin>>n)
		cout<<NumberOf1Between1AndN(n)<<endl;
	return 0;
}
