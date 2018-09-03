#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
using namespace std;

// using iter = vector<int>::iterator //���������֧��auto��Ҳ��ʹ�����ͱ���
 
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 }; 
 
//-------------��������-------------------
/* 
1. ���ܲ��ԣ�����ֻ��һ��Ԫ�أ������ж��Ԫ�� 
2. ������ԣ� ����Ϊ�գ������г��Ȳ��� ��������������в�ƥ�� 
 */

//TreeNode* ConstructCore(int *startPreOrder, int *endPreOrder, int *startInOrder, int *endInOrder)
TreeNode* ConstructCore(auto startPreOrder, auto endPreOrder, auto startInOrder, auto endInOrder)
{//˼·��������������ȷ�����ڵ㣨������ǰ���Ԫ�أ����ٸ��ݸ��ڵ����������ȷ��
//		 ���ڵ������������Ȼ������������ݹ��ִ����������
	TreeNode *root = new TreeNode(*startPreOrder);
	//����һ��Ԫ������inOrder��Ԫ����ȣ�ֱ�ӷ��ظ��ڵ� 
	if(startPreOrder == endPreOrder) 
	{
		if(startInOrder == endInOrder && *startPreOrder == *startInOrder) 
			return root;
		else
			{cerr<<"invalid input"<<endl; return root;}
	} 
//	int *rootInOrder = startInOrder;
	auto rootInOrder = startInOrder;
	// �����������У��ҵ����ڵ� 
	while(rootInOrder <= endInOrder && *rootInOrder != root->val) 
		++rootInOrder;
	if(rootInOrder > endInOrder)
		{cerr<<"invalid input"<<endl; return root;}
	// �����������и��ڵ�λ������������ڵ���Ŀ����Ӧ��Ҳ�������������������Ľڵ���Ŀ 
	int leftLength = rootInOrder - startInOrder;
//	int *leftPreOrderEnd = startPreOrder + leftLength;
	auto leftPreOrderEnd = startPreOrder + leftLength;
	if(leftLength > 0) //��������Ϊ�� 
		root->left = ConstructCore(startPreOrder+1, leftPreOrderEnd, startInOrder, rootInOrder-1);
	if(leftLength < endPreOrder - startPreOrder) //��������Ϊ�� 
		root->right = ConstructCore(leftPreOrderEnd+1, endPreOrder, rootInOrder+1, endInOrder);
	return root;
}

//TreeNode* reConstructBinaryTree(int *preOrder, int *inOrder, int length)
//{
//	if(preOrder == NULL || inOrder == NULL || length <=0)
//		return NULL;
//	return ConstructCore(preOrder, preOrder+length-1, inOrder, inOrder+length-1);
//}

// ������ָ��������vector���Կ���ת���ɶԵ��������� 
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
            s.pop(); //ֱ�ӵ������᷵��ջ��Ԫ��
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
