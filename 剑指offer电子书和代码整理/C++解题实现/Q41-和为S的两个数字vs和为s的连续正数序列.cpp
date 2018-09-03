#include <iostream>
#include <vector>
#include <climits>
#include <sstream>
#include <string> 
using namespace std;

//--------------��ΪS����������-----------------
//-------------��������------------------
/*
1. ���ܣ�û�з���������2��������һ�ԣ��ж��
2. ���棺���鳤��С��1 
*/ 
vector<int> FindNumbersWithSum(vector<int>  array, int sum)
{//˼·�����������˷ֱ���������ָ�룬������ָ���ĺ���sum�Ƚϣ�>sum����ָ�����ƣ�<sum����ָ�����ƣ�=sum���ж������˻��Ƿ���С 
	vector<int> result;
	int len = array.size();
	if(len <= 1)
		return result;
	int small=1, big=INT_MAX;
	int preIdx = 0, postIdx = len-1;
	while(preIdx < postIdx)
	{
		int tmpSum = array[preIdx] + array[postIdx];
		if(tmpSum == sum)
		{
			if(array[preIdx]*array[postIdx] < small*big)
			{
				small = array[preIdx];
				big = array[postIdx];
			}
			--postIdx;
		}
		else if(tmpSum < sum)
			++preIdx;
		else
			--postIdx;
	 } 
	if(big!=INT_MAX)
	{
	 	result.push_back(small);
	 	result.push_back(big);
	} 
	return result;
 } 
 
//-------------��չ����Ϊsum������������----------------
//-----------��������-------------- 
/*
1.���ܣ���Ϊsum�����������н���1�ԣ���3�����ж�ԣ���9��;�����ں�Ϊsum�������У���4�� 
2.���棺sum<3 
*/ 
vector<vector<int> > FindContinuousSequence(int sum)
{//˼·�����������˼·��Ҳ����������ָ�룬��������Ƕ�����ָ�뷶Χ�������� 
	vector<vector<int> > result;
	if(sum < 3)
		return result;
	int small = 1, big = 2, curSum = 3;
	while(small < (sum+1)/2)
	{
		if(curSum < sum)
		{
			++big; 
			curSum += big;
		}
		else
		{
			if(curSum == sum)
			{
				vector<int> curSeq;
				for(int i=small; i<=big; ++i)
					curSeq.push_back(i);
				result.push_back(curSeq);
			}
			curSum -= small;
			++small;
		}
	}
	return result;
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
//		vector<int> result = FindNumbersWithSum(v_test, 15);
//		if(result.size()>1)
//			cout<<result[0]<<" "<<result[1]<<endl; 
		vector<vector<int> > result = FindContinuousSequence(v_test[0]);
		for(auto curSeq: result)
		{
			for(auto num: curSeq)
				cout<<num<<" ";
			cout<<endl;
		}
	}
	return 0;
 } 
