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

//-----------测试用例---------------
/*
1.功能：对称的树（单节点，多节点）；不对称的树（只有左子树，只有右子树，均有）
2.负面：空树 
*/ 
bool isSymmetrical(TreeNode *pLeft, TreeNode *pRight)
{//思路：递归判断根两边的左右子树是否对称，左边按根左右访问节点，右边按根右左访问节点
 	if(pLeft==NULL && pRight==NULL)
 		return true;
 	if(pLeft!=NULL && pRight!=NULL)
 	{
 		if(pLeft->val != pRight->val)
 			return false;
 		else
 			return isSymmetrical(pLeft->left, pRight->right) && isSymmetrical(pLeft->right, pRight->left);
	 }
	else
		return false;
}

bool isSymmetrical(TreeNode *pRoot)
{
	return isSymmetrical(pRoot, pRoot);
}

int main()
{
	TreeNode root(8);
	if(isSymmetrical(&root))
		cout<<"is symmetrical"<<endl;
	return 0;
}
