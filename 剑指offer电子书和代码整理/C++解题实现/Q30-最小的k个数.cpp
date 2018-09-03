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
	Swap(A[pre], A[pre+rand()%(post-pre+1)]); //���ѡȡ��ŦԪ������Ԫ�ؽ��� 
	int pivot = A[pre]; //����ŦԪ��������
	int p=pre, q=post;
	while(p < q)
	{//������ӷ�,���Բ�����д�������� 
		while(p < q)
			if(A[q] > pivot) //ȥ��=�ſ����Ż����д����ظ�Ԫ�ص���������ڽ�����������չ 
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
 
//-------------��������---------------
/*
1.���ܣ����������ظ����֣�û���ظ����� 
2.�߽磺k=1���������鳤��
3.���棺k��������Χ������Ϊ�� 
*/ 
/*
vector<int> GetLeastNumbers_Solution(vector<int> input, int k) 
{
//�ⷨ1��������������㷨,ʱ�临�Ӷ�ΪO(n)�����ԭ������н����Ķ�
//		������partition��������ÿ�λ��ֽ������жϷ��ص�index�Ƿ���k-1��ȣ�
//		������index��Ϊ��k���������index>k-1,���k�������index��ߣ�
//		����partition���ҽ磻��index<k-1�����k�������index�ұߣ�����partition�����
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
//�ⷨ2������STL�Ĺ�������multiset�����ں����ʵ�֣�ȥ�洢��ǰ�ѱ�����������С��k����
//		ʱ�临�Ӷ�Ϊn*log(k)�������ԭ������иĶ����ʺϴ��������� 
using intSet = multiset<int, greater<int>>; //greater<int> ָ��multiset���������򣬵�һ��Ԫ�������Ԫ�� 
using setIterator = multiset<int, greater<int>>::iterator;
intSet GetLeastNumbers_Solution(vector<int> const &input, int k)
{
	intSet leastNums;
	int len = input.size();
	if(len==0 || k<1 || k>len)
		return leastNums;
	for(int i=0; i!=len; ++i)
	{
		if(leastNums.size() < k) //multiset������Ŀ����k������ֱ�Ӳ��� 
			leastNums.insert(input[i]);
		else{//���򽫵�ǰ����������Ԫ�رȽ� 
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
