# -*- coding:utf-8 -*-
def getLastK(data, low, high, num): # data[low, high)
    if low == high:
        return -1
    if low == high-1:
        return low if data[low] == num else -1
    mid = (low + high) / 2
    if data[mid] <= num:
        low = mid
    else:
        high = mid
    return getLastK(data, low, high, num)

def getLastSmallThanK(data, low, high, num):
    if low == high:
        return -1
    if low == high-1:
        return low if data[low] < num else -1
    mid = (low + high) / 2
    if num <= data[mid]:
        high = mid
    else:
        low = mid
    return getLastSmallThanK(data, low, high, num)

class Solution:
    def GetNumberOfK(self, data, k):
        """只考虑非降序数组情况，思路是找到不大于k的最后一个数
            以及小于k的最后一个数
        """
        if len(data) == 0:
            return 0
        postIdx = getLastK(data, 0, len(data), k)
        preIdx = getLastSmallThanK(data, 0, len(data), k)
        result = postIdx - preIdx
        return result if result > 0 else 0

s = Solution()
datas = [[1, 2], [1, 2, 3], [1, 3, 5], [3, 4, 5], [1, 2, 3, 3], [1, 3, 3, 5], [3, 3, 4, 5]]
for data in datas:
    print s.GetNumberOfK(data, 3)
