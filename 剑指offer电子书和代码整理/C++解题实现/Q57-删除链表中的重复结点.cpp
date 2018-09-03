#include <iostream>
using namespace std;

#include <iostream>
using namespace std;
using T=int;

struct ListNode {
    T val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
    
void AddToTail(ListNode **pHead, T value)
{//向链表*pHead添加值为value的节点，使用指向指针的指针（表示该指针是指向头结点指针，存的是头结点指针的地址）是因为 
// 函数体可能会对链表的头指针进行修改，如果不设为指向指针的指针，无法把对头指针的修改带出函数 
	//生成一个结点 
	ListNode *pNew = new ListNode(value);
	if(*pHead == NULL) //链表为空
		*pHead = pNew;
	else //遍历到链表尾部 
		{
			ListNode *pCur = *pHead;
			while(pCur->next != NULL)
				pCur = pCur->next;
			pCur->next = pNew; //在尾部插入新结点 
		}	 
}

void PrintList(ListNode *pHead)
{
	if(pHead==NULL)
		return;
	ListNode *pCur = pHead;
	while(pCur != NULL)
	{
		cout<<pCur->val<<"->";
		pCur = pCur->next;
	}
	cout<<"End"<<std::endl;
}

//---------------测试用例----------------
/*
1.功能：无/仅有一组/有多组重复的结点（重复数>=2)；重复结点在头，中，尾部
2.负面：链表为空 
*/ 
ListNode* deleteDuplication(ListNode* pHead)
{//思路：设置三个状态指针pNode,pNext和pPreNode,pNode和pNext用来判断当前结点是否与下一结点重复，pPreNode指向pNode的前一个不重复结点 
	if(pHead == NULL)
		return NULL;
	ListNode *pPreNode=NULL, *pNode=pHead, *pNewHead = pHead;
	while(pNode != NULL)
	{
		ListNode *pNext = pNode->next;
		bool needDelete = false; //设置标志位方便判断
		if(pNext!=NULL && pNode->val==pNext->val) 
			needDelete = true;
		if(!needDelete) //pNode与pNext不重复，更新pPreNode和pNode指针 
		{
			pPreNode = pNode;
			pNode = pNode->next;
		}
		else //pNode与pNext重复 
		{
			int delVal = pNode->val;
			ListNode *pDel = pNode;
			while(pDel!=NULL && pDel->val==delVal)
			{//删除重复的结点 
				pNext = pDel->next;
				delete pDel;
				pDel = pNext;
			}
			if(pPreNode == NULL) //头部有重复结点的情况,更新头结点 
				pNewHead = pNext;
			else	//头部无重复结点，更新pPreNode指针 
				pPreNode->next = pNext;
			pNode = pNext; 
		}
	 } 
	return pNewHead;
} 

int main()
{
	ListNode *list = NULL;
	AddToTail(&list, 1);
	AddToTail(&list, 1);
	AddToTail(&list, 3);
	AddToTail(&list, 3);
	AddToTail(&list, 5);
	ListNode *pHead = deleteDuplication(list);
	PrintList(pHead);
	return 0; 
 } 
