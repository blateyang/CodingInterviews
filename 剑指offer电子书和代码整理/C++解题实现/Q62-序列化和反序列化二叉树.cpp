#include <iostream>
#include <string> 
#include <vector>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 }; 
 
//------测试用例-------------
/*
1.功能：完全二叉树，非完全二叉树 
2.负面：二叉树为空或序列字符指针为空或序列字符数组不含树节点值 
*/ 
//思路：初步思路可以先序列化为前序序列和中序序列，然后再利用解Q6的思路利用前序和
//		中序序列重建二叉树，但该思路有两个缺点：一是二叉树中不能有值重复的节点；
//		二是需要前序和中序序列都得到后才能反序列二叉树
//		更好的思路是利用前序遍历+空指针替代符的策略 

string intToStr(int n) 
{
	string s;
	vector<char> v;
	bool negFlag = false;
	if(n < 0) 
	{
		negFlag = true;
		n = -n;
		s.push_back('-');
	}
	while(n)
	{
		v.push_back(n%10 + '0');
		n = n/10;
	}
	for(int i=v.size()-1; i>=0; --i)
		s.push_back(v[i]);
	return s;
}

void Serialize(TreeNode *root, string &str) {    
	if(root == NULL)
		{
			str += "$,";
			return; 
		} 
	str += intToStr(root->val)+','; //实现一个整数转string的功能 
	Serialize(root->left, str);
	Serialize(root->right, str); 
    }
    
bool ReadStr(string &str, int &num)
{
	if(str.size()==0)
		return false;
	string::iterator it = str.begin(); 
	while(*it != ',')
	{ 
		if(*it == '$')
		{
			str.erase(str.begin(), it+2); //erase删除的是[beg,end)间的元素 
			return false;
		}
		if(*it>='0' && *it<='9')
			num = num*10 + *(it++)- '0';
	}
	str.erase(str.begin(), it+1);
	return true;
}

TreeNode* Deserialize(string &str) {
    TreeNode *pNode = NULL;
    int num = 0;
    if(ReadStr(str, num)) //ReadStr函数在从str中读取到数字时返回true并存入num，否则返回false
		pNode = new TreeNode(num); 
	if(pNode != NULL)
	{
		pNode->left = Deserialize(str);
		pNode->right = Deserialize(str);
	}
	return pNode;
} 

int main()
{
	string str = "1,$,2,$,$,";
	TreeNode *root = Deserialize(str);
	cout<<root->val<<endl;
	cout<<root->right->val<<endl;
	string res;
	Serialize(root, res);
	cout<<res<<endl;
	return 0;
}
