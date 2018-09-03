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

//----------��������--------------
/*
1.���ܣ�k=1,�ڵ�����N��1~N֮���ĳֵ
2.���棺������Ϊ�գ�k������Ч��Χ 
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
{//˼·����������������������ɵõ�����õ����У����ص�k������
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
 
