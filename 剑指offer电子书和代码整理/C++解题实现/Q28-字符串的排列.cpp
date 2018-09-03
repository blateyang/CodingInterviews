#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;
using iter = string::iterator; 

//-------------��������-----------------
/*
1. ���ܲ��ԣ��ַ�������һ���ַ����ַ����ж����ͬ���ַ����ַ����ж����ͬ���ַ�
2. ������ԣ��ַ���Ϊ�� 
*/ 

void PermutationIter(vector<string> &v_str, string &str, int idxFirst)
{//�ݹ���ԣ����ڻ��ݷ����μ�https://www.nowcoder.com/questionTerminal/fe6b651b66ae47d7acce78ffdd9a96c7�� 
	if(idxFirst==str.size()-1) //�ݹ����������str���һ���ַ� 
		{
			v_str.push_back(str);
			return;
		}
	for(int i=idxFirst; i!=str.size(); ++i)
	{//֮���������ν�����Ϊ���ڽ������ַ���Ԫ�غ��ܻ��ݵ�����ǰ��״̬
				char tmp = str[idxFirst];
				str[idxFirst] = str[i];
				str[i] = tmp;
				PermutationIter(v_str, str, idxFirst+1);
				tmp = str[idxFirst];
				str[idxFirst] = str[i];
				str[i] = tmp;
	}
}
vector<string> Permutation(string str) 
{//˼·�����ַ������Ϊ��һ���ַ��ͺ�������ַ���������һ���ַ�������������ַ���
//		�еĲ�ͬ�ַ����н�������������浽vector�У�Ȼ��ݹ�ض����ַ���ִ����ͬ
//		�Ĳ�����Ϊ���ܹ����ֵ�˳�������������vector���������㷨 
	vector<string> v_str;
	if(str.size()!=0)
		PermutationIter(v_str, str, 0);
	//���ֵ�������v_str
	sort(v_str.begin(), v_str.end()); 
	//��v_strȥ�أ��ظ���Ԫ�ػᱻ������β����,���ص��ǵ����� 
	vector<string>::iterator unique_end = unique(v_str.begin(), v_str.end());
	v_str.erase(unique_end, v_str.end());
	return v_str;
} 

// ��չ�����ַ��������
void combinationIter(char *string, int m, vector<char> &v_str)
{//˼·�����������У�Ҳ���Բ��Ϊ�׸��ַ���ʣ�µ����ַ��������ݹ���⡣���ڴӳ���Ϊn���ַ���
//		��ѡ��m���ַ�����ϣ��������ַ���������У���ֻ���ʣ�³�Ϊn-1���ַ����� 
//		ѡ��m-1���ַ��������ַ���������У����ʣ�³�Ϊn-1���ַ�����ѡ��m���ַ� 
	//�ݹ���������������m����0���ߴﵽ�ַ���ĩβ����Ӧ�Ĵ���ʽ��ͨ����"ab\0"�����򵥵����ӷ��������� 
	if(m==0)
	{
		for(int i=0; i!=v_str.size(); ++i)
			cout<<v_str[i];
		cout<<endl;
		return;
	}
	if(*string == '\0')
		return;
	v_str.push_back(*string); //�����ַ���������У���ֻ���ʣ�³�Ϊn-1���ַ�����ѡ��m-1���ַ�
	combinationIter(string+1, m-1, v_str);
	v_str.pop_back();  //���ַ���������У����ʣ�³�Ϊn-1���ַ�����ѡ��m���ַ� 
	combinationIter(string+1, m, v_str);
 } 

void Combination(char *chars)
{
	if(chars == NULL)
		return;
	int len = strlen(chars);
	vector<char> v_str;
	for(int m=1; m<=len; ++m)
		combinationIter(chars, m, v_str);
}

//������⣺8�ʺ����⣨�����ʺ�����ͬһ�С�ͬһ�л�ͬһ�Խ����ϣ�,���ǹ���92�ְڷ� 
//˼·��������һ�������0~7��8���кţ���ʾ����ÿ���������ڵ������������ȫ���У���
//		��ÿ�������ж��Ƿ���Ԫ���ڶԽ�����
void swap(int &a, int &b)
{
	int tmp = a;
	a = b;
	b = tmp;
}
void permutationNums(vector<vector<int>> &v_arranges, vector<int> &v_nums, int idxFirst)
{
	if(idxFirst == v_nums.size()-1)
		{
			v_arranges.push_back(v_nums);
			return;
		}
	for(int i=idxFirst; i!=v_nums.size(); ++i)
	{
		swap(v_nums[i], v_nums[idxFirst]);
		permutationNums(v_arranges, v_nums, idxFirst+1);
		swap(v_nums[i], v_nums[idxFirst]);
	}
}
bool hasNoDiagonalItem(vector<int> const &v_nums)
{
	int len = v_nums.size();
	for(int i=0; i!=len; ++i)
		for(int j=i+1; j!=len; ++j)
		{
			if(j-i == v_nums[j]-v_nums[i] || j-i == v_nums[i]-v_nums[j])
				return false;
		}
	return true;
}

int main()
{
//	//�ַ������в��� 
//	string input;
//	while(getline(cin, input))
//	{
//		vector<string> v_test;
//		v_test = Permutation(input);
//		for(auto num: v_test)
//			cout<<num<<" ";
//		cout<<endl;
//	}
//	// �ַ�����ϲ���
//	char s[]="abc";
//	Combination(s); 
	//�������в��� 
	vector<int> v_nums{0,1,2,3,4,5,6,7};
	vector<vector<int>> v_arranges;
	permutationNums(v_arranges, v_nums, 0);
	cout<<"number of arranges:"<<v_arranges.size()<<endl;
	int arrange_num = 0;
	for(auto const &arrange:v_arranges)
		if(hasNoDiagonalItem(arrange))
			++arrange_num;
	cout<<arrange_num<<endl;
	return 0;
}
