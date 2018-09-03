#include <iostream>
#include <string>
using namespace std;

//-----------翻转单词顺序--------------
//------------测试用例------------
/*
1. 功能：仅有一个单词，有多个单词
2. 负面： 字符串为空，字符串中只有空格 
*/ 
void Reverse(string &str, int p, int q)
{//反转str[p, q]
	if(p >= q)
		return;
	while(p < q)
	{
		int tmp = str[p];
		str[p] = str[q];
		str[q] = tmp;
		++p;
		--q;
	 } 
 } 

string ReverseString(string str)
{//思路：先对整个字符串进行反转，再依次对每个单词进行反转 
	int len = str.size();
	if(len <= 1)
		return str;
	Reverse(str, 0, len-1);
	int p=0, q=1;
	while(p < len)
	{
		while(p<len && str[p]==' ')
		{//处理以空格开头的情况 
			++p;
			++q;
		}
		if(p < len)
		{//找到单词第一个字符后用q找到最后一个字符并对单词进行反转 
			while(q<len && str[q]!=' ')
				++q;
			--q;
			Reverse(str, p, q); 
		}
		//更新p,q指针 
		p = q+1;
		q = p+1;
	}
	return str; 
}

//-------------拓展：左旋转字符串----------------
//------------测试用例---------------------- 
/*
1.功能：循环左移1位，k位，len-1位
2.负面：字符串为空，n超出范围(<1或>len-1) 
*/ 
string LeftRotateString(string str, int n)
{
	int len = str.size();
	if(len==0 || n<1 || n>len-1)
		return str;
	Reverse(str, 0, len-1);
	Reverse(str, 0, len-n-1);
	Reverse(str, len-n, len-1);
	return str;
}
int main()
{
	string str;
	while(getline(cin, str))
	{
//		string result = ReverseString(str);
		string result = LeftRotateString(str, 2);
		cout<<result<<endl;
	}
	return 0;
}
