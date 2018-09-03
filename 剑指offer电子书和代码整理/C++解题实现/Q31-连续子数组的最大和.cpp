#include <iostream>
#include <vector>
#include <assert.h>
#include <string>
#include <sstream>
using namespace std;

//------------测试用例-------------
/*
1.功能：输入数组全为正数；全为负数；有正有负含有0；仅有一个元素 
2.负面：输入数组为空 
*/ 
int FindGreatestSumOfSubArray(vector<int> array)
{//思路1：通过举例法列表模拟求子数组和的过程分析出连续子数组最大和的规律
//思路2：动态规划，设f(i)表示以第i个数字结尾的子数组最大和，则要求的是max(f(i))
//		根据对问题的认识不难发现当i=0或f(i-1)<=0时，f(i)=array[i]；反之，f(i)=f(i-1)+array[i] 
	int len = array.size();
	assert(len > 0);
	int curSubArrSum = 0;
	int maxSubArrSum = 0x80000000; //需初始化为很小的负数,因为输入数组可能全为负数 
	for(int i=0; i!=len; ++i)
	{
		if(curSubArrSum <= 0) //当前子数组和<=0,清除，等于新的数 
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
