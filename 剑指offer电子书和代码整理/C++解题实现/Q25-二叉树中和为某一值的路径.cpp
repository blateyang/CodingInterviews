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

//-------------------��������------------------
/*
1.���ܲ��ԣ�����������һ���ڵ㣬�����������������������������������У����������л�û�к�Ϊ����ĳһֵ��·�� 
2.������ԣ����� 
*/ 
void FindPathRecursive(TreeNode *root, int expectNum, int sum, vector<int> &path, vector<vector<int> > &paths)
{//˼·����������������ԶԷ��ʹ��Ľڵ�ֵ�����ۼӣ�ͬʱѹ�뵱ǰ·��ջ�������ʵ�Ҷ�ڵ�ʱ��
//		�ж��ۼӺ��Ƿ������ֵ��ȣ�������������������˵����ڵ㣨�˻ظ��ڵ�֮ǰҪ��·����ɾ����ǰ�ڵ㣩 
	path.push_back(root->val);
	sum += root->val; 
	if(root->left==NULL && root->right==NULL)
	{//�ݹ�����ﵽҶ�ڵ� 
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
