#include <iostream>
#include <string>
using namespace std;

//-----------��ת����˳��--------------
//------------��������------------
/*
1. ���ܣ�����һ�����ʣ��ж������
2. ���棺 �ַ���Ϊ�գ��ַ�����ֻ�пո� 
*/ 
void Reverse(string &str, int p, int q)
{//��תstr[p, q]
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
{//˼·���ȶ������ַ������з�ת�������ζ�ÿ�����ʽ��з�ת 
	int len = str.size();
	if(len <= 1)
		return str;
	Reverse(str, 0, len-1);
	int p=0, q=1;
	while(p < len)
	{
		while(p<len && str[p]==' ')
		{//�����Կո�ͷ����� 
			++p;
			++q;
		}
		if(p < len)
		{//�ҵ����ʵ�һ���ַ�����q�ҵ����һ���ַ����Ե��ʽ��з�ת 
			while(q<len && str[q]!=' ')
				++q;
			--q;
			Reverse(str, p, q); 
		}
		//����p,qָ�� 
		p = q+1;
		q = p+1;
	}
	return str; 
}

//-------------��չ������ת�ַ���----------------
//------------��������---------------------- 
/*
1.���ܣ�ѭ������1λ��kλ��len-1λ
2.���棺�ַ���Ϊ�գ�n������Χ(<1��>len-1) 
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
