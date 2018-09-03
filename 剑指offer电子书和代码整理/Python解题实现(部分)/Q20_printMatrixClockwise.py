# -*- coding:utf-8 -*-
def printMatrixInCircle(matrix, rows, cols, start, result):
    endX = cols-1-start
    endY = rows-1-start
    for i in range(start, endX+1):
        result.append(matrix[start][i])
    if endY > start:
        for i in range(start+1, endY+1):
            result.append(matrix[i][endX])
    if endX > start and endY > start:
        for i in range(endX-1, start-1, -1):
            result.append(matrix[endY][i])
    if endX > start and endY > start+1:
        for i in range(endY-1, start, -1):
            result.append(matrix[i][start])


class Solution:
    # matrix类型为二维列表，需要返回列表
    def printMatrix(self, matrix):
        # write code here
        if len(matrix) == 0 or len(matrix[0]) == 0:
            return matrix
        result = []
        start = 0
        rows, cols = len(matrix), len(matrix[0])
        while rows > 2*start and cols > 2*start:
            printMatrixInCircle(matrix, rows, cols, start, result)
            start += 1
        return result


if __name__ == "__main__":
    s = Solution()
    matrix = [[1]]
    result = s.printMatrix(matrix)
    for item in result:
        print item