#include <iostream>
#include <vector> 
using namespace std;

//----------------��������--------------------
/*
1.���ܣ�ǰ��������(1,2,3,4,5,6,8,9)����1500������
2.���棺���벻�Ϸ� 
*/ 
bool isUglyNumber(unsigned num)
{
	if(num == 0)
		return false;
	while(num%2==0)
		num /= 2;
	while(num%3==0)
		num /= 3;
	while(num%5==0)
		num /= 5;
	if(num == 1)
		return true;
	return false;
}

int minOf3(int a, int b, int c)
{
	int min = (a<b)? a:b;
	return (min<c)? min:c;
}

int GetUglyNumber_Solution(int index) 
{
    if(index < 1)
    	return 0;
/*  //˼·1����дһ���ж��Ƿ�Ϊ�����ĺ�����Ȼ�������Ȼ���ҵ���index������ 
	int count = 0, result=0;
    for(unsigned i=1; count<index; ++i)
    {
    	if(isUglyNumber(i))
    		{
    			++count;
    			result = i;
			}
	}
	return result;*/
	//˼·2�����ÿռ任ʱ��Ķ�̬�滮������������ǰ������õĳ���ȥ�������ĳ���
	vector<int> uglyNums = {1};
	int idx2=0, idx3=0, idx5=0;
	int nextIdx = 1, count = 1;
	int curUglyNum;
	while(count<=index)
	{
		curUglyNum = minOf3(2*uglyNums[idx2], 3*uglyNums[idx3], 5*uglyNums[idx5]);
		uglyNums.push_back(curUglyNum);
		while(2*uglyNums[idx2] <= curUglyNum)
			++idx2;
		while(3*uglyNums[idx3] <= curUglyNum)
			++idx3;
		while(5*uglyNums[idx5] <= curUglyNum)
			++idx5;
		++count;
	}
	return uglyNums[index-1];
}

int main()
{
	int index;
	while(cin>>index)
		cout<<GetUglyNumber_Solution(index)<<endl;
	return 0;
}
