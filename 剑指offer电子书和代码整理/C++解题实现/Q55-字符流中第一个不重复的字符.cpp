#include <iostream>
#include <string>
#include <sstream>
using namespace std;

//-------------测试用例----------------
/*
1.功能：当前字符流存在出现一次的字符（一个或多个）；不存在出现一次的字符
2.负面：当前字符流为空 
*/ 
class Solution
{
private:
	int index; //记录字符流中当前字符的索引 
	//存储字符在字符流中的索引的哈希表，值为-1表示对应字符还未出现，为-2表示重复出现 
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
{//这种每次调用都要重新对当前字符流建立哈希表的方法没有剑指offer的方法高效（只要一次建立，每次插入时更新表即可） 
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
