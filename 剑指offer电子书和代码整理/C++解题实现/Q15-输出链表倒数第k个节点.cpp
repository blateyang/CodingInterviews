#include <iostream>
#include "single_list.h"
using namespace std;

//------------��������------------------
/*
1. ���ܲ��ԣ����������һ�������������k��������������һ��
2. ����������ԣ�������ԣ�������Ϊ�գ�kΪС��1������kΪ���������ȵ��� 
*/
ListNode* findKthToTail(ListNode *pHead, unsigned k)
{//˼·���������������Ϊk-1��ָ��p1,p2�����ȱ��������ָ��p1ָ������β��������1����ʱ��������p2��ָ������k����� 
	if(pHead == NULL || k < 1) return NULL;
	ListNode *p1 = pHead;
	ListNode *p2 = pHead;
	unsigned count = 0; //ͳ��p1�ߵĲ��� 
	while(p1->pNext != NULL)
		{
			p1 = p1->pNext;
			++count;
			if (count >= k) //p1�߹�k����p2��ʼ�ߣ����Ϊk-1�� 
				p2 = p2->pNext;
		}
	if(k > count+1) //count+1��Ϊ������,k���������ȷ��ؿ�ָ�� 
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
