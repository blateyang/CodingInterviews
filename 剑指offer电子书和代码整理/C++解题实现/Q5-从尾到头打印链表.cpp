// 面试题5：从尾到头打印链表
#include <iostream>
#include <stack>
using std::cout;
using T=int;

struct ListNode{ //链表结点定义 
	T nValue;
	ListNode *pNext; 
}; 

void AddToTail(ListNode **pHead, T value)
{//向链表*pHead添加值为value的节点，使用指向指针的指针（表示该指针是指向头结点指针，存的是头结点指针的地址）是因为 
// 函数体可能会对链表的头指针进行修改，如果不设为指向指针的指针，无法把对头指针的修改带出函数 
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
{//利用栈容器从尾到头打印链表 
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
