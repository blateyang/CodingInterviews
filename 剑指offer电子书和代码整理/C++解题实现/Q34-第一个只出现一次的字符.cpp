#include <iostream>
#include <vector>
using namespace std;

//---------------��������---------------------
/*
1.���ܣ��ַ�������1���ַ����ж���ַ������ִ�����Ϊ1�����ִ�������Ϊ1��ͨ�������
2.���棺�ַ���Ϊ��
*/
int FirstNotRepeatingChar(string str) {
//˼·��ɨ���ַ���������һ����ϣ��洢���ַ����ֵĴ����������ɨ��һ���ַ�����
//		���ݽ����Ĺ�ϣ���״�ֻ����һ�ε��ַ������������
	int len = str.size();
	if(len == 0)
		return -1;
	vector<unsigned> hashTable(256, 0);
	int i;
	for(i=0; i<len; ++i)
		++hashTable[str[i]];
	for(i=0; i<len; ++i)
		if(hashTable[str[i]] == 1)
			return i;
    } 

int main()
{
	vector<string> v_str{"a", "abc", "abaccdeff"}; 
	for(auto str:v_str)
		cout<<FirstNotRepeatingChar(str)<<endl;
	return 0;
}
