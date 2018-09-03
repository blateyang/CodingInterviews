#include <iostream>
#include <vector>
#include <sstream>
#include <string> 
using namespace std;

//-----------------��������---------------------
/*
1.���ܣ�����ֻ����һ�ε������ڻ�����
2.���棺����Ϊ�ջ����һ��Ԫ�أ������в�����ֻ����һ�ε��������������������Σ���ֻ��һ�� 
*/ 
int FindFirstBitOf1(int num)
{//���ش����λ�����λ�� 
	int bitIndex = 0;
	while(num != 0)
	{
		num = num >> 1;
		++bitIndex;
	}
	return bitIndex;
}

bool isBit1(int num, int index)
{
//	int base = 1<<(index-1); // index�����0
//	return ((num&base)==0)? false:true; //λ�������&���ȼ�Ҫ�����е�==
	num = num>>(index-1);
	return (num & 1);
}

void FindNumsAppearOnce(vector<int> &data, int *num1, int *num2)
{//˼·����������ֻ��һ��ֻ����һ�ε���ʱ��ͨ�����ζ������е�Ԫ�����õ���������������Ķ����Ʊ�ʾ,һ���������������õ�0,һ������0��򲻱䣩
//		��ԭ�����������������������������λ�Ƿ�Ϊ1��ֳ�������ֻ����һ��ֻ����һ�ε��������� 
	int len = data.size();
	if(len <= 1)
		return;
	int XORresult = 0;
	for(int i=0; i<len; ++i)
		XORresult ^= data[i];
	if(XORresult == 0)
		return;
	int FirstBitOf1 = FindFirstBitOf1(XORresult);
	*num1 = 0, *num2 = 0; 
	for(int i=0; i<len; ++i)
	{
		if(isBit1(data[i], FirstBitOf1))
			*num1 ^= data[i];
		else
			*num2 ^= data[i];
	}
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
	int num1=0, num2=0;
	while(getline(cin, input))
	{
		vector<int> v_test;
		istringstream str_in(input);	
		string tmp;
		while(str_in>>tmp)
			v_test.push_back(stringToInt(tmp));
		FindNumsAppearOnce(v_test, &num1, &num2);
		cout<<num1<<" "<<num2<<endl;
	}
	return 0; 
}
