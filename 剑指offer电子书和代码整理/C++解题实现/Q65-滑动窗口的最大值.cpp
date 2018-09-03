#include <iostream>
#include <vector> 
#include <deque>
using namespace std;
 
//-------------��������-------------
/*
1.���ܣ�{2,3,4,2,6,2,5,1}�����ڳ�kΪ3
2.���棺���鳤��С�ڻ������Ȼ򻬴�����Ϊ0 
*/ 
vector<int> maxInWindows(const vector<int> &num, unsigned size) 
{//˼·��1.�����������Ӷ�ΪO(nk)) 2.���Q21-��min������ջ��Q7-��ջʵ�ֶ��е�˼·��O(1)ʱ�����ҵ����������е����ֵ
//		3.����STL��˫�˶���deque�洢�����±�ʵ�֣���ʼʱ�Ƚ������У�Ȼ��ÿ�¶�ȡһ������Ԫ��
//		  �Ӷ���β����ǰ��������������е��±�����ӦԪ�رȽϣ������������ǣ������ǴӶ�βɾ��
//		  ��Ҫ�ж���Ԫ����Ӻ�ӳ��Ƿ�ᳬ����������������Ҫ����ͷԪ��ɾ��
	vector<int> result;
	unsigned len = num.size();
	if(len>=size && size>=1)
	{
		deque<int> index;
		unsigned i;
		for(i=0; i<size; ++i)
		{//�ڻ�δ�γ���������ʱ���Ƚ������� 
			if(!index.empty() && num[i]>=num[index.back()]) //ȡ>=�ܹ�ʹ�������ֵ��ʱ���� 
				index.pop_back();
			index.push_back(i);
		}
		for(i=size; i<len; ++i)
		{
			result.push_back(num[index.front()]); //����ͷ��Ӧ��Ԫ�أ���ǰ�������Ԫ�أ�����
			while(!index.empty() && num[i]>=num[index.back()]) 
				index.pop_back(); //����ǰԪ�شӶ�β��ǰ��������н������Ԫ�رȽ� 
			if(!index.empty() && i-index.front()>=size)
				index.pop_front(); //��ǰԪ���±����ͷ��������ڵ��ڻ������ȣ��轫��ͷɾ�� 
			index.push_back(i); 
		 } 
		 result.push_back(num[index.front()]); //���鳤�ȵ��ڻ������ȵ���� 
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
