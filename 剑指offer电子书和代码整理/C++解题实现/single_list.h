//单链表头文件 
#ifndef SINGLE_LIST_H
#define SINGLE_LIST_H
#include <iostream>
using std::cout;
using T=int;

struct ListNode{ //链表结点定义 
	T nValue;
	ListNode *pNext; 
}; 

void AddToTail(ListNode **pHead, T value)
{//向链表*pHead添加值为value的节点，使用指向指针的指针是因为函数体可能会对链表的
//头指针进行修改，如果不设为指向指针的指针，出了函数pHead就会变成空指针 
	//生成一个结点 
	ListNode *pNew = new ListNode;
	pNew->nValue = value;
	pNew->pNext = NULL;
	if(*pHead == NULL) //链表为空
		*pHead = pNew;
	else //遍历到链表尾部 
		{
			ListNode *pCur = *pHead;
			while(pCur->pNext != NULL)
				pCur = pCur->pNext;
			pCur->pNext = pNew; //在尾部插入新结点 
		}	 
}

void RemoveNode(ListNode **pHead, T value)
{//删除值为value的结点
	if(pHead == NULL || *pHead == NULL) 
		return;
	ListNode *pToBeDeleted = NULL;
	//删除的结点为头结点
	if((*pHead)->nValue == value)
		*pHead = (*pHead)->pNext;
		
	//删除的结点为其它结点
	else
	{
		ListNode *pNode = *pHead; //pNode指向待删结点的前一个结点 
//		pToBeDeleted = pNode->pNext;
		while(pNode->pNext != NULL && pNode->pNext->nValue != value)
			{//pNode未到达尾结点且未找到待删除的结点 
				pNode = pNode->pNext;
//				pToBeDeleted = pToBeDeleted->pNext;
			}
		if(pNode->pNext != NULL && pNode->pNext->nValue == value)
			{
				pToBeDeleted = pNode->pNext;
				pNode->pNext = pNode->pNext->pNext;
			}
		if(pToBeDeleted != NULL)
			{
				delete pToBeDeleted;
				pToBeDeleted = NULL;
			}
	}
}

ListNode *findFirstNodeByValue(ListNode *pHead, T value)
{
	ListNode *pCur = pHead;
	while(pCur != NULL)
	{
		if(pCur->nValue == value)
			return pCur;
		else
			pCur = pCur->pNext;
	}
	return pCur;
}

void PrintList(ListNode *pHead)
{
	if(pHead==NULL)
		return;
	ListNode *pCur = pHead;
	while(pCur != NULL)
	{
		cout<<pCur->nValue<<"->";
		pCur = pCur->pNext;
	}
	cout<<"End"<<std::endl;
}

//int main()
//{
//	ListNode *List=NULL;
//	AddToTail(&List, 1);
//	AddToTail(&List, 2);
//	RemoveNode(&List, 2); 
//	PrintList(List);
//}

# endif
