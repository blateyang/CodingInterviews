#include <iostream>
#include "single_list.h"
using namespace std;

//------------测试用例------------------
/*
1. 功能测试：输出倒数第一个；输出倒数第k个；输出倒数最后一个
2. 特殊输入测试（负面测试）：链表为空；k为小于1的数；k为大于链表长度的数 
*/
ListNode* findKthToTail(ListNode *pHead, unsigned k)
{//思路：用两个相隔距离为k-1的指针p1,p2，当先遍历链表的指针p1指到链表尾（倒数第1个）时，后来的p2即指向倒数第k个结点 
	if(pHead == NULL || k < 1) return NULL;
	ListNode *p1 = pHead;
	ListNode *p2 = pHead;
	unsigned count = 0; //统计p1走的步数 
	while(p1->pNext != NULL)
		{
			p1 = p1->pNext;
			++count;
			if (count >= k) //p1走过k步后，p2开始走，相距为k-1步 
				p2 = p2->pNext;
		}
	if(k > count+1) //count+1即为链表长度,k大于链表长度返回空指针 
		return NULL;
	return p2; 
}

int main()
{
	ListNode *list = NULL;
	for(int i=1; i<=6; ++i)
		AddToTail(&list, i);
	ListNode *KthToTail = findKthToTail(list, 8);
	if(KthToTail!=NULL) 
		cout<<KthToTail->nValue<<endl;
	return 0;
 } 
