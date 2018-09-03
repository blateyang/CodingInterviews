#include <iostream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;

//----------��������-------------
/*
1.���ܣ������н���һ��Ԫ�أ�������ȫ˳����ȫ����һ�����
2.���棺����Ϊ�� 
*/
//˼·������(�ݼ�)�鲢�����˼�룬�ڹ鲢��ͬʱͳ��������� 
void mergeInvPairs(vector<int> &A, int lo, int mi, int hi, int &invPairs)
{
	int i,il,ir;
	vector<int> buf;
	for(i=lo; i<mi; ++i)
		buf.push_back(A[i]);
	int lenBuf = buf.size(); 
	for(i=lo,il=0,ir=mi; il<lenBuf;)
	{
		if(ir<hi && A[ir]>=buf[il]) 
			A[i++] = A[ir++];	
		if(ir>=hi || A[ir]<buf[il])
		{//�������е�ǰԪ�ش����������е�ǰԪ�أ��������������ж��ǵݼ��ģ���˴���hi-ir������� 
			invPairs += hi-ir;
			A[i++] = buf[il++];
		}
			
	}
}
void mergeSortInvPairs(vector<int> &A, int lo, int hi, int &invPairs) //A[lo, hi)
{
	if(A.size()<=1 || hi-lo<2)
		return;
	int mi = (lo+hi)/2;
	mergeSortInvPairs(A, lo, mi, invPairs);
	mergeSortInvPairs(A, mi, hi, invPairs);
	mergeInvPairs(A, lo, mi, hi, invPairs);
}
int InversePairs(vector<int> data)
{
	int invPairs=0;
	mergeSortInvPairs(data, 0, data.size(), invPairs);
	return invPairs;
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
		
		int result=InversePairs(v_test);
		cout<<result<<endl;
//		for(auto num:v_test)
//			cout<<num<<" ";
//		cout<<endl;
	}
	return 0;
}
