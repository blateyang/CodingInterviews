#include <iostream>
#include <vector> 
#include <deque>
using namespace std;
 
//-------------测试用例-------------
/*
1.功能：{2,3,4,2,6,2,5,1}，窗口长k为3
2.负面：数组长度小于滑窗长度或滑窗长度为0 
*/ 
vector<int> maxInWindows(const vector<int> &num, unsigned size) 
{//思路：1.暴力法（复杂度为O(nk)) 2.借鉴Q21-含min函数的栈和Q7-用栈实现队列的思路在O(1)时间内找到滑动窗队列的最大值
//		3.借助STL的双端队列deque存储数组下标实现：初始时先建立队列，然后每新读取一个数组元素
//		  从队列尾部往前将其依次与队列中的下标所对应元素比较，若不低于它们，则将它们从队尾删除
//		  还要判断新元素入队后队长是否会超过滑窗长，若会则要将队头元素删除
	vector<int> result;
	unsigned len = num.size();
	if(len>=size && size>=1)
	{
		deque<int> index;
		unsigned i;
		for(i=0; i<size; ++i)
		{//在还未形成完整滑窗时，先建立队列 
			if(!index.empty() && num[i]>=num[index.back()]) //取>=能够使滑窗最大值及时更新 
				index.pop_back();
			index.push_back(i);
		}
		for(i=size; i<len; ++i)
		{
			result.push_back(num[index.front()]); //将队头对应的元素（当前滑窗最大元素）保存
			while(!index.empty() && num[i]>=num[index.back()]) 
				index.pop_back(); //将当前元素从队尾往前依次与队列结点代表的元素比较 
			if(!index.empty() && i-index.front()>=size)
				index.pop_front(); //当前元素下标与队头结点相差大于等于滑窗长度，需将队头删除 
			index.push_back(i); 
		 } 
		 result.push_back(num[index.front()]); //数组长度等于滑窗长度的情况 
	 } 
	return result; 
}

int main()
{
	vector<int> num{2,3,4,2,6,2,5,1};
	vector<int> result = maxInWindows(num, 3);
	for(auto item: result)
		cout<<item<<" ";
	cout<<endl;
	return 0;
}
