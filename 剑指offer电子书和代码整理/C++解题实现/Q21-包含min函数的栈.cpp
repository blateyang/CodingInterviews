#include <iostream>
#include <stack>
using namespace std;
using T=int;

//-----------测试用例-------------------
/*
1.功能测试： 空栈/非空栈入栈；非空栈出栈； 取栈最小元素
2.负面测试： 空栈出栈 
*/ 
//template <typename T> 
class StackWithMin{
	private:
		stack<T> m_data; //数据栈 
		stack<T> m_min;  //辅助栈，用于每次入栈时，将当前最小元素也压入辅助栈中 
	public:
		T top() {
			return m_data.top();
		}
		void push(const T &e){
			if(m_data.empty()) 
			{
				m_data.push(e);
				m_min.push(e);
				return;
			}
			T tmp = top();
			m_data.push(e);
			if(e <= tmp) 
				m_min.push(e);
			else
				m_min.push(tmp);
		}
		void pop(){
			if(!m_data.empty())
			{
				m_min.pop();
				m_data.pop();
			}
		}
		T min(){
			return m_min.top();
		} 
};

int main()
{
	StackWithMin s;
	s.push(3);
	s.push(4);
	cout<<s.min()<<endl;
	s.push(2);
	s.push(1);
	cout<<s.min()<<endl;
	s.pop();
	s.pop();
	cout<<s.min()<<endl;
}
