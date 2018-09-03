#include <iostream>
#include "single_list.h"
using namespace std;

//---------��������----------------
/*
1. ���ܲ��ԣ�����ֻ��1����㣻�����ж�����
2. ����������ԣ�����Ϊ�� 
*/ 
/*
ListNode *reverseList(ListNode *pHead) 
{//˼·��������ָ��p,p_pre,p_post��ɾֲ�������ת 
	if(pHead == NULL) return NULL;
	if(pHead->pNext == NULL) return pHead;
	ListNode *p_pre = pHead, *p = pHead->pNext, *p_post = p->pNext;
	p_pre->pNext = NULL; //��ԭͷ�����Ϊ�������β��� 
	while(p_post != NULL)
	{//ִ������ֲ������������ķ�ת�����θ���ָ�� 
		p->pNext = p_pre;
		p_pre = p;
		p = p_post;	
		p_post = p_post->pNext;
	}
	//�˳�ѭ����p��ָ����ԭ�����β��� 
	p->pNext = p_pre; //���β����ָ��ת
	return p; 
}

*/ 
// ��ָoffer˼·�����Ƶ�ÿ��ֻ���µ�ǰ������ǰ�Ľ�� 
ListNode *reverseList(ListNode *pHead) 
{
	ListNode *pReverseHead = NULL;
	ListNode *p = pHead;
	ListNode *p_pre = NULL;
	while(p != NULL)
	{
		ListNode *pNext = p->pNext;
		if(pNext == NULL) //���������һ��������� 
			pReverseHead = p; 
		p->pNext = p_pre;
		p_pre = p;
		p = pNext;
	}
	return pReverseHead; //��ͷ���Ϊ�յ���� 
}

int main()
{
	ListNode *List=NULL;
	AddToTail(&List, 1);
	AddToTail(&List, 2);
	AddToTail(&List, 3);
	PrintList(List);
	ListNode *newList = reverseList(List);
	PrintList(newList);
	return 0;
 } 
