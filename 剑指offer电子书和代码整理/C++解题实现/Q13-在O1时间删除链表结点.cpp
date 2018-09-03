#include <iostream>
#include "single_list.h"
using namespace std;

void DeleteNode(ListNode **pListHead, ListNode *pToBeDeleted)
{// ˼·������ɾ�����i����һ�����j�������򸲸�i���������ٽ����jɾ�����ɵ�Ч��ɾ��ԭ��Ҫɾ���Ľ�� 
// ����������1.�������ս�� 2.��ɾ���Ľ�㲻��β��� 3.��ɾ���Ľ����β���������ֻ��һ����� 
//			 4.��ɾ���Ľ��Ϊβ������������������Ͻ�� 
	if(*pListHead == NULL || pToBeDeleted == NULL)
		return;
	else if(pToBeDeleted->pNext != NULL) 
	{
		//�ô�ɾ����һ�����������򸲸Ǵ�ɾ���������� 
		ListNode *pNext = pToBeDeleted->pNext;
		pToBeDeleted->nValue = pNext->nValue;
		pToBeDeleted->pNext = pNext->pNext;
		delete pNext;
		pNext = NULL; //�ͷ�ָ����ָ�ڴ����ý�ָ���ÿ� 
	}
	else if(*pListHead == pToBeDeleted)
		{
			delete pToBeDeleted;
			pToBeDeleted = NULL;
			*pListHead = NULL;
			return;
		}
	else
	{// ���4 
		ListNode *pCur = *pListHead;
		while(pCur->pNext->pNext != NULL)
			pCur = pCur->pNext;
		delete pToBeDeleted;
		pToBeDeleted = NULL;
		pCur->pNext = NULL;
	}
	
}
int main()
{
	ListNode *List=NULL;
	AddToTail(&List, 1);
	AddToTail(&List, 2);
//	RemoveNode(&List, 2); 
	AddToTail(&List, 3);
	ListNode *pFind;
	pFind = findFirstNodeByValue(List, 3);
	PrintList(List);
//	cout<<pFind->nValue<<" "<<pFind->pNext<<endl; 
	//����DeleteNode���� 
	DeleteNode(&List, pFind);
	PrintList(List);
}
