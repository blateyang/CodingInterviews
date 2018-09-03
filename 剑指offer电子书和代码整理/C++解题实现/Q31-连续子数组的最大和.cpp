#include <iostream>
#include <vector>
#include <assert.h>
#include <string>
#include <sstream>
using namespace std;

//------------��������-------------
/*
1.���ܣ���������ȫΪ������ȫΪ�����������и�����0������һ��Ԫ�� 
2.���棺��������Ϊ�� 
*/ 
int FindGreatestSumOfSubArray(vector<int> array)
{//˼·1��ͨ���������б�ģ����������͵Ĺ��̷������������������͵Ĺ���
//˼·2����̬�滮����f(i)��ʾ�Ե�i�����ֽ�β�����������ͣ���Ҫ�����max(f(i))
//		���ݶ��������ʶ���ѷ��ֵ�i=0��f(i-1)<=0ʱ��f(i)=array[i]����֮��f(i)=f(i-1)+array[i] 
	int len = array.size();
	assert(len > 0);
	int curSubArrSum = 0;
	int maxSubArrSum = 0x80000000; //���ʼ��Ϊ��С�ĸ���,��Ϊ�����������ȫΪ���� 
	for(int i=0; i!=len; ++i)
	{
		if(curSubArrSum <= 0) //��ǰ�������<=0,����������µ��� 
			curSubArrSum = array[i];
		else				 
			curSubArrSum += array[i]; 
		if(curSubArrSum > maxSubArrSum)
			maxSubArrSum = curSubArrSum; 
	}
	return maxSubArrSum;
}

int stringToInt(string const &str)
{
	int num=0;
	if(str.size()==0)
		cout<<"can not convert empty string to int"<<endl; 
	int i = (str[0]!='-') ? 0:1;
	bool pos_flag=true;
	if(i==1)
		pos_flag=false;
	while(i<str.size())
		num = num*10 + str[i++]-'0';
	if(pos_flag)
		return num;
	else
		return -num;
}

int main()
{
//	vector<int> v1, v2{1,3,5}, v3{2,4,6}, v4{1,-2,3,4}, v5{2,-1,4,3};
	string input;
	while(getline(cin, input))
	{
		vector<int> v_test;
		istringstream str_in(input);
		string tmp;
		while(str_in>>tmp)
			v_test.push_back(stringToInt(tmp));
		cout<<"maxSubArrSum:"<<FindGreatestSumOfSubArray(v_test)<<endl;
	}
	return 0;
}
