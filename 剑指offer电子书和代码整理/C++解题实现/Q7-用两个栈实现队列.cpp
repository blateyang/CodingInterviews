#include <iostream>
#include <stack>
#include <stdexcept>
using namespace std;
bool illegalOperate = false;

/*-----------��������------------------
	1. �ӿն����в��롢ɾ��Ԫ��
	2. �ӷǿն����в��롢ɾ��Ԫ��
	3. ����ɾ��Ԫ��ֱ������Ϊ�� 
*/ 
template <typename T> class CQueue
{
	public:		
		void appendTail(const T &node)
		{
			stack1.push(node);
		}
/*		T deleteHead() //�Լ�д�ģ�������Ч 
		{
			if(stack1.size() == 0)
				illegalOperate = true;
			while(stack1.size() > 1)
				{
					stack2.push(stack1.top());
					stack1.pop();
				 } 
			T nodeToBeDeleted = stack1.top();
			stack1.pop();
			while(stack2.size() > 0)
				{
					stack1.push(stack2.top());
					stack2.pop();
				}
			return nodeToBeDeleted;
		}*/
		T deleteHead() //��ָoffer˼· 
		{
			if(stack2.size() == 0)
			{//��stack1�е�Ԫ������ѹ��stack2�� 
				while(stack1.size() > 0)	
					{
						stack2.push(stack1.top());
						stack1.pop();
					}
			 } 
//			try{
//				if(stack2.size() == 0) //�ӿն�����ɾ������� 
//					{logic_error err("queue is empty"); throw exception(err);}
//			}catch(exception err){
//				cout<<err.what()<<endl;
//			}
			if(stack2.size() == 0)
				{
					cerr<<"queue is empty"<<endl;
					return 0;
				}
			T item = stack2.top();
			stack2.pop();
			return item; 
		}
	private:
		stack<T> stack1;
		stack<T> stack2;
 } ;
 
int main()
{
	CQueue<int> queue;
//	queue.appendTail(1);
//	queue.appendTail(2);
	cout<<queue.deleteHead(); //��Ҫ����һ�������<<û�й涨���������������� 
//	cout<<" "<<queue.deletedHead()<<endl;
	return 0;
}
