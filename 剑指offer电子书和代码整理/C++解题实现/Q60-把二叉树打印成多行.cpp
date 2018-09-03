#include <iostream>
#include <vector> 
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

//------------测试用例--------------
/*
1.功能：二叉树仅一层/有多层；完全二叉树/非完全二叉树
2.负面：空二叉树 
*/ 
vector<vector<int> > Print(TreeNode *pRoot)
{//思路：在借助队列进行层序遍历的基础上额外设置两个变量toBePrinted和nextLevel分别
//		用于记录当前层需要打印的节点树及下一层需要打印的节点数，当toBePrinted为0时，令其等于nextLevel，同时nextLevle重置为0 
	vector<vector<int> > result;
	if(pRoot != NULL) //二叉树非空
	{
		queue<TreeNode *> nodes;
		nodes.push(pRoot);	//根节点入队
		int toBePrinted = 1, nextLevel = 0;
		vector<int> curLevel; //存储当前层需要打印的节点 
		while(!nodes.empty()) 
		{
			TreeNode *pNode = nodes.front(); //取当前队头节点
			curLevel.push_back(pNode->val);	 //保存要打印的值 
			if(pNode->left != NULL)
			{//左孩子非空，则入队同时nextLevel值+1 
				nodes.push(pNode->left);
				++nextLevel; 
			}
			if(pNode->right != NULL)
			{
				nodes.push(pNode->right);
				++nextLevel; 
			}
			nodes.pop(); //当前队头节点出队
			--toBePrinted;
			if(toBePrinted == 0)
			{//当前层已打印完 
				result.push_back(curLevel);
				curLevel.clear(); //清空curLevel向量
				toBePrinted = nextLevel;	//更新变量 
				nextLevel = 0; 
			 } 
		}
	 } 
	 return result; 
}

int main()
{
	TreeNode root(1);
	vector<vector<int> > result = Print(&root);
	for(auto vec:result)
		for(auto v:vec)
			cout<<v<<" ";
	return 0; 
}
 
