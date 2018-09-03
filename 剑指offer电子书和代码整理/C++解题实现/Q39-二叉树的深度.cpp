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

//------------测试用例---------------
/*
1.功能： 只有一个根节点；只有左子树；只有右子树；两者都有
2.负面： 空树 
*/ 
int TreeDepthIter(TreeNode *pRoot)
{//思路：借助后序遍历，以当前节点为子树的深度（按节点算）等于其左、右子树深度的大者+1
	if(pRoot->left == NULL && pRoot->right == NULL)	//递归基：遍历到叶节点，深度为1
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
//----------剑指offer的思路一样，但以遇到空指针为递归基，代码更简洁-----------
	int leftDepth = TreeDepth(pRoot->left);
	int rightDepth = TreeDepth(pRoot->right);
	return (leftDepth >= rightDepth)? (leftDepth+1):(rightDepth+1);	
}

//----------------拓展：判断平衡二叉树（树中所有节点的左右子树深度相差不超过1）----------- 
//低效思路：利用前面的求树深度的函数递归判断以当前节点为根节点的子树是否满足AVL条件（此种思路会重复遍历节点，效率不高） 
//高效思路：在后续遍历的时候已经先访问过左右子树了，故可以一边求树的深度一边判断其是否为AVL
bool isBalanced(TreeNode *pRoot, int &depth)
{
	if(pRoot == NULL)
	{
		depth = 0;
		return true; //空树为AVL 
	}
	int lDepth, rDepth;
	if(isBalanced(pRoot->left, lDepth) && isBalanced(pRoot->right, rDepth)) 
	{//左右子树均平衡时，再判断以当前节点为根节点的子树是否平衡 
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
