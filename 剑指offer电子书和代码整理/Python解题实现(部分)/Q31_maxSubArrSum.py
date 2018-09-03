# -*- coding:utf-8 -*-
class Solution:
    def FindGreatestSumOfSubArray(self, array):
        # write code here
        assert len(array) > 0, "invalid input"
        curSubArrSum = 0
        maxSubArrSum = -2**31
        for num in array:
            if curSubArrSum <= 0:
                curSubArrSum = num
            else:
                curSubArrSum += num
            if curSubArrSum > maxSubArrSum:
                maxSubArrSum = curSubArrSum
        return maxSubArrSum


if __name__ == "__main__":
    s = Solution()
    array = [1, -2, 3, 10, -4, 7, 2, -5]
    print s.FindGreatestSumOfSubArray(array)

