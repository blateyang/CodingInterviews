#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

//----------------��������--------------------
/*
1.���ܣ�����n��Ԫ�ص������Ӧ�ĳ˻�����(n=2, 5, 10)
2.���棺�������鳤��ΪС��2;�˻�����int�ı�ʾ��Χ 
*/ 
#define MAX_INT 0x7fffffff
#define MIN_INT 0X80000000
bool outOfRange(long long num)
{
	if((num>=0 && num>MAX_INT) || (num<0 && num>MIN_INT))
		return true;
	else
		return false; 
}

vector<int> multiply(const vector<int>& A) 
{
//˼·�����������������������ֱ�洢��ͷ�������ڶ����Լ���β���ڶ����������۳ˣ�
//		��������������ȥ�����˻�����
//	int len = A.size();
//	vector<int> result;
//	
//	if(len > 1)
//	{
//		vector<int> preArr{1}, postArr{1};
//		long long preProd=1, postProd=1, resProd=1;
//		int i;
//		for(i=0; i<len-1; ++i)
//		{
//			preProd *= A[i];
//			if(outOfRange(preProd))
//				return result;
//			preArr.push_back(preProd);
//			
//			postProd *= A[len-1-i];
//			if(outOfRange(postProd))
//				return result;
//			postArr.push_back(postProd); 
//		}
//		//���ڸ������鹹���˻�����
//		for(i=0; i<len; ++i)
//		{
//			resProd = preArr[i]*postArr[len-1-i];
//			if(outOfRange(resProd))
//				break;
//			result.push_back(resProd);
//		}
//	}
//	vector<int> invalid;
//	return (result.size()==len)? result:invalid;

//��ָoffer˼·�����ƣ�������ֱ������������ϼ��㣬δ���ǳ���int��Χ����� 
	int len = A.size();
	vector<int> B;
	if(len > 1)
	{
		int i; 
		for(i=0; i<len; ++i)
			B.push_back(1);
		//���϶����۳�����A�еĸ�Ԫ�� 
		for(i=1; i<len; ++i)
			B[i] = B[i-1]*A[i-1];
		int tmp = 1;
		//���¶����۳�����A�еĸ�Ԫ�� 
		for(i=len-1; i>=0; --i)
		{
			B[i] *= tmp;
			tmp *= A[i];
		}
	}
	return B;
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
	while(getline(cin, input))
	{
		vector<int> v_test;
		istringstream str_in(input);
		string tmp;
		while(str_in>>tmp)
			v_test.push_back(stringToInt(tmp));
		vector<int> result = multiply(v_test);
		for(auto num: result)
			cout<<num<<" ";
		cout<<endl;
	}
	return 0;
}
