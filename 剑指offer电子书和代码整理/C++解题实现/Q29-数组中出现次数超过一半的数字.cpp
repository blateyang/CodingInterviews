#include <iostream>
#include <vector>
#include <string>
#include <sstream> 
using namespace std;

//----------��������----------------
/*
1.���ܣ� ֻ��һ��Ԫ�ص����飻�ж��Ԫ�ص�����
2.���棺 �����飻������û�г��ִ�������һ������� 
*/ 
int MoreThanHalfNum_Solution(vector<int> numbers)
{//˼·���ҵ�min,max������һ����Ƶ����arr[max-min+1]={0}���������飬ͳ�Ƹ����ִ�Ƶ��
//		������Ƶ���飬�ҵ�����Ҫ������� 
	int numsLen = numbers.size();
	if(numsLen == 0)
		return 0;
	if(numsLen == 1)
		return numbers[0];
	int i, min, max;
	min = max = numbers[0];
	//���������ҵ�min��max 
	for(i=1; i!=numsLen; ++i)
	{
		if(numbers[i] < min)
			min = numbers[i];
		if(numbers[i] > max)
			max = numbers[i];
	}
	vector<int> countArr(max-min+1, 0);
	//ͳ�Ƹ����ִ�Ƶ 
	for(i=0; i!=numsLen; ++i)
		++countArr[numbers[i]-min];
	//������Ƶ���飬�ҵ�����Ҫ������� 
	int overHalfNum = 0;
	for(i=0; i!=countArr.size(); ++i)
		if(countArr[i]*2 > numsLen)
			{
				overHalfNum = min + i;
				break;
			}
	return overHalfNum;
} 

//-----------��ָoffer�ⷨ-------------
//˼·�������г��ִ�������һ���������ζ������ִ�����ʣ�µ��������ֳ��ִ�������
//		����������������overHalfNum��times���ֱ�浱ǰ���ܵĺ�ѡ���ֺʹ��������
//		��һ��������overHalfNum��ͬ��times��һ����ͬ���һ�����timesΪ0�������
//		overHalfNum����times��Ϊ1��overHalfNum�����������Ϊ���ܵĺ�ѡ���֣���Ҫ���������֤�� 
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
		int result = MoreThanHalfNum_Solution(v_test);
		cout<<"over half num:"<<result<<endl;
	}
	return 0;
}
