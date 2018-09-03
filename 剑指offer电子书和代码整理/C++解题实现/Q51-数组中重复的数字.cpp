#include <iostream>
using namespace std;

//-----------测试用例---------------
/*
1.功能：仅有一个重复的数；有多个重复的数；没有重复的数
2.负面：数组指针为空;数组长度<=1; 数组中的数字超出有效范围[0, len-1]
*/ 
bool duplicate(int numbers[], int length, int *duplication) 
{//思路1：先排序再顺序查找O(nlogn)；思路2：利用哈希表O(n) 采用思路2 
//	if(numbers==NULL || length<=1)
//		return false;
//	bool flag = true;	//为了能够将动态申请的哈希表释放，需要设置标志位 
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

//思路3：利用无重复数字的数组元素值与下标相等的特点边判断边排序，即遍历数组判断当前
//		元素值m是否与其下标i相等，若相等往后判断，若不等再判断m是否与下标为m的元素
//		相等（若相等，则证明相同的值m同时出现在了下标i和下标m处，即重复；若不等，则
//		将下标i和下标m的元素交换归位，继续判断下标i处的元素）
	if(numbers==NULL || length<=1)
		return false; 
	//判断是否有超出范围的数
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
