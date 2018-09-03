# coding:utf-8
def printNumber(str_num):
    """打印数（去除前导0）"""
    non_zero_flag = False
    num = ''
    for c in str_num:
        if c != '0':
            non_zero_flag = True
        if non_zero_flag:
            num += c
    print num + '\n'


def printToMaxNDigitsRecursively(str_num, idx):
    """递归输出与str_num长度相等的排列数字符串"""
    if idx == len(str_num):
        printNumber(str_num)
        return
    for i in range(10):
        str_num[idx] = str(i)
        printToMaxNDigitsRecursively(str_num, idx+1)


def printToMaxNDigits(n):
    if n <= 0:
        return
    str_num = ['0'] * n
    printToMaxNDigitsRecursively(str_num, 0)


if __name__ == "__main__":
    printToMaxNDigits(2)
    printToMaxNDigits(0)