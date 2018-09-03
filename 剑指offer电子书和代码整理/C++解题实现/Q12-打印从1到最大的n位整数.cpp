#include <iostream>
#include <string>
#include <algorithm> 
using namespace std;

void PrintNumber(string const &str)
{//��ӡ�����ַ�����ȥ��ǰ��0�� 
	bool FindNonZero = false;
	for(auto c:str)
		{
			if(c!='0') FindNonZero = true;
			if(FindNonZero) cout<<c;
		}
	cout<<endl;
}

bool Increment(string &str)
{//���ַ���ģ��������1���� 
	bool isOverflow = false;
	int nTakeover = 0; //��λλ 
	int length = str.size();
	for(int i=length-1; i>=0; --i)
	{
		unsigned nSum = str[i] - '0' + nTakeover;
		if(i == length-1) //ĩλ+1 
			++nSum;
		if(nSum >= 10) //����10������λ 
		{
			if(i == 0) //����λ���������λ����� 
				isOverflow = true;
			else	//�������λ�ͽ�λλ 
				{	
					nSum -= 10;
					nTakeover = 1;
					str[i] = nSum + '0';
				}
		}
		else
			{
				str[i] = nSum + '0';
				break;
			 } 
	}
	return isOverflow;
}

void PrintToMaxOfNDigitsRecursively(string &str, unsigned idx)
{//ͨ���ݹ�ķ�ʽ��ӡnλ������ȫ���� 
	if(idx==str.size())
	{
		PrintNumber(str);
		return;
	}
	for(int i=0; i<10; ++i)
	{
		str[idx] = i + '0';
		PrintToMaxOfNDigitsRecursively(str, idx+1);
	}
}

void PrintToMaxOfNDigits(int n)
{
	if(n<=0)
		return;
	string str(n,'0');
//	PrintToMaxOfNDigitsRecursively(str, 0);
	while(!Increment(str))
		PrintNumber(str);
}

//�����Ŀ�������Ӽ���˼·�������ַ���string��ģ������Ľ���λ���̣� 
string addTwoNum(string const str1, string const str2)
{
	int n1=str1.size();
	int n2=str2.size();
	//���ڲ�����ͳһת���ɳ����Ӷ��� 
	if(n1 < n2)
		return addTwoNum(str2, str1);
			
	int bigLen = n1;
	int smallLen = n2;
	unsigned stepIn = 0;
	string result;
	for(int i=0; i<bigLen; ++i)
	{//�Ӻ���ǰ��λ��Ӳ���¼��λ���ַ�������Ϊ���ĵ�λ�� 
		int secondNum = (i<smallLen) ? str2[--n2] - '0': 0;
		int sum = str1[--n1] - '0' + secondNum + stepIn;
		result.push_back(sum%10 + '0');
		stepIn = sum/10;
	}
//	for(int i=smallLen; i<bigLen; ++i)
//	{
//		int sum = str1[--n1] - '0' + stepIn;
//		result.push_back(sum%10 + '0');
//		stepIn = sum/10; 
//	}
	if(stepIn==1) //ԭ���������λҲ������λ 
		result.push_back('1');
	reverse(result.begin(), result.end());
	return result;
}

string subtractTwoNum(string str1, string str2)
{
	string result;
	int n1 = str1.size();
	int n2 = str2.size();
	//�жϽ������
	char sign = '+';
	if(n1 < n2)
	{
		sign = '-';
		swap(str1, str2);
	 } 
	 if(n1 == n2)
	 {
	 	for(int i=0; i<n1; ++i)
	 	{
	 		if(str1[i]>str2[i])
	 			break;
	 		else if(str1[i]<str2[i])
	 			{
					sign = '-';
					swap(str1, str2);
					break; 
				 } 
		 }
	 }
	 
	int bigLen = str1.size();
	int smallLen = str2.size();
	unsigned borrow=0;
	reverse(str1.begin(), str1.end());
	reverse(str2.begin(), str2.end());
	for(int i=0; i<bigLen; ++i)
	{
		int secondNum = (i<smallLen) ? str2[i]-'0' : '0';
		int sub = str1[i] - '0' - secondNum - borrow;
		borrow = 0; //ע��ʹ�����λ��Ҫ��ʱ���� 
		if(sub<0)
		{
			borrow = 1;
			result.push_back(10 + sub + '0');
		}
		else
			result.push_back(sub+'0');
	}
	reverse(result.begin(), result.end());
	result = result.substr(result.find_first_not_of('0'));
	if(sign=='-')
		result.insert(result.begin(), '-');
	return result;
}

int main()
{
//	PrintToMaxOfNDigits(2);
	string str1{"987656789"},str2{"987654321"},str;
//	str = addTwoNum(str1, str2);
//	cout<<str1+" + "+str2+"="<<str<<endl;
	str = subtractTwoNum(str1, str2);
	cout<<str1+" - "+str2+"="<<str<<endl;
	return 0;
}
