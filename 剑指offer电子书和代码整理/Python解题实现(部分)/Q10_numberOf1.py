class Solution:
    def numberOf1(self, n):
        count = 0
        while n:
            n = n & (n-1)
            count += 1
        return count


if __name__ == "__main__":
    s = Solution()
    print(s.numberOf1(10))