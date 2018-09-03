// ������5����β��ͷ��ӡ����
#include <iostream>
#include <stack>
using std::cout;
using T=int;

struct ListNode{ //�����㶨�� 
	T nValue;
	ListNode *pNext; 
}; 

void AddToTail(ListNode **pHead, T value)
{//������*pHead���ֵΪvalue�Ľڵ㣬ʹ��ָ��ָ���ָ�루��ʾ��ָ����ָ��ͷ���ָ�룬�����ͷ���ָ��ĵ�ַ������Ϊ 
// ��������ܻ�������ͷָ������޸ģ��������Ϊָ��ָ���ָ�룬�޷��Ѷ�ͷָ����޸Ĵ������� 
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

void PrintInvListByStack(ListNode *pHead)
{//����ջ������β��ͷ��ӡ���� 
	std::stack<ListNode*> nodes;
	if(pHead == NULL)
		return;
	ListNode *pCur = pHead;
	while(pCur!=NULL) 
		{
			nodes.push(pCur);
			pCur = pCur->pNext;
		}
	while(!nodes.empty())
	{
		pCur = nodes.top();
		cout<<pCur->nValue<<"<-";
		nodes.pop();
	}
}

void PrintInvListByRecursion(ListNode *pHead)
{
	if(pHead == NULL)
		return;
	ListNode *pCur = pHead;
	PrintInvListByRecursion(pHead->pNext);
	cout<<pCur->nValue<<"<-";
}

int main()
{
	ListNode *List=NULL;
	AddToTail(&List, 1);
	AddToTail(&List, 2);
//	RemoveNode(&List, 2); 
	AddToTail(&List, 3);
	PrintList(List);
	PrintInvListByRecursion(List);
	cout<<"head"<<std::endl;
}
