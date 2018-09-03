//������ͷ�ļ� 
#ifndef SINGLE_LIST_H
#define SINGLE_LIST_H
#include <iostream>
using std::cout;
using T=int;

struct ListNode{ //�����㶨�� 
	T nValue;
	ListNode *pNext; 
}; 

void AddToTail(ListNode **pHead, T value)
{//������*pHead���ֵΪvalue�Ľڵ㣬ʹ��ָ��ָ���ָ������Ϊ��������ܻ�������
//ͷָ������޸ģ��������Ϊָ��ָ���ָ�룬���˺���pHead�ͻ��ɿ�ָ�� 
	//����һ����� 
	ListNode *pNew = new ListNode;
	pNew->nValue = value;
	pNew->pNext = NULL;
	if(*pHead == NULL) //����Ϊ��
		*pHead = pNew;
	else //����������β�� 
		{
			ListNode *pCur = *pHead;
			while(pCur->pNext != NULL)
				pCur = pCur->pNext;
			pCur->pNext = pNew; //��β�������½�� 
		}	 
}

void RemoveNode(ListNode **pHead, T value)
{//ɾ��ֵΪvalue�Ľ��
	if(pHead == NULL || *pHead == NULL) 
		return;
	ListNode *pToBeDeleted = NULL;
	//ɾ���Ľ��Ϊͷ���
	if((*pHead)->nValue == value)
		*pHead = (*pHead)->pNext;
		
	//ɾ���Ľ��Ϊ�������
	else
	{
		ListNode *pNode = *pHead; //pNodeָ���ɾ����ǰһ����� 
//		pToBeDeleted = pNode->pNext;
		while(pNode->pNext != NULL && pNode->pNext->nValue != value)
			{//pNodeδ����β�����δ�ҵ���ɾ���Ľ�� 
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
