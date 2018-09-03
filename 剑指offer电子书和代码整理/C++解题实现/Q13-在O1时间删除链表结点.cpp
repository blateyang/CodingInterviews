#include <iostream>
#include "single_list.h"
using namespace std;

void DeleteNode(ListNode **pListHead, ListNode *pToBeDeleted)
{// 思路：将待删除结点i的下一个结点j的数据域覆盖i的数据域，再将结点j删除即可等效地删除原来要删除的结点 
// 测试用例：1.空链表或空结点 2.待删除的结点不是尾结点 3.待删除的结点是尾结点且链表只有一个结点 
//			 4.待删除的结点为尾结点且链表有两个以上结点 
	if(*pListHead == NULL || pToBeDeleted == NULL)
		return;
	else if(pToBeDeleted->pNext != NULL) 
	{
		//用待删结点后一个结点的数据域覆盖待删结点的数据域 
		ListNode *pNext = pToBeDeleted->pNext;
		pToBeDeleted->nValue = pNext->nValue;
		pToBeDeleted->pNext = pNext->pNext;
		delete pNext;
		pNext = NULL; //释放指针所指内存后最好将指针置空 
	}
	else if(*pListHead == pToBeDeleted)
		{
			delete pToBeDeleted;
			pToBeDeleted = NULL;
			*pListHead = NULL;
			return;
		}
	else
	{// 情况4 
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
	//测试DeleteNode函数 
	DeleteNode(&List, pFind);
	PrintList(List);
}
