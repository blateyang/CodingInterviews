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

// 书上解法
bool isEven(int var)
{
	return (var & 0x1) == 0;
}

void reOrderArray(vector<int> &array, bool (*pFunc)(int)) //使用函数指针可以提高程序的扩展性 
{//思路： 用两个分别指向数组首位的指针，同时向中间行进，当首指针指向偶数且尾指针指向奇数时，
//		  交换它们所指向的元素，直至两指针相遇 
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
//自己的解法：用两个辅助数组，能保持奇数间与偶数间的相对位置不变 ，但需要额外的辅助空间 
        if(array.size()==0)
        	return;
        vector<int> evenArr, oddArr;
        for(auto num: array)
        	if(num%2) //当前元素为奇数
				oddArr.push_back(num);
			else	//当前元素为偶数 
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
