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
 
//------��������-------------
/*
1.���ܣ���ȫ������������ȫ������ 
2.���棺������Ϊ�ջ������ַ�ָ��Ϊ�ջ������ַ����鲻�����ڵ�ֵ 
*/ 
//˼·������˼·���������л�Ϊǰ�����к��������У�Ȼ�������ý�Q6��˼·����ǰ���
//		���������ؽ�������������˼·������ȱ�㣺һ�Ƕ������в�����ֵ�ظ��Ľڵ㣻
//		������Ҫǰ����������ж��õ�����ܷ����ж�����
//		���õ�˼·������ǰ�����+��ָ��������Ĳ��� 

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
	str += intToStr(root->val)+','; //ʵ��һ������תstring�Ĺ��� 
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
			str.erase(str.begin(), it+2); //eraseɾ������[beg,end)���Ԫ�� 
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
    if(ReadStr(str, num)) //ReadStr�����ڴ�str�ж�ȡ������ʱ����true������num�����򷵻�false
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
