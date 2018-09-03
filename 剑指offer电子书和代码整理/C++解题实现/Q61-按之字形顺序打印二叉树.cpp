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

//------------��������--------------
/*
1.���ܣ���������һ��/�ж�㣻��ȫ������/����ȫ������
2.���棺�ն����� 
*/ 
vector<vector<int> > Print(TreeNode *pRoot)
{//˼·1���ڰѶ�������ӡ�ɶ���˼·�Ļ����Ͻ����л���˫�˶��У���������һ����־λorderFlag,
//		Ϊtrue�������ͷ���������Ҳ��������ң���Ϊfalse�����Ҷ�ͷ������������Һ��󣩣�ÿ������һ�㽫��־λ��תһ��
//˼·2����ָoffer�ϵ�˼·��������ջS1��S2ʵ�֣�S1������������Ľڵ㣬S2������ż����Ľڵ㣬�ڴ�ӡS1�еĽڵ�ʱ������ڵ���ջ��S2�С���һ��ջΪ�պ󣬽���������ջ 
	vector<vector<int> > result;
	if(pRoot != NULL) //�������ǿ�
	{
		deque<TreeNode*> nodes;
		nodes.push_back(pRoot);
		int toBePrinted = 1, nextLevel = 0;
		bool orderFlag = true;
		vector<int> curLevel;
		while(!nodes.empty())
		{
			if(orderFlag)
			{//orderFlagΪtrue,�������ͷ�����Ӵ��Ҷ�β��� 
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
			else //�����Ҷ�ͷ�����Ӵ����β��� 
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
