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
{//������*pHead���ֵΪvalue�Ľڵ㣬ʹ��ָ��ָ���ָ�루��ʾ��ָ����ָ��ͷ���ָ�룬�����ͷ���ָ��ĵ�ַ������Ϊ 
// ��������ܻ�������ͷָ������޸ģ��������Ϊָ��ָ���ָ�룬�޷��Ѷ�ͷָ����޸Ĵ������� 
	//����һ����� 
	ListNode *pNew = new ListNode(value);
	if(*pHead == NULL) //����Ϊ��
		*pHead = pNew;
	else //����������β�� 
		{
			ListNode *pCur = *pHead;
			while(pCur->next != NULL)
				pCur = pCur->next;
			pCur->next = pNew; //��β�������½�� 
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

//---------------��������----------------
/*
1.���ܣ���/����һ��/�ж����ظ��Ľ�㣨�ظ���>=2)���ظ������ͷ���У�β��
2.���棺����Ϊ�� 
*/ 
ListNode* deleteDuplication(ListNode* pHead)
{//˼·����������״ָ̬��pNode,pNext��pPreNode,pNode��pNext�����жϵ�ǰ����Ƿ�����һ����ظ���pPreNodeָ��pNode��ǰһ�����ظ���� 
	if(pHead == NULL)
		return NULL;
	ListNode *pPreNode=NULL, *pNode=pHead, *pNewHead = pHead;
	while(pNode != NULL)
	{
		ListNode *pNext = pNode->next;
		bool needDelete = false; //���ñ�־λ�����ж�
		if(pNext!=NULL && pNode->val==pNext->val) 
			needDelete = true;
		if(!needDelete) //pNode��pNext���ظ�������pPreNode��pNodeָ�� 
		{
			pPreNode = pNode;
			pNode = pNode->next;
		}
		else //pNode��pNext�ظ� 
		{
			int delVal = pNode->val;
			ListNode *pDel = pNode;
			while(pDel!=NULL && pDel->val==delVal)
			{//ɾ���ظ��Ľ�� 
				pNext = pDel->next;
				delete pDel;
				pDel = pNext;
			}
			if(pPreNode == NULL) //ͷ�����ظ��������,����ͷ��� 
				pNewHead = pNext;
			else	//ͷ�����ظ���㣬����pPreNodeָ�� 
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
