#include <iostream>
#include <vector>
#include <stack>
using namespace std;

//=============测试用例-------------------
/*
1. 功能测试：输入的两个数组含有多个数字或只有一个数字；第二个数组是或者不是第一个数组
			的压入序列对应的栈弹出序列 
2. 负面测试： 输入序列为空 
*/ 
bool IsPopOrder(vector<int> const &pushV,vector<int> const &popV)
{//思路：对popV中的每个元素vi，如不在栈顶，则将pushV中的元素依次入栈直至将vi入栈；
//		将vi从栈顶弹出访问popV中的下个元素；如popV中元素访问完输出true,
//		如pushV中的元素全部入栈仍未找到vi，则输出false 
	unsigned vLen = popV.size();
	if(vLen==0 || pushV.size()!=vLen)
		return false;
	stack<int> s;
	s.push(pushV[0]); //将入栈序列的首个元素入栈 
	int popIdx = 0, pushIdx = 1;
	while(popIdx < vLen) //未访问完popV序列 
	{
		while(pushIdx<vLen && popV[popIdx]!=s.top())
			{
				s.push(pushV[pushIdx]);
				++pushIdx;
			}
		if(pushIdx==vLen && popV[popIdx]!=s.top())
			return false;
		s.pop();
		++popIdx;
	}
	return true;
}

int main()
{
	vector<int> pushV{1,2,3,4,5};
	vector<int> popV{4,3,5,1,2};
	if(IsPopOrder(pushV, popV))
		cout<<"is pop order"<<endl;
	return 0;
}
