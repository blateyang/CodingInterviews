# -*- coding:utf-8 -*-
class Solution:
    def FindContinuousSequence(self, tsum):
        result = []
        if tsum < 3:
            return result
        small, big, curSum = 1, 2, 3
        while small < (tsum+1)/2:
            if curSum < tsum:
                big += 1
                curSum += big
            else:
                if curSum == tsum:
                    curSeq = []
                    for i in range(small, big+1):
                        curSeq.append(i)
                    result.append(curSeq)
                curSum -= small
                small += 1
        return result

s = Solution()
test = [3, 4, 9, 15]
for num in test:
    result = s.FindContinuousSequence(num)
    print result
                