#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
using namespace std;

// using iter = vector<int>::iterator //如编译器不支持auto，也可使用类型别名
 
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 }; 
 
//-------------测试用例-------------------
/* 
1. 功能测试：序列只有一个元素；序列有多个元素 
2. 负面测试： 序列为空；两序列长度不等 ；先序和中序序列不匹配 
 */

//TreeNode* ConstructCore(int *startPreOrder, int *endPreOrder, int *startInOrder, int *endInOrder)
TreeNode* ConstructCore(auto startPreOrder, auto endPreOrder, auto startInOrder, auto endInOrder)
{//思路：根据先序序列确定根节点（序列最前面的元素），再根据根节点和中序序列确定
//		 根节点的左右子树，然后对左右子树递归的执行上述操作
	TreeNode *root = new TreeNode(*startPreOrder);
	//仅有一个元素且与inOrder首元素相等，直接返回根节点 
	if(startPreOrder == endPreOrder) 
	{
		if(startInOrder == endInOrder && *startPreOrder == *startInOrder) 
			return root;
		else
			{cerr<<"invalid input"<<endl; return root;}
	} 
//	int *rootInOrder = startInOrder;
	auto rootInOrder = startInOrder;
	// 遍历中序序列，找到根节点 
	while(rootInOrder <= endInOrder && *rootInOrder != root->val) 
		++rootInOrder;
	if(rootInOrder > endInOrder)
		{cerr<<"invalid input"<<endl; return root;}
	// 根据中序序列根节点位置求出左子树节点数目，对应的也是先序序列中左子树的节点数目 
	int leftLength = rootInOrder - startInOrder;
//	int *leftPreOrderEnd = startPreOrder + leftLength;
	auto leftPreOrderEnd = startPreOrder + leftLength;
	if(leftLength > 0) //左子树不为空 
		root->left = ConstructCore(startPreOrder+1, leftPreOrderEnd, startInOrder, rootInOrder-1);
	if(leftLength < endPreOrder - startPreOrder) //右子树不为空 
		root->right = ConstructCore(leftPreOrderEnd+1, endPreOrder, rootInOrder+1, endInOrder);
	return root;
}

//TreeNode* reConstructBinaryTree(int *preOrder, int *inOrder, int length)
//{
//	if(preOrder == NULL || inOrder == NULL || length <=0)
//		return NULL;
//	return ConstructCore(preOrder, preOrder+length-1, inOrder, inOrder+length-1);
//}

// 对数组指针操作针对vector而言可以转换成对迭代器操作 
TreeNode* reConstructBinaryTree(vector<int> &preOrder, vector<int> &inOrder)
{
	if(preOrder.size()==0 || inOrder.size()==0)
		return NULL;
	return ConstructCore(preOrder.begin(), preOrder.end()-1, inOrder.begin(), inOrder.end()-1);
}

void visitAlongLeftBranch(TreeNode *x, stack<TreeNode*> &s)
{
	while(x)
	{
		TreeNode *pTmp = x->left;
		x->left = x->right;
		x->right = pTmp;
		pTmp = NULL;
		
		s.push(x->right);
		x = x->left; 
	}
}

void Mirror(TreeNode *pRoot)
    {
        stack<TreeNode*> s;
        TreeNode *x = pRoot;
        while(true)
        {
            visitAlongLeftBranch(x, s);
            if(s.empty()) break;
            x = s.top();
            s.pop(); //直接弹出不会返回栈顶元素
        }
    }

int main()
{
//	int preOrder[] = {1,2,4,7,3,5,6,8};
//	int inOrder[] = {4,7,2,1,5,3,8,6};
//	TreeNode *root = reConstructBinaryTree(preOrder, inOrder, 8);
	vector<int> preOrder = {8,6,5,7,10,9,11};
	vector<int> inOrder =  {5,6,7,8,9,10,11};
	TreeNode *root = reConstructBinaryTree(preOrder, inOrder);
	cout<<root->val<<" "<<root->left->val<<" "<<root->right->val<<endl;
	Mirror(root);
	cout<<root->val<<" "<<root->left->val<<" "<<root->right->val<<endl;
	return 0;
 } 
