#include <iostream>
#include <vector>
using namespace std;

void Swap(string &str1, string &str2)
{
	string tmp=str1;
	str1 = str2;
	str2 = tmp;
}

int partition(vector<string> &A, int low, int high) //A[low, high),low<high
{
	int base = low;
	int p=low, q=high-1;
	while(p < q)
	{
		while(A[q]+A[base] >= A[base]+A[q] && p<q)
			--q;
		while(A[p]+A[base] <= A[base]+A[p] && p<q)
			++p;
		if(p<q)
			Swap(A[p], A[q]); 
	}
	Swap(A[q], A[base]);
	return q;
}

void quickSort(vector<string> &A, int low, int high)
{
	if(A.size()==0 || A.size()==1 || high-low<2)
		return;
	int mid = partition(A, low, high);
	quickSort(A, low, mid);
	quickSort(A, mid+1, high);
 } 
 
//-----------��������----------------
/*
1.���ܣ����������ֻ��һ�������ж����������λ����ͬ��ͬ�����������ظ�����λ
2.���棺��������Ϊ�� 
*/ 
string PrintMinNumber(vector<int> numbers)
{
	string result;
	int len = numbers.size();
	if(len == 0)
		return result;
	//��numbersת���ַ�������
	vector<string> strArr;
	string bufStr;
	for(int i=0; i<len; ++i)
	{
		char buf[256];
		sprintf(buf, "%d", numbers[i]);
		bufStr = buf;
		strArr.push_back(bufStr);
	 } 
	//��strArr�����Զ���Ĵ�С�ȽϹ���������� 
	quickSort(strArr, 0, len);
	//��strArr��Ԫ�ش�ǰ����ƴ����������
	for(int i=0; i<len; ++i)
		result += strArr[i];
	return result; 
}

int main()
{
	vector<int> numbers{3,32,321};
	string result = PrintMinNumber(numbers);
	cout<<result<<endl;
	return 0; 
}
