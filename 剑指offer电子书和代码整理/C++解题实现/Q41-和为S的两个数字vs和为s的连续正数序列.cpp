#include <iostream>
#include <vector>
#include <climits>
#include <sstream>
#include <string> 
using namespace std;

//--------------和为S的两个数字-----------------
//-------------测试用例------------------
/*
1. 功能：没有符合条件的2个数；有一对；有多对
2. 负面：数组长度小于1 
*/ 
vector<int> FindNumbersWithSum(vector<int>  array, int sum)
{//思路：在数组两端分别设置两个指针，将其所指数的和与sum比较，>sum将右指针左移，<sum将左指针右移，=sum则判断两数乘积是否最小 
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
 
//-------------拓展：和为sum的连续子数组----------------
//-----------测试用例-------------- 
/*
1.功能：和为sum的连续子序列仅有1对（如3）或有多对（如9）;不存在和为sum的子序列（如4） 
2.负面：sum<3 
*/ 
vector<vector<int> > FindContinuousSequence(int sum)
{//思路：类似上面的思路，也是设置两个指针，不过求和是对两个指针范围间的数求和 
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
