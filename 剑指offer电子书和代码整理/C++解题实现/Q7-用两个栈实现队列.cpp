#include <iostream>
#include <stack>
#include <stdexcept>
using namespace std;
bool illegalOperate = false;

/*-----------测试用例------------------
	1. 从空队列中插入、删除元素
	2. 从非空队列中插入、删除元素
	3. 连续删除元素直至队列为空 
*/ 
template <typename T> class CQueue
{
	public:		
		void appendTail(const T &node)
		{
			stack1.push(node);
		}
/*		T deleteHead() //自己写的，不够高效 
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
		T deleteHead() //剑指offer思路 
		{
			if(stack2.size() == 0)
			{//将stack1中的元素依次压入stack2中 
				while(stack1.size() > 0)	
					{
						stack2.push(stack1.top());
						stack1.pop();
					}
			 } 
//			try{
//				if(stack2.size() == 0) //从空队列中删除的情况 
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
	cout<<queue.deleteHead(); //不要连在一起输出，<<没有规定操作对象的运算次序 
//	cout<<" "<<queue.deletedHead()<<endl;
	return 0;
}
