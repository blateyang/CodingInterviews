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

//-----------��������---------------
/*
1.���ܣ��ԳƵ��������ڵ㣬��ڵ㣩�����ԳƵ�����ֻ����������ֻ�������������У�
2.���棺���� 
*/ 
bool isSymmetrical(TreeNode *pLeft, TreeNode *pRight)
{//˼·���ݹ��жϸ����ߵ����������Ƿ�Գƣ���߰������ҷ��ʽڵ㣬�ұ߰���������ʽڵ�
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
