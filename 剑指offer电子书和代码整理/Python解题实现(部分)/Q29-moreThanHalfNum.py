# coding:utf-8
"""
//-----------剑指offer解法-------------
//思路：数组中出现次数超过一半的数字意味着其出现次数比剩下的所有数字出现次数都多
//		可以设置两个变量overHalfNum和times，分别存当前可能的候选数字和次数，如果
//		后一个数字与overHalfNum相同，times加一；不同则减一；如果times为0，则更新
//		overHalfNum并将times设为1。overHalfNum中最后存的数字为可能的候选数字（需要对其进行验证)
"""
class Solution:
    def MoreThanHalfNum_Solution(self, numbers):
        # write code here
        Len = len(numbers)
        if Len == 0:
            return 0
        overHalfNum = numbers[0]
        times = 1
        for i in range(1, Len):
            if times == 0:
                overHalfNum = numbers[i]
                times = 1
            elif numbers[i] == overHalfNum:
                times += 1
            else:
                times -= 1
        # 对overHalfNum进行检验（因为输入数组可能根本就没有符合条件的数）
        times = 0
        for i in range(Len):
            if numbers[i] == overHalfNum:
                times += 1
        if 2*times > Len:
            return overHalfNum
        else:
            return 0


if __name__ == "__main__":
    s = Solution()
    numbers_list = [[1], [1, 2, 3], [1, 2, 3, 2, 2, 2, 5, 4, 2]]
    for numbers in numbers_list:
        print s.MoreThanHalfNum_Solution(numbers)