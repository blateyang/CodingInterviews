#include <iostream>
#include <vector>
#include <deque>
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
{//思路1：在把二叉树打印成多行思路的基础上将队列换成双端队列，并再增加一个标志位orderFlag,
//		为true访问左队头（孩子入队也是先左后右），为false访问右队头（孩子入队先右后左），每遍历完一层将标志位反转一次
//思路2：剑指offer上的思路是用两个栈S1和S2实现，S1用来存奇数层的节点，S2用来存偶数层的节点，在打印S1中的节点时，将其节点入栈到S2中。当一个栈为空后，交换处理两栈 
	vector<vector<int> > result;
	if(pRoot != NULL) //二叉树非空
	{
		deque<TreeNode*> nodes;
		nodes.push_back(pRoot);
		int toBePrinted = 1, nextLevel = 0;
		bool orderFlag = true;
		vector<int> curLevel;
		while(!nodes.empty())
		{
			if(orderFlag)
			{//orderFlag为true,访问左队头，孩子从右队尾入队 
				TreeNode *pNode = nodes.front();
				curLevel.push_back(pNode->val);
				if(pNode->left != NULL){
					nodes.push_back(pNode->left);
					++nextLevel;
				}
				if(pNode->right != NULL){
					nodes.push_back(pNode->right);
					++nextLevel;
				}
				nodes.pop_front();
			}
			else //访问右队头，孩子从左队尾入队 
			{
				TreeNode *pNode = nodes.back();
				curLevel.push_back(pNode->val);
				if(pNode->right != NULL){
					nodes.push_front(pNode->right);
					++nextLevel;
				}
				if(pNode->left != NULL){
					nodes.push_front(pNode->left);
					++nextLevel;
				}
				nodes.pop_back();
			 } 
			--toBePrinted;
			if(toBePrinted == 0)
				{
					result.push_back(curLevel);
					curLevel.clear();
					toBePrinted = nextLevel;
					nextLevel = 0;
					orderFlag = !orderFlag;
				}
		}
	}
	return result;
}

int main()
{
	TreeNode root(1);
	TreeNode l1(2), r1(3);
	root.left = &l1;
	root.right = &r1;
	TreeNode rr2(7), rl2(6);
	r1.right = &rr2;
	r1.left = &rl2;
	vector<vector<int> > result = Print(&root);
	for(auto vec:result)
		for(auto v:vec)
			cout<<v<<" ";
	return 0;
}
