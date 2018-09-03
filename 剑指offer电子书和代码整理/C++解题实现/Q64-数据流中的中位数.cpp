#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
/*
public:
//自己想到的思路：用vector作为数据容器，每次获取中位数时，对当前向量进行排序，复杂度为O(nlogn) 
    void Insert(int num)
    {
        stream.push_back(num);
    }

    double GetMedian()
    { 
    	int len = stream.size();
    	if(len == 0) return 0.0; //当未插入即试图获取中位数时，规定返回0 
    	sort(stream.begin(), stream.end());
    	double result;
    	if(len%2 == 1)
    		result = stream[len/2];
    	else
    		result = double(stream[len/2-1] + stream[len/2])/2;
    	return result;
    }
private:
	vector<int> stream; */
	
//剑指offer思路：分析了多种方法，有未排序的数组(O(1),O(n))、排序的数组(O(n),O(1))
//				排序的链表(O(n),O(1))、二叉搜索树、平衡二叉树和最大最小堆（最后
//				两种方法的效率最高，插入为O(logn)，获取中位数为O(1)),下面是最大最小堆的实现
private:
	vector<int> max;	//最大堆，用于存整个数据流中的前半段值较小的元素 
	vector<int> min; 	//最小堆，用于存整个数据流中的后半段值较大的元素
public:
	void Insert(int num)
	{//为保证两个堆的规模相当，当数据量为偶数时，应将新元素插入到最小堆中，但当该元素 
	//比最大堆中的堆顶元素还要小时，应先将其插入最大堆中，再取最大堆堆顶元素插入到最小堆中；当数据量为奇数时，正好相反 
		if((max.size()+min.size())%2 == 0) //数据量为偶数 
		{
			if(max.size()>0 && num<max[0]) 
			{//插入元素比最大堆堆顶元素小 
				max.push_back(num); //先加到容器中，再加到堆中，出堆时则相反 
				//push_heap()为STL中向堆添加元素的函数,比较函数less()指定堆类型为最大堆，当使用比较函数将堆的最高值和
				//堆中其它值比较时，函数会返回false,详见http://www.cplusplus.com/reference/algorithm/make_heap/ 
				push_heap(max.begin(), max.end(), less<int>()); 
				num = max[0];
				pop_heap(max.begin(), max.end(), less<int>());
				max.pop_back();
			}
			min.push_back(num); //将新元素插入最小堆 
			push_heap(min.begin(), min.end(), greater<int>());
		}
		else
		{
			if(min.size()>0 && num>min[0])
			{
				min.push_back(num);
				push_heap(min.begin(), min.end(), greater<int>());
				num = min[0];
				pop_heap(min.begin(), min.end(), greater<int>());
				min.pop_back();
			}
			max.push_back(num);
			push_heap(max.begin(), max.end(), less<int>());
		 } 
	}
	double GetMedian()
	{
		int size = max.size() + min.size();
		if(size == 0)
			return 0.0; //无效操作返回0
		if(size%2 == 1) //数据量为奇数，则返回min堆顶元素
			return double(min[0]);
		else
			return double(min[0]+max[0])/2; 
	 } 
};

int main()
{
	Solution s;
	s.Insert(1);
	s.Insert(2);
	cout<<s.GetMedian()<<endl;
	return 0;
}
