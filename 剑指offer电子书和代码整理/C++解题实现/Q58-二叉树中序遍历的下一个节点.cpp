#include <iostream>
#include <stack>
using namespace std;

struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};

//-------------��������----------------
/*
1.���ܣ������ڵ�Ϊ��Ҷ�ڵ㣻�����ڵ�Ϊ��Ҷ�ڵ㣻�����ڵ�Ϊ��Ҷ�ڵ�
2.���棺�����ڵ�Ϊ�� 
*/ 

TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        if(pNode == NULL)
            return NULL;
        TreeLinkNode *pNext=NULL; 
        //�����ڵ�����������,�����������һ���ڵ�Ϊ��������������ڵ� 
        if(pNode->right != NULL)  
        {
			pNode = pNode->right;
			while(pNode->left != NULL)
				pNode = pNode->left;
			pNext = pNode;	
		}
        else //�����ڵ������������ڣ���Ҫ�жϸ����ڵ��Ƿ����丸�ڵ㣨�����ڣ������� 
        {
        	while(pNode->next != NULL) //���ڵ����ʱ
			{
				if(pNode->next->left == pNode)
				{//�����ڵ����丸�ڵ�����ӣ�����������¸��ڵ㼴Ϊ���ڵ� 
					pNext = pNode->next;
					break;
				}
				else //�����ڵ����丸�ڵ���Һ��ӣ�������������жϣ�ֱ�����ڵ� 
					pNode = pNode->next;
			 } 
		}
		return pNext; 
    }
    
int main()
{
	return 0;
}
