#include <iostream>
using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};

//------------��������---------------
/*
1.���ܣ� ֻ��һ�����ڵ㣻ֻ����������ֻ�������������߶���
2.���棺 ���� 
*/ 
int TreeDepthIter(TreeNode *pRoot)
{//˼·����������������Ե�ǰ�ڵ�Ϊ��������ȣ����ڵ��㣩����������������ȵĴ���+1
	if(pRoot->left == NULL && pRoot->right == NULL)	//�ݹ����������Ҷ�ڵ㣬���Ϊ1
		return 1;
	int LSubTreeDepth=0, RSubTreeDepth = 0;
	if(pRoot->left != NULL)
		LSubTreeDepth = TreeDepthIter(pRoot->left);
	if(pRoot->right != NULL)
		RSubTreeDepth = TreeDepthIter(pRoot->right);
	int SubTreeDepth = (LSubTreeDepth >= RSubTreeDepth)? LSubTreeDepth:RSubTreeDepth;
	return 1+SubTreeDepth;
 } 
 
int TreeDepth(TreeNode *pRoot)
{
	if(pRoot == NULL)
		return 0;
//	return TreeDepthIter(pRoot);
//----------��ָoffer��˼·һ��������������ָ��Ϊ�ݹ������������-----------
	int leftDepth = TreeDepth(pRoot->left);
	int rightDepth = TreeDepth(pRoot->right);
	return (leftDepth >= rightDepth)? (leftDepth+1):(rightDepth+1);	
}

//----------------��չ���ж�ƽ����������������нڵ�������������������1��----------- 
//��Ч˼·������ǰ���������ȵĺ����ݹ��ж��Ե�ǰ�ڵ�Ϊ���ڵ�������Ƿ�����AVL����������˼·���ظ������ڵ㣬Ч�ʲ��ߣ� 
//��Ч˼·���ں���������ʱ���Ѿ��ȷ��ʹ����������ˣ��ʿ���һ�����������һ���ж����Ƿ�ΪAVL
bool isBalanced(TreeNode *pRoot, int &depth)
{
	if(pRoot == NULL)
	{
		depth = 0;
		return true; //����ΪAVL 
	}
	int lDepth, rDepth;
	if(isBalanced(pRoot->left, lDepth) && isBalanced(pRoot->right, rDepth)) 
	{//����������ƽ��ʱ�����ж��Ե�ǰ�ڵ�Ϊ���ڵ�������Ƿ�ƽ�� 
		int diff = lDepth - rDepth;
		if(diff<=1 && diff>=-1) 
			{
				depth = (lDepth >= rDepth)? lDepth+1:rDepth+1;
				return true;
			}
	}
	return false;
 } 

bool isBalanced(TreeNode *pRoot)
{
	int depth = 0;
	return isBalanced(pRoot, depth);
}


int main()
{
	return 0;
}
