# -*- coding:utf-8 -*-
class Solution:
    # 这里要特别注意~找到任意重复的一个值并赋值到duplication[0]
    # 函数返回True/False
    def duplicate(self, numbers, duplication):
        # write code here
        length = len(numbers)
        if numbers is None or length <= 1:
            return False
        hashTable = [0]*length
        for i in range(length):
            if numbers[i] < 0 or numbers[i] >= length:
                return False
            hashTable[numbers[i]] += 1
        for i in range(length):
            if hashTable[i] > 1:
                duplication[0] = numbers[i]
                return True
        return False

s = Solution()
nums_test = [[1, 2, 3], [1, 2, 2, 3], [1, 1, 2, 2], [1], [4, 2]]
dup = [-1]
for nums in nums_test:
    if s.duplicate(nums, dup):
        print dup
