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
 
//-----------测试用例----------------
/*
1.功能：输入的数组只有一个数；有多个数（各数位数相同或不同）；数中有重复的数位
2.负面：输入数组为空 
*/ 
string PrintMinNumber(vector<int> numbers)
{
	string result;
	int len = numbers.size();
	if(len == 0)
		return result;
	//将numbers转成字符串数组
	vector<string> strArr;
	string bufStr;
	for(int i=0; i<len; ++i)
	{
		char buf[256];
		sprintf(buf, "%d", numbers[i]);
		bufStr = buf;
		strArr.push_back(bufStr);
	 } 
	//对strArr按照自定义的大小比较规则进行排序 
	quickSort(strArr, 0, len);
	//将strArr各元素从前往后拼接起来返回
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
