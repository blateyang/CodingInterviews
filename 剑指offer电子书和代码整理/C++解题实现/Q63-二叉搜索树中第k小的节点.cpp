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

//----------测试用例--------------
/*
1.功能：k=1,节点总数N，1~N之间的某值
2.负面：二叉树为空，k超出有效范围 
*/ 
void travIn(TreeNode *pRoot, vector<TreeNode*> &nodes)
{
	if(pRoot == NULL)
		return;
	travIn(pRoot->left, nodes);
	nodes.push_back(pRoot);
	travIn(pRoot->right, nodes);
}
TreeNode *KthNode(TreeNode *pRoot, int k)
{//思路：中序遍历二叉搜索树即可得到排序好的序列，返回第k个即可
	vector<TreeNode*> nodes;
	travIn(pRoot, nodes);
	if(pRoot==NULL || k<1 || k>nodes.size())
		return NULL;
	return nodes[k-1];
}

int main()
{
	TreeNode root(2), lchild(1), rchild(3);
	TreeNode *pNode = &root;
	pNode->left = &lchild;
	pNode->right = &rchild;
	TreeNode *result = KthNode(pNode, 3);
	cout<<result->val<<endl;
	return 0;
}
 
