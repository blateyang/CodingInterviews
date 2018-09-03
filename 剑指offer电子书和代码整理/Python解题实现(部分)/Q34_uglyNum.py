# -*- coding:utf-8 -*-
def Min(a, b, c):
    return min([a, b, c])

class Solution:
    def GetUglyNumber_Solution(self, index):
        """
        思路1：先写一个判断是否为丑数的函数;然后从1开始递增的对每个
              数判断是否为丑数，累加丑数的个数直到等于index（简单但低效）
        思路2：利用已有的丑数计算出新的丑数并利用数组存起来（空间换时间）
        """
        assert index > 0, "invalid input"
        # 采用思路2
        uglyNums = [1]*index
        pMultiply2, pMultiply3, pMultiply5 = 0, 0, 0
        pNextUglyNum = 1
        while pNextUglyNum < index:
            uglyNums[pNextUglyNum] = min([2*uglyNums[pMultiply2], 3*uglyNums[pMultiply3], 5*uglyNums[pMultiply5]])
            while 2*uglyNums[pMultiply2] <= uglyNums[pNextUglyNum]:
                pMultiply2 += 1
            while 3*uglyNums[pMultiply3] <= uglyNums[pNextUglyNum]:
                pMultiply3 += 1
            while 5*uglyNums[pMultiply5] <= uglyNums[pNextUglyNum]:
                pMultiply5 += 1
            pNextUglyNum += 1
        return uglyNums[pNextUglyNum-1]

s = Solution()
test = [1, 2, 3, 4, 5, 6, 7, 1500]
for t in test:
    print s.GetUglyNumber_Solution(t)
            