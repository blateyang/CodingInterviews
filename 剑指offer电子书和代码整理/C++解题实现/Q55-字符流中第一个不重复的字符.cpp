#include <iostream>
#include <string>
#include <sstream>
using namespace std;

//-------------��������----------------
/*
1.���ܣ���ǰ�ַ������ڳ���һ�ε��ַ���һ���������������ڳ���һ�ε��ַ�
2.���棺��ǰ�ַ���Ϊ�� 
*/ 
class Solution
{
private:
	int index; //��¼�ַ����е�ǰ�ַ������� 
	//�洢�ַ����ַ����е������Ĺ�ϣ��ֵΪ-1��ʾ��Ӧ�ַ���δ���֣�Ϊ-2��ʾ�ظ����� 
	int occurrence[256]; 
public:
	Solution():index(0){
		for(int i=0; i<256; ++i)
			occurrence[i] = -1;
	}
	void Insert(char ch)
	{
		if(occurrence[ch] == -1)
			occurrence[ch] = index;
		else if(occurrence[ch] >= 0)
			occurrence[ch] = -2;
		++index;
	}
	char FirstAppearingOnce()
	{
		char ch = '#';
		int minIndex = 0x7fffffff;
		for(int i=0; i<256; ++i)
		{
			if(occurrence[i]>=0 && occurrence[i]<minIndex)
			{
				ch = char(i);
				minIndex = occurrence[i];
			}
		}
		return ch;
	}
};

string strStream;
void Insert(char ch)
    {
         strStream.push_back(ch);
    }
char FirstAppearingOnce()
{//����ÿ�ε��ö�Ҫ���¶Ե�ǰ�ַ���������ϣ��ķ���û�н�ָoffer�ķ�����Ч��ֻҪһ�ν�����ÿ�β���ʱ���±��ɣ� 
	string str = strStream;
	int len = str.size();
	if(len==0)
		return '#';
	int hashTable[256] = {0};
	int i;
	for(i=0; i<len; ++i)
		++hashTable[str[i]];
	for(i=0; i<len; ++i)
		if(hashTable[str[i]] == 1)
			return str[i];
	return '#'; 
}

int main()
{
//	Solution s;
//	s.Insert('g');
//	s.Insert('o');
//	s.Insert('o');
//	s.Insert('g');
//	s.Insert('l');
//	s.Insert('e');
//	cout<<s.FirstAppearingOnce()<<endl;
	Insert('g');
	cout<<FirstAppearingOnce()<<endl;
	Insert('o');
	cout<<FirstAppearingOnce()<<endl;
	Insert('g');
	cout<<FirstAppearingOnce()<<endl;
	return 0;
}
