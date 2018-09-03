#include <iostream>
#include <vector>
using namespace std;

//---------------测试用例---------------------
/*
1.功能：字符串仅有1个字符，有多个字符（出现次数均为1，出现次数均不为1，通常情况）
2.负面：字符串为空
*/
int FirstNotRepeatingChar(string str) {
//思路：扫描字符串，利用一个哈希表存储各字符出现的次数，最后再扫描一遍字符串并
//		根据建立的哈希表将首次只出现一次的字符所在索引输出
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
