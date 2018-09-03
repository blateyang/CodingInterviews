#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};
	
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

//-------------------测试用例------------------
/*
1.功能测试：二叉树仅有一个节点，仅有左子树，仅有右子树，左右子树均有；二叉树中有或没有和为给定某一值的路径 
2.负面测试：空树 
*/ 
void FindPathRecursive(TreeNode *root, int expectNum, int sum, vector<int> &path, vector<vector<int> > &paths)
{//思路：采用先序遍历策略对访问过的节点值进行累加，同时压入当前路径栈；当访问到叶节点时，
//		判断累加和是否与给定值相等，若相等则输出，否则回退到父节点（退回父节点之前要在路径上删除当前节点） 
	path.push_back(root->val);
	sum += root->val; 
	if(root->left==NULL && root->right==NULL)
	{//递归基：达到叶节点 
		if(sum == expectNum)
			paths.push_back(path);
//		return;
	}
	if(root->left!=NULL) 
	{
		FindPathRecursive(root->left, expectNum, sum, path, paths);
//		sum -= root->left->val;
//		path.pop_back();
	}
	if(root->right!=NULL)
	{
		FindPathRecursive(root->right, expectNum, sum, path, paths);
//		sum -= root->right->val;
//		path.pop_back();		
	}
	path.pop_back();
 }
 
vector<vector<int> > FindPath(TreeNode *root, int expectNumber)
{
	int sum=0;
	vector<int> path;
	vector<vector<int> > paths;
	if(root==NULL)
	{
		cerr<<"invalid input"<<endl;
		return paths;
	 } 
	FindPathRecursive(root, expectNumber, sum, path, paths);
	return paths;
 } 
 
int main()
{
	vector<int> preOrder = {10,5,4,12};
	vector<int> inOrder =  {4,5,10,12};
	TreeNode *root = reConstructBinaryTree(preOrder, inOrder);
	cout<<root->val<<" "<<root->left->val<<" "<<root->right->val<<endl;
	vector<vector<int> > paths=FindPath(root, 22);
	for(auto path:paths)
		{
			for(auto v:path)
				cout<<v<<" ";
			cout<<endl;
		}
	return 0;
 } 
