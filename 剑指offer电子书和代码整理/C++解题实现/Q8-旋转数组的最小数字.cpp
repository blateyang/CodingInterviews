#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

/*-----------测试用例-------------------
1. 输入数组为空
2. 输入数组仅含一个元素
3. 输入的非减排序数组未旋转
4. 输入的非减排序数组旋转(不含或含重复元素） 
*/

// ------------自己的解法-----------------
//思路：采用二分查找的思路进行递归（分别从左、右子序列中找到最小的元素，然后返回其中的较小者） 
int findMin(vector<int> const &A, int lo, int hi)
{
	if(lo == hi-1) return A[lo];
	if(lo > hi-1) return 0;
	int mi = (lo+hi)/2;
	int num_l = findMin(A, lo, mi);
	int num_r = findMin(A, mi, hi);
	return (num_l < num_r) ? num_l : num_r;
}

//------------剑指offer的解法--------------
//思路：采用二分查找的思路进行迭代（设置两个初始分别指向头尾的指针，然后将两指针p,q所指范围内
//		中间元素mi与p,q所指元素进行比较，若A[mi]>=A[p],用mi更新p;若A[mi]<=A[q]，用mi更新q,直至p,q相邻
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
		if(A[p] == A[mi] && A[mi] == A[q]) //无法确定A[mi]是在左边更大的子序列还是在右边更小的子序列 
			{//只能顺序查找序列A[p,q] 
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
