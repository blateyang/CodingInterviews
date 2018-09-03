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
//	pNew->val = value;
//	pNew->next = NULL;
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

bool hasLoop(ListNode *pHead, ListNode **meetNode) //��Ҫ�Դ����ָ�뱾���޸�ʱ��Ҫʹ��ָ��ָ���ָ�� 
{//ͨ������ָ���ж��������Ƿ��л�,����ͬʱ�����ڻ����������ָ�� 
	if(pHead == NULL)
		return false;
	ListNode *s = pHead->next; //��ʼʱ����ָ��s�ȴ�ͷ��㿪ʼ��1�� 
	if(s == NULL)
		return false;
	ListNode *q = s->next;	//��ʼʱ����ָ��q��ͷ��㿪ʼ��2�� 
	while(q != NULL) //�����޻�ʱ��ѭ��������β���� 
	{
		if(s == q)
			{*meetNode = q; return true;} 
		s = s->next; //sÿ����һ�� 
		q = q->next; //qÿ�������� 
		if(q != NULL)
			q = q->next;
	 } 
	return false;
 } 

ListNode *EntryNodeOfLoop(ListNode *pHead)
{
	ListNode *meetNode = NULL;
	if(hasLoop(pHead, &meetNode))
	{	//���л���������ĳ��� 
		ListNode *tmp = meetNode->next;
		int count = 1;
		while(tmp != meetNode)
		{
			tmp = tmp->next;
			++count;
		 } 
		//������2��ָ���ͷ��㿪ʼ����һ��ָ������count����Ȼ��2��ָ������ȵ�
		//�ٶ�ͬ���ߣ����Ǳ��ڻ���ڴ�����
		ListNode *pre = pHead;
		while(count--)
			pre = pre->next;
		ListNode *post = pHead;
		while(pre != post)
		{
			pre = pre->next;
			post = post->next;
		 } 
		return pre;
	}
	return NULL;
 } 
 
int main()
{
	ListNode *list = NULL;
	AddToTail(&list, 1);
	AddToTail(&list, 2);
	//����һ����� 
	ListNode *pNew = new ListNode(3);
	pNew->next = list->next; //���������ɻ� 
	ListNode *pCur = list;
	while(pCur->next != NULL)
		pCur = pCur->next;
	pCur->next = pNew; //��β�������½�� 
	ListNode *entryNode = EntryNodeOfLoop(list);
	if(entryNode != NULL)
		cout<<entryNode->val<<endl;
	return 0; 
}
