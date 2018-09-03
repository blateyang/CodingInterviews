#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;
using iter=vector<int>::iterator;

//------------��������------------------
/*
1.���ܲ��ԣ�ĳ�����ǻ���BST�ĺ�����������BST������������ֻ����������ֻ��������,����һ�����ڵ�)
2.������ԣ������� 
*/ 

bool VerifySubSeq(vector<int> const &seq, iter begin, iter end)
{//�ݹ��жϴ�begin��end���������Ƿ���ĳBST�ĺ������ 
	if(end-begin<2)  //�ݹ��������С������Ԫ�� 
		return true; 
	if(end-begin==2) //�ݹ����ֻʣ����Ԫ�أ���<������>��Ϊ��(BST����ȫ�������� 
	{
		if(*begin>*(begin+1) && *(begin+1)<*end ) return false;
		else return true;
	}
	iter it=begin; 
	while(it<end && *it<=*end) //�ҵ���һ������end���ڵ��Ԫ��
		++it;
	//�豣֤it�����Ԫ�ؾ����ڸ��ڵ� 
	for(iter i=it; i<end; ++i)
		if(*i<=*end) return false; 
	return VerifySubSeq(seq, begin, it-1)&&VerifySubSeq(seq, it, end-1);	
}

bool VerifySeqOfBST(vector<int> seq)
{
	if(seq.size()==0)
		return false;
	return VerifySubSeq(seq, seq.begin(), seq.end()-1);	
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
			
		if(VerifySeqOfBST(v_test))
			cout<<"true"<<endl;
		else
			cout<<"false"<<endl;
	}
	return 0;
}
