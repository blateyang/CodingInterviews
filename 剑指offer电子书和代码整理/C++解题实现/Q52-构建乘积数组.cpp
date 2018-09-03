#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

//----------------测试用例--------------------
/*
1.功能：含有n个元素的数组对应的乘积数组(n=2, 5, 10)
2.负面：输入数组长度为小于2;乘积超出int的表示范围 
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
//思路：设置两个辅助数组用来分别存储从头至倒数第二个以及从尾至第二个的数的累乘，
//		基于这两个数组去构建乘积数组
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
//		//基于辅助数组构建乘积数组
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

//剑指offer思路：类似，但是是直接在输出数组上计算，未考虑超出int范围的情况 
	int len = A.size();
	vector<int> B;
	if(len > 1)
	{
		int i; 
		for(i=0; i<len; ++i)
			B.push_back(1);
		//自上而下累乘数组A中的各元素 
		for(i=1; i<len; ++i)
			B[i] = B[i-1]*A[i-1];
		int tmp = 1;
		//自下而上累乘数组A中的各元素 
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
