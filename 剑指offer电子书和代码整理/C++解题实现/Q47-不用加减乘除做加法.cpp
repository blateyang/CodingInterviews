#include <iostream>
using namespace std;

//-----��������------
/*
1.���ܣ��������Ϊ��������Ϊ������һ��һ��������0��������λ/��������λ 
*/ 
int Add(int num1, int num2)
{//˼·������ʮ�������Ͷ�������������ļӷ����������߹��ɣ�1.ֱ����Ӳ��ƽ�λ��λ���ʵ�֣� 
//		2.�����λֵ��λ��ʵ�֣� 3.����λֵ��ֱ����ӵ�ֵ����ӡ��ظ�����ֱ�����ڲ�����λ 
	int sum, sumWithoutCarry;
	sum = sumWithoutCarry = num1 ^ num2;
	int carry = (num1 & num2)<<1; //��λ��<<���ߵĶ���Ҫ����ˣ�����Ǳ���λ�Ķ��� 
	while(carry) //Ҳ�ɲ���ֱ���ͽṹ��������һ��sum���� 
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
