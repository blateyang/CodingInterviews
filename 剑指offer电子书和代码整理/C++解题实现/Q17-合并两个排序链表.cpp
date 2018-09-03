#include <iostream>
#include "single_list.h"
using namespace std;

//--------��������----------------
/*
1. ���ܲ��ԣ��������������в�����ͬԪ�أ�������ͬԪ�� ��һ�������е�ֵ��С����һ���� 
2. ����������ԣ�������������һ��Ϊ�������������н���һ����� 
*/ 
//----------��ָoffer˼·-----------
//�����������ϲ��Ĺ��̣����ǽ���ǰ������ͷ����еĽ�С�߽���ϲ���������У�
//������ʣ�µĲ�����Ȼ���ֵ��������õݹ���������� 
ListNode* mergeRecur(ListNode *pHead1, ListNode *pHead2)
{
	if(pHead1 == NULL) return pHead2;
	if(pHead2 == NULL) return pHead1;
	ListNode *pNewHead;
	if(pHead1->nValue <= pHead2->nValue)
	{
		pNewHead = pHead1;
		pNewHead->pNext = mergeRecur(pHead1->pNext, pHead2);
	}
	else
	{
		pNewHead = pHead2;
		pNewHead->pNext = mergeRecur(pHead1, pHead2->pNext);
	}
	return pNewHead;
}
ListNode* merge(ListNode *pHead1, ListNode *pHead2)
{//�Լ���˼·��ʹ������ָ�룬���������ֱ�ָ����������������ָ��ʼ��ָ���С����ָ���ǰһ����� 
	if(pHead1 == NULL) return pHead2;
	if(pHead2 == NULL) return pHead1;
	ListNode *pNewHead, *p1 , *p2 ;
	//pNewHeadָ��������ͷ����ͷ��С��������p1ָ������һ����㣬p2ָ��ͷ���ֵ�ϴ������ 
	if(pHead1->nValue <= pHead2->nValue)
	{
		pNewHead = pHead1;
		p2 = pHead2;
	}
	else
	{
		pNewHead = pHead2;
		p2 = pHead1;
	}
	p1 = pNewHead->pNext;  
	ListNode *p_pre = pNewHead; 
	while(p1 != NULL && p2 != NULL)
	{
		if(p1->nValue <= p2->nValue)
		{
			p1 = p1->pNext;
			p_pre = p_pre->pNext;
		}
		else
		{ //����p1��p2ָ�룬ʹp1����ָ���С������ 
			p_pre->pNext = p2;
			p2 = p1;
			p1 = p_pre->pNext;
		}
	 } 
	if(p1 == NULL)
		p_pre->pNext = p2;
	else
		p_pre->pNext = p1;
	return pNewHead; 
 } 

int main()
{
	ListNode *List1 = NULL;
	AddToTail(&List1, 1);
	AddToTail(&List1, 2);
	AddToTail(&List1, 3);
	ListNode *List2 = NULL;
	AddToTail(&List2, 4);
	AddToTail(&List2, 5);
	AddToTail(&List2, 6);
	ListNode *pNewHead = mergeRecur(List1, List2);
	PrintList(pNewHead);
	return 0;
}
