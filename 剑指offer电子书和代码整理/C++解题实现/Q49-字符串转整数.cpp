#include <iostream>
#include <string>
using namespace std;

//--------------��������----------------
/*
1.���ܣ��������ַ��������򲻺�'+')���������ַ�����0
2.���棺�ַ���Ϊ�գ��ַ����к��зǷ��ַ����ַ���ת���ɵ���������int��Χ 
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
			if(!minus && num > 0x7FFFFFFF) //����int���ֵ 
				return 0;
			if(minus && num > 0x80000000)  //����int��Сֵ 
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
