#include <iostream>
#include <vector>
using namespace std;

//------------��������----------------
/*
1.���ܣ�n<10;n�ĸ�λȫΪ1������Ϊ1 ������Ϊ1
2.���棺n<1 
*/ 
////��Ч��ֱ�۵�˼·������1~n����ÿ�����á���10ȡ�෨������京�е�1�ĸ������ۼӵõ��𰸣����Ӷ�Ϊn*log(n) 
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

//�ݹ������˼·�������n��λ��len;��n�ֳ����λn_hi��ʣ�µ�len-1λn_low���������λ����1��
//				����num1hi������ʣ�µ�len-1λ����1�Ĵ���num1low=n_hi*(len-1)*10^(len-2)��
//				��󷵻�num1hi+num1low+f(n_low)
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
	if(n<10)  //�ݹ�� 
		return (n==0)? 0:1;
	//��n���ֳ����λ���ֺ�ʣ�µ�digits-1λ 
	int base = powerBase10(digits-1); 
	int n_low = n%base;
	int n_highest = n/base;
	//�������λ����1�Ĵ���
	int timesHigh= base; //Ĭ��Ϊbase�� 
	if(n_highest == 1)
		timesHigh = n_low+1;
	//�����digits-1λ����1�Ĵ���
	int timesLow = n_highest*(digits-1)*powerBase10(digits-2);
	//�ݹ����ʣ�µ�n_low���� 
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
