# -*- coding:utf-8 -*-
import collections
"""
测试用例
1.功能：字符串仅有1个字符，有多个字符（出现次数均为1，有出现次数超过1的）
2.负面：字符串为空
"""
class Solution:
    def FirstNotRepeatingChar(self, s):
        if len(s) == 0:
            return -1
#        hashTable = collections.OrderedDict()
        hashTable = {}
        for c in s:
            hashTable[c] = 0
        for c in s:
            hashTable[c] += 1
        for i,c in enumerate(s):
            if hashTable[c] == 1:
                return i
        return -1

if __name__ == "__main__":
    s = Solution()
    s_test = "abaccdeff"
    print s.FirstNotRepeatingChar(s_test)

        
        