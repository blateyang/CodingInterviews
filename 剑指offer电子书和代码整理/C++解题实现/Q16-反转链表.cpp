#include <iostream>
#include "single_list.h"
using namespace std;

//---------测试用例----------------
/*
1. 功能测试：链表只有1个结点；链表有多个结点
2. 特殊输入测试：链表为空 
*/ 
/*
ListNode *reverseList(ListNode *pHead) 
{//思路：用三个指针p,p_pre,p_post完成局部的链表反转 
	if(pHead == NULL) return NULL;
	if(pHead->pNext == NULL) return pHead;
	ListNode *p_pre = pHead, *p = pHead->pNext, *p_post = p->pNext;
	p_pre->pNext = NULL; //将原头结点作为新链表的尾结点 
	while(p_post != NULL)
	{//执行链表局部相邻三个结点的反转并依次更新指针 
		p->pNext = p_pre;
		p_pre = p;
		p = p_post;	
		p_post = p_post->pNext;
	}
	//退出循环后p已指向了原链表的尾结点 
	p->pNext = p_pre; //完成尾结点的指向反转
	return p; 
}

*/ 
// 剑指offer思路：类似但每次只更新当前结点和其前的结点 
ListNode *reverseList(ListNode *pHead) 
{
	ListNode *pReverseHead = NULL;
	ListNode *p = pHead;
	ListNode *p_pre = NULL;
	while(p != NULL)
	{
		ListNode *pNext = p->pNext;
		if(pNext == NULL) //含链表仅有一个结点的情况 
			pReverseHead = p; 
		p->pNext = p_pre;
		p_pre = p;
		p = pNext;
	}
	return pReverseHead; //含头结点为空的情况 
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
