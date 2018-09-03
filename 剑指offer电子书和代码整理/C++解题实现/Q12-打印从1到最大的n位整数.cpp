#include <iostream>
#include <string>
#include <algorithm> 
using namespace std;

void PrintNumber(string const &str)
{//打印数字字符串（去除前导0） 
	bool FindNonZero = false;
	for(auto c:str)
		{
			if(c!='0') FindNonZero = true;
			if(FindNonZero) cout<<c;
		}
	cout<<endl;
}

bool Increment(string &str)
{//用字符串模拟整数加1运算 
	bool isOverflow = false;
	int nTakeover = 0; //进位位 
	int length = str.size();
	for(int i=length-1; i>=0; --i)
	{
		unsigned nSum = str[i] - '0' + nTakeover;
		if(i == length-1) //末位+1 
			++nSum;
		if(nSum >= 10) //超过10产生进位 
		{
			if(i == 0) //若进位发生在最高位，溢出 
				isOverflow = true;
			else	//更新最低位和进位位 
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
{//通过递归的方式打印n位整数的全排列 
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

//相关题目：大数加减（思路：利用字符串string，模拟手算的进借位过程） 
string addTwoNum(string const str1, string const str2)
{
	int n1=str1.size();
	int n2=str2.size();
	//便于操作，统一转换成长数加短数 
	if(n1 < n2)
		return addTwoNum(str2, str1);
			
	int bigLen = n1;
	int smallLen = n2;
	unsigned stepIn = 0;
	string result;
	for(int i=0; i<bigLen; ++i)
	{//从后往前逐位相加并记录进位（字符串后面为数的低位） 
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
	if(stepIn==1) //原大数的最高位也发生进位 
		result.push_back('1');
	reverse(result.begin(), result.end());
	return result;
}

string subtractTwoNum(string str1, string str2)
{
	string result;
	int n1 = str1.size();
	int n2 = str2.size();
	//判断结果正负
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
		borrow = 0; //注意使用完借位后要及时清零 
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
