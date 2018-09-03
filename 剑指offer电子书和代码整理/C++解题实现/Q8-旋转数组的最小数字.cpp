#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

/*-----------��������-------------------
1. ��������Ϊ��
2. �����������һ��Ԫ��
3. ����ķǼ���������δ��ת
4. ����ķǼ�����������ת(�������ظ�Ԫ�أ� 
*/

// ------------�Լ��Ľⷨ-----------------
//˼·�����ö��ֲ��ҵ�˼·���еݹ飨�ֱ���������������ҵ���С��Ԫ�أ�Ȼ�󷵻����еĽ�С�ߣ� 
int findMin(vector<int> const &A, int lo, int hi)
{
	if(lo == hi-1) return A[lo];
	if(lo > hi-1) return 0;
	int mi = (lo+hi)/2;
	int num_l = findMin(A, lo, mi);
	int num_r = findMin(A, mi, hi);
	return (num_l < num_r) ? num_l : num_r;
}

//------------��ָoffer�Ľⷨ--------------
//˼·�����ö��ֲ��ҵ�˼·���е���������������ʼ�ֱ�ָ��ͷβ��ָ�룬Ȼ����ָ��p,q��ָ��Χ��
//		�м�Ԫ��mi��p,q��ָԪ�ؽ��бȽϣ���A[mi]>=A[p],��mi����p;��A[mi]<=A[q]����mi����q,ֱ��p,q����
int findMinIter(vector<int> const &A)
{
	int p=0, q=A.size()-1;
	int mi = p;
	while(A[p] >= A[q])
	{
		if(q-p == 1)
			{
				mi = q;
				break;
			}
		mi = (p+q)/2;
		if(A[p] == A[mi] && A[mi] == A[q]) //�޷�ȷ��A[mi]������߸���������л������ұ߸�С�������� 
			{//ֻ��˳���������A[p,q] 
				int minNum = A[p];
				for(int i=p+1; i<=q; i++)
					if(A[i] < minNum) 
						minNum = A[i];
				return minNum;
			} 
		if(A[mi] >= A[p])
			p = mi;
		if(A[mi] <= A[q])
			q = mi;
	 }
	return A[mi];
}

int  minNumberInRotateArray(vector<int> rotateArray)
{
	int length = rotateArray.size();
	if(length == 0)
		return 0;
	if(length == 1)
		return rotateArray[0];
//	return findMin(rotateArray, 0, length);
	return findMinIter(rotateArray);
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
			
		cout<<minNumberInRotateArray(v_test)<<endl;
	}
	return 0;
}
