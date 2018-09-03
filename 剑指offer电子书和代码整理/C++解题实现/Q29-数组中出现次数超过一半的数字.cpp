#include <iostream>
#include <vector>
#include <string>
#include <sstream> 
using namespace std;

//----------测试用例----------------
/*
1.功能： 只有一个元素的数组；有多个元素的数组
2.负面： 空数组；数组中没有出现次数超过一半的数字 
*/ 
int MoreThanHalfNum_Solution(vector<int> numbers)
{//思路：找到min,max；建立一个词频数组arr[max-min+1]={0}；遍历数组，统计各数字词频；
//		遍历词频数组，找到符合要求的数字 
	int numsLen = numbers.size();
	if(numsLen == 0)
		return 0;
	if(numsLen == 1)
		return numbers[0];
	int i, min, max;
	min = max = numbers[0];
	//遍历数组找到min，max 
	for(i=1; i!=numsLen; ++i)
	{
		if(numbers[i] < min)
			min = numbers[i];
		if(numbers[i] > max)
			max = numbers[i];
	}
	vector<int> countArr(max-min+1, 0);
	//统计各数字词频 
	for(i=0; i!=numsLen; ++i)
		++countArr[numbers[i]-min];
	//遍历词频数组，找到符合要求的数字 
	int overHalfNum = 0;
	for(i=0; i!=countArr.size(); ++i)
		if(countArr[i]*2 > numsLen)
			{
				overHalfNum = min + i;
				break;
			}
	return overHalfNum;
} 

//-----------剑指offer解法-------------
//思路：数组中出现次数超过一半的数字意味着其出现次数比剩下的所有数字出现次数都多
//		可以设置两个变量overHalfNum和times，分别存当前可能的候选数字和次数，如果
//		后一个数字与overHalfNum相同，times加一；不同则减一；如果times为0，则更新
//		overHalfNum并将times设为1。overHalfNum中最后存的数字为可能的候选数字（需要对其进行验证） 
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
