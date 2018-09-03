#include <iostream>
#include <string>
using namespace std;

//--------------测试用例----------------
/*
1.功能：正整数字符串（含或不含'+')、负整数字符串、0
2.负面：字符串为空，字符串中含有非法字符，字符串转换成的整数超出int范围 
*/ 
int StrToInt(string str)
{
	int len = str.size();
	if(len == 0)
		return 0;
	bool minus = false;
	int i=0;
	long long num=0;
	if(str[i] == '-')
	{
		minus = true;
		++i;
	}
	if(str[i] == '+')
		++i;
	for(; i<len; ++i)
	{
		if(str[i]>='0' && str[i]<='9')
		{
			num = num*10 + str[i]-'0';
			if(!minus && num > 0x7FFFFFFF) //超过int最大值 
				return 0;
			if(minus && num > 0x80000000)  //超过int最小值 
				return 0;
		}
		else
			return 0;
	}
	if(minus)
	{
		num = 0-num; 
	}
	return int(num);
 } 
 
int main()
{
	string str;
	while(cin>>str)
		cout<<StrToInt(str)<<endl; 
	return 0;
}
