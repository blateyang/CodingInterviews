# -*- coding:utf-8 -*-
def notContainsWord(s):
    for c in s:
        if c not in [' ', '\t', '\n']:
            return False
    return True


class Solution:
    def ReverseSentence(self, s):
        Len = len(s)
        if Len == 0 or notContainsWord(s):
            return s
        s_list = s.split()
        reverse_s = ''
        print s_list
        for i in range(len(s_list)):
            reverse_s += s_list[-1-i]+' '
        return reverse_s[:-1] # 去掉最后一个空格

s = Solution()
while True:
    s_test = raw_input()
#    s_test = "I am a students"
    reverse_s = s.ReverseSentence(s_test)
    print reverse_s