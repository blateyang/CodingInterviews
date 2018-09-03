#include <iostream>
#include <list>
#include <ctime> 
using namespace std;

//-------------��������------------------
/*
1.���ܣ�m<n,m>=n
2.�������룺n<1��m<1
3.���ܲ��ԣ�n��m���ܴ���n=4000,m=1000 
*/ 
int LastRemaining(int n, int m)
{//ʱ�临�ƶ� O(nm)���ռ临�ƶ�O(n) 
//˼·1��ʹ��ѭ������ʵ�֣�ע��list��˫��������ѭ��������Ҫ�ڵ�����ָ��endʱ�ֶ�����ָ��begin)
	if(n<1 || m<1)
		return -1;	//�Ƿ����뷵��-1
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
//			if(itNext != circle.end()) //��������ж�count����itNextָ��beginǰ�ȴﵽѭ���˳����� 
//				++count;
//		}
//		it = circle.erase(itNext); //erase()����ָ����һ��Ԫ�صĵ����� 
	//��ָoffer˼·����ͨ���������ҵ���ɾ���Ľ�㣬����++��ȡ����һ����㣬����--ʹ������ָ�ش�ɾ���
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
 
//��ָoffer�ṩ�Ĵ��½ⷨ��ͨ����ɾ����һ����k=(m-1)%n��ʣ�µ����Ĺ��ɷ������н�ģ��
//						������ƹ�ϵʽf(n,m)=[f(n-1,m)+k+1]%n=[f(n-1,m)+m]%n,��ʼ����f(1,m)=0 
int LastRemaining2(int n, int m)
{//ʱ�临�Ӷ�O(n)���ռ临�Ӷ�O(1) 
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
