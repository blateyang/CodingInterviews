#include <iostream>
#include <list>
#include <ctime> 
using namespace std;

//-------------测试用例------------------
/*
1.功能：m<n,m>=n
2.特殊输入：n<1或m<1
3.性能测试：n和m都很大，如n=4000,m=1000 
*/ 
int LastRemaining(int n, int m)
{//时间复制度 O(nm)，空间复制度O(n) 
//思路1：使用循环链表实现（注意list是双向链表，非循环链表，需要在迭代器指向end时手动将其指向begin)
	if(n<1 || m<1)
		return -1;	//非法输入返回-1
	list<int> circle;
	for(int i=0; i<n; ++i)
		circle.push_back(i);
	list<int>::iterator it=circle.begin(), itNext;
	while(circle.size() > 1)
	{
//		itNext = (it!=circle.end())? it:circle.begin();
//		int count = 1;
//		while(count < m)
//		{
//			if(itNext != circle.end()) 
//				++itNext;
//			else
//				itNext = circle.begin();  
//			if(itNext != circle.end()) //不加这句判断count会在itNext指向begin前先达到循环退出条件 
//				++count;
//		}
//		it = circle.erase(itNext); //erase()返回指向下一个元素的迭代器 
	//剑指offer思路：先通过迭代器找到待删除的结点，再用++获取其下一个结点，再用--使迭代器指回待删结点
		for(int i=1; i<m; ++i)
			{
				++it;
				if(it == circle.end())
					it = circle.begin();
			}
		list<int>::iterator Next = ++it;
		if(Next == circle.end())
			Next = circle.begin();
		--it;
		circle.erase(it);
		it = Next;
	 } 
	return *circle.begin();
 } 
 
//剑指offer提供的创新解法：通过对删除第一个数k=(m-1)%n后剩下的数的规律分析进行建模，
//						构造递推关系式f(n,m)=[f(n-1,m)+k+1]%n=[f(n-1,m)+m]%n,初始条件f(1,m)=0 
int LastRemaining2(int n, int m)
{//时间复杂度O(n)，空间复杂度O(1) 
	if(n<1 || m<1)
		return -1;
	int last = 0;
	for(int i=2; i<=n; ++i)
		last = (last+m)%i; 
	return last;
 } 
 
int main()
{
	int m;
	clock_t t;
	while(cin>>m)
	{
		t = clock();
		cout<<LastRemaining(6000, m)<<endl;
		cout<<"time1:"<<double(clock()-t)/CLOCKS_PER_SEC<<endl;
		t = clock();
		cout<<LastRemaining2(60000, m)<<endl;
		cout<<"time2:"<<double(clock()-t)/CLOCKS_PER_SEC<<endl;
	}
	return 0; 
}
