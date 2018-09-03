#include <iostream>
using namespace std;

//-----------��������---------------
/*
1.���ܣ�����һ���ظ��������ж���ظ�������û���ظ�����
2.���棺����ָ��Ϊ��;���鳤��<=1; �����е����ֳ�����Ч��Χ[0, len-1]
*/ 
bool duplicate(int numbers[], int length, int *duplication) 
{//˼·1����������˳�����O(nlogn)��˼·2�����ù�ϣ��O(n) ����˼·2 
//	if(numbers==NULL || length<=1)
//		return false;
//	bool flag = true;	//Ϊ���ܹ�����̬����Ĺ�ϣ���ͷţ���Ҫ���ñ�־λ 
//	int *hashTable = new int[length];
//	int i;
//	for(i=0; i<length; ++i)
//		hashTable[i] = 0;
//	for(i=0; i<length; ++i)
//	{
//		if(numbers[i]<0 || numbers[i]>=length)
//		{
//			flag = false;
//			break;
//		}
//		++hashTable[numbers[i]];
//	}
//	if(flag)
//	{
//		for(i=0; i<length; ++i)
//			if(hashTable[i] > 1)
//			{
//				*duplication = numbers[i];
//				break;
//			}
//		flag = false;
//	}
//	delete []hashTable;
//	return flag;

//˼·3���������ظ����ֵ�����Ԫ��ֵ���±���ȵ��ص���жϱ����򣬼����������жϵ�ǰ
//		Ԫ��ֵm�Ƿ������±�i��ȣ�����������жϣ����������ж�m�Ƿ����±�Ϊm��Ԫ��
//		��ȣ�����ȣ���֤����ͬ��ֵmͬʱ���������±�i���±�m�������ظ��������ȣ���
//		���±�i���±�m��Ԫ�ؽ�����λ�������ж��±�i����Ԫ�أ�
	if(numbers==NULL || length<=1)
		return false; 
	//�ж��Ƿ��г�����Χ����
	for(int i=0; i<length; ++i)
		if(numbers[i]<0 || numbers[i]>=length)
			return false;
	for(int i=0; i<length; ++i)
	{
		if(numbers[i] != i)
			if(numbers[i] == numbers[numbers[i]])
			{
				*duplication = numbers[i];
				return true;
			}
			else
			{
				int tmp = numbers[i];
				numbers[i] = numbers[numbers[i]];
				numbers[tmp] = tmp;
				--i;
			}
	}
	return false;
}

int main()
{
	int nums[] = {1, 2, 2};
	int dup;
	if(duplicate(nums, 3, &dup))
		cout<<dup<<endl;
	return 0;
}
