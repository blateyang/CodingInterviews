#include <iostream>
#include <vector>
#include <stack>
using namespace std;

//=============��������-------------------
/*
1. ���ܲ��ԣ�������������麬�ж�����ֻ�ֻ��һ�����֣��ڶ��������ǻ��߲��ǵ�һ������
			��ѹ�����ж�Ӧ��ջ�������� 
2. ������ԣ� ��������Ϊ�� 
*/ 
bool IsPopOrder(vector<int> const &pushV,vector<int> const &popV)
{//˼·����popV�е�ÿ��Ԫ��vi���粻��ջ������pushV�е�Ԫ��������ջֱ����vi��ջ��
//		��vi��ջ����������popV�е��¸�Ԫ�أ���popV��Ԫ�ط��������true,
//		��pushV�е�Ԫ��ȫ����ջ��δ�ҵ�vi�������false 
	unsigned vLen = popV.size();
	if(vLen==0 || pushV.size()!=vLen)
		return false;
	stack<int> s;
	s.push(pushV[0]); //����ջ���е��׸�Ԫ����ջ 
	int popIdx = 0, pushIdx = 1;
	while(popIdx < vLen) //δ������popV���� 
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
