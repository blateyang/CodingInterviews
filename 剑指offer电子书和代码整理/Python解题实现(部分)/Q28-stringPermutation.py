# -*- coding:utf-8 -*-
def permutationIter(ss_list, ss, start):
    if start == len(ss)-1:
        ss_immutable = ''
        for i in range(len(ss)):
            ss_immutable += ss[i]
        ss_list.append(ss_immutable)
        return
    for i in range(start, len(ss)):  #基于回溯法
        ss[start], ss[i] = ss[i], ss[start]
        permutationIter(ss_list, ss, start+1)
        ss[start], ss[i] = ss[i], ss[start]


class Solution:
    def Permutation(self, ss):
        # write code here
        ss_list = []
        if len(ss) != 0:
            ss_mutable = []
            for i in range(len(ss)):
                ss_mutable.append(ss[i])
            permutationIter(ss_list, ss_mutable, 0)
        # 对ss_list进行去重并按字典序排序
        unique_ss_list = set(ss_list)
        return sorted(unique_ss_list)


if __name__ == "__main__":
    while True:
        ss = raw_input()
        s = Solution()
        print(s.Permutation(ss))