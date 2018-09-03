#include <iostream>
#include <stack>
#include <deque> //不用自己实现，STL中有双端队列deque的实现 
#include <vector>
using namespace std;

template<typename T>
class Queue{
	private:
		//利用两个栈实现队列 
		stack<T> s_in;
		stack<T> s_out; 
	public:
		bool empty(){
			if(s_in.empty() && s_out.empty())
				return true;
			else
				return false;
		}
		void enqueue(T const &e){
			s_in.push(e);
		} 
		T dequeue();
}; 

template<typename T>
T Queue<T>::dequeue()
		{
			if(empty()){
					cerr<<"dequeue is empty"<<endl;
					return 0;
				}
			if(s_out.empty())
			{
				while(!s_in.empty()) 
				{
					T tmp = s_in.top();
					s_in.pop();
					s_out.push(tmp);
				}
			}
			T out = s_out.top();
			s_out.pop();
			return out;
		}

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	};
};

//--------------测试用例----------------
/*
1.功能测试： 仅有一个节点的树；仅有左孩子的树；仅有右孩子的树；完全二叉树
2.负面测试：空树 
*/ 
vector<int> PrintFromTopToBottom(TreeNode* root)
{//思路：使用队列实现树的中序遍历 
	vector<int> out;
	if(root==NULL) return out;
	deque<TreeNode*> q;
	q.push_back(root);
	while(!q.empty()){
		TreeNode *x = q.front();
		q.pop_front(); 
		out.push_back(x->val);
		if(x->left!=NULL) 
			q.push_back(x->left);
		if(x->right!=NULL)
			q.push_back(x->right);
	}
	return out;
}

int main()
{
	Queue<int> q;
	q.enqueue(1);
	q.enqueue(2);
	cout<<q.dequeue()<<endl;
	cout<<q.dequeue()<<endl;
	return 0;
}
