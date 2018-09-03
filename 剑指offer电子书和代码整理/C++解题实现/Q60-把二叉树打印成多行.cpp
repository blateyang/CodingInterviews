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

//------------��������--------------
/*
1.���ܣ���������һ��/�ж�㣻��ȫ������/����ȫ������
2.���棺�ն����� 
*/ 
vector<vector<int> > Print(TreeNode *pRoot)
{//˼·���ڽ������н��в�������Ļ����϶���������������toBePrinted��nextLevel�ֱ�
//		���ڼ�¼��ǰ����Ҫ��ӡ�Ľڵ�������һ����Ҫ��ӡ�Ľڵ�������toBePrintedΪ0ʱ���������nextLevel��ͬʱnextLevle����Ϊ0 
	vector<vector<int> > result;
	if(pRoot != NULL) //�������ǿ�
	{
		queue<TreeNode *> nodes;
		nodes.push(pRoot);	//���ڵ����
		int toBePrinted = 1, nextLevel = 0;
		vector<int> curLevel; //�洢��ǰ����Ҫ��ӡ�Ľڵ� 
		while(!nodes.empty()) 
		{
			TreeNode *pNode = nodes.front(); //ȡ��ǰ��ͷ�ڵ�
			curLevel.push_back(pNode->val);	 //����Ҫ��ӡ��ֵ 
			if(pNode->left != NULL)
			{//���ӷǿգ������ͬʱnextLevelֵ+1 
				nodes.push(pNode->left);
				++nextLevel; 
			}
			if(pNode->right != NULL)
			{
				nodes.push(pNode->right);
				++nextLevel; 
			}
			nodes.pop(); //��ǰ��ͷ�ڵ����
			--toBePrinted;
			if(toBePrinted == 0)
			{//��ǰ���Ѵ�ӡ�� 
				result.push_back(curLevel);
				curLevel.clear(); //���curLevel����
				toBePrinted = nextLevel;	//���±��� 
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
 
