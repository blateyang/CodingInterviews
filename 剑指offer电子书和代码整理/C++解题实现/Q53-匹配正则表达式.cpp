#include <iostream>
using namespace std;

//--------------测试用例---------------
/*
1.功能：str="aaa", pattern="aaa","a.a","aba","a*a","a.*a","ab*ac*a"
2.负面：str或pattern为空 
*/ 
bool matchCore(char *str, char *pattern)
{//对于含*的匹配有多种可能（相当于非确定有限状态机），通过递归的方式返回所有可能的情况 
	if(*str=='\0' && *pattern=='\0')
		return true;
	if(*str!='\0' && *pattern=='\0')
		return false;
	//对于含'*'的情况(要先与含'.'的情况判断，否则对于"a*a"的例子就无法正确匹配） 
	if(*(pattern+1) == '*')
	{
		if(*str==*pattern || (*pattern=='.' && *str!='\0'))
		{
			bool state1, state2, state3;
			state1 = matchCore(str+1, pattern+2); //将a*当一个字符，同时进入下一个字符匹配状态
			state2 = matchCore(str+1, pattern);	  //将a*当多个a,字符串往下走一个
			state3 = matchCore(str, pattern+2);	  //将a*当0个字符，忽略该'*' 
			return state1||state2||state3;
		}
		else
			return matchCore(str, pattern+2);	//直接忽略b* 
	 } 
	//对于仅含'.'的情况 
	if(*str==*pattern || (*pattern=='.' && *str!='\0')) 
		return matchCore(str+1, pattern+1);
	return false;	//平凡情况 
}

bool match(char *str, char *pattern)
{
	if(str==NULL || pattern==NULL)
		return false;
	return matchCore(str, pattern);
 } 
 
int main()
{
	char str[] = "aaa";
	char *pattern[6] = {"aaa","a.a","aba","a*a","a.*a","ab*ac*a"};
	for(int i=0; i<6; ++i)
		if(match(str, pattern[i]))
			cout<<pattern[i]<<endl;
	return 0;
}
