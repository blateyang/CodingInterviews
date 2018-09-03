#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
using namespace std;

//----------测试用例----------------
/*
1.功能： 输入数组连续/不连续，不含0，含多个0，含重复元素
2.特殊输入： 数组长度！=5或含有超过范围的数 
*/ 
int NUMS = 5;
void bubbleSort(vector<int> &arr)
{
	int len = arr.size();
	int tmp;
	for(int i=0; i<len-1; ++i) //n-1趟扫描
	{
		for(int j=0; j<len-1-i; ++j)
			if(arr[j] > arr[j+1])
			{
				tmp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = tmp;
			}		
	 } 
}

bool isContinuous(vector<int> nums)
{//思路：1.对输入的5个数递增排序； 2.统计0的个数; 3.对非0数统计空缺数，需<=0的个数 
	int len = nums.size();
	if(len != NUMS)
		return false;
//	bubbleSort(nums);
	sort(nums.begin(), nums.end());
	if(nums[0]<0 || nums[NUMS-1]>13)
		return false;
	int num0 = 0, gap = 0;
	int i;
	while(nums[i] == 0)
	{
		++num0;
		++i;
	 } 
	if(num0 > 4)
		return false;
	for(; i<NUMS-1; ++i)
	{
		int diff = nums[i+1] - nums[i];
		if(diff == 0)
			return false;
		else
			gap += diff-1;
	}
	return (gap <= num0)? true:false;
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
		if(isContinuous(v_test))
			cout<<"is continuous"<<endl;
	}
	return 0;
}
