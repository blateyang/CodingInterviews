#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;
using iter = string::iterator; 

//-------------测试用例-----------------
/*
1. 功能测试：字符串仅有一个字符；字符串有多个不同的字符；字符串有多个相同的字符
2. 负面测试：字符串为空 
*/ 

void PermutationIter(vector<string> &v_str, string &str, int idxFirst)
{//递归策略：基于回溯法（参见https://www.nowcoder.com/questionTerminal/fe6b651b66ae47d7acce78ffdd9a96c7） 
	if(idxFirst==str.size()-1) //递归基，迭代至str最后一个字符 
		{
			v_str.push_back(str);
			return;
		}
	for(int i=idxFirst; i!=str.size(); ++i)
	{//之所以有两次交换是为了在交换了字符串元素后能回溯到交换前的状态
				char tmp = str[idxFirst];
				str[idxFirst] = str[i];
				str[i] = tmp;
				PermutationIter(v_str, str, idxFirst+1);
				tmp = str[idxFirst];
				str[idxFirst] = str[i];
				str[i] = tmp;
	}
}
vector<string> Permutation(string str) 
{//思路：将字符串拆解为第一个字符和后面的子字符串，将第一个字符依次与后面子字符串
//		中的不同字符进行交换，将结果保存到vector中，然后递归地对子字符串执行相同
//		的操作，为了能够按字典顺序输出可以最后对vector调用排序算法 
	vector<string> v_str;
	if(str.size()!=0)
		PermutationIter(v_str, str, 0);
	//按字典序排序v_str
	sort(v_str.begin(), v_str.end()); 
	//对v_str去重（重复的元素会被调整到尾部）,返回的是迭代器 
	vector<string>::iterator unique_end = unique(v_str.begin(), v_str.end());
	v_str.erase(unique_end, v_str.end());
	return v_str;
} 

// 拓展：求字符串的组合
void combinationIter(char *string, int m, vector<char> &v_str)
{//思路：类似求排列，也可以拆解为首个字符和剩下的子字符串，并递归求解。对于从长度为n的字符串
//		中选出m个字符的组合，若将首字符放入组合中，则只需从剩下长为n-1的字符串中 
//		选出m-1个字符；若首字符不在组合中，则从剩下长为n-1的字符串中选出m个字符 
	//递归基（有两种情况：m减到0或者达到字符串末尾，对应的处理方式可通过举"ab\0"这样简单的例子分析出来） 
	if(m==0)
	{
		for(int i=0; i!=v_str.size(); ++i)
			cout<<v_str[i];
		cout<<endl;
		return;
	}
	if(*string == '\0')
		return;
	v_str.push_back(*string); //将首字符放入组合中，则只需从剩下长为n-1的字符串中选出m-1个字符
	combinationIter(string+1, m-1, v_str);
	v_str.pop_back();  //首字符不在组合中，则从剩下长为n-1的字符串中选出m个字符 
	combinationIter(string+1, m, v_str);
 } 

void Combination(char *chars)
{
	if(chars == NULL)
		return;
	int len = strlen(chars);
	vector<char> v_str;
	for(int m=1; m<=len; ++m)
		combinationIter(chars, m, v_str);
}

//相关问题：8皇后问题（两个皇后不能在同一行、同一列或同一对角线上）,答案是共有92种摆法 
//思路：首先用一个数组存0~7共8个列号，表示棋盘每行棋子所在的列数，求出其全排列，再
//		对每个排列判断是否有元素在对角线上
void swap(int &a, int &b)
{
	int tmp = a;
	a = b;
	b = tmp;
}
void permutationNums(vector<vector<int>> &v_arranges, vector<int> &v_nums, int idxFirst)
{
	if(idxFirst == v_nums.size()-1)
		{
			v_arranges.push_back(v_nums);
			return;
		}
	for(int i=idxFirst; i!=v_nums.size(); ++i)
	{
		swap(v_nums[i], v_nums[idxFirst]);
		permutationNums(v_arranges, v_nums, idxFirst+1);
		swap(v_nums[i], v_nums[idxFirst]);
	}
}
bool hasNoDiagonalItem(vector<int> const &v_nums)
{
	int len = v_nums.size();
	for(int i=0; i!=len; ++i)
		for(int j=i+1; j!=len; ++j)
		{
			if(j-i == v_nums[j]-v_nums[i] || j-i == v_nums[i]-v_nums[j])
				return false;
		}
	return true;
}

int main()
{
//	//字符串排列测试 
//	string input;
//	while(getline(cin, input))
//	{
//		vector<string> v_test;
//		v_test = Permutation(input);
//		for(auto num: v_test)
//			cout<<num<<" ";
//		cout<<endl;
//	}
//	// 字符串组合测试
//	char s[]="abc";
//	Combination(s); 
	//数组排列测试 
	vector<int> v_nums{0,1,2,3,4,5,6,7};
	vector<vector<int>> v_arranges;
	permutationNums(v_arranges, v_nums, 0);
	cout<<"number of arranges:"<<v_arranges.size()<<endl;
	int arrange_num = 0;
	for(auto const &arrange:v_arranges)
		if(hasNoDiagonalItem(arrange))
			++arrange_num;
	cout<<arrange_num<<endl;
	return 0;
}
