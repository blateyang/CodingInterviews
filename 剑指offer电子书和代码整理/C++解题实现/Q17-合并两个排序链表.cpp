#include <iostream>
#include "single_list.h"
using namespace std;

//--------测试用例----------------
/*
1. 功能测试：两个递增链表中不含相同元素；含有相同元素 ；一个链表中的值均小于另一链表 
2. 特殊输入测试：两链表至少有一个为空链表，两链表中仅有一个结点 
*/ 
//----------剑指offer思路-----------
//分析清楚链表合并的过程，总是将当前两链表头结点中的较小者接入合并后的链表中，
//两链表剩下的部分依然保持递增有序。用递归来做更简洁 
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
{//自己的思路：使用三个指针，其中两个分别指向两个链表，第三个指针始终指向较小链表指针的前一个结点 
	if(pHead1 == NULL) return pHead2;
	if(pHead2 == NULL) return pHead1;
	ListNode *pNewHead, *p1 , *p2 ;
	//pNewHead指向新链表头（开头较小的链表），p1指向其下一个结点，p2指向头结点值较大的链表 
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
		{ //交换p1和p2指针，使p1重新指向较小的链表 
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
