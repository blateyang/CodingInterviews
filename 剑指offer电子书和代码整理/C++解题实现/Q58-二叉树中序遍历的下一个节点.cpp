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

//-------------测试用例----------------
/*
1.功能：给定节点为非叶节点；给定节点为左叶节点；给定节点为右叶节点
2.负面：给定节点为空 
*/ 

TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        if(pNode == NULL)
            return NULL;
        TreeLinkNode *pNext=NULL; 
        //给定节点右子树存在,中序遍历的下一个节点为其右子树的最左节点 
        if(pNode->right != NULL)  
        {
			pNode = pNode->right;
			while(pNode->left != NULL)
				pNode = pNode->left;
			pNext = pNode;	
		}
        else //给定节点右子树不存在，则要判断给定节点是否是其父节点（若存在）的左孩子 
        {
        	while(pNode->next != NULL) //父节点存在时
			{
				if(pNode->next->left == pNode)
				{//给定节点是其父节点的左孩子，中序遍历的下个节点即为父节点 
					pNext = pNode->next;
					break;
				}
				else //给定节点是其父节点的右孩子，则需继续上溯判断，直至根节点 
					pNode = pNode->next;
			 } 
		}
		return pNext; 
    }
    
int main()
{
	return 0;
}
