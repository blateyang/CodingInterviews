#include <iostream>
#include <stack>
using namespace std;
using T=int;

//-----------��������-------------------
/*
1.���ܲ��ԣ� ��ջ/�ǿ�ջ��ջ���ǿ�ջ��ջ�� ȡջ��СԪ��
2.������ԣ� ��ջ��ջ 
*/ 
//template <typename T> 
class StackWithMin{
	private:
		stack<T> m_data; //����ջ 
		stack<T> m_min;  //����ջ������ÿ����ջʱ������ǰ��СԪ��Ҳѹ�븨��ջ�� 
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
