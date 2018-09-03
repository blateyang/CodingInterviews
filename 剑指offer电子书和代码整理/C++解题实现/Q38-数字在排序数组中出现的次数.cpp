#include <iostream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;

//------------测试用例-----------------
/*
1.功能：排序数组为升序或降序(剑指offer中并未考虑）；数字在排序数组中出现1次或多次
2.边界：数字出现在排序数组最前面或最后面
3.负面：数组为空;数字未在排序数组中出现
*/ 
//思路：对二分查找算法进行迁移，对升序数组分别找到不超过给定数字的最后一个数字和
//		低于给定数字的最后一个数字；降序数组正好相反，分别找到不低于给定数字的最后一个数字和高于给定数字的最后一个数字 
bool ascendFlag = true; 
int BinSearchPost(vector<int> const &data, int low, int high, int num) //data[low, high)
{
	//递归基 
	if(low == high) //越界情况 
		return -1;
	if(low == high-1) //搜索范围退化到只有一个数 
		return (data[low]==num)? low:-1;
	int mid = (low+high)/2;
	if(ascendFlag)
	{
		if(data[mid] <= num) //待查找数不低于中点数且升序，向后半区间查找 
				low = mid;
			else
				high = mid;
//		cout<<low<<" "<<high<<endl;
	}
	else
	{
		if(data[mid] >= num) //待查找数不高于中点数且降序，向后半区间查找 
				low = mid;	
			else
				high = mid; 
	}
	return BinSearchPost(data, low, high, num);
 } 

int BinSearchPre(vector<int> const &data, int low, int high, int num) //data[low, high)
{
	//递归基 
	if(low == high) //越界情况 
		return -1;
	if(low == high-1) //搜索范围退化到只有一个数
		if(ascendFlag) 
			return (data[low]<num)? low:-1;
		else
			return (data[low]>num)? low:-1;
	int mid = (low+high)/2;
	if(ascendFlag)
	{
		if(num <= data[mid]) // 待查找数不高于中点数且升序，向前半区间查找 
				high = mid; 
			else 
				low = mid; 
	}
	else
	{
		if(data[mid] <= num) // 待查找数不低于中点数降序，向前半区间查找
			high = mid;
		else  
			low = mid;	
	}
	return BinSearchPre(data, low, high, num);
 } 

 
int GetNumberOfK(vector<int> data, int k)
{
	int len = data.size();
	if(len==0)
		return 0;
	if(data[0]>data[len-1])
		ascendFlag = false;
	int postIdx = BinSearchPost(data, 0, len, k);
	int preIdx = BinSearchPre(data, 0, len, k);
//	cout<<"preIdx:"<<preIdx<<"	postIdx:"<<postIdx<<endl;
	int result = postIdx-preIdx; 
	return (result<0)? 0:result;
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
		int result = GetNumberOfK(v_test, 3);
		cout<<"times of k:"<<result<<endl; 
	}
	return 0;
}
