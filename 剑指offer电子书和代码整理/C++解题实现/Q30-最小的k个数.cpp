#include <iostream>
#include <vector>
#include <set>
using namespace std;

void Swap(int &a, int &b)
{
	int tmp;
	tmp = a;
	a = b;
	b = tmp;
}

int partition(vector<int> &A, int pre, int post) //A[pre, post]
{
	Swap(A[pre], A[pre+rand()%(post-pre+1)]); //随机选取枢纽元并与首元素交换 
	int pivot = A[pre]; //把枢纽元保存起来
	int p=pre, q=post;
	while(p < q)
	{//采用填坑法,可以不用再写交换函数 
		while(p < q)
			if(A[q] > pivot) //去掉=号可以优化含有大量重复元素的情况，勤于交换，懒于拓展 
				--q;
			else
			{
				A[p++] = A[q];
				break;
			}
		while(p < q)
			if(A[p] < pivot)
				++p;
			else
			{
				A[q--] = A[p];
				break;
			}		
	 } 
	 A[q] = pivot;
	 return q;
 } 
 
//-------------测试用例---------------
/*
1.功能：输入中有重复数字；没有重复数字 
2.边界：k=1或整个数组长度
3.负面：k超出合理范围；数组为空 
*/ 
/*
vector<int> GetLeastNumbers_Solution(vector<int> input, int k) 
{
//解法1：随机快速排序算法,时间复杂度为O(n)，会对原数组进行交换改动
//		（基于partition函数，在每次划分交换后判断返回的index是否与k-1相等，
//		若是则index即为第k大的数；若index>k-1,则第k大的数在index左边，
//		更新partition的右界；若index<k-1，则第k大的数在index右边，更新partition的左界
	vector<int> result;
	int len = input.size();
	if(len==0 || k<1 || k>len)
		return result;
	int start = 0, end = len-1;
	int index = partition(input, start, end);
	while(index != k-1)
	{
		if(index > k-1)
			{
				end = index-1;
				index = partition(input, start, end);
			}
		else
		{
			start = index+1;
			index = partition(input, start, end);
		}
	}
	for(int i=0; i<=index; ++i)
		result.push_back(input[i]);
	return result;
}
*/
//解法2：利用STL的关联容器multiset（基于红黑树实现）去存储当前已遍历序列中最小的k个数
//		时间复杂度为n*log(k)，不会对原数组进行改动，适合处理海量数据 
using intSet = multiset<int, greater<int>>; //greater<int> 指定multiset按降序排序，第一个元素是最大元素 
using setIterator = multiset<int, greater<int>>::iterator;
intSet GetLeastNumbers_Solution(vector<int> const &input, int k)
{
	intSet leastNums;
	int len = input.size();
	if(len==0 || k<1 || k>len)
		return leastNums;
	for(int i=0; i!=len; ++i)
	{
		if(leastNums.size() < k) //multiset容器数目少于k，可以直接插入 
			leastNums.insert(input[i]);
		else{//否则将当前数与容器首元素比较 
			setIterator setGreatest = leastNums.begin();
			if(input[i] < *setGreatest)
				{
					leastNums.erase(setGreatest);
					leastNums.insert(input[i]);
				} 	
		}
	}
	return leastNums;
}

int main()
{
	vector<int> input{4,5,5,5,5,7,3};
//	vector<int> result;
	intSet result;
	result = GetLeastNumbers_Solution(input, 3);
	for(auto num: result)
		cout<<num<<" ";
	cout<<endl;
	return 0;
}
