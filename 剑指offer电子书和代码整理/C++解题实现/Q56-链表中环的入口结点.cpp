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
//	pNew->val = value;
//	pNew->next = NULL;
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

bool hasLoop(ListNode *pHead, ListNode **meetNode) //当要对传入的指针本身修改时需要使用指向指针的指针 
{//通过快慢指针判断链表中是否有环,若有同时返回在环中相遇点的指针 
	if(pHead == NULL)
		return false;
	ListNode *s = pHead->next; //初始时，慢指针s先从头结点开始走1步 
	if(s == NULL)
		return false;
	ListNode *q = s->next;	//初始时，快指针q从头结点开始走2步 
	while(q != NULL) //链表无环时，循环到链表尾结束 
	{
		if(s == q)
			{*meetNode = q; return true;} 
		s = s->next; //s每次走一步 
		q = q->next; //q每次走两步 
		if(q != NULL)
			q = q->next;
	 } 
	return false;
 } 

ListNode *EntryNodeOfLoop(ListNode *pHead)
{
	ListNode *meetNode = NULL;
	if(hasLoop(pHead, &meetNode))
	{	//若有环，算出环的长度 
		ListNode *tmp = meetNode->next;
		int count = 1;
		while(tmp != meetNode)
		{
			tmp = tmp->next;
			++count;
		 } 
		//再利用2个指针从头结点开始，让一个指针先走count步，然后2个指针以相等的
		//速度同步走，它们必在环入口处相遇
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
	//生成一个结点 
	ListNode *pNew = new ListNode(3);
	pNew->next = list->next; //后两个结点成环 
	ListNode *pCur = list;
	while(pCur->next != NULL)
		pCur = pCur->next;
	pCur->next = pNew; //在尾部插入新结点 
	ListNode *entryNode = EntryNodeOfLoop(list);
	if(entryNode != NULL)
		cout<<entryNode->val<<endl;
	return 0; 
}
