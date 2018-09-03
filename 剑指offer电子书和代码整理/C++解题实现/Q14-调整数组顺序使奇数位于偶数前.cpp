#include <iostream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;

int stringToInt(string const &str)
{
	int num=0;
	if(str.size()==0)
		cout<<"can not convert empty string to int"<<endl; 
	int i = (str[0]!='-') ? 0:1;
	bool pos_flag=true;
	if(i==1)
		pos_flag=false;
	while(i<str.size())
		num = num*10 + str[i++]-'0';
	if(pos_flag)
		return num;
	else
		return -num;
}

// ���Ͻⷨ
bool isEven(int var)
{
	return (var & 0x1) == 0;
}

void reOrderArray(vector<int> &array, bool (*pFunc)(int)) //ʹ�ú���ָ�������߳������չ�� 
{//˼·�� �������ֱ�ָ��������λ��ָ�룬ͬʱ���м��н�������ָ��ָ��ż����βָ��ָ������ʱ��
//		  ����������ָ���Ԫ�أ�ֱ����ָ������ 
	if(array.size() == 0)
		return;
	int *pHead = &array[0];
	int *pEnd = pHead + array.size()-1;
	while(pHead < pEnd)
	{
		while(pHead < pEnd && !pFunc(*pHead))
			pHead++;
		while(pHead < pEnd && pFunc(*pEnd))
			pEnd--;
		if(pHead < pEnd)
			{
				int tmp = *pHead;
				*pHead = *pEnd;
				*pEnd = tmp;
			}
//		cout<<*pHead<<" "<<*pEnd<<endl;
	}
 } 
 
void reOrderArray(vector<int> &array) {
//�Լ��Ľⷨ���������������飬�ܱ�����������ż��������λ�ò��� ������Ҫ����ĸ����ռ� 
        if(array.size()==0)
        	return;
        vector<int> evenArr, oddArr;
        for(auto num: array)
        	if(num%2) //��ǰԪ��Ϊ����
				oddArr.push_back(num);
			else	//��ǰԪ��Ϊż�� 
				evenArr.push_back(num);
		int oddLen = oddArr.size();
		for(int i=0; i<oddLen; ++i)
			array[i] = oddArr[i];
		for(int i=0; i<evenArr.size(); ++i)
			array[i+oddLen] = evenArr[i];
    }
    

int main()
{
//	vector<int> v1, v2{1,3,5}, v3{2,4,6}, v4{1,-2,3,4}, v5{2,-1,4,3};
	string input;
	while(getline(cin, input))
	{
		vector<int> v_test;
		istringstream str_in(input);
		string tmp;
		while(str_in>>tmp)
			v_test.push_back(stringToInt(tmp));
			
		reOrderArray(v_test, isEven);
		for(auto num: v_test)
			cout<<num<<" ";
		cout<<endl;
	}
	return 0;
}
