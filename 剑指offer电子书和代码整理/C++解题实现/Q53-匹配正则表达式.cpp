#include <iostream>
using namespace std;

//--------------��������---------------
/*
1.���ܣ�str="aaa", pattern="aaa","a.a","aba","a*a","a.*a","ab*ac*a"
2.���棺str��patternΪ�� 
*/ 
bool matchCore(char *str, char *pattern)
{//���ں�*��ƥ���ж��ֿ��ܣ��൱�ڷ�ȷ������״̬������ͨ���ݹ�ķ�ʽ�������п��ܵ���� 
	if(*str=='\0' && *pattern=='\0')
		return true;
	if(*str!='\0' && *pattern=='\0')
		return false;
	//���ں�'*'�����(Ҫ���뺬'.'������жϣ��������"a*a"�����Ӿ��޷���ȷƥ�䣩 
	if(*(pattern+1) == '*')
	{
		if(*str==*pattern || (*pattern=='.' && *str!='\0'))
		{
			bool state1, state2, state3;
			state1 = matchCore(str+1, pattern+2); //��a*��һ���ַ���ͬʱ������һ���ַ�ƥ��״̬
			state2 = matchCore(str+1, pattern);	  //��a*�����a,�ַ���������һ��
			state3 = matchCore(str, pattern+2);	  //��a*��0���ַ������Ը�'*' 
			return state1||state2||state3;
		}
		else
			return matchCore(str, pattern+2);	//ֱ�Ӻ���b* 
	 } 
	//���ڽ���'.'����� 
	if(*str==*pattern || (*pattern=='.' && *str!='\0')) 
		return matchCore(str+1, pattern+1);
	return false;	//ƽ����� 
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
