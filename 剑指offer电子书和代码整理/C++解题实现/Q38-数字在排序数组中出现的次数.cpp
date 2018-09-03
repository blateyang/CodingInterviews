#include <iostream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;

//------------��������-----------------
/*
1.���ܣ���������Ϊ�������(��ָoffer�в�δ���ǣ������������������г���1�λ���
2.�߽磺���ֳ���������������ǰ��������
3.���棺����Ϊ��;����δ�����������г���
*/ 
//˼·���Զ��ֲ����㷨����Ǩ�ƣ�����������ֱ��ҵ��������������ֵ����һ�����ֺ�
//		���ڸ������ֵ����һ�����֣��������������෴���ֱ��ҵ������ڸ������ֵ����һ�����ֺ͸��ڸ������ֵ����һ������ 
bool ascendFlag = true; 
int BinSearchPost(vector<int> const &data, int low, int high, int num) //data[low, high)
{
	//�ݹ�� 
	if(low == high) //Խ����� 
		return -1;
	if(low == high-1) //������Χ�˻���ֻ��һ���� 
		return (data[low]==num)? low:-1;
	int mid = (low+high)/2;
	if(ascendFlag)
	{
		if(data[mid] <= num) //���������������е�������������������� 
				low = mid;
			else
				high = mid;
//		cout<<low<<" "<<high<<endl;
	}
	else
	{
		if(data[mid] >= num) //���������������е����ҽ�������������� 
				low = mid;	
			else
				high = mid; 
	}
	return BinSearchPost(data, low, high, num);
 } 

int BinSearchPre(vector<int> const &data, int low, int high, int num) //data[low, high)
{
	//�ݹ�� 
	if(low == high) //Խ����� 
		return -1;
	if(low == high-1) //������Χ�˻���ֻ��һ����
		if(ascendFlag) 
			return (data[low]<num)? low:-1;
		else
			return (data[low]>num)? low:-1;
	int mid = (low+high)/2;
	if(ascendFlag)
	{
		if(num <= data[mid]) // ���������������е�����������ǰ��������� 
				high = mid; 
			else 
				low = mid; 
	}
	else
	{
		if(data[mid] <= num) // ���������������е���������ǰ���������
			high = mid;
		else  
			low = mid;	
	}
	return BinSearchPre(data, low, high, num);
 } 

 
int GetNumberOfK(vector<int> data, int k)
{
	int len = data.size();
	if(len==0)
		return 0;
	if(data[0]>data[len-1])
		ascendFlag = false;
	int postIdx = BinSearchPost(data, 0, len, k);
	int preIdx = BinSearchPre(data, 0, len, k);
//	cout<<"preIdx:"<<preIdx<<"	postIdx:"<<postIdx<<endl;
	int result = postIdx-preIdx; 
	return (result<0)? 0:result;
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
		int result = GetNumberOfK(v_test, 3);
		cout<<"times of k:"<<result<<endl; 
	}
	return 0;
}
